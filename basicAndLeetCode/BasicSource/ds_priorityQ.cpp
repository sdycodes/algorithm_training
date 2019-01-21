//
//  ds_priorityQ.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "dataStructure.h"

struct pqueue* createQ(int maxSize){
    struct pqueue* Q;
    Q = (struct pqueue*)malloc(sizeof(struct pqueue));
    Q->maxSize = maxSize;
    Q->eleNum = 0;
    Q->ids = (int*)malloc(sizeof(int)*maxSize);
    Q->vals = (int*)malloc(sizeof(int)*maxSize);
    Q->index = (int*)malloc(sizeof(int)*maxSize);
    return Q;
}
void insertQ(int val, int id, struct pqueue* Q){
    (Q->vals)[Q->eleNum++] = val;
    (Q->ids)[Q->eleNum-1] = id;
    (Q->index)[id] = Q->eleNum-1;
    int i = Q->eleNum-1, tmp;
    while(i>0&&(Q->vals)[i]<(Q->vals)[(i-1)>>1]){
        swap((Q->vals)[(i-1)>>1], (Q->vals)[i])
        swap((Q->ids)[(i-1)>>1], (Q->ids)[i])
        (Q->index)[(Q->ids)[(i-1)>>1]] = (i-1)>>1;
        (Q->index)[(Q->ids)[i]] = i;
        i = (i-1)>>1;
    }
}

int* extractQ(struct pqueue* Q){
    int *min, tmp;
    min = (int*)malloc(sizeof(int)*2);
    min[0] = (Q->vals)[0];
    min[1] = (Q->ids)[0];
    (Q->vals)[0] = (Q->vals)[--Q->eleNum];
    (Q->ids)[0] = (Q->ids)[Q->eleNum];
    (Q->index)[Q->ids[0]] = 0;
    int i = 0;
    while(i<Q->eleNum){
        if((2+(i<<1)<Q->eleNum &&
            Q->vals[2+(i<<1)]>Q->vals[1+(i<<1)]&&
            Q->vals[i]>Q->vals[1+(i<<1)])||
           (2+(i<<1)>=Q->eleNum &&
            1+(i<<1)<Q->eleNum &&
            Q->vals[i] > Q->vals[1+(i<<1)])
           ){
            swap(Q->vals[i], Q->vals[1+(i<<1)])
            swap(Q->ids[i], Q->ids[1+(i<<1)])
            (Q->index)[(Q->ids)[1+(i<<1)]] = 1+(i<<1);
            (Q->index)[(Q->ids)[i]] = i;
            i = 1+(i<<1);
        }
        else if(2+(i<<1)<Q->eleNum &&
                Q->vals[2+(i<<1)]<Q->vals[1+(i<<1)]&&
                Q->vals[2+(i<<1)]<Q->vals[i]){
            swap(Q->vals[i], Q->vals[2+(i<<1)])
            swap(Q->ids[i], Q->ids[2+(i<<1)])
            (Q->index)[(Q->ids)[2+(i<<1)]] = 2+(i<<1);
            (Q->index)[(Q->ids)[i]] = i;
            i = 2+(i<<1);
        }
        else
            break;
    }
    return min;
}
void decVal(struct pqueue* Q, int newVal, int id){
    int index = (Q->index)[id];
    (Q->vals)[index] = newVal;
    int i = index, tmp;
    while(i>0&&(Q->vals)[i]<(Q->vals)[(i-1)>>1]){
        swap((Q->vals)[(i-1)>>1], (Q->vals)[i])
        swap((Q->ids)[(i-1)>>1], (Q->ids)[i])
        (Q->index)[(Q->ids)[(i-1)>>1]] = (i-1)>>1;
        (Q->index)[(Q->ids)[i]] = i;
        i = (i-1)>>1;
    }
}
