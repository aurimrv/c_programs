#!/bin/bash

##############################################################################
# summary_report.sh $HOME/User/folder_repository programs.txt summary_llm.csv
##############################################################################

if [ "$#" -ne 3 ]
then
  echo "Usage: summary_report.sh <projects root directory> <file with directory names to be tested> <csv report filename>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2
   OUT=$3

   echo "filename,line_total,line_covered,line_percent,branch_total,branch_covered,branch_percent,mutation_score" > ${EXPER_HOME}/$OUT
   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG
      
      echo "############### REPORTING DATA OF PROGRAM: $PROG ###############"
      dos2unix coverage.csv
      head -2 coverage.csv | tail -1 | xargs echo -n >> ${EXPER_HOME}/$OUT
      cat ${PROG}_final.lst | grep SCORE | awk '{printf(",%s\n",$4)}' >> ${EXPER_HOME}/$OUT
   done
fi
