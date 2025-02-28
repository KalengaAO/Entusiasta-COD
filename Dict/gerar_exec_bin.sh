#!/bin/bash

gcc -Wall -Wextra -Werror src/* -Iinc/ -o dic \
 $(pkg-config --cflags --libs gtk+-3.0)

sudo mkdir /usr/lib/Dic
sudo mv dic /usr/lib/Dic

echo "Instalação concluida!"
