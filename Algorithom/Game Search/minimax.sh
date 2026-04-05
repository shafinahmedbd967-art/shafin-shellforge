#!/bin/bash

echo "===== Minimax Algorithm (2-player game) ====="

echo -n "Enter number of leaf nodes: "
read n

declare -a leaves

echo "Enter leaf values (evaluation scores):"
for ((i=0; i<n; i++))
do
    read val
    leaves[$i]=$val
done

echo ""
echo "Leaf nodes: ${leaves[@]}"

# Minimax recursion
minimax() {
    local depth=$1
    local index=$2
    local isMax=$3

    # If leaf node
    if [ $depth -eq 0 ]
    then
        echo "${leaves[$index]}"
        return
    fi

    mid=$((2 ** (depth - 1)))

    left=$(minimax $((depth-1)) $index $((1 - isMax)))
    right=$(minimax $((depth-1)) $((index + mid)) $((1 - isMax)))

    if [ $isMax -eq 1 ]
    then
        if [ $left -gt $right ]
        then
            echo $left
        else
            echo $right
        fi
    else
        if [ $left -lt $right ]
        then
            echo $left
        else
            echo $right
        fi
    fi
}

echo ""
echo "===== Minimax Result ====="

# Assume tree depth based on number of leaves
depth=0
temp=$n
while [ $temp -gt 1 ]
do
    temp=$((temp / 2))
    depth=$((depth + 1))
done

result=$(minimax $depth 0 1)

echo "Optimal Value (Maximizer): $result"