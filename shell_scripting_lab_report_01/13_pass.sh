#!/bin/bash

# user ke password length dite bola hocche
echo "Enter the length of your password:"
read PASS_LENGTH

# check kora hocche input number kina
if [[ $PASS_LENGTH =~ ^[0-9]+$ ]]; then
    
    # openssl diye random password generate kora hocche
    # base64 format theke nirdisto length cut kora hocche
    openssl rand -base64 48 | cut -c1-$PASS_LENGTH

else
    # invalid input hole error message
    echo "Please enter a valid number."
fi