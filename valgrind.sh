#!/bin/bash
make redebug
valgrind --leak-check=full --track-origins=yes -s --malloc-fill=0x42 --free-fill=0x84 --log-file=valgrind.log ./my_rpg
