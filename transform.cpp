/*************************************************************************
	> File Name: transform.cpp
	> Author: dengqi
	> Mail: 906262038@qq.com 
	> Created Time: 2019年09月14日 星期六 20时02分56秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

int main()
{
	string flow_val_file="./BA50_real.txt";
	ifstream ifs(flow_val_file.c_str());
	string line;
	stringstream linebuf;
	int key;
	int val;
	int s,d,weight;
	map<pair<int,int>,int>coaseflows;
	while(getline(ifs,line))
	{
		linebuf.clear();
		linebuf.str(line);
		linebuf>>key>>val;
		s=key/100000;
		key%=100000;
		d=key/1000;
		coaseflows[make_pair(s,d)]++;
	}
	string outfile="./BA50flow.txt";
	ifs.close();
	ofstream ofs(outfile.c_str());
	int ma=0,mi=coaseflows.begin()->second;
	int sum=0;
	for(auto it=coaseflows.begin();it!=coaseflows.end();it++)
	{
		ofs<<it->first.first<<" "<<it->first.second<<endl;
		ofs<<it->second<<endl;
		ma=max(it->second,ma);
		mi=min(it->second,mi);
		sum+=it->second;
	}
	ofs.close();
	cout<<ma<<" "<<mi<<" "<<sum<<endl;

	return 0;
}

