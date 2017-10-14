#!/bin/bash


OPTIONS='Halt init0 init6 Poweroff Reboot Shutdown'
PS3='Choose an option: '

select CHOICE in $OPTIONS
do
if [ $CHOICE == Halt ]
 then
   sudo halt
elif [ $CHOICE == init0 ]
 then
   sudo init 0
elif [ $CHOICE == init6 ]
 then
   sudo init 6
elif [ $CHOICE == Poweroff ]
 then
   poweroff
elif [ $CHOICE == Reboot ]
 then
   reboot
elif [ $CHOICE == Shutdown ]
 then
   shutdown
else echo NO such option
fi
done
