#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int dir[6][2] = { {0,-1},{1,0},{1,1},{0,1},{-1,0},{-1,-1} };

int main(){
	int n, case_num = 1;
	while(scanf("%d",&n)!=EOF && n!=0){
		char board[n+1][n+1];		// read '\0'
		for(int j = 0;j<=n;++j){
			for(int i = 0;i<=n;++i)	board[i][j] = 'b';
		}// initial all point are black
		for(int j = 1;j<=n;++j){
			getchar();
			for(int i = 1;i<=n;++i)	scanf("%c",&board[i][j]);
		}// start from (1,1)
		int mark[n+1][n+1];
		for(int j = 0;j<=n;++j){
			for(int i = 0;i<=n;++i){
				if(board[i][j] == 'w')	mark[i][j] = 0;	// 0 can walk
				else	mark[i][j] = 1;	// 1 can't walk
			}
		}
	/*	for(int j = 1;j<=n;++j){
			for(int i = 1;i<=n;++i)	printf("%d",mark[i][j]);
			cout << endl;
		}*/
		char winner = 'B';
		int row = 1;
		stack<int> pos_x,pos_y;
		while(row <= n && winner !='W'){
			if(mark[1][row] == 1){	row++;	continue;}	// dead road
			else{
				pos_x.push(1);	pos_y.push(row++);	// row+1 to find next start
				while(!pos_x.empty() && !pos_y.empty()){
					int noRoad = 0;
					if(pos_x.top() == n){	winner = 'W';	break;}
					for(int i = 0;i<6;++i){
						int next_x = pos_x.top() + dir[i][0];
						int next_y = pos_y.top() + dir[i][1];
						if(mark[next_x][next_y] == 1 || next_x > n || next_y > n){
							noRoad++;	continue;
						}
						if(next_x > 0 && next_y > 0){
							if(mark[next_x][next_y] == 0){
								pos_x.push(next_x);
								pos_y.push(next_y);
								mark[next_x][next_y] = 1;
								break;
							}							
						}
					}//	try all direction
					if(noRoad == 6){	pos_x.pop();	pos_y.pop();}
				}
			}
		}
		printf("%d %c\n",case_num++,winner);
	}
	return 0;
}
