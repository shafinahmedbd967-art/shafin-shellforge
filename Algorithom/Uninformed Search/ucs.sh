#!/bin/bash

echo "===== Uniform Cost Search (UCS) ====="

echo -n "Enter number of nodes: "
read n

declare -A graph
declare -A cost
declare -A visited

nodes=()

echo "Enter node names:"
for ((i=0; i<n; i++))
do
    read node
    nodes[$i]=$node
done

echo "Enter neighbors with cost (format: B,2 C,3):"
for node in "${nodes[@]}"
do
    echo "For node $node:"
    echo -n "Enter neighbors: "
    read input
    graph[$node]=$input
done

echo -n "Enter Start Node: "
read start

echo -n "Enter Goal Node: "
read goal

# Initialize
declare -a queue

queue=("$start")
cost[$start]=0

echo ""
echo "===== UCS Steps ====="

while [ ${#queue[@]} -gt 0 ]
do
    # Find node with minimum cost
    current=${queue[0]}
    min_cost=${cost[$current]}
    index=0

    for i in "${!queue[@]}"
    do
        node=${queue[$i]}
        if [ ${cost[$node]} -lt $min_cost ]
        then
            min_cost=${cost[$node]}
            current=$node
            index=$i
        fi
    done

    echo "Expanding: $current (Cost=${cost[$current]})"

    unset queue[$index]
    queue=("${queue[@]}")

    visited[$current]=1

    if [ "$current" == "$goal" ]
    then
        echo "Goal Reached!"
        echo "Total Cost: ${cost[$goal]}"
        exit 0
    fi

    for pair in ${graph[$current]}
    do
        neighbor=$(echo $pair | cut -d',' -f1)
        w=$(echo $pair | cut -d',' -f2)

        new_cost=$((cost[$current] + w))

        if [ -z "${cost[$neighbor]}" ] || [ $new_cost -lt ${cost[$neighbor]} ]
        then
            cost[$neighbor]=$new_cost
            queue+=("$neighbor")
        fi
    done

    echo "Queue: ${queue[@]}"
    echo "----------------------"
done

echo "Goal not reachable"