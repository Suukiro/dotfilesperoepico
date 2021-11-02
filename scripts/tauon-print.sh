#!/bin/sh
if [ "$(playerctl status -p tauon 2>&1)" = "No players found" ]; then
	echo ""
else
	echo $(playerctl metadata -p tauon | grep artist | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g' | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g'; playerctl metadata -p tauon | grep title | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g' | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g')
fi
