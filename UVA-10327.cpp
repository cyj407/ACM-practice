#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[n];
		for(int i = 0;i<n;++i){
			scanf("%d",&a[i]);
		}
		int temp;
		int count = 0;
		for(int i = n-1;i>=0;--i){
			for(int j = 0;j<i;++j){
				if(a[j] > a[j+1]){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					count++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",count);
	}
	return 0;
}
