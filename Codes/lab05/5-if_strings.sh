#!/bin/bash
#string comparision

echo "do u want to continue?(y/n)"
read ans
if [ "$ans" = "y" ]
then
echo "let's go"
elif [ "$ans" = "n" ]
then
echo "see you later"
else
echo "please type y/n!"
fi

#read  -p  " do u want to continue?(y/n)" ans  #bash
