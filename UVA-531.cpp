#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
string input;
vector<string> text1,text2;

void create(int n){
	int end = 0;
	while(input.length()!=0){
		if(end == input.length()){
			if(n == 1)
				text1.push_back(input);
			if(n == 2)
				text2.push_back(input);
			break;
		}
		if(input[end] == ' '){
			string voc = input.substr(0,end);
			if(n == 1)
				text1.push_back(voc);
			if(n == 2)
				text2.push_back(voc);
			if(input.length()-end == 0){	
				break;
			}
			input = input.substr(end+1,input.length()-end);
			end = 0;
		}
		++end;
	}
}

void LCS(){
	int t1_len = text1.size()+1;
	int t2_len = text2.size()+1;
	int rec[t1_len][t2_len];
	char pre[t1_len][t2_len];
	memset(pre,'x',sizeof(pre));
	memset(rec,0,sizeof(rec));
	for(int i = 1;i<t1_len;++i){
		for(int j = 1;j<t2_len;++j){
			if(text2[j-1] == text1[i-1]){
				pre[i][j] = 'd';	// diagonal
				rec[i][j] = rec[i-1][j-1]+1;
			}
			else{
				if(rec[i-1][j] > rec[i][j-1]){
					rec[i][j] = rec[i-1][j];
					pre[i][j] = 'i';	// text1
				}
				else{
					rec[i][j] = rec[i][j-1];
					pre[i][j] = 'j';	// text2
				}
			}
		}
	}
	int end1 = t1_len-1;
	int end2 = t2_len-1;
	vector<string> lcs;
	while(pre[end1][end2] != 'x'){
		if(pre[end1][end2] == 'd'){
			lcs.push_back(text1[end1-1]);
			end1--, end2--;
			continue;
		}
		if(pre[end1][end2] == 'i'){
			end1--;
			continue;
		}
		if(pre[end1][end2] == 'j'){
			end2--;
			continue;
		}
	}
	for(int i = lcs.size()-1;i>=0;--i){
		cout << lcs[i];
		if(i != 0)	cout << " ";
	}
	cout << endl;
}

int main(){
	bool getT1 = false;
	while(getline(cin,input)){
		if(input[0] == '#' && !getT1){
			getT1 = true;
			continue;
		}
		if(input[0] != '#' && !getT1){
			create(1);
			continue;
		}
		if(input[0] != '#' && getT1){
			create(2);
			continue;
		}
		if(input[0] == '#' && getT1){
			LCS();
			text1.clear();
			text2.clear();
			getT1 = false;
			continue;
		}
	}
	return 0;
}
