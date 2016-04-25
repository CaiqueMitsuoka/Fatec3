roda=True
# Para atribuir tem que ser tudo juntinho
clear
# Cada linha um comando
# While\nDo\noque se vai fazer, lembrando do test e termina com o done
while test $roda
do
    echo Usuario: $LOGNAME
    echo 1 - Listar um diretorio:
    echo 2 - Listar um arquivo comum:
    echo 3 - Calcular a area de um quadrado:
    echo 9 - Encerrar script:
    read comando
    #case $variavel in aopção) comandos e ;; quando acabar
    case $comando in
        1)echo Entre com diretorio:
        read diretorio
        if test -d $diretorio
        then
            # Não esquecer do | more pra a exibir em paginas
            ls $diretorio -l | more
        else
            echo Caminho ou Pasta não encontrada
        fi
        echo Enter para continuar
        read lixo
        ;;
        2)echo Pressione Entre com arquivo:
        read arquivo
        if test -f $arquivo
        then
            # cat pra ler o arquivo emforma de testo e jogar o mesmo na tela
            cat $arquivo | more
        else
            echo Arquivo não encontrado
        fi
        echo Pressione Enter para continuar
        read lixo
        ;;
        3)echo Insira um lado do quadrado:
        read l1
        # 'aspas dizem que isso é um comando só apesar do espaço, como o expr ou uma string/diretorio com espaço'
        echo A area do quadrado é igual a: `expr $l1 \* $l1`
        echo Pressione Enter para continuar
        read lixo
        ;;
        9)clear
        break
        ;;
        *)echo opção invalida!
        echo Pressione Enter para continuar
        read lixo
        #acaba o case com esac
    esac
    clear
done
