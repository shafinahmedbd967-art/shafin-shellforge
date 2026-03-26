#!/bin/bash

# duita number variable e store kora hocche
num1=30
num2=6

# expr use kore jog (addition)
echo $(expr $num1 + $num2)

# biyog (subtraction)
echo $(expr $num1 - $num2)

# gun (multiplication)
# * use korle shell globbing hoy, tai \* use kora lagbe
echo $(expr $num1 \* $num2)

# vag (division)
echo $(expr $num1 / $num2)

# vag sesh (modulus / remainder)
echo $(expr $num1 % $num2)