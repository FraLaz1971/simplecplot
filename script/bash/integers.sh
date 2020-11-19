#!/bin/bash
echo "Type an integer number: "
read x
if [ $x -lt 0 ]
then
    printf "You typed a negative integer\n"
elif [ $x -eq 0 ]
then
    printf "You typed Zero\n"
else
    printf "you typed a positive integer\n"
fi
echo bye
date
