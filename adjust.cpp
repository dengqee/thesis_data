/*************************************************************************
	> File Name: adjust.cpp
	> Author: dengqi
	> Mail: 906262038@qq.com 
	> Created Time: 2019年09月28日 星期六 10时16分56秒
	>调整Geant_12388_packets.txt中num的序号，使他连续
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
	string dir="/home/dengqi/project5/Thesis/multiswitch/data/";
	string filepackets=dir+"Geant_126388_packets.txt";
	string fileflows=dir+"Geant_126388_real.txt";
	string flowsnum=dir+"Geantflow_126388.txt";
	string outfile=dir+"Geant_126388_packets_new.txt";
	ifstream ifs(flowsnum.c_str());

	string line;
	stringstream linebuf;

	map<uint32_t,uint32_t>coastFlow;//保存粗流的权重
	while(getline(ifs,line))
	{
		linebuf.clear();
		linebuf.str(line);
		uint32_t s,t,num;
		linebuf>>s>>t;
		getline(ifs,line);
		linebuf.clear();
		linebuf.str(line);
		linebuf>>num;
		uint32_t key=s*100+t;
		coastFlow[key]=num;
	}
	ifs.close();
	ifs.open(fileflows.c_str());
	map<uint32_t,uint32_t>adjust;//保存调整map,<原key,新key>
	uint32_t cnt=0,adjust_cnt=0;
	while(getline(ifs,line))
	{
		linebuf.clear();
		linebuf.str(line);
		uint32_t finekey,coastkey;
		linebuf>>finekey;
		coastkey=finekey/1000;
		adjust[finekey]=coastkey*1000+cnt;
		if(finekey!=coastkey*1000+cnt)
			adjust_cnt++;
		cnt++;
		if(cnt>=coastFlow[coastkey])
			cnt=0;
	}
	ifs.close();
	cout<<"调整了"<<adjust_cnt<<"条细流的ID"<<endl;
	ifs.open(filepackets.c_str());
	ofstream ofs(outfile.c_str());
	while(getline(ifs,line))
	{
		linebuf.clear();
		linebuf.str(line);
		uint32_t s,t,num,oldkey,newkey;
		linebuf>>s>>t>>num;
		oldkey=s*100000+t*1000+num;
		newkey=adjust[oldkey];
		s=newkey/100000;
		t=newkey%100000/1000;
		num=newkey%1000;
		ofs<<s<<" "<<t<<" "<<num<<" "<<endl;
	}
	ifs.close();
	ofs.close();
	

	return 0;
}
