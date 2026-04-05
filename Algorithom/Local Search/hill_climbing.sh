#!/bin/bash

echo "===== Hill Climbing Algorithm ====="

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

echo "Enter heuristic/evaluation values (higher is better):"
for ((i=0; i<n; i++))
do
    echo -n "Value for ${states[$i]}: "
    read v
    values[$i]=$v
done

echo -n "Enter initial state index (0 to $((n-1))): "
read current

echo ""
echo "===== Hill Climbing Steps ====="

while true
do
    echo "Current State: ${states[$current]} (Value=${values[$current]})"

    best=$current

    # Check neighbors (adjacent states)
    if [ $current -gt 0 ]
    then
        left=$((current - 1))
        if [ ${values[$left]} -gt ${values[$best]} ]
        then
            best=$left
        fi
    fi

    if [ $current -lt $((n-1)) ]
    then
        right=$((current + 1))
        if [ ${values[$right]} -gt ${values[$best]} ]
        then
            best=$right
        fi
    fi

    if [ $best -eq $current ]
    then
        echo "Reached Local Maximum at ${states[$current]}"
        break
    fi

    current=$best
done