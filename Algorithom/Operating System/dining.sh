#!/bin/bash

echo "Enter number of philosophers (n): "
read n

echo "Select a philosopher who wants to eat (0 to $((n-1))): "
read p

echo ""
echo "Philosopher $p is HUNGRY..."

# Fork calculation
left=$p
right=$(( (p + 1) % n ))

echo "Left Fork: F$left"
echo "Right Fork: F$right"

echo ""

# Deadlock prevention rule
if (( p % 2 == 0 ))
then
    echo "Philosopher $p picks LEFT fork first (F$left)"
    echo "Philosopher $p picks RIGHT fork (F$right)"
else
    echo "Philosopher $p picks RIGHT fork first (F$right)"
    echo "Philosopher $p picks LEFT fork (F$left)"
fi

echo "Philosopher $p is EATING "

sleep 2

echo "Philosopher $p puts down forks and starts THINKING "