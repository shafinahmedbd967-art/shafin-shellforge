#!/bin/bash

echo "===== Simulated Annealing ====="

echo -n "Enter number of states: "
read n

declare -a states
declare -a values

echo "Enter state names:"
for ((i=0; i<n; i++))
do
    read s
    states[$i]=$s
done

echo "Enter heuristic values (higher is better):"
for ((i=0; i<n; i++))
do
    echo -n "Value for ${states[$i]}: "
    read v
    values[$i]=$v
done

echo -n "Enter initial state index (0 to $((n-1))): "
read current

echo -n "Enter initial temperature: "
read T

echo -n "Enter cooling rate (e.g. 0.8): "
read alpha

echo ""
echo "===== Simulated Annealing Steps ====="

while (( $(echo "$T > 0.1" | bc -l) ))
do
    echo "Current State: ${states[$current]} (Value=${values[$current]}), Temp=$T"

    # Random neighbor (left or right)
    rand=$((RANDOM % 2))

    if [ $rand -eq 0 ] && [ $current -gt 0 ]
    then
        neighbor=$((current - 1))
    elif [ $rand -eq 1 ] && [ $current -lt $((n-1)) ]
    then
        neighbor=$((current + 1))
    else
        neighbor=$current
    fi

    delta=$((values[$neighbor] - values[$current]))

    # Accept condition
    if [ $delta -gt 0 ]
    then
        current=$neighbor
    else
        prob=$(echo "e($delta / $T)" | bc -l)
        rand_prob=$(awk 'BEGIN {srand(); print rand()}')

        if (( $(echo "$rand_prob < $prob" | bc -l) ))
        then
            current=$neighbor
        fi
    fi

    # Cooling
    T=$(echo "$T * $alpha" | bc -l)
done

echo "Final State: ${states[$current]} (Value=${values[$current]})"