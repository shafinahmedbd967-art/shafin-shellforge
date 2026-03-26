#!/bin/bash

# n variable 0 diye initialize kora hocche
n=0

# jotokkhon porjonto condition false (n >= 10 false), loop cholbe
# mane n < 10 thakle loop run korbe
until [ $n -ge 10 ]
do
    # current value of n print kora hocche
    echo $n

    # n er value 1 kore barano hocche
    n=$((n+1))
done
