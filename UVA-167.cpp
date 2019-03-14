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
	int case_n;
	scanf("%d",&case_n);
	method(0);
	while(case_n-- > 0){
		int board[8][8];
		for(int i = 0;i<8;++i){
			for(int j = 0;j<8;++j){
				scanf("%d",&board[i][j]);
			}
		}
		int max = 0;
		for(int i = 0;i<100;++i){
			int sum = 0;
			for(int j = 0;j<8;++j){
				sum += board[j][ans[i][j]];
			}
			if(sum > max){
				max = sum;
			}
		}
		printf("%5d\n",max);
	}
	return 0;
}
