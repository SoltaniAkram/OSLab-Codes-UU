#!/bin/bash
# Special Variables and Environmental Variables

echo " --------script info--------"
echo "file name: $0 !"
echo "Process Id: $$ "

echo " --------environment info: one--------"
echo "$HOME"
echo " --------environment info: all--------"
printenv |less   #or env
