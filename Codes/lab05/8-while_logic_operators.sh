#!/bin/bash
#while;  loop + Logical Operators

while [ "$ans" != "y" ] && [ "$ans" != "n" ] &&  [ "$ans" != "Y" ] && [ "$ans" != "N" ]
 do
    read -p "do you want to continue? (y/n) "  ans
 done
if [ "$ans" = "y" ] || [ "$ans" = "Y" ] 
 then
    echo "ok"
elif [ "$ans" = "n" ] || [ "$ans" = "N" ]
 then
    echo "bye"
fi

