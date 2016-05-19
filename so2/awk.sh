# Utilitario awk
# usado para extrair conteudo de arquivos textocom formatação coerente
# formato geral do programa awk
# BEGIN{
#     comando antes de iniciar o processamento
# }
# {
#     comandos durante o processamento
# }
# END{
#     comandos após o processamento
# }
#
# Cada "campo" do reg lido representado posicionalmente po $1 $2 $3 ...
# processamento condicional
# condição{
#     comandos
# }
# ex: $4 > 5{
#     printf "nome: " %4
# }
# ```
# $ awk -F"char de separação" -f pgm01 file
# ```
BEGIN{
    print "aluno(nome)/faltas"
}
$4 > 5{
    # print "nome: " $2 "  faltas: " $4
        printf "nome: %15s --faltas: %d\n", $2, $4
}
END{
    print "pronto"
}
