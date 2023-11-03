#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "multi_thread.h"


int main(int argc, char** argv) {

    long n_retries;
    long n_bodies;
    int n_threads;
    char* HT;

    if (argc < 4){
        printf("Usage : %s <thread_count> <bodies_count> <HT True/False> <retries_count>", argv[0]);
        return 0;
    }
    
    if (argc == 5){
        n_threads = strtol(argv[1], NULL, 10);
        n_bodies = strtol(argv[2], NULL, 10);
        HT = argv[3];
        n_retries = strtol(argv[4], NULL, 10);
    }
    else if(argc == 4){
        printf("Not implemented yet\n");
        return 0;


        n_bodies = strtol(argv[1], NULL, 10);
        long tm; 
        printf("Input max whole computation time (min): ");
        scanf("%ld", &tm);



    }
        
    char file_in[128] = "./data/input/gen_input%ld.txt";
    char file_out[128] = "./data/output/gen_output%ld.csv";
    char fin[128];
    char fout[128];

    sprintf(fin, file_in, n_bodies);
    sprintf(fout, file_out, n_bodies);

    printf("---> Input file: %s\n", fin);
    printf("---> Output file: %s\n", fout);

    printf("---> Testing %ld bodies on %d threads for %ld retries.\n", n_bodies, n_threads, n_retries);

    char metrics_filename[128] = "./experiments/bodies/exp_data.txt";
    FILE *metr_file = fopen(metrics_filename, "a");

    double sum_exec_time = 0;

    printf("RETRY ");
    for (long i = 0; i < n_retries; ++i){
        printf("#%ld ", i);
        sum_exec_time += make_single_run(n_threads, fin, fout);
    }
    printf("\n");
    
    printf("---> Mean execution time over %ld retries = %4.12lf s.\n", n_retries, sum_exec_time / n_retries);
    fprintf(metr_file, "%ld,%d,%ld,%4.12lf,%s\n", n_bodies, n_threads, n_retries, sum_exec_time / n_retries, HT);

    fclose(metr_file);

    return 0;
}
