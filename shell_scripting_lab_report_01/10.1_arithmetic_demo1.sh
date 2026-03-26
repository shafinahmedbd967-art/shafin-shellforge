#!/bin/bash

# normal echo te 1+1 evaluate hoy na, just string hisebe print hoy
echo 1+1

# duita number variable e store kora hocche
num1=30
num2=6

# arithmetic expansion use kore jog (addition)
echo $(( num1 + num2 ))

# biyog (subtraction)
echo $(( num1 - num2 ))

# gun (multiplication)
echo $(( num1 * num2 ))

# vag (division)
echo $(( num1 / num2 ))

# vag sesh (modulus / remainder)
echo $(( num1 % num2 ))