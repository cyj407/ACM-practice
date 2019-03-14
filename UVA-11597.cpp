#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int case_n = 1,m;
	while(cin >> m && m){
		printf("Case %d: %d\n",case_n++,m/2);
	}
	return 0;
}
