#产生拓扑
import random
from random import choice
import math
toposize=[50]
for topo in toposize:
    to= open('ER'+str(topo)+'.txt','w')
    p0 = math.log(topo, 2)
    for i in range(topo):
        for j in range(topo):
            if i < j:
                randomnum = random.randint(1, topo)
                if randomnum < p0:
                    to.write(str(i)+' '+str(j)+'\n')

    to2 = open('BA' + str(topo) + '.txt', 'w')
    degree=[]

    for i in range(3):
        degree.append(0)
        degree.append(i+1)
        to2.write(str(0) + ' ' + str(i+1) + '\n')

    for i in range(topo-4):
        usednode=[]
        usenum=0
        while usenum < 3:
            node=choice(degree)
            if node not in usednode and node != i+4:
                degree.append(node)
                degree.append(i+4)
                to2.write(str(node) + ' ' + str(i+4) + '\n')
                usenum+=1
                usednode.append(node)
