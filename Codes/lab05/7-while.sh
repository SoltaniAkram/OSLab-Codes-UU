#!/bin/bash
# while1.sh

echo "Enter password: "
read pass

while [ "$pass" != "secret" ]
do
  echo "Sorry, try again"
  read pass
done

exit 0
