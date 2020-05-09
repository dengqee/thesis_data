import random
import math
#输入文件名
def FlowGen(filename):
    ftopo = open(filename, 'r')
    lines = ftopo.readlines()
    # 统计链路信息
    slist = []
    tlist = []
    nodenum = int(lines[0])
    for l in lines[1:]:
        eage=l.split()
        slist.append(int(eage[0]))
        tlist.append(int(eage[1]))

    # 设置网络
    G = {i: {} for i in range(nodenum)}
    Commodity = []
    edgenums = len(slist)  # 边数量
    # 设置链路
    while slist:
        s = slist.pop()
        t = tlist.pop()
        G[s][t] = 500 * 1000
        G[t][s] = 500 * 1000

        # 设置容量
        for i, v in G.items():
            for j in v:
                if len(G[i]) > 5 and len(G[j]) > 5:
                    G[i][j] = 5000 * 1000
                    G[j][i] = 5000 * 1000
                else:
                    if len(G[i]) > 5 and len(G[j]) <= 5:
                        G[i][j] = 1000 * 1000
                        G[j][i] = 1000 * 1000
                    else:
                        pass

    # 采用Gravity模型产生商品流

    # 随机产生Tin 和 Tout
    Tinlist = []
    Toutlist = []
    for i, v in G.items():
        # 产生0.3-0.8的随机数
#        a = random.randint(4, 8) / 10
#        b = random.randint(4, 8) / 10
        a=0.6
        b=0.6
        sumc = 0
        for j, c in v.items():
            sumc += c
        Tin = a * sumc
        Tout = b * sumc
        Tinlist.append(Tin)
        Toutlist.append(Tout)

    for i in range(nodenum):
        for j in range(nodenum):
            if i != j:
                Tij = Tinlist[i] * Toutlist[j] / sum(Toutlist)
                Commodity.append([i, j, Tij / 5])
    outfile = open("TM_BA50_OC192.txt","w")
    for f in Commodity:
        for i in f:
            outfile.write(str(i)+" ")
        outfile.write("\n")
    outfile.close()

    Commodity = sorted(Commodity, key=lambda l: l[2], reverse=True)



    nCommodity = []
    for com in Commodity:
        # 随机选择5-10个子网
        num1 = random.randint(5, 10)
        num2 = random.randint(5, 10)
        prelist = random.sample(range(24), num1 + num2)
        # print(prelist)

        prenumlist1 = []
        for i in range(num1):
            pre = prelist.pop(0)
            prenumlist1.append(32 - int(pre))

        prenumlist2 = []
        for i in range(num2):
            pre = prelist.pop(0)
            prenumlist2.append(32 - int(pre))

        # 拆分子网
        for fnum1 in prenumlist1:
            for fnum2 in prenumlist2:
                nCommodity.append([com[0], com[1], com[2] * fnum1 / sum(prenumlist1) * fnum2 / sum(prenumlist2)])

    print('商品流已经拆分完成')
    nCommodity = sorted(nCommodity, key=lambda l: l[2], reverse=True)
    return Commodity
if __name__ == "__main__":
    FlowGen("Topology_BA50.txt")
