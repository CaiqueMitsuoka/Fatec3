baralho = int(raw_input())
while baralho:
    vet = range(1, baralho+1)
    # for card in vet:
    #     print(card)
    vet.reverse()
    popados = ''
    virgula = False
    while not (len(vet) == 1):
        if virgula:
            popados = popados + ', '
        popados = popados + str(vet.pop())
        vet.insert(0,vet.pop())
        virgula = True

    print('Discarded cards: ' + popados)
    print('Remaining card: ' + str(vet[0]))
    baralho = int(raw_input())
