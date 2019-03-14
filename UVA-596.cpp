#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
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
		while(node >= 2 && cross(convexHull[node-2],convexHull[node-1],point[i]) < 0)
			--node;
		convexHull[node++] = point[i];
	}
	for(int i = n-2,end = node+1;i>=0;--i){
		while(node >= end && cross(convexHull[node-2],convexHull[node-1],point[i]) < 0)
			--node;
		convexHull[node++] = point[i];
	}
	return node-1;
}

int main(){
	int case_n,cur,prev = 1;
	char first;
	string str = "",prestr;
	while(scanf("%c",&first)!=EOF && first != 'E'){
		if(first == 'P'){
			int pointNum;
			scanf("%d",&pointNum);
			for(int i = 0;i<pointNum;++i,++cur)
				scanf("%d%d",&point[cur].x,&point[cur].y);
		}
		else{
			if(prev != 1){
				cout << prestr << " " << prev << " convex hull:\n";
				int chNum =	findConvexHull(cur);
				for(int i = chNum-1;i>=0;--i)
					printf(" (%d,%d)",convexHull[i].x,convexHull[i].y);
				printf("\n");
			}
			cin >> str >> case_n;
			getchar();
		//	cout << str << " " << case_n << endl;
			prev = case_n, prestr = str;
			cur = 0;
			memset(point,0,sizeof(point));
			memset(convexHull,0,sizeof(convexHull));
		}
	}
	return 0;
}
