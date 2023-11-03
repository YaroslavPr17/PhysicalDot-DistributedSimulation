# !/bin/bash

START_VALUE=$1
FINISH_VALUE=$2
STEP=$3

for ((n_bodies=$START_VALUE; n_bodies < $FINISH_VALUE; n_bodies += $STEP))
do
    ./out/gen_run $n_bodies 1000
    sleep 1
done
