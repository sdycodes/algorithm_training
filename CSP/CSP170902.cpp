#include <iostream>
#include <queue>
using namespace std;
struct Event{
	int type;	//0-还  1-取
	int number; //钥匙号
	int time;	//发生时间
	Event(int type, int number, int time):type(type), number(number), time(time){}
	friend bool operator<(Event a, Event b){
		if(a.time!=b.time){
			return a.time>b.time;
		}
		else{
			if(a.type!=b.type){
				return a.type>b.type;
			}
			else{
				return a.number>b.number;
			}
		}
	}
};
int pos[1005];
int main(int argc, char *argv[]) {
	int N, K;
	priority_queue<Event> q;
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		pos[i] = i;
	}
	int w,s,c;
	for(int i=1;i<=K;i++){
		cin>>w>>s>>c;
		q.push(Event(1, w, s));
		q.push(Event(0, w, s+c));
	}
	while(!q.empty()){
		Event e = q.top();
		q.pop();
		if(e.type==0){
			for(int i=1;i<=N;i++){
				if(pos[i]==0){
					pos[i] = e.number;
					break;
				}
			}
		}
		else{
			for(int i=1;i<=N;i++){
				if(pos[i]==e.number){
					pos[i] = 0;
					break;
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		cout<<pos[i]<<" ";
	}
}