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
	string	filename="Geant_126388_real.txt";
	ifstream ifs(filename.c_str());
	ofstream ofs("TM_Geant.txt");
	string line;
	istringstream lineBuffer;
	uint32_t s,d;
	uint32_t num;
	uint32_t key;
	float val,sum=0;
	string nodepair,nodepair_old;

	getline(ifs,line);
	lineBuffer.clear();
	lineBuffer.str (line);
	lineBuffer>>key>>val>>num;
	s=key/100000;
	d=key%100000/1000;
	num=key%1000;
	sum+=val;
	nodepair_old=to_string(s)+" "+to_string(d);
	while(getline(ifs,line))
	{
		lineBuffer.clear();
		lineBuffer.str (line);
		lineBuffer>>key>>val>>num;
		s=key/100000;
		d=key%100000/1000;
		num=key%1000;
		nodepair=to_string(s)+" "+to_string(d);
		if(nodepair!=nodepair_old)
		{
			ofs<<nodepair_old<<" "<<sum<<endl;

			nodepair_old=nodepair;
			sum=0;
		}
		sum+=val;
	}
	ofs<<nodepair<<" "<<sum<<endl;
	ofs.close();
	ifs.close();
	return 0;
}
