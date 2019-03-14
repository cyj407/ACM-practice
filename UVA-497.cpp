#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
vector<int> in;

void LIS(){
	int lis[in.size()], max = -1;
	for(int i = 0;i<in.size();++i){
		lis[i] = 1;
		for(int j = 0;j<i;++j){
			if(in[i] > in[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j]+1;
		}
		if(lis[i] > max)
			max = lis[i];
	}
	int tmp = max;
	vector<int> ans;
	for(int i = in.size()-1;i>=0;--i){
		if(lis[i] == tmp){
			ans.push_back(in[i]);
			tmp--;
		}
		if(tmp == 0)
			break;
	}
	printf("Max hits: %d\n",max);
	for(int i = ans.size()-1;i>=0;--i)
		cout << ans[i] << endl;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		string str;
		while(getline(cin,str)){
			if(str[0] == '\0'){
				if(in.empty())
					continue;
				else
					break;
			}
			if(str[0] != '\0')
				in.push_back(atoi(str.c_str()));
		}
		LIS();
		if(n)	cout << endl;
		in.clear();
	}
	return 0;
}
