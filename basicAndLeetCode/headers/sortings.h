//
//  sortings.h
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef sortings_h
#define sortings_h
#include "stdHeader.h"
void bubbleSort(int a[], int numsSize);
int Dpartition(int a[], int begin, int end);
int Tpartition(int a[], int begin, int end);
int RDpartition(int a[], int begin, int end);
int RTpartition(int a[], int begin, int end);
void quickSort(int a[], int begin, int end);
void merge(int a[], int begin, int mid, int end);
void mergeSort(int a[], int begin, int end);
//data structure: heap/priority queue
struct heap{
    int* vals;
    int maxSize;
    int valNum;
};
void insertHeap(int val, struct heap* maxheap);
int extractHeap(struct heap* maxheap);
struct heap* createHeap(int a[], int numsSize);
void heapSort(int a[], int numsSize);
void countingSort(int a[], int numsSize);
void radixSort(int a[], int numsSize);
int Dselection(int a[], int begin, int end, int k);
#endif /* sortings_h */
