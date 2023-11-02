#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <float.h>
#include <string.h>

#include "multi_thread.h"
#include "timer.h"


#define DT 0.05
#define EPS 10e-32
#define VEC_LEN_EPS 10e-6
#define OUT_FEATURE_COUNT 6

typedef struct
{
    double x, y;
} vector;

int bodies, timeSteps;
double *masses, GravConstant;
vector **acc_table;
vector *positions, *velocities, *accelerations;

char* output_filename;

double **temp_res;

int thread_count = 0;
pthread_t* thread_handles = NULL;

sem_t* sems;
int sval;
int n_finished = 0;

pthread_mutex_t mutex_mini;




// INITIALIZATION ==============================================================================

vector addVectors(vector a, vector b)
{
    vector c = {a.x + b.x, a.y + b.y};

    return c;
}

vector scaleVector(double b, vector a)
{
    vector c = {b * a.x, b * a.y};

    return c;
}

vector subtractVectors(vector a, vector b)
{
    vector c = {a.x - b.x, a.y - b.y};

    return c;
}

double mod(vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

// void initThreads(){
//     thread_handles = (void*)malloc(thread_count * sizeof(pthread_t));

//     for (long i = 0; i < thread_count; ++i ) {
//         pthread_create(&thread_handles[i], NULL, simulate, (void*) i);
//     }
//     for (long i = 0; i < thread_count; ++i) {
//         pthread_join(thread_handles[i], NULL);
//     }
// }

int initiateSystem(char *fileName)
{
    long i;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL){
        return 1;
    }

    fscanf(fp, "%lf%d%d", &GravConstant, &bodies, &timeSteps);

    masses = (double *)malloc(bodies * sizeof(double));
    positions = (vector *)malloc(bodies * sizeof(vector));
    velocities = (vector *)malloc(bodies * sizeof(vector));
    accelerations = (vector *)malloc(bodies * sizeof(vector));

    acc_table = (vector**)malloc(bodies * sizeof(vector*));
    for (i = 0; i < bodies; ++i){
        acc_table[i] = (vector*)malloc(bodies * sizeof(vector));
        for (long j = 0; j < bodies; ++j){
            acc_table[i][j].x = DBL_MAX;            
        }
    }

    temp_res = (double**)malloc(bodies * sizeof(double*));
    for (i = 0; i < bodies; ++i){
        temp_res[i] = (double*)malloc(OUT_FEATURE_COUNT * sizeof(double));
    }

    sems = (sem_t*) malloc(thread_count * sizeof(sem_t));
    for (i = 0; i < thread_count; ++i){
        sem_init(&sems[i], 0, 0);
    }

    pthread_mutex_init (&mutex_mini, NULL);

    for (i = 0; i < bodies; i++)
    {
        fscanf(fp, "%lf", &masses[i]);
        fscanf(fp, "%lf%lf", &positions[i].x, &positions[i].y);
        fscanf(fp, "%lf%lf", &velocities[i].x, &velocities[i].y);
    }

    fclose(fp);
    return 0;
}

void removeSystem()
{
    free(masses);
    free(positions);
    free(velocities);
    free(accelerations);

    for (long i = 0; i < bodies; ++i){
        free(acc_table[i]);
    }
    free(acc_table);
}

void resolveCollisions()
{
    long i, j;

    for (i = 0; i < bodies - 1; i++)
        for (j = i + 1; j < bodies; j++)
        {
            if ((fabs(positions[i].x - positions[j].x) < EPS) && (fabs(positions[i].y - positions[j].y) < EPS))
            {
                vector temp = velocities[i];
                velocities[i] = velocities[j];
                velocities[j] = temp;
            }
        }
}


// ACCELERATIONS ==============================================================================


void* computeAccelerationsRoutine(void* rank){
    long thread_n = (long) rank;
    long batch_size = bodies / thread_count;
    long start = batch_size * thread_n;
    long finish = start + batch_size;    

    long i, j;

    for (i = start; i < finish; i++)
    {
        for (j = 0; j < bodies; j++)
        {
            if (i != j){
                if (fabs(acc_table[j][i].x - DBL_MAX) < EPS)   // Верхняя часть 
                {
                    double vec_len = mod(subtractVectors(positions[i], positions[j]));
                    vec_len = vec_len < VEC_LEN_EPS ? VEC_LEN_EPS : vec_len;
                    acc_table[i][j] =
                        scaleVector(
                            GravConstant * masses[j] / pow(
                                vec_len, 
                                3), 
                            subtractVectors(positions[j], positions[i]));
                }
                else {
                    acc_table[i][j] = scaleVector(-1, acc_table[j][i]);
                }
            }

        }
    }

    return NULL;
}


void* sumAccelerationsRoutine(void* rank){
    long thread_n = (long) rank;
    long batch_size = bodies / thread_count;
    long start = batch_size * thread_n;
    long finish = start + batch_size;    

    long i, j;

    for (i = start; i < finish; i++)
    {
        accelerations[i].x = 0;
        accelerations[i].y = 0;        
        for (j = 0; j < bodies; j++)
        {
            if (i != j)
                accelerations[i] = addVectors(accelerations[i], acc_table[i][j]);
        }
    }

    return NULL;
}



void* computeAccelerationsMultiSum(void* rank){
    
    computeAccelerationsRoutine(rank);
    sumAccelerationsRoutine(rank);

    return NULL;
}


// VELOCITIES ==============================================================================

void* computeVelocitiesRoutine(void* rank){
    long thread_n = (long) rank;
    long batch_size = bodies / thread_count;
    long start = batch_size * thread_n;
    long finish = start + batch_size;    

    long i, j;

    for (i = start; i < finish; i++)
    {    
        velocities[i] = addVectors(
            velocities[i], 
            scaleVector(DT, accelerations[i])
        );
    }

    return NULL;
}


void* computeVelocitiesMulti(void* rank)
{
    computeVelocitiesRoutine(rank);

    return NULL;
}


// POSITIONS ==============================================================================

void* computePositionsRoutine(void* rank){
    long thread_n = (long) rank;
    long batch_size = bodies / thread_count;
    long start = batch_size * thread_n;
    long finish = start + batch_size;    

    long i, j;

    for (i = start; i < finish; i++)
    {    

        positions[i] = addVectors(positions[i], scaleVector(DT, velocities[i]));

    }

    return NULL;
}


void* computePositionsMulti(void* rank)
{
    computePositionsRoutine(rank);

    return NULL;
}



// OUT_CALL ==============================================================================


void* simulate(void* rank)
{
    for (int i = 0; i < timeSteps; i++)
    {
        long thread_n = (long) rank;
        long batch_size = bodies / thread_count;
        long start = batch_size * thread_n;
        long finish = start + batch_size;    

        computeAccelerationsMultiSum(rank);
        computePositionsMulti(rank);
        computeVelocitiesMulti(rank);
        // resolveCollisions();



        for (long j = start; j < finish; j++){
            temp_res[j][0] = j;
            temp_res[j][1] = masses[j];
            temp_res[j][2] = positions[j].x;
            temp_res[j][3] = positions[j].y;
            temp_res[j][4] = velocities[j].x;
            temp_res[j][5] = velocities[j].y;
        }
        
        pthread_mutex_lock(&mutex_mini);
        ++n_finished;
        pthread_mutex_unlock(&mutex_mini);

        if (n_finished == thread_count){

            FILE *fp = fopen(output_filename, "a");
            if (fp == NULL){
                printf("Error when opening output_file; '%s'.\n", output_filename);
                return NULL;
            }

            for (long j = 0; j < bodies; j++){
                fprintf(fp, "%6.0lf,%lf,%lf,%lf,%lf,%lf\n", 
                    temp_res[j][0] + 1, 
                    temp_res[j][1], 
                    temp_res[j][2], 
                    temp_res[j][3], 
                    temp_res[j][4], 
                    temp_res[j][5]
                );
            }
        
            fclose(fp);
            
            for (int j = 0; j < thread_count; ++j){
                if (sem_getvalue(&sems[j], &sval)){
                    printf("Wrong semaphore value check!!!\n");
                    return NULL;
                }
                if (j != thread_n){

                    sem_post(&sems[j]);
                }
            }
            n_finished = 0;

        }
        else{

            sem_wait(&sems[thread_n]);
        }   


    }

    return NULL;
}

double make_single_run(int n_threads, char* input_file, char* output_file)
{
    thread_handles = (void*)malloc(thread_count * sizeof(pthread_t));
    output_filename = output_file;
    thread_count = n_threads;

    double start, end, overall_time = 0.0; 

    if (initiateSystem(input_file)){
        printf("Error when opening input_file: '%s'.\n", input_file);
        return overall_time;
    }

    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL){
        printf("Error when opening output_file; '%s'.\n", output_filename);
        return overall_time;
    }
    fprintf(fp, "Body,mass,x,y,vx,vy\n");

    fclose(fp);

    GET_TIME(start);
    for (long i = 0; i < thread_count; ++i ) {
        pthread_create(&thread_handles[i], NULL, simulate, (void*) i);
    }
    for (long i = 0; i < thread_count; ++i) {
        pthread_join(thread_handles[i], NULL);
    } 
    GET_TIME(end);

    overall_time += end - start;

    removeSystem();

    return overall_time;
}
