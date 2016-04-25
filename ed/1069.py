casos = int(raw_input())
for caso in range(casos):
    mine = list(raw_input())
    diamente = 0
    cont = 1
    for comeco in mine:
        if comeco == '<':
            cont2 = cont
            for fim in mine[cont:]:
                if fim == '>':
                    diamente += 1
                    mine[cont - 1] = '.'
                    mine[cont2] = '.'
                    break
                cont2 += 1
        cont += 1
    print(diamente)
