from sys import stdin

for line in stdin:
    arr = list(map(int, line.split()))
    si = sorted(arr)
    sd = list(reversed(si))
    ff, ffi, ffd, bf, wf = [[0 for _ in range(25)] for i in range(5)]
    for i in range(len(arr)):
        ff[next((j, v) for j, v in enumerate(ff) if arr[i]+v <= 10)[0]] += arr[i]
        ffi[next((j, v) for j, v in enumerate(ffi) if si[i]+v <= 10)[0]] += si[i]
        ffd[next((j, v) for j, v in enumerate(ffd) if sd[i]+v <= 10)[0]] += sd[i]
        
        bfi, wfi = 0, 0
        for j in range(25):
            if arr[i]+bf[j] > 10: continue
            elif arr[i]+bf[j] > arr[i]+bf[bfi] or arr[i]+bf[bfi]>10: bfi = j
            if bf[bfi] == 0 or arr[i]+bf[j] == 10: break
        for j in range(25):
            if arr[i]+wf[j] > 10: continue
            if arr[i]+wf[j] < arr[i]+wf[wfi] and wf[j] > 0: wfi = j
                
        if wfi == 0 and wf[wfi]+arr[i] > 10: wfi = next((j, v) for j, v in enumerate(wf) if wf[j] == 0)[0]
                
        bf[bfi] += arr[i]
        wf[wfi] += arr[i]
        

    print(f"FF: {str([x for x in ff if x > 0]).replace('[', '').replace(',', '').replace(']', '')}")
    print(f"FFI: {str([x for x in ffi if x > 0]).replace('[', '').replace(',', '').replace(']', '')}")
    print(f"FFD: {str([x for x in ffd if x > 0]).replace('[', '').replace(',', '').replace(']', '')}")
    print(f"BF: {str([x for x in bf if x > 0]).replace('[', '').replace(',', '').replace(']', '')}")
    print(f"WF: {str([x for x in wf if x > 0]).replace('[', '').replace(',', '').replace(']', '')}")
    print()
        