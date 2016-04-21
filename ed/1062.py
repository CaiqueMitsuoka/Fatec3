def SaiTrem():
    for n,m in enumerate(stc):
        if lsaida[n] == m:
            lsaida.remove(lsaida[n])
            stc.remove(m)
        else:
            lsaida.reverse()
            break

def EntraTrem():
    for n,trem in enumerate(ltrem[::-1]):
        stc.append(trem)
        ltrem.pop()
        if(trem == lsaida[0]):
            SaiTrem()
            if len(lsaida) == 0:
                break


ntrem = int(input())

while ntrem != 0:
    saida = str(input())
    while saida != '0':
        ltrem = list(range(1,ntrem + 1))
        ltrem.reverse()
        lsaida = saida.rsplit(' ')

        for n,trem in enumerate(lsaida):
            lsaida[n] = int(trem)
        stc = []

        EntraTrem()
        print(ltrem)
        print(stc)
        print(lsaida)
        if (len(lsaida) == 0) and (len(stc) == 0) and (len(ltrem) == 0):
            print('Yes')
        else:
            print('No')

        saida = str(input())

    print('')
    ntrem = int(input())
