#include <cstdio>
#include <stack>
using namespace std;
int step[50]; //1 denote in 2 denote out	
int scnt;

//火车栈模拟  差点误入歧途  但最后自己想出来了
int main(int argc, char *argv[]) {
	int n;
	int o1[15];
	int o2[15];
	int tag1, tag2;
	char t;
	while(scanf("%d", &n)!=EOF){
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c", &t);
			o1[i] = t-'0';
		}
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c", &t);
			o2[i] = t-'0';
		}
		stack<int> stk;
		scnt = 0;
		tag2 = 0;
		for(tag1=0;tag1<n;tag1++){
			stk.push(o1[tag1]);
			step[scnt++] = 1;
			while(!stk.empty()&&stk.top()==o2[tag2]){
				tag2++;
				stk.pop();
				step[scnt++] = 2;
			}
		}
		if(!stk.empty())	printf("No.\nFINISH\n");
		else{
			printf("Yes.\n");
			for(int i=0;i<scnt;i++){
				if(step[i]==1)	printf("in\n");
				else printf("out\n");
			}
			printf("FINISH\n");
		}
	}
}