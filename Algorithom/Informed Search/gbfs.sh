#!/bin/bash

echo "===== Greedy Best First Search (GBFS) ====="

# Input number of nodes
echo -n "Enter number of nodes: "
read n

declare -A graph
declare -A heuristic
nodes=()

# Input node names
echo "Enter node names:"
for ((i=0; i<n; i++))
do
    read node
    nodes[$i]=$node
done

# Input heuristic values
echo "Enter heuristic values (h):"
for node in "${nodes[@]}"
do
    echo -n "h($node): "
    read h
    heuristic[$node]=$h
done

# Input adjacency list
echo "Enter adjacency (neighbors) for each node:"
for node in "${nodes[@]}"
do
    echo -n "Neighbors of $node (space separated): "
    read neighbors
    graph[$node]=$neighbors
done

# Start and Goal
echo -n "Enter Start Node: "
read start

echo -n "Enter Goal Node: "
read goal

# GBFS Algorithm
declare -a open_list
declare -a closed_list

open_list=("$start")

echo ""
echo "===== Search Steps ====="

while [ ${#open_list[@]} -gt 0 ]
do
    # Find node with lowest heuristic
    current=${open_list[0]}
    min_h=${heuristic[$current]}
    index=0

    for i in "${!open_list[@]}"
    do
        node=${open_list[$i]}
        h=${heuristic[$node]}

        if [ $h -lt $min_h ]
        then
            min_h=$h
            current=$node
            index=$i
        fi
    done

    echo "Expanding Node: $current (h=${heuristic[$current]})"

    # Remove selected node from open list
    unset open_list[$index]
    open_list=("${open_list[@]}")

    closed_list+=("$current")

    # Goal check
    if [ "$current" == "$goal" ]
    then
        echo "Goal Node Reached: $goal"
        exit 0
    fi

    # Add neighbors to open list
    for neighbor in ${graph[$current]}
    do
        # Check if already visited
        skip=false
        for closed in "${closed_list[@]}"
        do
            if [ "$neighbor" == "$closed" ]
            then
                skip=true
                break
            fi
        done

        if [ "$skip" = false ]
        then
            open_list+=("$neighbor")
        fi
    done

    echo "Open List: ${open_list[@]}"
    echo "Closed List: ${closed_list[@]}"
    echo "--------------------------"
done

echo "Goal not reachable"
