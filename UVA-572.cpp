#include<iostream>
#include<cstdio>
#include<stack>

int dir[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };

using namespace std;

int main(){
	int x_length,y_length, case_num = 1;
	while(scanf("%d%d",&x_length,&y_length)!=EOF && x_length!=0){
		char board[x_length+1][y_length+1];
		for(int i = 0;i<=x_length;++i){
			for(int j = 0;j<=y_length;++j)	board[i][j] = '*';
		}// intialize
		for(int j = 1;j<=x_length;++j){
			getchar();	// read \n
			for(int i = 1;i<=y_length;++i)	scanf("%c",&board[j][i]);
		}// start from (1,1)
		char mark[x_length+1][y_length+1];
		for(int i = 0;i<=x_length;++i){
			for(int j = 0;j<=y_length;++j){
				if(board[i][j] == '*')	mark[i][j] = '*';
				else	mark[i][j] = '@';
			}
		}
		int oil_n = 0;
		for(int i = 1;i<=x_length;++i){
			for(int j = 0;j<=y_length;++j){

				stack<int> oil_x,oil_y;
				if(mark[i][j] == '*')	continue;
				else{
					oil_x.push(i);	oil_y.push(j);
					while(!oil_x.empty() && !oil_y.empty()){
						int noFind = 0;
						for(int k = 0;k<8;++k){
							int next_x = oil_x.top() + dir[k][0];
							int next_y = oil_y.top() + dir[k][1];
							if(next_x > 0 && next_y > 0 && next_x <= x_length && next_y <= y_length){
								if(mark[next_x][next_y] != '@')	noFind++;
								else{
									oil_x.push(next_x);
									oil_y.push(next_y);
									mark[next_x][next_y] = '*';
								}
							}
							else	noFind++;
						}
						if(noFind == 8){	oil_x.pop();	oil_y.pop();}
					}
					oil_n++;
				}

			}
		}
		printf("%d\n",oil_n);
	}
	return 0;
}

