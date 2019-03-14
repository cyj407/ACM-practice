#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

bool cmp(int a, int b){
	return a < b;
}

int main(){
	int n,q;
	scanf("%d",&n);
	int list[n];
	for(int i = 0;i<n;++i)
		scanf("%d",&list[i]);
	scanf("%d",&q);
	int quest[q];
	for(int i = 0;i<q;++i)
		scanf("%d",&quest[i]);
	
	for(int i = 0;i<q;++i){
		int tmp = lower_bound(list,list+n,quest[i])-list-1;
		if(tmp < 0)
			cout << "X" << " ";
		else
			cout << list[tmp] << " ";
		if(list[tmp+1] == quest[i]){
			if(tmp+2 < n){
				while(list[tmp+2] == quest[i])
					tmp++;
				if(tmp+2 < n)
					cout << list[tmp+2] << endl;
				else
					cout << "X" << endl;
				continue;
			}
		}
		else{
			if(tmp+1 < n)
				cout << list[tmp+1] << endl;
			continue;
		}
		cout << "X" << endl;
	}
	return 0;
}
