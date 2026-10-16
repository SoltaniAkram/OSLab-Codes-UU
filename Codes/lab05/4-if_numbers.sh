#!/bin/bash
# number comparision!

echo  "enter an int" 
read x

if [ $x -gt 0 ]
then
echo "Positive"

elif [ $x -lt 0 ]
then
echo "negative"

else
echo "Zero"

fi

