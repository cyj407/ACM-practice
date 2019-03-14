#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

int add(int a[], int b[]){
	int c[10], ope = 0;
	for(int i = 0;i<10;++i)	c[i] = a[i] + b[i];
	for(int i = 0;i<10-1;++i){
		if(c[i]/10 != 0)	ope++;
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	return ope;
}

void rev_n(int a[]){
	stack<int> s;
	for(int i = 0;i<10;++i){
		if(a[i]>=0)	s.push(a[i]);
	}
	int tmp = s.size();
	for(int i = 0;i<10;i++){
		if(i<tmp){
			a[i] = s.top();
			s.pop();
		}
		else	a[i] = 0;
	}
}

int main(){
	string line;
	while(getline(cin,line)){
		if(line[0] == '0' && line[2] == '0')	break;
		int n1[10],n2[10],k = 0;
		memset(n1,-1,sizeof(n1));
		memset(n2,-1,sizeof(n2));
		bool space = false;
		for(int i = 0;i<line.length();++i){
			if(line[i] == ' '){
				space = true;	continue;
			}
			if(!space)	n1[i] = line[i]-'0';
			else	n2[k++] = line[i]-'0';
		}
		rev_n(n1);
		rev_n(n2);
		int oper = add(n1,n2);
		if(oper == 0)	printf("No carry operation.\n");
		else if(oper == 1)	printf("%d carry operation.\n",oper);
		else	printf("%d carry operations.\n",oper);
	}
	return 0;
}
