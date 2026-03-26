#!/bin/bash

# user ke multiple name input dite bola hocche
echo "Enter names: "

# -a flag use kore input gula array 'n' er moddhe store kora hocche
# space diye alada kore joto input dibe, sob gula array te chole jabe
read -a n

# array er specific index theke value print kora hocche
# n[0] = prothom input, n[1] = ditiyo, n[2] = tritiyo
echo "Names: ${n[0]}, ${n[1]}, ${n[2]}"