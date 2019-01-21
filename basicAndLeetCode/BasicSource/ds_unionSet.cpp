//
//  ds_unionSet.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "dataStructure.h"

struct unionNode* createSet(int id){
    struct unionNode* x;
    x = (struct unionNode*)malloc(sizeof(struct unionNode));
    x->id = id;
    x->parent = x;
    x->h = 1;
    return x;
}
struct unionNode* findSet(struct unionNode* x){
    while(x->parent!=x)
        x = x->parent;
    return x;
}
void uni2sets(struct unionNode* x, struct unionNode* y){
    struct unionNode* a = findSet(x);
    struct unionNode* b = findSet(y);
    if(a->h<=b->h){
        if(a->h==b->h)
            b->h++;
        a->parent = b;
    }
    else
        b->parent = a;
}
