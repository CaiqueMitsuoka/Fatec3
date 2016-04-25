def SaiTrem():
    tp = []

    for n,m in enumerate(stc):
        tp.append((lsaida[n],m))
    print(tp)
    for tpl in tp:
        if tpl[0] == tpl[1]:
            lsaida.remove(tpl[0])
            stc.remove(tpl[1])
        else:
            break


def EntraTrem():
    for trem in ltrem[::-1]:
        stc.insert(0,trem)
        ltrem.remove(trem)
        if trem == saida[0]:
            SaiTrem()
            if len(lsaida) == 0:
                break


ntrem = int(input())

while ntrem != 0:
    saida = str(input())
    while saida != '0':
        ltrem = list(range(1,ntrem + 1))
        lsaida = saida.rsplit(' ')

        for n,trem in enumerate(lsaida):
            lsaida[n] = int(trem)

        stc = []
        ltrem.reverse()
        lsaida.reverse()

        EntraTrem()

        print(ltrem)
        print(stc)
        print(lsaida)

        if (len(lsaida) == 0) and (len(stc) == 0):
            print('yes')
        else:
            print('no')

        saida = str(input())

    print('')
    ntrem = int(input())
