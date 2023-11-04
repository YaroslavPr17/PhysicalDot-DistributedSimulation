#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "multi_thread.h"

#define MAX_SINGLE_TEST_COUNT 300
#define MAX_RETRIES_COUNT 20


int main(int argc, char** argv) {

    long n_retries;
    long n_bodies;
    int n_threads;
    char *HT, *src;

    if (argc < 5){
        printf("Usage : %s <thread_count> <bodies_count> <HT True/False> <src_name.cpp> <retries_count>", argv[0]);
        return 0;
    }

    n_threads = strtol(argv[1], NULL, 10);
    n_bodies = strtol(argv[2], NULL, 10);
    HT = argv[3];
    src = argv[4];

    if (argc == 6){
        n_retries = strtol(argv[5], NULL, 10);
    }
        
    char file_in[128] = "./data/input/gen_input%ld.txt";
    char file_out[128] = "./data/output/gen_output%ld.csv";
    char metrics_filename[128] = "./experiments/bodies/exp_data.%s.txt";
    char fin[128];
    char fout[128];
    char fmetr[128];

    sprintf(fin, file_in, n_bodies);
    sprintf(fout, file_out, n_bodies);
    sprintf(fmetr, metrics_filename, src);

    // printf("---> Input file: %s\n", fin);
    // printf("---> Output file: %s\n", fout);

    // printf("---> Metrics file: %s\n", fmetr);
    FILE *metr_file = fopen(fmetr, "a");

    double sum_exec_time = 0;

    if (argc == 5){
        // printf("---> Retries count is not provided and will be automatically adjusted.\n");

        double temp_time = make_single_run(n_threads, fin, fout);
        sum_exec_time += temp_time;
        n_retries = MAX_SINGLE_TEST_COUNT / temp_time;
        if (n_retries > MAX_RETRIES_COUNT) 
            n_retries = MAX_RETRIES_COUNT;
        if (n_retries < 1) 
            n_retries = 2;
    }

    // printf("---> Testing %ld bodies on %d threads for %ld retries.\n", n_bodies, n_threads, n_retries);

    printf("\nLOGS: n_threads=%d, n_bodies=%ld, n_retries=%ld\n", n_threads, n_bodies, n_retries);


    printf("Retries ");
    for (long i = 0; i < n_retries; ++i){
        if (i < 10 || i % 10 == 0){
            printf("%ld ", i + 1);
            fflush(stdout);
        }
        sum_exec_time += make_single_run(n_threads, fin, fout);
    }
    printf("\n");

    if (argc == 5)
        n_retries++;

    printf("Result=%lf\n", sum_exec_time / n_retries);

    
    // printf("---> Mean execution time over %ld retries = %4.12lf s.\n", n_retries, sum_exec_time / n_retries);
    fprintf(metr_file, "%ld,%d,%ld,%4.12lf,%s\n", n_bodies, n_threads, n_retries, sum_exec_time / n_retries, HT);

    fclose(metr_file);

    return 0;
}
