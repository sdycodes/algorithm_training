#include <iostream>

using namespace std;
struct Node{
	int val;
	struct Node* next,*pre;
	Node(int val, Node* next, Node* pre):val(val), next(next), pre(pre){}
};
int main(int argc, char *argv[]) {
	int n, m;
	cin>>n>>m;
	Node *head, *tmp;
	head = new Node(0, NULL, NULL);
	for(int i=n;i>=1;i--){
		tmp = new Node(i, head, NULL);
		head->pre = tmp;
		head = tmp;
	}
	for(int i=1;i<=m;i++){
		int p, q;
		cin>>p>>q;
		for(tmp=head;tmp->val;tmp = tmp->next){
			if(tmp->val==p)
				break;
		}
		Node *tar = tmp;
		if(q>0){
			while(q--){
				tar = tar->next;
			}
			tar = tar->next; //统一插到tar的前面 因为最后一个哨兵 所以更方便
		}
		else if(q<0){
			while(q++){
				tar = tar->pre;
			}
		}
		if(!tmp->pre)
			head = tmp->next;
		if(!tar->pre)
			head = tmp;
		if(tmp->pre)
			tmp->pre->next = tmp->next;
		if(tmp->next)
			tmp->next->pre = tmp->pre;
		tmp->next = tar;
		tmp->pre = tar->pre;
		tar->pre = tmp;
		if(tmp->pre)
			tmp->pre->next = tmp;
	}
	for(tmp=head;tmp->val;tmp=tmp->next){
		cout<<tmp->val<<" ";
	}
	return 0;
}