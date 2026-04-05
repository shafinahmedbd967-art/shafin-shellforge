#!/bin/bash

echo "===== A* Search Algorithm ====="

# Number of nodes
echo -n "Enter number of nodes: "
read n

declare -A graph
declare -A h
declare -A g
declare -A f

nodes=()

# Input nodes
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
    read val
    h[$node]=$val
done

# Input graph (neighbors with cost)
echo "Enter neighbors with cost (format: neighbor,cost):"
for node in "${nodes[@]}"
do
    echo "For node $node:"
    echo -n "Enter neighbors (e.g. B,1 C,3): "
    read input
    graph[$node]=$input
done

# Start and Goal
echo -n "Enter Start Node: "
read start

echo -n "Enter Goal Node: "
read goal

# Initialize
open_list=("$start")
g[$start]=0

echo ""
echo "===== A* Steps ====="

while [ ${#open_list[@]} -gt 0 ]
do
    # Find node with lowest f = g + h
    current=${open_list[0]}
    min_f=$((g[$current] + h[$current]))
    index=0

    for i in "${!open_list[@]}"
    do
        node=${open_list[$i]}
        f_val=$((g[$node] + h[$node]))

        if [ $f_val -lt $min_f ]
        then
            min_f=$f_val
            current=$node
            index=$i
        fi
    done

    echo "Expanding Node: $current (g=${g[$current]}, h=${h[$current]}, f=$((g[$current]+h[$current])) )"

    # Remove current from open list
    unset open_list[$index]
    open_list=("${open_list[@]}")

    # Goal check
    if [ "$current" == "$goal" ]
    then
        echo "Goal Reached: $goal"
        echo "Total Cost: ${g[$goal]}"
        exit 0
    fi

    # Process neighbors
    for pair in ${graph[$current]}
    do
        neighbor=$(echo $pair | cut -d',' -f1)
        cost=$(echo $pair | cut -d',' -f2)

        tentative_g=$((g[$current] + cost))

        # If neighbor not visited or better path found
        if [ -z "${g[$neighbor]}" ] || [ $tentative_g -lt ${g[$neighbor]} ]
        then
            g[$neighbor]=$tentative_g
            f[$neighbor]=$((g[$neighbor] + h[$neighbor]))
            open_list+=("$neighbor")
        fi
    done

    echo "Open List: ${open_list[@]}"
    echo "--------------------------"
done

echo "Goal not reachable"