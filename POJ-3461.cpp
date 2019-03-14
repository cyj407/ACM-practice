#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int pi[1000010];

void fail(string w){
	int len = w.length();
	pi[0] = -1;
	for(int i = 1,cur = -1;i<len;++i){
		while(cur!=-1 && w[i]!=w[cur+1])
			cur = pi[cur];
		if(w[i] == w[cur+1])
			++cur;
		pi[i] = cur;
	}
}

int match(string w1,string w2){
	fail(w1);
	int ans = 0;
	int len1 = w1.length();
	int len2 = w2.length();
	for(int i = 0,cur = -1;i<len2;++i){
		while(cur!=-1 && w2[i]!=w1[cur+1])
			cur = pi[cur];
		if(w2[i] == w1[cur+1])
			++cur;
		if(cur+1 == len1){
			ans++;		
			cur = pi[cur];
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d\n",&n);
	while(n--){
		string w1,w2;
		getline(cin,w1);
		getline(cin,w2);
		cout << match(w1,w2) << endl;
	}
	return 0;
}
