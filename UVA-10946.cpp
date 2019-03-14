#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

struct rec{
	char alp;
	int total;
};

struct point{
	int r,c;
};

bool cmp(struct rec r1,struct rec r2){
	if(r1.total == r2.total)	return r1.alp < r2.alp;
	else	return r1.total > r2.total;
}

using namespace std;

int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int main(){
	int row,col,prob = 1;
	while(scanf("%d%d",&row,&col)!=EOF && row+col!=0){
		char m[row+1][col+1];
		for(int i = 1;i<=row;++i){
			getchar();
			for(int j = 1;j<=col;++j)	scanf("%c",&m[i][j]);
		}
		char mark[row+1][col+1];
		for(int i = 0;i<=row;++i){
			for(int j = 0;j<=col;++j){
				if(i == 0 || j == 0)	mark[i][j] = '.';
				else	mark[i][j] = m[i][j];
			}
		}
		
		vector<struct rec> all;

		struct rec cur;
		for(int i = 1;i<=row;++i){
			for(int j = 1;j<=col;++j){
				if(mark[i][j] == '.')	continue;
				else{
					cur.alp = mark[i][j];
					cur.total = 1;
					mark[i][j] = '.';
				}
				queue<struct point> count;
				struct point first;
				first.r = i;	first.c = j;
				count.push(first);
				while(!count.empty()){
					int noEqu = 0;	// not equal alphet
					for(int k = 0;k<4;++k){
						int next_r = count.front().r + dir[k][0];
						int next_c = count.front().c + dir[k][1];
						if(next_r > 0 && next_r <= row && next_c > 0 && next_c <= col){
							if(cur.alp != mark[next_r][next_c])	noEqu++;
							else{	
								cur.total++;
								struct point tmp;
								tmp.r = next_r;	tmp.c = next_c;
								count.push(tmp);
								mark[next_r][next_c] = '.';
							}
						}
						else	noEqu++;
					}
					if(noEqu == 4)	count.pop();
				}
				all.push_back(cur);
			}
		}
		sort(all.begin(),all.end(),cmp);
		printf("Problem %d:\n",prob++);
		for(int i = 0;i<all.size();++i)	printf("%c %d\n",all[i].alp,all[i].total);
	}
	return 0;
}
