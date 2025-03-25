#!/bin/bash

# This file is called sortrace.sh
# It must have execute privilege set to run
# run it as a background task like this: (see the 2 lines below)
#----------------------------------------------------------------------------------------------
# $ rm sortrace.log # start with fresh log file
# $ sortrace.sh >> sortrace.log & # this may take an hour
#----------------------------------------------------------------------------------------------

echo "=======Start======="
whoami
date
echo My machine has this many processors
sysctl -n hw.ncpu

echo Generating 1000000 random numbers

sleep 1

./generate 1000000 -1000000 1000000 # you have to write generate.cpp

sleep 1
echo Starting system sort
sleep 1

{ time sort -n numbers.dat > systemsort.out; } 2>&1>> sortrace.log # modification for Mac

sleep 1
echo Starting mysort
sleep 1

{ time ./mysort numbers.dat mysort.out; } 2>&1>> sortrace.log # modification for Mac computers

sleep 1

ls -l systemsort.out
ls -l mysort.out

echo Comparing systemsort.out to mysort.out
diff systemsort.out mysort.out 2>> sortrace.log

echo "=======End======="
date