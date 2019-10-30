#!/usr/bin/env bash

PATH_CHECKER=./CHECKER_ASM/src_test_files/
PATH_OUR_ASM=./
PATH_ORIG_ASM=./CHECKER_ASM

FILES_ERR=${PATH_CHECKER}error/*.s
FILES_VAL=${PATH_CHECKER}valid/*.s

OUTPUT_ERR=${PATH_CHECKER}error/*.cor
OUTPUT_VALID=${PATH_CHECKER}valid/*.cor

OUTPUT_OUR=./CHECKER_ASM/our_output
OUTPUT_ORIG=./CHECKER_ASM/origin_output
CYAN='\033[0;36m'
GREEN='\033[0;32m'
RED='\033[0;31m'
YEL='\033[1;32m'
NC='\033[0m'

echo "\n${YEL}ERROR_ARGS ${NC} \n"

for f in $FILES_ERR
do

  ${PATH_OUR_ASM}/asm $f > ./CHECKER_ASM/error_output
  grep 'Writing output program to' ./CHECKER_ASM/error_output > ./CHECKER_ASM/grep_result
  ERROR_SIZE=$(wc -l < ./CHECKER_ASM/grep_result)
  rm ./CHECKER_ASM/grep_result
  rm ./CHECKER_ASM/error_output

  ${PATH_ORIG_ASM}/asm $f >  ./CHECKER_ASM/error_output
  grep 'Writing output program to' ./CHECKER_ASM/error_output > ./CHECKER_ASM/grep_result
  ERROR_ORIG_SIZE=$(wc -l < ./CHECKER_ASM/grep_result)
  rm ./CHECKER_ASM/grep_result
  rm ./CHECKER_ASM/error_output

  if [ "$ERROR_SIZE" == "$ERROR_ORIG_SIZE" ]; then
    echo "${GREEN}OK${NC}"
  else
    echo "${RED}KO${NC}   By test - $f"
    rm -rf ${OUTPUT_ERR}
  fi
done
rm -rf ${PATH_CHECKER}/*.cor


echo "\n${YEL}VALID_ARGS ${NC} \n"


for i in $FILES_VAL
do
${PATH_OUR_ASM}/asm $i > ./CHECKER_ASM/test_valid_our
cp $OUTPUT_VALID ./CHECKER_ASM/our_output_file

${PATH_ORIG_ASM}/asm $i > ./CHECKER_ASM/test_valid_origin
cp $OUTPUT_VALID ./CHECKER_ASM/orig_output_file


if diff ./CHECKER_ASM/our_output_file ./CHECKER_ASM/orig_output_file &> /dev/null; then
    echo "bytecode -> ${GREEN}OK${NC}"
  else
    echo "${RED}exec test - $i${NC}"
    echo "bytecode -> ${RED}KO${NC}"
fi


if diff ./CHECKER_ASM/test_valid_origin ./CHECKER_ASM/test_valid_our &> /dev/null; then
  echo "error handling -> ${GREEN}OK${NC}"
  else
    echo "${CYAN}exec test - $i${NC}"
    echo "error handling -> ${RED}KO${NC}"
    echo "${GREEN}Our asm ${NC}"
    cat test_valid_our
    echo "${GREEN}Original${NC}"
    cat test_valid_origin
    echo "\n"

  fi

rm ./CHECKER_ASM/test_valid_origin ./CHECKER_ASM/test_valid_our
rm ./CHECKER_ASM/orig_output_file
rm ./CHECKER_ASM/our_output_file
rm ${PATH_CHECKER}valid/*.cor

done

