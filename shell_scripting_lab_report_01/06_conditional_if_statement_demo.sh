#!/bin/bash

# user theke ekta word input neya hocche
read word

# user ki input dise seta print kora hocche
echo "Enter: $word"

# if condition check kora hocche
# variable ke " " er moddhe rakha safe (empty hole error hobe na)
if [ "$word" == "y" ]
then
    # jodi input 'y' hoy
    echo "condition y is true"

elif [ "$word" == "x" ]
then
    # jodi input 'x' hoy
    echo "condition x is true"

else
    # jodi konotai na hoy
    echo "condition is false"
fi