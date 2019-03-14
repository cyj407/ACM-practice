#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct Point{
	int x,y;
};

struct Point point[100100],convexHull[100100];

double cross(struct Point p,struct Point a,struct Point b){
	return (a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x);
}

bool cmp(struct Point a,struct Point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int findConvexHull(int n){
	sort(point,point+n,cmp);
	int node = 0;
	for(int i = 0;i<n;++i){
		while(node >= 2 && cross(convexHull[node-2],convexHull[node-1],point[i]) <= 0)
			--node;
		convexHull[node++] = point[i];
	}
	for(int i = n-2,end = node+1;i>=0;--i){
		while(node >= end && cross(convexHull[node-2],convexHull[node-1],point[i]) <= 0)
			--node;
		convexHull[node++] = point[i];
	}
	return node;
}

int main(){
	int cur = 0;
	int case_n = 1;
	string str;
	struct Point tmp[100100];
	while(getline(cin,str)){
		if(str[0] != '\0'){
			int cut = str.find(",");
			string tmp_x = str.substr(0,cut);
			string tmp_y = str.substr(cut+2);
			tmp[cur].x = point[cur].x = atoi(tmp_x.c_str());
			tmp[cur].y = point[cur].y = atoi(tmp_y.c_str());
			++cur;
		}
		else{
			int chNum = findConvexHull(cur);
			int first = -1;
			for(int i = 0;i<cur && first == -1;++i){
				for(int j = 0;j<chNum;++j){
					if(convexHull[j].x == tmp[i].x && convexHull[j].y == tmp[i].y){
						first = j;
						break;
					}
				}
			}
			if(case_n != 1)
				printf("\n");
			for(int i = first;i<chNum;++i){
				printf("%d, %d\n",convexHull[i].x,convexHull[i].y);
			}
			for(int i = 0;i<first;++i){
				printf("%d, %d\n",convexHull[i].x,convexHull[i].y);
			}
			case_n++;
			memset(point,0,sizeof(point));
			memset(convexHull,0,sizeof(convexHull));
			memset(tmp,0,sizeof(tmp));
			cur = 0;
		}
	}
	return 0;
}
