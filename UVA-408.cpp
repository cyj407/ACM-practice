#include<iostream>
#include<cstdio>

using namespace std;

long int gcd(long int a, long int b){
	if(a == 0)	return b;
	return gcd(b%a,a);
}

int main(){
	long int step,mod;
	while(scanf("%ld%ld",&step,&mod)!=EOF){
		long int choice = gcd(step,mod);
		printf("%10ld%10ld    ",step,mod);
		if(choice == 1){
			printf("Good Choice\n\n");
		}
		else	printf("Bad Choice\n\n");
	}
	return 0;
}
