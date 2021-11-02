#!/bin/sh
echo $(cmus-remote -Q | grep album | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g' | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g'; cmus-remote -Q | grep title | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g' | awk {'first = $1; $1=""; print $0'}|sed 's/^ //g')

