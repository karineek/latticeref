#!/bin/bash

# Check a single file $1
function test_one {

  HIFROG_OUTPUT="$1"
  HIFROG_RESULT="results_sum.txt"

  if [[ ! -r ${HIFROG_OUTPUT} ]] ; then
    error "The input file ${HIFROG_OUTPUT} does not exist or it is not readable."
  fi
  
  # Filter the relevant information
  cat ${HIFROG_OUTPUT} | ${FILTER_RESULT} > ${HIFROG_RESULT}
  #cat ${HIFROG_OUTPUT} | ${FILTER_TIME} > ${HIFROG_TIME}
}
################### MAIN ###############################
PATH_reg=$(readlink -f $0)
PATH_reg=${PATH_reg: : -11}
echo "This is the script for getting regression tests results"
echo " - date: $(date '+%Y-%m-%d at %H:%M.%S')"
echo " - host name $(hostname -f)"
echo " - script path: $(readlink -f $0)"
echo " - path regression tests: $PATH_reg"

FILTER_RESULT="./filter-result.sh"
FILTER_TIME="./filter-time.sh"
OUTPUT_PREFIX="output"

#Prepare main output folder
OUTDIR="mainReg_$OUTPUT_PREFIX"
rm -r $OUTDIR
mkdir $OUTDIR


# Iterating over all the test cases - When result shall match the known results
i=0;
for filename in outputs/*.txt 
do
    # Per file, run all its inner test cases. 0 => clear summaries
    test_one $filename
done


