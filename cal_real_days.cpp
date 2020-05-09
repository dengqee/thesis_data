/*************************************************************************
  > File Name: cal_real_days.cpp
  > Author: dengqi
  > Mail: 906262038@qq.com 
  > Created Time: Wed 12 Feb 2020 10:19:08 AM CST
  > 分时段统计真实流量
 ************************************************************************/

#include<iostream>
#include<map>
#include<set>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

	//读取每天的packet
	cout<<endl<<"读取每天的packet:";
	ifstream ifs("Geant_126388_real.txt");

	map<uint32_t,uint32_t>allkey;
	string line;
	istringstream lineBuffer;
	uint32_t key,val;
	while(getline(ifs,line))
	{

		lineBuffer.clear();
		lineBuffer.str(line);
		lineBuffer>>key>>val;
		allkey[key]=0;
	}

	for(int day=1;day<=10;day++)
	{
		map<uint32_t,uint32_t>real(allkey); 
		cout<<day<<" ";
		string packet_day_file="./GEANT_days/packets_day"+to_string(day)+".txt";
		ifstream ifs(packet_day_file.c_str());
		int s,d,num,key;
		string line;
		istringstream lineBuffer;
		while(getline(ifs,line))
		{
			lineBuffer.clear();
			lineBuffer.str(line);
			lineBuffer>>s>>d>>num;
			key=s*100000+d*1000+num;
			if(real.find(key)==real.end())
				cout<<key<<endl;
			real[key]++;
		}
		ifs.close();
		string outdir="./GEANT_days/day"+to_string(day)+"/";
		string cmd="mkdir -r "+outdir;
		string outfile=outdir+"real.txt";
		ofstream ofs(outfile.c_str());
		for(auto it=real.begin();it!=real.end();it++)
		{
			ofs<<it->first<<" "<<it->second<<endl;
		}
		ofs.close();

	}



	return 0;
}
