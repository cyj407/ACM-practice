#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

struct Tries{
	Tries* next[10];
	bool end;
	Tries(){
		end = false;
		for(int i = 0;i<10;++i)
			next[i] = NULL;
	}
};

int k;
Tries *root;
Tries node[100010];

int add(string s){
	Tries* tmp = root;
	int num;
	for(int i = 0;i<s.length();++i){
		num = s[i] - '0';
		if(tmp->next[num] != NULL){
			if(tmp->next[i]->end)
				return false;
			tmp = tmp->next[num];
		}
		else{
			tmp->next[num] = &node[k++];
			tmp = tmp->next[num];
		}
	}
	tmp->end = true;
	for(int i = 0;i<10;++i)
		if(tmp->next[i])
			return false;
	return true;
}

int main(){
	int case_n;
	scanf("%d",&case_n);
	while(case_n--){
		k = 0;
		memset(node,0,sizeof(node));
		root = &node[k++];
		bool ans = true;
		string in[100010];
		int n;
		scanf("%d\n",&n);
		for(int i = 0;i<n;++i){
			getline(cin,in[i]);
			if(ans)
				ans = add(in[i]);
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
