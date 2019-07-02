//不知道 发送消息有没有顺序的问题 
#include <iostream>
#include <vector>
#define MAXN 10
using namespace std;

int main(int argc, char *argv[]) {
	freopen("data.in","r",stdin);
	int a[MAXN][11];
	int T, n;
	scanf("%d", &T);
	scanf("%d", &n);
	getchar();
	while(T--) {
		char op;
		int no;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			do {
				scanf("%c%d", &op, &no);
				if (op == 'R') {
					a[i][cnt++] = -1 * no - 1;
				} else {
					a[i][cnt++] = no + 1;
				}
			} while (getchar() == ' ');
			a[i][10] = cnt;
			a[i][9] = 0;
		}
		//循环
		bool mod = true;
		while (mod) {
			vector<int> msgs[MAXN];
			mod = false;
			//所有能发消息的人
			for (int i = 0; i < n; i++) {
				while (a[i][9] < a[i][10] && a[i][a[i][9]] > 0) {
					msgs[a[i][a[i][9]] - 1].push_back(i);
					a[i][9]++;
					mod = true;
				}
			}
			//开始接收消息
			for (int i = 0; i < n; i++) {
				bool mod2 = true;
				//有收到的消息
				while (a[i][9] < a[i][10] && a[i][a[i][9]] < 0 && mod2) {
					mod2 = false;
					for (int j = 0; j < msgs[i].size(); j++) {
						if (-a[i][a[i][9]] - 1 == msgs[i][j]) {
							a[i][9]++;
							mod = true;
							mod2 = true;
							msgs[i].erase(msgs[i].begin() + j);
							break;
						}
					}	
				}
			}
		}
		//check 是否全部结束
		int i;
		for (i =0; i < n; i++) {
			if (a[i][9] != a[i][10]) {
				break;
			}
		}
		if (i == n) {
			printf("0\n");
		} else {
			printf("1\n");
		}
	}
}