#!/bin/bash

export ASAN_OPTIONS=halt_on_error=0
make resanitize
./my_rpg
