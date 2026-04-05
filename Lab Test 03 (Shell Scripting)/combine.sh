#!/bin/bash

echo "========= Question 1 ========="
echo "Home Directory: $HOME"
echo "Current Directory: $(pwd)"
echo "File Permission:"
ls -l hermione_1234_q1.sh

echo ""
echo "========= Question 2 ========="
echo -n "Enter a number to find factorial: "
read num

fact=1
for (( i=1; i<=num; i++ ))
do
    fact=$((fact * i))
done

echo "Factorial of $num is: $fact"

echo ""
echo "========= Question 3 ========="

even_sum=0
odd_sum=0

echo "Even Numbers (5 to 25):"
for (( i=5; i<=25; i++ ))
do
    if (( i % 2 == 0 ))
    then
        echo -n "$i "
        even_sum=$((even_sum + i))
    fi
done

echo ""
echo "Odd Numbers (5 to 25):"
for (( i=5; i<=25; i++ ))
do
    if (( i % 2 != 0 ))
    then
        echo -n "$i "
        odd_sum=$((odd_sum + i))
    fi
done

echo ""
echo "Sum of Even Numbers: $even_sum"
echo "Sum of Odd Numbers: $odd_sum"

#gedit combine.sh
#bash combine.sh