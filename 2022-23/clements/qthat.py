for _ in range(int(input())):
    arr = list(map(int, input().split()))
    fifo = [(0, -3), (0, -2), (0, -1)]
    lru = [(0, -3), (0, -2), (0, -1)]
    ind = 0
    
    for i, x in enumerate(arr):
        # listen, i don't want to talk about how poorly this is structured
        if True:
            fi = 0
            is_in = False
            for j, a in enumerate(fifo):
                if x == a[0]: 
                    is_in = True
                if (a[1] < fifo[fi][1]): fi = j

            if not is_in: fifo[fi] = (x, i)   

        if True:
            li = 0
            ind_if_found = 0
            is_in = False
            for j, a in enumerate(lru):
                if x == a[0]: 
                    is_in = True
                    ind_if_found = j
                if (a[1] < lru[li][1]): li = j

            if not is_in: lru[li] = (x, i) 
            else: lru[ind_if_found] = (x, i)

    
    print(f"FIFO:{' '.join([str(a) for a, b in fifo])}")
    print(f"LRU:{' '.join([str(a) for a, b in lru])}\n")
        