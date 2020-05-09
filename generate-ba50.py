from random import randint,shuffle
from math import pow,ceil
import numpy


def generate_packet(nodes, smin,smax,alpha,txtname):

    flow_val_all = {}
    flow_val_all=generate_total_value()
    packets = []
    for i in range(NODES):
        for j in range(NODES):
            if i != j:
                flow_num = randint(smin,smax)
                flow_val= (flow_val_all[str(i)+" "+str(j)] )
                sum = 0
                for k in range(1,flow_num+1):
                    sum+= 1/pow(k,alpha)
                packet_weight = flow_val/sum
                for k in range(1,flow_num+1):
                    for l in range(ceil(packet_weight/pow(k,alpha))):
                        packets.append(str(i)+" " +str(j)+" "+str(k-1)+"\n")
                        if len(packets)%1000000==0:
                            print(len(packets))
                            print("\n")
    shuffle(packets)
    with open (txtname,"w") as f:
        for packet in packets:
            f.write(packet)


#读取流的方法
def generate_total_value():
    print("读取流\n")
    flow_vol = {}
    s=0
    with open("TM_BA50_OC192.txt") as f:
        for line in f.readlines():
            nums = line.split(" ")
            flow_vol[nums[0]+" "+nums[1]] = float(nums[2])
            s+=float(nums[2])
    print(s)
    print("读取流完成\n")
    return flow_vol


#进行归一化处理
def deal_flow_vol(ori_vol):
    return int(ori_vol)


if __name__ == '__main__':
    NODES = 50  #总的节点数目
    ALPHA = 0.5   #zipf分布中的alpha参数
    FLOW_TO_SPLIT_MIN = 50   #两节点最少分割流量数
    FLOW_TO_SPLIT_MAX = 150   #最大分割流量数
    TXTNAME="BA50_packets.txt" #生成文件的名称
    generate_packet(NODES,FLOW_TO_SPLIT_MIN ,FLOW_TO_SPLIT_MAX,ALPHA,TXTNAME)
