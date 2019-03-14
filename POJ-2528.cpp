#include<cstring>
#include<climits>
#include<cstdio>
#include<algorithm>

using namespace std;
int s[20100]; 
struct Node *root;
int ans_max = INT_MIN, ans_min = INT_MAX;

struct Node{
	int l_bound,r_bound;
	bool isCovered;
	Node *left,*right;
};

struct Node *build(int L,int R){
	struct Node *cur = new struct Node();
	if(L == R){
		cur->mini = cur->maxi = s[L];
		return cur;
	}
	int mid = (L+R) >> 1;
	cur->left = build(L,mid);
	cur->right = build(mid+1,R);

	cur->mini = min(cur->left->mini,cur->right->mini);
	cur->maxi = max(cur->left->maxi,cur->right->maxi);
	return cur;
}

void query(struct Node *cur,int L,int R,int x,int y){
	if(x > R || y < L)
		return;
	if(x <= L && y >= R){
		ans_min = min(ans_min,cur->mini);
		ans_max = max(ans_max,cur->maxi);
		return;
	}
	int mid = (L+R) >> 1;
	query(cur->left,L,mid,x,y);
	query(cur->right,mid+1,R,x,y);
}

int main(){
	int case_n;
	scanf("%d",&case_n);
	while(case_n--){
		int n;
		scanf("%d",&n);
		for(int i = 1;i<=n;++i)
			scanf("%d%d",&node[i].l_bound,&node[i].r_bound);
		root = build(1,n);
		for(int i = 0;i<q;++i){
			ans_max = INT_MIN, ans_min = INT_MAX;
			int lb,ub;
			scanf("%d%d",&lb,&ub);
			query(root,1,n,lb,ub);
		}
		printf("%d\n",ans_max-ans_min);
	}
	return 0;
}
