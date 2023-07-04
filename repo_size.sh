#!/bin/bash

make fclean &> /dev/null
du -hs -c fonts/ images/ include/ lib/ musics/ src/ .gitignore .git/ Makefile *.sh
