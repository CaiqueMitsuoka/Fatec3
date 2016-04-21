read variavel
# ele ja cria a variavel
echo oque ele de e printar
test $variavel -eq 10
# retorno verdadeiro ou falso pra if ou while
# (ed, ==), (ne,!=), (gt, >), (ge, >=)
# (lt, <), (le, <=), (&&, E), (||, OU)
'expr $variavel + $variavel'
# + - \* / %
exit 0
# termina o script e retorna o valor
if [[ condition ]]
then
    #statements
else
    
fi
case condition in
    test)
    test)
    *)
esac
# aqui tem o until tambem
while [[ condition ]]
do
    #statements
done
break
continue
find . -print | cpio -ocv >bkp.cpio
cpio -ict <bkp.cpio | more
