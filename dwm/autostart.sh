#! /bin/sh

sxhkd &
xrandr --output Virtual1 --mode 1920x1080
nitrogen --restore
xcompmgr &
dwmblocks &
flatpak run com.valvesoftware.Steam
