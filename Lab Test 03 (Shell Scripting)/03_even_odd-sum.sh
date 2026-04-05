#!/bin/bash

even_sum=0
odd_sum=0

echo "Even Numbers:"
for (( i=5; i<=25; i++ ))
do
    if (( i % 2 == 0 ))
    then
        echo $i
        even_sum=$((even_sum + i))
    fi
done

echo "Odd Numbers:"
for (( i=5; i<=25; i++ ))
do
    if (( i % 2 != 0 ))
    then
        echo $i
        odd_sum=$((odd_sum + i))
    fi
done

echo "Sum of Even Numbers: $even_sum"
echo "Sum of Odd Numbers: $odd_sum"


#gedit 03_even_odd-sum.sh  
#bash 03_even_odd-sum.sh