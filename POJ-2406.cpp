#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int pi[1000010];
int len;

void KMP(string input){
	len = input.length();
	pi[0] = -1;
	for(int i = 1,cur = -1;i<len;++i){
		while(cur!=-1 && input[i]!=input[cur+1])
			cur = pi[cur];
		if(input[i] == input[cur+1])
			++cur;
		pi[i] = cur;
	}
}

int main(){
	string input;
	while(getline(cin,input) && input != "."){
		KMP(input);
		int ans = (len-1) - pi[len-1];
		if(len % ans == 0)		// ans is composed of input
			cout << len/ans << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}
