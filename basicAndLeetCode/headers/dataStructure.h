//
//  dataStructure.h
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef dataStructure_h
#define dataStructure_h
#include "stdHeader.h"
// union set
struct unionNode{
    int id;
    struct unionNode* parent;
    int h;
};
struct unionNode* createSet(int id);
struct unionNode* findSet(struct unionNode* x);
void uni2sets(struct unionNode* x, struct unionNode* y);

//priority queue
struct pqueue{
    int* vals;
    int* ids;
    int* index;
    int maxSize;
    int eleNum;
};
struct pqueue* createQ(int maxSize);
void insertQ(int val, int id, struct pqueue* Q);
int* extractQ(struct pqueue* Q);
void decVal(struct pqueue* Q, int newVal, int id);

#endif /* dataStructure_h */
