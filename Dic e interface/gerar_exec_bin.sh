#!/bin/bash

gcc -Wall -Wextra -Werror src/* -Iinc/ -o dic $(pkg-config --cflags --libs gtk+-3.0)

