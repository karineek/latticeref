#!/bin/bash

# Check a single file $1
function test_one {

  HIFROG_OUTPUT="$1"
  HIFROG_RESULT="results_sum.txt"

  if [[ ! -r ${HIFROG_OUTPUT} ]] ; then
    error "The input file ${HIFROG_OUTPUT} does not exist or it is not readable."
  fi
  
  # Filter the relevant information
  echo "Extracting from $HIFROG_OUTPUT " >> ${HIFROG_RESULT}
  cat ${HIFROG_OUTPUT} | ${FILTER_RESULT} >> ${HIFROG_RESULT}
}
################### MAIN ###############################
PATH_reg=$(readlink -f $0)
PATH_reg=${PATH_reg: : -11}
echo "This is the script for getting regression tests results"
echo " - date: $(date '+%Y-%m-%d at %H:%M.%S')"
echo " - host name $(hostname -f)"
echo " - script path: $(readlink -f $0)"
echo " - path regression tests: $PATH_reg"

FILTER_RESULT="./filter-result-sum.sh"

# Iterating over all the test cases - When result shall match the known results
for filename in validation_mainReg_output/*/*/*/*hifrog*.txt
do
    # Per file, run all its inner test cases. 0 => clear summaries
    echo "Extracting from $filename"
    test_one $filename
done



