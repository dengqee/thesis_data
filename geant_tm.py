from random import randint,shuffle
from math import pow,ceil


def generate_packet(nodes, flow_pair,alpha,txtname):
    flow_pair_num={}

    with open(flow_pair) as f:
        for line in f.readlines():
            flow=line.split(" ")
            i=flow[0]
            j=flow[1]
            num=flow[2]
            flow_pair[i+" "+j]=int(num)

    flow_vol = {}
    with open("TM_Geant_all.txt") as f:
        for line in f.readlines():
            nums = line.split(" ")
            flow_vol[nums[0]+" "+nums[1]] = float(nums[2])
            
    packets = []
    for i in range(NODES):
        for j in range(NODES):
            if i != j:
                flow_num = flow_pair_num[str(i)+" "+str(j)]
                flow_val=flow_vol[str(i)+" "+str(j)]
                sum = 0
                for k in range(1,flow_num+1):
                    sum+= 1/pow(k,alpha)
                packet_weight = flow_val/sum
                for k in range(1,flow_num+1):
                    for l in range(ceil(packet_weight/pow(k,alpha))):
                        packets.append(str(i)+" " +str(j)+" "+str(k-1)+"\n")
    shuffle(packets)
    with open (txtname,"w") as f:
        for packet in packets:
            f.write(packet)




#进行归一化处理
def deal_flow_vol(ori_vol):
    return int(ori_vol)


if __name__ == '__main__':
    NODES = 23  #总的节点数目
    ALPHA = 1   #zipf分布中的alpha参数
    flow_pair "Geantflow_126388.txt"
    for day in range(9):
        TXTNAME="GEANT_days/packets_day"+str(day+2)+".txt" #生成文件的名称
        generate_packet(NODES, flow_pair,ALPHA,TXTNAME)
        
