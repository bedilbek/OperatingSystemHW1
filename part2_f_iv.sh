#!/bin/bash

cat part2q > part2m
sed -i -e '1 d' part2m
sed -i -e '$ d' part2m
echo First and LAST lines are DELETED from part2m FILEs
