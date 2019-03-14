#include<cstdio>
#include<algorithm>

using namespace std;

struct Point{
	double x,y;
};

struct Segment{
	Point st,end;
};

double cross(struct Point p,struct Point a,struct Point b){
	return (a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x);
}

bool inRect(struct Point point,struct Point rect_st,struct Point rect_end){
	if((point.x >= rect_st.x) && (point.x <= rect_end.x))
		if((point.y >= rect_end.y) && (point.y <= rect_st.y))
			return true;
	return false;
}

bool onLine(struct Segment segment,struct Point p){
	double min_x = min(segment.st.x,segment.end.x);
	double min_y = min(segment.st.y,segment.end.y);
	double max_x = max(segment.st.x,segment.end.x);
	double max_y = max(segment.st.y,segment.end.y);
	if(p.x >= min_x && p.x <= max_x && p.y >= min_y && p.y <= max_y)
		if((segment.st.x-segment.end.x)*(p.y-segment.st.y) == (segment.st.y-segment.end.y)*(p.x-segment.st.x))
			return true;
	return false;
}

bool intersect(struct Segment segment,struct Segment rectEdge){
	if(cross(rectEdge.st,rectEdge.end,segment.st)*cross(rectEdge.st,rectEdge.end,segment.end) < 0\
	&& cross(rectEdge.end,rectEdge.st,segment.st)*cross(rectEdge.end,rectEdge.st,segment.end) < 0\
	&& cross(segment.st,segment.end,rectEdge.st)*cross(segment.st,segment.end,rectEdge.end) < 0\
	&& cross(segment.end,segment.st,rectEdge.st)*cross(segment.end,segment.st,rectEdge.end) < 0){
		return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		Point tmp1,tmp2,leftTop,leftDown,rightTop,rightDown;
		Segment seg,left,right,top,down;
		scanf("%lf%lf%lf%lf",&seg.st.x,&seg.st.y,&seg.end.x,&seg.end.y);
		scanf("%lf%lf%lf%lf",&tmp1.x,&tmp1.y,&tmp2.x,&tmp2.y);
		leftTop.x = leftDown.x = min(tmp1.x,tmp2.x);
		leftTop.y = rightTop.y = max(tmp1.y,tmp2.y);
		rightDown.x = rightTop.x = max(tmp1.x,tmp2.x);
		rightDown.y = leftDown.y = min(tmp1.y,tmp2.y);
		left.st = leftTop, left.end = leftDown;
		right.st = rightTop, right.end = rightDown;
		top.st = leftTop, top.end = rightTop;
		down.st = leftDown, down.end = rightDown;
		if(inRect(seg.st,leftTop,rightDown)||inRect(seg.end,leftTop,rightDown))
			printf("T\n");
		else if(intersect(seg,left)||intersect(seg,right)||intersect(seg,top)||intersect(seg,down))
			printf("T\n");
		else if(onLine(seg,leftDown)||onLine(seg,rightTop)||onLine(seg,rightDown)||onLine(seg,leftTop))
			printf("T\n");
		else
			printf("F\n");
	}
	return 0;
}
