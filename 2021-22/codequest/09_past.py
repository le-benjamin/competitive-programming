teca = int(input())

for tc in range(teca):
    n = int(input())
    d = {}
    for line in range(n):
        dsid, p, s, eid, t = input().split(",")
        if t == 'true':
            if not eid in d.keys():
                d[eid] = [{"\\"}, {"\\"}]
            if s == 'Day':
                d[eid][0].add(p)
            else:
                d[eid][1].add(p)
    for k in sorted(d):
        print("{0},{1},{2}".format(k, len(d[k][0])-1, len(d[k][1])-1))
