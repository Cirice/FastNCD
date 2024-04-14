#!/bin/bash

# Build the test program
make test

# Run the test program
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH
./test_program

# Check the return code
if [ $? -eq 0 ]
then
  echo "Tests passed successfully."
  make clean
else
  echo "Tests failed."
  make clean
  exit 1
fi
