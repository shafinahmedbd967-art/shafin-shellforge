#!/bin/bash

# function define
function write() {
    # local variable (function er moddhei kaj korbe)
    local name=$1
    echo "The first name is $name"
}

# global variable
name="Tom"

# global variable print
echo "The second name is $name"

# function call (local variable use hobe)
write Jerry

# abar global variable unchanged thakbe
echo "The third name is $name"