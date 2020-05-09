/*************************************************************************
  > File Name: Geant_real.cpp
  > Author: dengqi
  > Mail: 906262038@qq.com 
  > Created Time: 2019年07月02日 星期二 19时40分14秒
 ************************************************************************/
#include<stdlib.h>
#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
typedef unsigned int uint32_t;

int main()
{
	string	filename="BA50_packets.txt";
	ifstream ifs(filename.c_str());
	string line;
	istringstream lineBuffer;
	uint32_t s,d;
	uint32_t num;
	uint32_t key;
	map<uint32_t,uint32_t>real;
	while(getline(ifs,line))
	{
		lineBuffer.clear();
		lineBuffer.str (line);
		lineBuffer>>s>>d>>num;
		key=s*100000+d*1000+num;
		real[key]++;
	}
	ofstream ofs("BA50_real.txt");
	for(auto it=real.begin();it!=real.end();it++)
		ofs<<it->first<<" "<<it->second<<endl;
	ofs.close();
	ifs.close();
	return 0;
}
