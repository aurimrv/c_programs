#!/bin/bash

#####################################################################
# run_cover_llm.sh $HOME/User/folder_repository programs.txt
#####################################################################


if [ "$#" -ne 2 ]
then
  echo "Usage: run_cover_llm.sh <projects root directory> <file with directory names to be tested>"
  exit 1
else
   EXPER_HOME=$1
   FILES=$2

   for PROG in $(cat ${EXPER_HOME}/$FILES)
   do
      SESSION=S_$PROG

      # Compilando o código
      cd $EXPER_HOME/$PROG
      
      compilation=$(cat compile-coverage.txt)
      $compilation
      
      compilation=$(cat compile.txt)
      $compilation

      # Criação da Sessão de Teste
      test-new -S $PROG -E $PROG -C "$compilation"  $SESSION

      # Criar codigo versão instrumentada
      instrum -EE $SESSION __${PROG}

      # Compilar código instrumentado
      gcc __${PROG}_inst.c  __${PROG}_pp.c driver.c -o ${PROG}_inst -w -lm -I$PROTEUMIMHOME
        
      # Geração dos Mutantes Unitários
      functions=$(cat functions.txt | awk '{printf("-unit %s ", $1)}')
      muta-gen $functions -u- 1.0 0 $SESSION

      # Geração do relatório inicial
      exemuta -exec -v . -trace $SESSION
      report -tcase -S ${PROG}_initial $SESSION

      # Marcando Mutantes Equivalentes
      equivalents=$(cat equivalent_$PROG.txt)
      muta -equiv -x "$equivalents" $SESSION

      # Importar casos de teste
      tc=1
      NTC=$(wc -l testset.txt | awk '{print $1}')
      while [ $tc -le $NTC ]; 
      do
         param=$(head -$tc testset.txt | tail -1)
         echo "tcase-add -p $param -EE ${PROG}_inst -trace $SESSION"

         tcase-add -p "$param" -EE ${PROG}_inst -trace $SESSION
         tc=$((tc + 1))
         ./${PROG}Cov $param
      done
      tcase -l $SESSION &> tc-imported.txt

      # Executar Mutantes
      exemuta -exec -v . -trace $SESSION

      # Geração do Relatório
      report -tcase -S ${PROG}_final $SESSION
      
      # Generating coverage report
      gcov ${PROG}.c
      lcov --capture --directory . --output-file coverage.info
      genhtml coverage.info --output-directory coverage_report
      # Generating CSV report with statement and branch coverage
      gcovr -f ${PROG} --csv coverage.csv 
   done
fi
