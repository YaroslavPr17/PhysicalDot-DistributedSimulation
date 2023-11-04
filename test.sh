# !/bin/bash

START_VALUE=$1
FINISH_VALUE=$2
STEP=$3

SOURCE_NAME=$4
IS_HT=$5
        
gcc src/$SOURCE_NAME.c -lm src/test_unit.c -o ./out/test_unit_run

for ((n_bodies=$START_VALUE; n_bodies < $FINISH_VALUE; n_bodies += $STEP))
do
    for n_threads in 1 2 4 6 12 24 30 40 60 120
    do
        ./out/test_unit_run $n_threads $n_bodies $IS_HT $SOURCE_NAME
    done
done
