#!/bin/bash

#####################################################################
# run_cover.sh $HOME/User/folder_repository programs.txt
#####################################################################

if [ "$#" -ne 2 ]
then
  echo "Usage: check-equiv.sh <projects root directory> <file with directory names to be tested>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2

   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG
      
      echo "############### TESTING PROGRAM: $PROG ###############"
   
      echo " " >> equivalent_${PROG}.txt
      muta -l $SESSION | info-muta -alive >> equivalent_${PROG}.txt

      sleep 1

      # Marcando Mutantes Equivalentes
      equivalents=$(cat equivalent_$PROG.txt)
      if [ -n "${equivalents}" ]
      then
         muta -equiv -x "$equivalents" $SESSION
         exemuta -exec -v . -trace $SESSION
      fi

      # Geração do Relatório
      report -tcase -S ${PROG}_final $SESSION
   done
fi
