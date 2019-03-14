#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
int p,q,r,s,t,u;

double answer(double x){
	double ans = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
	return ans;
}

int main(){
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		double l = 0.0;
		double r = 1.0;
		double k;
		double tmp;
		for(int i = 0;i<100;++i){
			k = (l+r)/2;
			tmp = answer(k);
			if(tmp > 0){
				l = k;
			}
			else{
				r = k;
			}
		}
		if(abs(tmp) < 0.000001){
			printf("%.4f\n",k);
		}
		else{
			printf("No solution\n");
		}
	}
	return 0;
}
