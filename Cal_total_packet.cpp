/*************************************************************************
	> File Name: Cal_total_packet.cpp
	> Author: dengqi
	> Mail: 906262038@qq.com 
	> Created Time: Sun 16 Feb 2020 08:05:04 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main()
{
	string file="Geant_126388_real.txt";
	ifstream ifs(file.c_str());
	string line;
	stringstream linebuf;
	uint64_t s=0;
	while(getline(ifs,line))
	{
		uint64_t key,val;
		linebuf.clear();
		linebuf>>key>>val;
		s+=val;

	}
	cout<<s<<endl;

	return 0;
}
