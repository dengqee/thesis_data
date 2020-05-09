from random import randint,shuffle
from math import pow,ceil
import numpy


def generate_packet(nodes, flow_pair,alpha,txtname):
    flow_pair_num=numpy.zeros((nodes,nodes))

    with open(flow_pair) as f:
        for line in f.readlines():
            flow=line.split(" ")
            i=flow[0]
            j=flow[1]
            num=flow[2]
            flow_pair[i][j]=num

            
    packets = []
    for i in range(NODES):
        for j in range(NODES):
            if i != j:
                flow_num = flow_pair_num[i][j]
                flow_val=generate_total_value(i,j)
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


#读取流的方法
def generate_total_value(i,j):
    flow_vol = {}
    with open("TM_BA50.txt") as f:
        for line in f.readlines():
            nums = line.split(" ")
            flow_vol[nums[0]+" "+nums[1]] = float(nums[2])
    return deal_flow_vol(flow_vol[str(i)+" "+str(j)])


#进行归一化处理
def deal_flow_vol(ori_vol):
    return int(ori_vol)


if __name__ == '__main__':
    NODES = 50  #总的节点数目
    ALPHA = 1   #zipf分布中的alpha参数
    flow_pair "BA50flow.txt"
    FLOW_TO_SPLIT_MIN = 0   #两节点最少分割流量数
    FLOW_TO_SPLIT_MAX = 100   #最大分割流量数
    TXTNAME="BA50_packets_100.txt" #生成文件的名称
    generate_packet(NODES, flow_pair,ALPHA,TXTNAME)
