#include<cstdlib>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#define MAX 100000

using namespace std;
vector<long int> pri;

void is_prime(){
	bool prime[MAX];
	memset(prime,1,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(long int i = 2;i<=sqrt(MAX);i++){
		if(prime[i]){
			for(long int j = i+i;j<MAX;j+=i)	prime[j] = false;
		}
	}
	for(long int i = 2;i<MAX;i++){
		if(prime[i])	pri.push_back(i);
	}
}

int count_div(long long int n){
	int div_n = 1;
	long int i = 0;
	vector<long int> v;
	while(i<pri.size()){
		if(n == pri[i]){
			v.push_back(pri[i]);	
			break;
		}
		if(n % pri[i] == 0){
			n /= pri[i];
			v.push_back(pri[i]);
		}
		else	i++;
	}
	sort(v.begin(),v.end());
	stack<int> s;
	int count = 1;
	for(int j = 0;j<v.size();j++){
		if(j == v.size()-1){
			s.push(count+1);
			break;
		}
		if(v[j] == v[j+1])	count++;
		else{
			s.push(count+1);	// n^0~n^count -> count+1 possible answer
			count = 1;
		}
	}// count different prime
	v.clear();
	while(!s.empty()){
		div_n *= s.top();
		s.pop();
	}// count divisor
	return div_n;
}

int main(){
	is_prime();
	int n;
	scanf("%d\n",&n);
	while((n--)>0){
		long long int l, u;
		scanf("%lld%lld",&l,&u);
		int max = 0;
		long long int most_div = -1;
		for(long long int i = l;i<=u;++i){
			int tmp = count_div(i);
			if(tmp > max){
				max = tmp;
				most_div = i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n",l,u,most_div,max);
	}
	return 0;
}
