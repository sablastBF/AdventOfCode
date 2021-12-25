import numpy as np

def f(v):
    sol = 1
    for i in v:
        if i != 0:
            return sol*i
        sol+=1

for i in range(3):
    for j in range(3):
        if i == j:
            continue
        for k in [-1, 1]:
            for p in [-1,1]:
                x = [0,0,0]
                y = [0,0,0]
                x[i] = k
                y[j] = p
                crs = np.cross(x,y)
                print(f(crs),",",f(x),",",f(y),",")

                

