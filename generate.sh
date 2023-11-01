# !/bin/bash

START_VALUE=100
FINISH_VALUE=2000

for ((n_bodies=$START_VALUE; n_bodies <= $FINISH_VALUE; n_bodies += 100))
do
    ./out/gen_run $n_bodies 1000
    sleep 1
done
