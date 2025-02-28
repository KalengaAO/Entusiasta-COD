#/bin/bash

sudo cp -r arq /usr/lib/Dic
sudo cp -r css /usr/lib/Dic

arq=dic.desktop
dest=/home/organon/.local/share/applications

if [ -e "$dest" ]; then
	echo "O arquivo já existe!"
else
	mv "$arq" "$dest"
	echo "arquivo dic.desktop movido com sucesso"
fi

echo "Arquivos actulizados!"
