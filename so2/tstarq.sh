echo "nome do arquivo"
read nome

if test -f $nome
then
    echo "tem"
else
    echo "n tem"
fi
