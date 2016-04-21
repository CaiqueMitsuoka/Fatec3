echo "ano:"
read ano
if test `expr $ano % 400` -gt 0 && test `expr $ano % 100` -gt 0 && test `expr $ano % 4` -eq 0
then
    echo "boa"
else
    echo "nem"
fi
