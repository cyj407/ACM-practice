#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

int p[5000];

int find(int x){
	if(x == p[x])	return x;
	return x = find(p[x]);
}

void Union(int x, int y){
	int X = find(x);
	int Y = find(y);
	(X > Y)?(p[Y] = X):(p[X] = Y);
}

int main(){
	int cre,rela;
	while(scanf("%d%d\n",&cre,&rela)!=EOF && cre+rela!=0){
		map<string,int> rec;

		int count[cre];
		for(int i = 0;i<cre;++i){
			string str;
			getline(cin,str);
			rec[str] = i;
			p[i] = i;
			count[i] = 0;
		}	
		string pair_1,pair_2;
		for(int i = 0;i<rela;++i){
			string str;
			getline(cin,str);
			for(int j = 0;j<str.length();++j){
				if(str[j] == ' '){	pair_1 = str.substr(0,j);	break;}
			}//	get pair_1
			size_t pos = str.find(" ");
			pair_2 = str.substr(pos+1);	// get pair_2
			Union(rec[pair_1],rec[pair_2]);
		}

		for(int i = 0;i<cre;++i)	p[i] = find(p[i]);
		for(int i = 0;i<cre;++i)	count[p[i]]++;
		int max = 0;
		for(int i = 0;i<cre;++i){
			if(count[i] > max)	max = count[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
