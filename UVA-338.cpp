#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

void reverse(int length,int num[]){
	int tmp[length], k = 0;
	for(int i = length-1;i>=0;i--)	tmp[i] = num[k++];	
	for(int i = 0;i<length;i++)	num[i] = tmp[i];
}

int Mult(int dig1,int dig2,int bigN1[],int bigN2[],int ans[]){
	int digit;
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
	reverse(digit,ans);
	return digit;
}

void print(int space,int ans_length, int tmp_digit, int output[]){		
	for(int i = 0;i<space;i++)	cout << " ";
	for(int j = 0;j<(ans_length-tmp_digit);j++)	cout << " ";
	for(int i = 0;i<tmp_digit;i++)	cout << output[i];
	cout << endl;
}

int main(){
	string str;
	while(getline(cin,str)){
		if(str.length() == 1 && str[0] == '0')	break;
		int a[10],b[10],answer[25];
		int pos, a_length, b_length;
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(answer,0,sizeof(answer));
		for(pos = 0;pos<str.length();++pos)	if(str[pos]!=' ')	break;
		str = str.substr(pos);
		for(pos = 0;pos<10;pos++){
			if(str[pos] == ' ')	break;
			a[pos] = str[pos] - '0';
		}
		a_length = pos;
		while(str[pos]==' ')	pos++;
		str = str.substr(pos);
		bool find_length = false;
		for(int i = 0;i<str.length();++i){
			if(str[i] == ' '){
				b_length = i;
				find_length = true;
				break;
			}
			b[i] = str[i] - '0';
		}
		if(!find_length)	b_length = str.length();		
		int dash = (a_length>b_length)?a_length:b_length;
		reverse(a_length,a);	reverse(b_length,b);		
		int ans_n = Mult(a_length,b_length,a,b,answer);
		reverse(a_length,a);	reverse(b_length,b);
		// print a and b
		print(ans_n-dash,dash,a_length,a);
		print(ans_n-dash,dash,b_length,b);
		for(int i = 0;i<ans_n-dash;i++)	cout << " ";
		for(int i = 0;i<dash;i++)	cout << "-";
		cout << endl;
		// print the process
		reverse(a_length,a);	reverse(b_length,b);
		bool skip = false;
		if(b_length > 1){
			int count_zero = 0;
			for(int i = 0;i<b_length;i++){
				if(a_length == 1 && a[0] == 0)	break;
				int b_one[1] = {b[i]} , tmp[12];
				if(b[i] == 0){	count_zero++;	continue;}	// skip 0
				if(count_zero == b_length-1){ skip = true;	break;}	// ex:200->don't need to print process
				memset(tmp,0,sizeof(tmp));
				int line_digit = Mult(a_length,1,a,b_one,tmp);
				for(int j = 0;j<(ans_n-line_digit-i);j++)	cout << " ";
				for(int i = 0;i<line_digit;i++)	cout << tmp[i];
				cout << endl;
			}
		}
		if(b_length > 1 && (a_length>1 || a[0] != 0) && !skip){
			for(int i = 0;i<ans_n;i++)	cout << "-";
			cout << endl;
		}
		if(ans_n == 1 && answer[0] == 0){
			for(int i = 0;i<dash-1;i++)	cout << " ";
		}
		for(int i = 0;i<ans_n;i++)	cout << answer[i];
		cout << endl << endl;
	}
	return 0;
}
