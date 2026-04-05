#!/bin/bash

echo "===== Genetic Algorithm ====="

echo -n "Enter population size: "
read pop_size

echo -n "Enter chromosome length (binary): "
read length

echo -n "Enter number of generations: "
read generations

declare -a population

# Generate initial population randomly
echo ""
echo "Initial Population:"
for ((i=0; i<pop_size; i++))
do
    chromosome=""
    for ((j=0; j<length; j++))
    do
        bit=$((RANDOM % 2))
        chromosome+=$bit
    done
    population[$i]=$chromosome
    echo "Individual $i: ${population[$i]}"
done

# Fitness function (example: maximize number of 1s)
fitness() {
    local chrom=$1
    count=$(echo "$chrom" | grep -o "1" | wc -l)
    echo $count
}

# Selection (simple tournament)
select_parent() {
    i1=$((RANDOM % pop_size))
    i2=$((RANDOM % pop_size))

    f1=$(fitness ${population[$i1]})
    f2=$(fitness ${population[$i2]})

    if [ $f1 -gt $f2 ]
    then
        echo ${population[$i1]}
    else
        echo ${population[$i2]}
    fi
}

# Crossover
crossover() {
    parent1=$1
    parent2=$2
    point=$((RANDOM % length))

    child1="${parent1:0:$point}${parent2:$point}"
    child2="${parent2:0:$point}${parent1:$point}"

    echo "$child1 $child2"
}

# Mutation
mutate() {
    chrom=$1
    pos=$((RANDOM % length))

    bit=${chrom:$pos:1}

    if [ "$bit" == "0" ]
    then
        new_bit="1"
    else
        new_bit="0"
    fi

    mutated="${chrom:0:$pos}$new_bit${chrom:$((pos+1))}"
    echo $mutated
}

echo ""
echo "===== Evolution Process ====="

for ((g=0; g<generations; g++))
do
    echo ""
    echo "Generation $g"

    new_population=()

    for ((i=0; i<pop_size; i+=2))
    do
        parent1=$(select_parent)
        parent2=$(select_parent)

        read child1 child2 <<< $(crossover $parent1 $parent2)

        # Mutation probability
        if [ $((RANDOM % 100)) -lt 20 ]
        then
            child1=$(mutate $child1)
        fi

        if [ $((RANDOM % 100)) -lt 20 ]
        then
            child2=$(mutate $child2)
        fi

        new_population+=("$child1")
        new_population+=("$child2")

        echo "Parents: $parent1 , $parent2"
        echo "Children: $child1 , $child2"
    done

    population=("${new_population[@]}")

    echo "Population after generation $g:"
    for ind in "${population[@]}"
    do
        echo "$ind (Fitness: $(fitness $ind))"
    done
done

echo ""
echo "===== Final Population ====="
for ind in "${population[@]}"
do
    echo "$ind (Fitness: $(fitness $ind))"
done