//
//  main.c
//  list3
//
//  Created by shidingyuan on 2017/9/27.
//  Copyright © 2017年 Shi Dingyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//link list
struct Lnode{
    int val;
    struct Lnode *next;
};

//double link list
struct DLnode{
    int val;
    struct DLnode *next,*pre;
};

//ploymer list
struct Ploy{
    int exp;
    float coeff;
    struct Ploy* next;
};

//typedef of the three structs
typedef struct Lnode lnode;
typedef struct DLnode dnode;
typedef struct Ploy pnode;


//DeleteByCountFunnction
lnode* DeleteByCount(lnode*l1,int countNum){
    int count = 1;
    lnode* current;
    current  = l1;
    //这个问题的核心是l1可能会丢 所以全程用current
    while(current->next!=current){
        if(count ==6){
            //到6就处理可以少用一个记录指针
            current->next = current->next->next;
            count = 1;
            current = current->next;
        }
        else{
            count++;
            current = current->next;
        }
    }
    //必须返回current 而不是l1
    return current;
}


//insert according to pre
void insertByPre(dnode*dn,int num){
    dnode* trans;
    trans  =(dnode*)malloc(sizeof(dnode));
    trans->val = num;
    trans->next = dn->next;
    trans->pre = dn;
    //注意尾部可能导致的越界访问
    if(dn->next!=NULL){
        dn->next->pre = trans;
    }
    dn->next = trans;
}


//delete according to pre
void deleteByPre(dnode*dn){
    if(dn->next!=NULL){
        dn->next->pre = dn->pre;
    }
    dn->pre->next = dn->next;
    free(dn);
}


//add two ploys
pnode* add2ploys(pnode*p1,pnode*p2){
    //注意保留头
    //不要贸然让p = p->next 尤其当next悬空的时候
    //循环一般从开空间开始
    //上面的声明中 p3是头，phead是变化的
    pnode *p3,*phead;
    //第一次特殊处理
    phead = (pnode*)malloc(sizeof(pnode));
    phead->exp = p1->exp<p2->exp?p1->exp:p2->exp;
    phead->coeff = phead->exp==p1->exp?p1->coeff:p2->coeff;
    if(phead->exp==p1->exp)
        p1 = p1->next;
    else
        p2 = p2->next;
    p3 = phead;
    while(p1!=NULL&&p2!=NULL){
        //指数较小的先放
        if(p1->exp<p2->exp){
            phead->next = (pnode*)malloc(sizeof(pnode));
            phead = phead->next;
            phead->exp = p1->exp;
            phead->coeff = p1->coeff;
            p1 = p1->next;
            
        }
        else if(p1->exp>p2->exp){
            phead->next = (pnode*)malloc(sizeof(pnode));
            phead = phead->next;
            phead->exp = p2->exp;
            phead->coeff = p2->coeff;
            p2 = p2->next;
            
        }
        //指数相等做加法
        else{
            //加为0，则不填充
            if(fabs(p1->coeff+p2->coeff)<1e-5){
                p1 = p1->next;
                p2 = p2->next;
            }
            //不为0填充，而且p1，p2都前进
            else{
                phead->next = (pnode*)malloc(sizeof(pnode));
                phead = phead->next;
                phead->coeff = p1->coeff+p2->coeff;
                phead->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
                
            }
        }
    }
    //当有一条走到头，跳出循环，p3尾部接上较长的一条
    phead->next = p1?p1:p2;
    return p3;
}
int main(int argc, const char * argv[]) {
    

    //******************PART I CIRCUIT******************
    //use file to create a link list
    FILE *fp;
    //open file for Lnode (circuit)
    fp = fopen("a.txt","r+");
    lnode *l1,*ltemp;
    
    //***********begin to create**********
    l1 = (lnode*)malloc(sizeof(lnode));
    fscanf(fp,"%d",&(l1->val));
    ltemp = l1;
    //更适合用尾插法
    while(!feof(fp)){
        
        ltemp->next = (lnode*)malloc(sizeof(lnode));
        ltemp = ltemp->next;
        fscanf(fp,"%d",&(ltemp->val));
    }
    ltemp->next = l1;
    fclose(fp);
    //************create ended****************
    
    //test 这里有点小细节 一次循环貌似不能完全输出
    ltemp = l1;
    while(ltemp->next!=l1){
        //体会这里的判断条件和函数里有何不同（l1的存在性问题，与ltemp自增,此时节点不减少，不可能出现ltemp->next==ltemp）
        printf("%d",ltemp->val);
        ltemp = ltemp->next;
    }
    
    //调用数数删除函数
    l1 = DeleteByCount(l1,7);
    //显示还剩下谁
    printf(" %d ",l1->val);
    //确定只剩下一个
    printf("%d\n",l1->next->val);
    //********************END OF PART I*******************
    
    
    //******************PART II DoubleLINK****************
    //open file for Dlink
    fp = fopen("a.txt","r+");
    dnode *d1 ,*dtemp;
    
    //*******begin to create*********
    d1 = (dnode*)malloc(sizeof(dnode));
    fscanf(fp,"%d",&(d1->val));
    d1->pre = NULL;
    dtemp = d1;
    //更适合用尾插法
    while(!feof(fp)){
        
        dtemp->next = (dnode*)malloc(sizeof(dnode));
        dtemp->next->pre = dtemp; //画重点
        fscanf(fp,"%d",&(dtemp->next->val));
        dtemp = dtemp->next;
    }
    dtemp->next = NULL;
    fclose(fp);
    //*******create ended************
    
    //test
    dtemp=d1;
    while(dtemp!=NULL){
        printf("%d ",dtemp->val);
        dtemp = dtemp->next;
    }
    //insert according to pre
    insertByPre(d1->next->next->next,12);
    //test
    dtemp=d1;
    printf("\n");
    while(dtemp!=NULL){
        printf("%d ",dtemp->val);
        dtemp = dtemp->next;
    }
    //delete according to pre
    deleteByPre(d1->next->next->next);
    //test
    dtemp=d1;
    printf("\n");
    while(dtemp!=NULL){
        printf("%d ",dtemp->val);
        dtemp = dtemp->next;
    }
    //******************END OF PART II*****************
    
    
    //****************PART III PLOY********************
    //open a NEW file
   
    pnode *p1,*p2,*ptemp;
    //*********begin to create***********
    //****p1*****
    fp = fopen("b.txt","r+");
    p1 = (pnode*)malloc(sizeof(pnode));
    fscanf(fp,"%d",&(p1->exp));
    fscanf(fp,"%f",&(p1->coeff));
    ptemp = p1;
    while(!feof(fp)){
        ptemp->next = (pnode*)malloc(sizeof(pnode));
        ptemp = ptemp->next;
        fscanf(fp,"%d",&(ptemp->exp));
        fscanf(fp,"%f",&(ptemp->coeff));
    }
    ptemp->next = NULL;
    fclose(fp);
    
    //******p2********
     fp = fopen("b2.txt","r+");
    p2 = (pnode*)malloc(sizeof(pnode));
    fscanf(fp,"%d",&(p2->exp));
    fscanf(fp,"%f",&(p2->coeff));
    ptemp = p2;
    while(!feof(fp)){
        ptemp->next = (pnode*)malloc(sizeof(pnode));
        ptemp = ptemp->next;
        fscanf(fp,"%d",&(ptemp->exp));
        fscanf(fp,"%f",&(ptemp->coeff));
    }
    ptemp->next = NULL;
    //*********end of create*************
    //test
    ptemp=p1;
    printf("\n");
    while(ptemp!=NULL){
        printf("%.2f",ptemp->coeff);
        printf("x%d ",ptemp->exp);
        ptemp = ptemp->next;
    }
    
    ptemp=p2;
    printf("\n");
    while(ptemp!=NULL){
        printf("%.2f",ptemp->coeff);
        printf("x%d ",ptemp->exp);
        ptemp = ptemp->next;
    }
    
    //add two ploy
    pnode* p3;
    p3 = add2ploys(p1,p2);
    //test
    ptemp=p3;
    printf("\n");
    while(ptemp!=NULL){
        printf("%.2f",ptemp->coeff);
        printf("x%d ",ptemp->exp);
        ptemp = ptemp->next;
    }
    //***************END OF PART III*****************
    
    
    return 0;
}



