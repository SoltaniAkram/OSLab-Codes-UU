#!/bin/bash
# math_ops.sh : Math Operations

echo “Insert a positive integer number: “
read x

let y=x**2
let z=x%2
let x++

echo "x^2 = $y"
echo "x%2 = $z"
echo "x+1 = $x"

exit 0
