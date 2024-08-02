# Repository of C Programs and Script

This repository contains a set of C programs used for experimentation and scripts used to call software testing tools (gcov, lcov, and Proteum/IM). The Proteum/IM binary Linux version used in this experiment is also available in the tools subdirectory. All other tools are regular Linux command-line tools and can be installed via the official package repository.

## Pre-requirements

	sudo apt install lcov gcovr

## Repository organization

```
repo/
├── LICENSE
├── LLMProgs
│ ├── boundedQueue
│ ├── cal
│ ├── Calculation
│ ├── checkIt
│ ├── CheckPalindrome
│ ├── countPositive
│ ├── date-plus
│ ├── DigitReverser
│ ├── findLast
│ ├── findVal
│ ├── Heap
│ ├── InversePermutation
│ ├── jday-jdate
│ ├── lastZero
│ ├── LLMProgs.log              % Execution log 
│ ├── LLMProgs-summary.csv      % Summmary report
│ ├── LLMProgs-summary.ods      % Summmary report
│ ├── LRS
│ ├── MergeSort
│ ├── numZero
│ ├── oddOrPos
│ ├── pcal
│ ├── power
│ ├── printPrimes
│ ├── programs
│ ├── Queue
│ ├── quicksort
│ ├── RecursiveSelectionSort
│ ├── Stack
│ ├── sum
│ ├── trashAndTakeOut
│ └── UnixCal
├── ManualProg
│ ├── boundedQueue
│ ├── cal
│ ├── Calculation
│ ├── checkIt
│ ├── CheckPalindrome
│ ├── countPositive
│ ├── date-plus
│ ├── DigitReverser
│ ├── findLast
│ ├── findVal
│ ├── Heap
│ ├── InversePermutation
│ ├── jday-jdate
│ ├── lastZero
│ ├── LRS
│ ├── ManualProg.log              % Execution log
│ ├── ManualProg-summary.csv      % Summmary report
│ ├── ManualProg-summary.ods      % Summmary report
│ ├── MergeSort
│ ├── numZero
│ ├── oddOrPos
│ ├── pcal
│ ├── power
│ ├── printPrimes
│ ├── programs
│ ├── Queue
│ ├── quicksort
│ ├── RecursiveSelectionSort
│ ├── Stack
│ ├── sum
│ ├── trashAndTakeOut
│ └── UnixCal
├── README.md                     % This file
├── scripts
│ ├── clean-coverage-files.sh
│ ├── coverage_per_function.sh
│ ├── manual_check-equiv.sh
│ ├── mark_check-equiv.sh
│ ├── run_cover_llm.sh
│ ├── run_cover_manual.sh
│ └── summary_report.sh
└── tools
    └── ProteumIM64.tgz           % Mutation testing tool for C

```
