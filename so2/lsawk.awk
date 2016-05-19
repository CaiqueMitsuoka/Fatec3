BEGIN { cont = 0 } NF >= 9 { if(int($5) > 0) { print($9, $3, $5); cont+=1 } } END { print("Total de arquivos lidos : ", NF, "\nTotal de Arquivos de tamanho 0 : ", NF - cont ) }
