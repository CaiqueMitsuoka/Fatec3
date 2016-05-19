echo Insira o nome de um diretorio:
read path
if test -d $path
then
    clear
    ls $path -l >lista01.txt
    awk -F" " -f folderview.awk lista01.txt | more
else
    echo diretorio invalido
fi
echo qualquer tecla para continuar
read yo
clear
