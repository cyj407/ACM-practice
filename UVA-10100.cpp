#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
#include<cctype>

using namespace std;
int case_n = 1;
string str1,str2;
vector<string> text1,text2;

void create(int n){
	string input = (n == 1)?str1:str2;
	int length = 0, word_st = 0;
	for(int j = 0;j<input.length();++j){
		if(isalpha(input[j]) || isdigit(input[j])){
			length++;
			continue;
		}
		if(!isalpha(input[j]) && !isdigit(input[j])){
			if(length != 0){
				string word = input.substr(word_st,length);
				if(n == 1)
					text1.push_back(word);
				if(n == 2)
					text2.push_back(word);
			}
			length = 0;
			word_st = j+1;
		}
	}
	if(length != 0){
		string word = input.substr(word_st,length);
		if(n == 1)
			text1.push_back(word);
		if(n == 2)
			text2.push_back(word);
	}
}

void LCS(){
	create(1);
	create(2);
	int t1_len = text1.size()+1;
	int t2_len = text2.size()+1;
	int rec[t1_len][t2_len];
	memset(rec,0,sizeof(rec));
	for(int i = 1;i<t1_len;++i){
		for(int j = 1;j<t2_len;++j){
			if(text2[j-1] == text1[i-1])
				rec[i][j] = rec[i-1][j-1]+1;
			else{
				if(rec[i-1][j] > rec[i][j-1])
					rec[i][j] = rec[i-1][j];
				else
					rec[i][j] = rec[i][j-1];
			}
		}
	}
	printf("%2d. Length of longest match: %d\n",case_n++,rec[t1_len-1][t2_len-1]);
}

int main(){
	while(getline(cin,str1)){
		getline(cin,str2);
		if(str1[0] == '\0' || str2[0] == '\0'){
			printf("%2d. Blank!\n",case_n++);
			continue;
		}
		LCS();
		text1.clear();
		text2.clear();
	}
	return 0;
}
