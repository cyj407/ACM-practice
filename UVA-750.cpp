#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int ans[100][8];
int number[8];	
int total = 0;

void method(int order){
	bool attack;
	if(order == 8){
		for(int i = 0;i<8;++i){
			ans[total][i] = number[i];
		}
		total++;
		return;
	}

	for(int i = 0;i<8;++i){
		attack = false;
		number[order] = i;
		for(int j = 0;j<order;++j){
			if(number[order] == number[j] || number[order]+order == number[j]+j || order-number[order] == j-number[j]){
				attack = true;	break;
			}
		}
		if(!attack){
			method(order+1);
		}
	}

}

int main(){
	int case_n,queen_x,queen_y;
	scanf("%d",&case_n);
	memset(ans,-1,sizeof(ans));
	method(0);
	while(case_n--){
		scanf("%d%d",&queen_x,&queen_y);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		int solu[100][8],sol = 0;
		for(int i = 0;i<100;++i){
			if(ans[i][queen_y-1] == queen_x-1){
				for(int j = 0;j<8;++j){
					solu[sol][j] = ans[i][j];
				}
				sol++;
			}
		}
		for(int i = 0;i<sol;++i){
			printf("%2d      ",i+1);	// solution num
			for(int j = 0;j<8;++j){
				cout << solu[i][j]+1;
				if(j!= 7)	cout << " ";
			}
			cout << endl;
		}
		if(case_n != 0)	cout << endl;
	}
	return 0;
}
