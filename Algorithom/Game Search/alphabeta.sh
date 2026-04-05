#!/bin/bash

echo "===== Alpha-Beta Pruning ====="

echo -n "Enter number of leaf nodes: "
read n

declare -a leaves

echo "Enter leaf values:"
for ((i=0; i<n; i++))
do
    read val
    leaves[$i]=$val
done

echo ""
echo "Leaf nodes: ${leaves[@]}"

# Alpha-Beta function
alphabeta() {
    local depth=$1
    local index=$2
    local isMax=$3
    local alpha=$4
    local beta=$5

    if [ $depth -eq 0 ]
    then
        echo "${leaves[$index]}"
        return
    fi

    mid=$((2 ** (depth - 1)))

    if [ $isMax -eq 1 ]
    then
        value=-999999
        for child in 0 1
        do
            if [ $child -eq 0 ]
            then
                v=$(alphabeta $((depth-1)) $index 0 $alpha $beta)
            else
                v=$(alphabeta $((depth-1)) $((index + mid)) 0 $alpha $beta)
            fi

            if [ $v -gt $value ]
            then
                value=$v
            fi

            if [ $value -gt $alpha ]
            then
                alpha=$value
            fi

            if [ $alpha -ge $beta ]
            then
                echo $value
                return
            fi
        done
        echo $value
    else
        value=999999
        for child in 0 1
        do
            if [ $child -eq 0 ]
            then
                v=$(alphabeta $((depth-1)) $index 1 $alpha $beta)
            else
                v=$(alphabeta $((depth-1)) $((index + mid)) 1 $alpha $beta)
            fi

            if [ $v -lt $value ]
            then
                value=$v
            fi

            if [ $value -lt $beta ]
            then
                beta=$value
            fi

            if [ $alpha -ge $beta ]
            then
                echo $value
                return
            fi
        done
        echo $value
    fi
}

echo ""
echo "===== Alpha-Beta Result ====="

depth=0
temp=$n
while [ $temp -gt 1 ]
do
    temp=$((temp / 2))
    depth=$((depth + 1))
done

result=$(alphabeta $depth 0 1 -999999 999999)

echo "Optimal Value (Maximizer): $result"