echo $(echo 'BAT '; upower -i $(upower -e | grep 'BAT')| grep percentage | awk '{print $2}'; upower -i $(upower -e | grep 'BAT')| grep state | awk '{print $2}')
