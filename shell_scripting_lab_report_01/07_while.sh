#!/bin/bash

# n variable 1 diye initialize kora hocche
n=1

# jokhon porjonto n <= 5, loop cholbe
while [ $n -le 5 ]
do
    # current value of n print kora hocche
    echo "$n"

    # 3 second delay deya hocche
    sleep 3

    # n er value 1 kore barano hocche (important, na hole infinite loop hobe)
    ((n++))
done