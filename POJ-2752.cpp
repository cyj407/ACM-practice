#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

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
	while(getline(cin,input)){
		vector<int> ans;
		ans.push_back(input.length());
		KMP(input);
		int i = pi[input.length()-1];
		while(i != -1){
			ans.push_back(i+1);
			i = pi[i];
		}
		sort(ans.begin(),ans.end());
		for(int j = 0;j<ans.size();++j){
			cout << ans[j];
			if(j != ans.size()-1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
