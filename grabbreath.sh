#!/bin/bash
stty -F /dev/ttyACM0 cs8 9600 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts
echo "Avg Diff Left Right" > breath.dat
cu -l /dev/ttyACM0 -s 9600 >> breath.dat




