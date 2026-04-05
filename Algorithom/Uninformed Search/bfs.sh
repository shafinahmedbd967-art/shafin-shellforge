#!/bin/bash

echo "===== Breadth First Search (BFS) ====="

# Input nodes
echo -n "Enter number of nodes: "
read n

declare -A graph
nodes=()

echo "Enter node names:"
for ((i=0; i<n; i++))
do
    read node
    nodes[$i]=$node
done

# Input adjacency list
echo "Enter neighbors for each node (space separated):"
for node in "${nodes[@]}"
do
    echo -n "Neighbors of $node: "
    read neighbors
    graph[$node]=$neighbors
done

echo -n "Enter Start Node: "
read start

echo -n "Enter Goal Node: "
read goal

# BFS
declare -a queue
declare -A visited

queue=("$start")
visited[$start]=1

echo ""
echo "===== BFS Traversal ====="

while [ ${#queue[@]} -gt 0 ]
do
    current=${queue[0]}
    queue=("${queue[@]:1}")

    echo "Visiting: $current"

    if [ "$current" == "$goal" ]
    then
        echo "Goal Reached!"
        exit 0
    fi

    for neighbor in ${graph[$current]}
    do
        if [ -z "${visited[$neighbor]}" ]
        then
            queue+=("$neighbor")
            visited[$neighbor]=1
        fi
    done
done

echo "Goal not found"