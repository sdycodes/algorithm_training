#include<iostream>
#include<queue>
using namespace std;
 
int v[10][10] = {0};
int d[10][10] = {0};
int m,n;
 
int nx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int ny[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
 
int BFS(int x, int y)
{
	queue<int> que;
	que.push(x*8+y);
 	d[x][y] = 0;
	while (que.size() > 0)
	{
		int cur = que.front();
		que.pop();
		int first = cur / 8;
		int second = cur % 8;
		if (first == m && second == n)
			return d[first][second];
 		
		for (int i = 0; i < 8; i++)
		{
			int next_x = first + nx[i];
			int next_y = second + ny[i];
			if (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8 && v[next_x][next_y] == 0)
			{
				que.push(next_x*8 + next_y);
				d[next_x][next_y] = 1 + d[first][second];
				v[next_x][next_y] = 1;
			}
		}
	}
}
 
int main()
{
	int i,j,x,y;
	char a[5],b[5]; 
	while(cin >> a >> b)
	{
		for(i = 0; i < 10; i++)
			for(j = 0; j < 10; j++) {
				v[i][j] = 0;
				d[i][j] = 0;
			}
		
		x = a[0] - 'a';
		y = a[1] - '0' - 1;
		m = b[0] - 'a';
		n = b[1] - '0' - 1;
		
		int steps = BFS(x, y);
 
		cout << "It takes " << steps << " steps to get from " << a << " to " << b << endl;
	}
	return 0;
}