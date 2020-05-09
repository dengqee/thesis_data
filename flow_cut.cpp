/*************************************************************************
	> File Name: flow_cut.cpp
	> Author: dengqi
	> Mail: 906262038@qq.com 
	> Created Time: Mon 10 Feb 2020 03:08:00 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//#include<stdlib>
using namespace std;

int main()
{
	string allflow="BA50_packets.txt";
	int days=10;//分割的天数
	ifstream ifs(allflow.c_str());
	string line;
	vector<string>lines;
	while(getline(ifs,line))
	{
		lines.push_back(line);
	}
	ifs.close();
	
	int n=lines.size()/days;//每天行数
	int i=0;//lines第几行
	string dir="./BA50_days/";
	for(int day=1;day<days;day++)
	{
		string outfile=dir+"packets_"+"day"+to_string(day)+".txt";
		ofstream ofs(outfile);
		for(int cnt=0;cnt<n;cnt++)
		{
			ofs<<lines[i++]<<endl;
		}
		ofs.close();

	}
	string outfile=dir+"packets_"+"day"+to_string(days)+".txt";
	ofstream ofs(outfile);
	while(i<lines.size())
	{
		ofs<<lines[i++]<<endl;
	}
	ofs.close();
	return 0;
}
