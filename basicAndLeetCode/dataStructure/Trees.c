//
//  treesTraversal.c
//  Trees
//
//  Created by shidingyuan on 2017/12/27.
//  Copyright © 2017年 Shi Dingyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* left;
    struct node* right;
};
//-----------------BEGIN--------------------------
//递归遍历（先序、中序、后序）
void DLR(struct node * p){
    if(p){
        printf("%3d",p->val);
        DLR(p->left);
        DLR(p->right);
    }
}
void LDR(struct node *p){
    if(p){
        LDR(p->left);
        printf("%3d", p->val);
        LDR(p->right);
    }
}
void LRD(struct node *p){
    if(p){
        LRD(p->left);
        LRD(p->right);
        printf("%3d",p->val);
    }
}

//非递归遍历 先序、中序、后序
void nonDLR(struct node*head){
    struct node* p =head;
    struct node * stack[20];
    int top = 0;
    while(p||top){
        while(p){
            printf("%3d",p->val);
            stack[top++] = p;
            p = p->left;
        }
        if(top){
            p = stack[--top];
            p = p->right;
        }
    }
}
void nonLDR(struct node*head){
    struct node* p =head;
    struct node * stack[20];
    int top = 0;
    while(p||top){
        while(p){
            stack[top++] = p;
            p = p->left;
        }
        if(top){
            p = stack[--top];
            printf("%3d",p->val);
            p = p->right;
        }
    }
}
void nonLRD(struct node*p){
    struct node * stack[20];
    int top = 19;
    struct node * pre = NULL;
    stack[top--] = p;
    while(top!=19){
        p = stack[top+1];
        if((p->left==NULL&&p->right==NULL)||(pre!=NULL&&(p->left==pre||p->right==pre))){
            printf("%3d",p->val);
        //如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，
            //则直接输出该节点，将其出栈，将其设为上一个访问的节点
            pre = stack[++top];
        }
        else{
            //如果不满足上面两种情况,则将其右孩子左孩子依次入栈
            if(p->right!= NULL)
                stack[top--] = p->right;
            if(p->left!= NULL)
                stack[top--] = p->left;
        }
    }
}

//层次遍历
void layer(struct node*p){
    struct node * fifo[20];
    int head = 0,rear = 0;
    fifo[rear++] = p;
    while(head!=rear){
        if(fifo[head]->left!=NULL)
            fifo[rear++] = fifo[head]->left;
        if(fifo[head]->right!=NULL)
            fifo[rear++] = fifo[head]->right;
        printf("%3d", fifo[head]->val);
        head++;
    }
}
//------------------------END---------------------------




int main(int argc, const char * argv[]) {
    struct node*p, *q, *r;
    p = (struct node*)malloc(sizeof(struct node));
    p->val = 1;
    p->left = (struct node*)malloc(sizeof(struct node));
    p->left->val = 4;
    p->right = (struct node*)malloc(sizeof(struct node));
    p->right->val = 6;
    r = p->left;
    q = p->right;
    r->left = (struct node*)malloc(sizeof(struct node));
    r->left->val = 7;
    r->left->left = NULL;
    r->left->right = NULL;
    r->right = (struct node*)malloc(sizeof(struct node));
    r->right->val = 8;
    r->right->left = NULL;
    r->right->right = NULL;
    q->left = (struct node*)malloc(sizeof(struct node));
    q->left->val = 11;
    q->left->left = NULL;
    q->left->right = NULL;
    q->right = (struct node*)malloc(sizeof(struct node));
    q->right->val = 9;
    q->right->left = NULL;
    q->right->right = NULL;
    DLR(p);
    printf("\n");
    LDR(p);
    printf("\n");
    LRD(p);
    printf("\n");
    nonDLR(p);
    printf("\n");
    nonLDR(p);
    printf("\n");
    nonLRD(p);
    printf("\n");
    layer(p);
    return 0;
}
