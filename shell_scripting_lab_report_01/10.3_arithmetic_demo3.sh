#!/bin/bash

# floating point number declare kora hocche
num1=30.5
num2=6

# bc use kore jog
echo "30.5+6" | bc

# biyog
echo "30.5-6" | bc

# gun
echo "30.5*6" | bc

# vag
echo "30.5/6" | bc

# modulus (bc te integer base e kaj kore)
echo "30.5%6" | bc

# scale use kore decimal precision set kora hocche (2 digit)
echo "scale=2;30.5/6" | bc