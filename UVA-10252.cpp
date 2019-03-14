#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
string in1,in2;

void common(){
	vector<char> ans;
	string s,l;
	int slen,llen,cur = 0;
	if(in1.length()>in2.length()){
		s = in2 , l = in1;
		slen = in2.length() , llen = in1.length();
	}
	else{
		s = in1 , l = in2;
		slen = in1.length() , llen = in2.length();
	}
	bool found[llen];
	memset(found,false,sizeof(found));
	for(int i = 0;i<slen;++i){
		for(int j = 0;j<llen;++j){
			if(s[i] == l[j] && !found[j]){
				found[j] = true;
				ans.push_back(l[j]);
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	for(int i = 0;i<ans.size();++i){
		cout << ans[i];
	}
	cout << endl;
}

int main(){
	while(getline(cin,in1)){
		getline(cin,in2);
		if(in1[0] == '\0' || in2[0] == '\0'){
			cout << endl;
			continue;
		}
		common();
		in1.clear();
		in2.clear();
	}
	return 0;
}
