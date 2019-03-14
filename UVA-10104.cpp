#include<cstdio>
#include<iostream>

using namespace std;

long long int exGCD(long long int a,long long int b,long long int &x,long long int &y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	else{
		long long int gcd = exGCD(b,a%b,x,y);
		long long int tmp = x;
		x = y;
		y = tmp-(a/b)*y;
		return gcd;
	}
}

int main(){
	long long int a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		long long int X,Y;
		long long int D = exGCD(a,b,X,Y);
		cout << X << " "<< Y << " "<< D << endl;
	}
	return 0;
}
