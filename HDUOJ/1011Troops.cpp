#include <iostream>
#include <vector>
using namespace std;
int dp[105][105]; //在i点有j个人的收益
bool visited[105];
int M, N;
inline int max(int a, int b){
	return a>b?a:b;
}
struct node{
	int bugs;
	int brains;
	vector<int> next;
};
node nodes[105];

void dfs(int cur){										//当前在cur点  注意不需要人数的信息，因为dp的话保留备选方案，所以所有的m全算
	int needed = (nodes[cur].bugs+19)/20;				//上取整的方法 计算出打下这个点的人数
	for(int i=needed;i<=M;i++)							//小于needed肯定是0 已经memset过  在needed到M之间至少可以获得这个点的收益
		dp[cur][i] = nodes[cur].brains;					//这里其实有点重复利用的意思 要高度小心后面的循环顺序
	visited[cur] = true;								//当前点置true dfs常规操作
	for(int i=0;i<(int)nodes[cur].next.size();i++){		//对这个点相邻的点
		if(visited[nodes[cur].next[i]])	continue;		//在这里判断visited不进入比在dfs开头判断少一层递归 更快
		dfs(nodes[cur].next[i]);						//对下面的点dfs 启示本质是计算出dp[nodes[cur].next[i]][*]这一行
		for(int j=M;j>=needed;j--){						//求解这一行 dp[cur][*]	到cur点的时候，人数在M～needed之间
			for(int k=1;k<=j-needed;k++)				//可以派出去打下一个点的人数为k  其实保留下来的人数也就是用来打其他点的人数 这个会随最外层循环更新
				dp[cur][j] = max(dp[cur][j], dp[cur][j-k] + dp[nodes[cur].next[i]][k]); 
				//注意这里的dp[cur][j]也会被最外层（所有相邻点）循环更新 这也是为什么可以把所有的人全都派到这个点的原因，其他每个点都这样算
		}
	}
	//注意并不涉及回溯过程，所以不把visited置false
}


int main(int argc, char *argv[]) {
	int a, b;
	while(scanf("%d%d", &N, &M)&&!(N==-1&&M==-1)){
		memset(visited, 0, sizeof(visited));	//全局性的东西每一轮次要清零
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=N;i++){
			scanf("%d%d", &(nodes[i].bugs), &(nodes[i].brains));
			nodes[i].next.clear();	//注意清零
		}
		for(int i=1;i<N;i++){
			scanf("%d%d", &a, &b);
			nodes[a].next.push_back(b);	//双向边的添加
			nodes[b].next.push_back(a);
		}
		if(M==0)	printf("0\n");	//因为必须有一个人过去，所以即使bug为0 如果没有人一样得不到
		else{
			dfs(1);		//深度优先搜索  此时dp数组填满了 dp[i][j]表示在i点有j个人时的收益
			printf("%d\n", dp[1][M]);	//输出结果 在1点有M个人的收益
		}
	}
}