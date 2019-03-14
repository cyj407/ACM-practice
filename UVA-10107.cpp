#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<long int> v;
	long int num;
	while(scanf("%ld",&num)!=EOF){
		v.push_back(num);
		sort(v.begin(),v.end());
		
		int mid;
		if(v.size()%2!=0){
			mid = (v.size()+1)/2 -1;
			printf("%ld\n",v.at(mid));
		}
		else{
			mid = v.size()/2 -1;
			printf("%ld\n",(v.at(mid)+v.at(mid+1))/2);
		}
	}
	return 0;
}
