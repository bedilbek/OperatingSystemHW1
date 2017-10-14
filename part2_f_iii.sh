#!/bin/bash


cat part2q > part2qr
sed -i '/commands/ s/the/THE/g' part2qr
sed -i 's/commands/COMMANDS/g' part2qr
echo In part2q the lines with word \'commnads\' found and the occurencies with \'the\' IN these lines were UPPERCASED and the words \'commands\' as well.
