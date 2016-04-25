casos = int(input())
for a in range(1,casos + 1):
    dim = int(input())
    Matrix = [][]
    # Matrix[dim][dim] = -1
    for c in range(dim):
        for d in range(dim):
            Matrix[c][d] = -1
    for b in range((2*dim)-1):
        entrada = str(input())
        tupla = []
        for c in entrada:
            if c != ' ':
                tupla.append(int(c))
        for c in range(dim):
            if(Matrix[0][c] == -1):
                for ind,num in enumerate(tupla):
                    Matrix[num][c] = num
                break
        else:
            for c in range(dim):
                if(Matrix[c][0] == -1):
                    for ind,num in enumerate(tupla):
                        Matrix[c][num] = num
                    break
        for c in range(dim):
            for d in range(dim):
                print(' ' + Matrix[c][d])
            print('')
