#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
int ans[1000];

int Digit(char in[],int num[]){
	int digit;
	for(digit = 999;digit>0;digit--){
		if(in[digit]>='0' && in[digit]<='9' && in[digit-1]<='9' && in[digit-1]>='0')	break;
	}// find LSB digit
	for(int i = 0;i<=digit;++i){
		num[i] = (int)(in[digit-i]-'0');
	}// save value in num[]
	return digit+1;
}

int Mult(int dig1,int dig2,int bigN1[],int bigN2[]){
	int digit;
	memset(ans,0,sizeof(ans));
	if(dig1 == 1 && bigN1[0] == 0)	return digit = 1;
	if(dig2 == 1 && bigN2[0] == 0)	return digit = 1;	
	for(int i = 0;i<dig2;++i){
		for(int j = 0;j<dig1;++j){
			ans[i+j] += (bigN1[j]*bigN2[i])%10;
			ans[i+j+1] += (bigN1[j]*bigN2[i])/10;
		}
	}
	int carry = 0;
	for(int i = 1;i<dig1+dig2;++i){
		ans[i] += carry;
		carry = ans[i]/10;
		ans[i] = ans[i]%10;
	}
	digit = (ans[dig1+dig2-1]==0)? dig1+dig2-1 : dig1+dig2;
	return digit;
}

int main(){
	char input1[1000],input2[1000];
	memset(input1,'Z',sizeof(input1));
	memset(input2,'Z',sizeof(input2));
	while(fgets(input1,1000,stdin) && fgets(input2,1000,stdin)){
		int num1[1000],num2[1000];
		memset(num1,-1,sizeof(num1));
		memset(num2,-1,sizeof(num2));
		int digit1 = Digit(input1,num1);
		int digit2 = Digit(input2,num2);
		int ans_d = Mult(digit1,digit2,num1,num2);
		for(int i = ans_d-1;i>=0;i--)	printf("%d",ans[i]);
		printf("\n");
		memset(input1,'Z',sizeof(input1));
		memset(input2,'Z',sizeof(input2));
	}
	return 0;
}
