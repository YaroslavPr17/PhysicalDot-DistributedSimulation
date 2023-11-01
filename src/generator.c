#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){    
    srand(time(NULL));   // Initialization, should only be called once.

    const double GRAV_CONST = 6.6743e-11;

    long n_bodies = strtol(argv[1], NULL, 10);
    long n_steps = strtol(argv[2], NULL, 10);

    char temp[128] = "./data/input/gen_input";
    char temp1[32];

    printf("---> %ld bodies will be generated to be modelled for %ld time-steps.\n", n_bodies , n_steps);

    sprintf(temp1, "%ld", n_bodies);
    strcat(temp, temp1);

    FILE *fp = fopen(temp, "w");

    if (fp == NULL){
        printf("File opening error! (%s)\n", temp); 
        return 0;
    }

    fprintf(fp, "%s %ld %ld\n", "6.6743e-11", n_bodies, n_steps);

    for (long i = 0; i < n_bodies; ++i){
        int val = rand() % 200 + 50;
        fprintf(fp, "%d\n", val);

        fprintf(fp, "%d %d\n", rand() % 100, rand() % 100);
        fprintf(fp, "%d %d\n", rand() % 50 + 50, rand() % 50 + 50);
    }

    return 0;
}