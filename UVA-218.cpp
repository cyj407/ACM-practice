#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point{
	double x,y;
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
	int pointNum,case_n = 1;
	while(scanf("%d",&pointNum)!=EOF && pointNum){
		memset(point,0,sizeof(point));
		memset(convexHull,0,sizeof(convexHull));
		for(int i = 0;i<pointNum;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		printf("Region #%d:\n",case_n++);
		int chNum = findConvexHull(pointNum);
		double length = 0;
		if(chNum == 1)
			printf("(%.1lf,%.1lf)-",convexHull[0].x,convexHull[0].y);	
		for(int i = chNum-1;i>=0;--i){
			if(i != 0)
				printf("(%.1lf,%.1lf)-",convexHull[i].x,convexHull[i].y);
			else
				printf("(%.1lf,%.1lf)\n",convexHull[i].x,convexHull[i].y);
			if(i != 0){
				length += sqrt(pow(convexHull[i-1].x - convexHull[i].x,2) + \
							pow(convexHull[i].y - convexHull[i-1].y,2));
			}
		}
		printf("Perimeter length = %.2lf\n\n",length);
	}
	return 0;
}
