while True:
    try:
        equa = list(raw_input())
    except EOFError:
        break

    tam = len(equa) - 1
    cont = 0
    equa2 = []
    for item in equa:
        if item == '(':
            cont2 = 0
            equa.reverse
            for cara in equa:
                if cara == ')':
                    equa.remove(')')
                    equa.reverse()
                    equa.remove('(')
                    break
                cont2 += 1
            equa.reverse()
        cont += 1
    print(equa)
    equa.reverse()
    print(equa)

    for item in equa:
        if (item == '(') or (item == ')'):
            print('incorrect')
            break
    else:
        print('correct')
