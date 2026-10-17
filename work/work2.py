import sys
import numpy as np




memo = {}
memos = set()


ichiran: np.ndarray = np.empty(0, dtype=np.int64)
for i in range(1,2299):
    for j in range(i,3300):
        c = i*i+j*j
        if c in memos:
            memo[i*i+j*j]+=1
        else:
            memo[i*i+j*j]=1

keys = memo.keys()
for e in keys:
    v = memo[e]
    if v == 1:
        ichiran = np.append(ichiran,e)

ichiran = np.sort(ichiran)

np.save('./ichiran.npy', ichiran)


ichiran: np.ndarray = np.load('./ichiran.npy')
N: int = int(input())
K=0
while True:
    if ichiran[K]<=N:
        print(ichiran[K])
    else:
        break
    K+=1


