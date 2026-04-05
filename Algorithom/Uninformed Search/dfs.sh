#!/bin/bash

echo "===== Depth First Search (DFS) ====="

echo -n "Enter number of nodes: "
read n

declare -A graph
declare -A visited
nodes=()

echo "Enter node names:"
for ((i=0; i<n; i++))
do
    read node
    nodes[$i]=$node
done

echo "Enter neighbors for each node:"
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

echo ""
echo "===== DFS Traversal ====="

# DFS Function
dfs() {
    local node=$1

    echo "Visiting: $node"
    visited[$node]=1

    if [ "$node" == "$goal" ]
    then
        echo "Goal Reached!"
        exit 0
    fi

    for neighbor in ${graph[$node]}
    do
        if [ -z "${visited[$neighbor]}" ]
        then
            dfs $neighbor
        fi
    done
}

dfs $start

echo "Goal not found"