#include<cstring>
#include<iostream>
#include<climits>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int s[100010]; 
struct Node *root;

struct Node{
	int mini;
	Node *left,*right;
};

struct Node *build(int L,int R){
	struct Node *cur = new struct Node();
	if(L == R){
		cur->mini = s[L];
		return cur;
	}
	int mid = (L+R) >> 1;
	cur->left = build(L,mid);
	cur->right = build(mid+1,R);
	cur->mini = min(cur->left->mini,cur->right->mini);
	return cur;
}

int query(struct Node *cur,int L,int R,int x,int y){
	if(x > R || y < L)
		return INT_MAX;
	if(x <= L && y >= R){
		return cur->mini;
	}
	int mid = (L+R) >> 1;
	return min(query(cur->left,L,mid,x,y),query(cur->right,mid+1,R,x,y));
}

void update(struct Node *cur,int L,int R,int pos,int newVal){
	if(L == R){
		cur->mini = newVal;
		return;
	}
	int mid = (L+R) >> 1;
	if(pos <= mid)
		update(cur->left,L,mid,pos,newVal);
	else
		update(cur->right,mid+1,R,pos,newVal);
	cur->mini = min(cur->left->mini,cur->right->mini);
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i = 1;i<=n;++i)
			scanf("%d",&s[i]);
		root = build(1,n);
		for(int i = 0;i<q;++i){
			getchar();
			char in[5],delim;
			scanf("%c%c%c%c%c%c",&in[0],&in[1],&in[2],&in[3],&in[4],&delim);
			if(in[0] == 'q'){
				int tmp[2];
				char sep1,sep2;
				scanf("%d%c%d%c",&tmp[0],&sep1,&tmp[1],&sep2);
				printf("%d\n",query(root,1,n,tmp[0],tmp[1]));
			}
			else{		// shift
				int tmp[100010],idx = 0;
				char delim;
				while(scanf("%d%c",&tmp[idx++],&delim) == 2)
					if(delim == ')')
						break;
				int pre = s[tmp[0]];
				for(int j = 0;j<idx;++j){
					if(j != idx-1){
						update(root,1,n,tmp[j],s[tmp[j+1]]);
						s[tmp[j]] = s[tmp[j+1]];
						continue;
					}
					update(root,1,n,tmp[j],pre);
					s[tmp[j]] = pre;
				}
			}
		}
	}
	return 0;
}
