#include<cstdio>
#include<cstring>

using namespace std;
bool isCovered[210][210];

bool overlap(int lx,int ly,int rx,int ry){
	for(int i = lx;i<rx;++i)
		for(int j = ly;j<ry;++j)
			if(isCovered[i][j])
				return true;
	return false;
}

int main(){
	int case_n,ca = 0;
	scanf("%d",&case_n);
	while(case_n--){
		int ans = 0, n;
		scanf("%d",&n);
		memset(isCovered,false,sizeof(isCovered));
		for(int k = 0;k<n;++k){
			int lx,rx,ly,ry;
			scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
			lx+= 100, ly+=100, rx+=100, ry+=100;
			if(k == 0 || !overlap(lx,ly,rx,ry)){
				int area = (rx-lx)*(ry-ly);
				ans += area;
				for(int i = lx;i<rx;++i)
					for(int j = ly;j<ry;++j)
						isCovered[i][j] = true;
			}
		}
		printf("Case %d: %d\n",++ca,ans);
	}
	return 0;
}
