#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
vector<long long int> list;

bool cmp(long long int a, long long int b){
	return a<=b;
}

void create(){
	for(int i = 0;i<32;++i){
		for(int j = 0;j<32;++j){
			long long int tmp = pow(2,i)*pow(3,j);
			list.push_back(tmp);
		}
	}
	sort(list.begin(),list.end());
}

int main(){	
	int in;
	create();
	while(scanf("%d",&in)!=EOF && in!=0){
		int ans = upper_bound(list.begin(),list.end(),in,cmp)-list.begin();
		cout << list[ans] << endl;
	}
	return 0;
}
