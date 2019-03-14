#include<iostream>
#include<cstdio>
#include<queue>

struct pos{
	char x;
	int y;
	int move;
};

using namespace std;
int dir[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

int main(){
	char start_x,end_x;
	int start_y,end_y;
	while(scanf("%c%d %c%d\n",&start_x,&start_y,&end_x,&end_y)!=EOF){
		struct pos tmp;
		tmp.x = start_x;
		tmp.y = start_y;
		tmp.move = 0;
		queue<struct pos> cur;
		cur.push(tmp);
		bool found = false;
		int move = 0;
		while(!found){
			if(cur.front().x == end_x && cur.front().y == end_y)	break;
			for(int i = 0;i<8;++i){
				struct pos next;
				next.x = cur.front().x + dir[i][0];
				next.y = cur.front().y + dir[i][1];
				next.move = cur.front().move + 1;
				if(next.x>='a' && next.x<='h' && next.y>=1 && next.y<=8){
					if(next.x == end_x && next.y == end_y){	found = true;	move = next.move;	break;}
					cur.push(next);
				}
			}
			cur.pop();
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",start_x,start_y,end_x,end_y,move);
	}
	return 0;
}
