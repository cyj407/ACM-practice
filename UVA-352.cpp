#include<iostream>
#include<cstdio>
#include<stack>

int dir[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };

using namespace std;

int main(){
	int n, case_num = 1;
	while(scanf("%d",&n)!=EOF){
		char board[n+1][n+1];
		for(int i = 0;i<=n;++i){
			for(int j = 0;j<=n;++j)	board[i][j] = '0';
		}// intialize
		for(int j = 1;j<=n;++j){
			getchar();	// read \n
			for(int i = 1;i<=n;++i)	scanf("%c",&board[j][i]);
		}// start from (1,1)
		char mark[n+1][n+1];
		for(int i = 0;i<=n;++i){
			for(int j = 0;j<=n;++j){
				if(board[i][j] == '0')	mark[i][j] = 'N';
				else	mark[i][j] = 'Y';
			}
		}
		int eagle_n = 0;
		for(int i = 1;i<=n;++i){
			for(int j = 0;j<=n;++j){

				stack<int> eag_x,eag_y;
				if(mark[i][j] == 'N')	continue;
				else{
					eag_x.push(i);	eag_y.push(j);
					while(!eag_x.empty() && !eag_y.empty()){
						int noFind = 0;
						for(int k = 0;k<8;++k){
							int next_x = eag_x.top() + dir[k][0];
							int next_y = eag_y.top() + dir[k][1];
							if(next_x > 0 && next_y > 0 && next_x <= n && next_y <= n){
								if(mark[next_x][next_y] == 'Y'){
									eag_x.push(next_x);
									eag_y.push(next_y);
									mark[next_x][next_y] = 'N';
								}
								else	noFind++;
							}
							else	noFind++;
						}
						if(noFind == 8){	eag_x.pop();	eag_y.pop();}
					}
					eagle_n++;
				}

			}
		}
		printf("Image number %d contains %d war eagles.\n",case_num++,eagle_n);
	}
	return 0;
}
