#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

const int SIZE=1000+5;
const int MAX_E=10000*4+100;

struct Edge{
    int st,end,cap,cost;
};

vector<struct Edge> edge;
int pre[SIZE];
int s,t,n,m;
int dis[SIZE];
bool used[SIZE];

bool SPFA(int s,int t){
    queue<int> q;
    memset(used,false,sizeof(used));
    for(int i=0;i<=SIZE;i++)
        dis[i] = 1000000;
    dis[s] = 0;
    que.push(src);
    used[s] = true;
    while(!q.empty()){
        int v = que.front();
        used[v] = false;
        que.pop();
        for(int i = 0;i < e[v].size();++i){
            int y = e[v].at(i).to;
            if(e[v].at(i).cap>0&&dis[y]>dis[v]+e[v].at(i).cost){
                dis[y]=dis[v]+e[v].at(i).cost;
                pre[y]=e[v].at(i).id;
                if(!used[y]){
                    used[y]=true;
                    que.push(y);
				}
            }
        }
    }
    return dis[t] < INF;
}

int MCMF(int s,int t)
{
    int sum = 0;
    while(SPFA(s,t)){
        int minflow = 1000000;
        for(int i=t;i!=s;i = p[i])
            minflow=MIN(minflow,e[e[i].at(pre[i]).to].at(e[i].at(pre[i]).id).cap);
        for(int i=t;i!=s;i=e[i].at(pre[i]).to)
            e[e[i].at(pre[i]).to].at(e[i].at(pre[i]).id).cap -= minflow;
            e[i].at(pre[i]).cap += minflow;
        sum += dis[t]*minflow;
    }
    return sum;
}

int main(){
	int 


	return 0;
}
