#include <stdio.h>
#include <unistd.h>

int main(int argc) {
    char binaryPath[] = "./out/multi_run";
    char arg1[] = "./out/multi_run";
    char arg2[] = "1";
    char arg3[] = "./data/input/input4";
    char arg4[] = "./data/output/output4";
    printf("First line of current program\n");
    execl(binaryPath, arg1, arg2, arg3, arg4, (char*) NULL);
    printf("Last line of current program\n");
    return 0;
}