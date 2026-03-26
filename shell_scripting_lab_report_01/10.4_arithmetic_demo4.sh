#!/bin/bash

# variable declare
num1=30.5
num2=6

# variable use kore arithmetic
echo "$num1 + $num2" | bc

echo "$num1 - $num2" | bc

# square root ber kora hocche (bc -l lagbe)
num=27
echo "scale=2;sqrt($num)" | bc -l