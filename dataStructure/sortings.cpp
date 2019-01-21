//
//  sortings.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "sortings.h"


void bubbleSort(int a[], int numsSize){
    int i, j, tmp;
    for(i=0;i<numsSize;i++)
        for(j=i+1;j<numsSize;j++)
            if(a[i]>a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    return;
}

int Dpartition(int a[], int begin, int end){
    int i = begin, j = end, tmp;
    int r = a[begin];
    while(i!=j){
        while(a[j]>=r && i<j)
            j--;
        while(a[i]<=r && i<j)
            i++;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[begin] = a[i];
    a[i] = r;
    return i;
}

int Tpartition(int a[], int begin, int end){
    int r = a[end], tmp;
    int i = begin - 1, j = begin;
    while(j<end){
        if(a[j]<=r){
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        j++;
    }
    a[end] = a[i+1];
    a[i+1] = r;
    return i+1;
}

int RDpartition(int a[], int begin, int end){
    int randp = rand()%(end-begin+1) + begin;
    int tmp = a[randp];
    a[randp] = a[end];
    a[end] = tmp;
    return Dpartition(a, begin, end);
}

int RTpartition(int a[], int begin, int end){
    int randp = rand()%(end-begin+1) + begin;
    int tmp = a[randp];
    a[randp] = a[end];
    a[end] = tmp;
    return Tpartition(a, begin, end);
}

void quickSort(int a[], int begin, int end){
    if(begin<end){
        //choose solution of pivot here
        int mid = RDpartition(a, begin, end);
        //most important part: mid -1
        quickSort(a, begin, mid-1);
        quickSort(a, mid+1, end);
    }
}

void merge(int a[], int begin, int mid, int end){
    int* tmp = (int*)malloc(sizeof(int)*(end-begin+1));
    int i = begin, j = mid+1, k = 0;
    while(i<=mid && j<=end){
        if(a[i]<a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=end)
        tmp[k++] = a[j++];
    for(k = begin; k<=end; k++)
        a[k] = tmp[k-begin];    //caution here
}
void mergeSort(int a[], int begin, int end){
    if(begin<end){
        int mid = (begin+end)/2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid+1, end);
        merge(a, begin, mid, end);
    }
}

void insertHeap(int val, struct heap* maxheap){
    (maxheap->vals)[maxheap->valNum++] = val;
    int i = maxheap->valNum-1, tmp;
    while(i>0&&(maxheap->vals)[i]>(maxheap->vals)[(i-1)>>1]){
        tmp = (maxheap->vals)[(i-1)>>1];
        (maxheap->vals)[(i-1)>>1] = (maxheap->vals)[i];
        (maxheap->vals)[i] = tmp;
        i = (i-1)>>1;
    }
}

int extractHeap(struct heap* maxheap){
    int max = (maxheap->vals)[0], tmp;
    (maxheap->vals)[0] = (maxheap->vals)[--maxheap->valNum];
    int i = 0;
    while(i<maxheap->valNum){
        //逻辑坑点：和左孩子交换的条件是：
        //有右孩子且左孩子三者最大
        //无右孩子且有左孩子！！且左孩子更大
        if((2+(i<<1)<maxheap->valNum &&
            maxheap->vals[2+(i<<1)]<maxheap->vals[1+(i<<1)]&&
            maxheap->vals[i]<maxheap->vals[1+(i<<1)])||
           (2+(i<<1)>=maxheap->valNum &&
            1+(i<<1)<maxheap->valNum &&
            maxheap->vals[i]<maxheap->vals[1+(i<<1)])
           ){
            tmp = maxheap->vals[i];
            maxheap->vals[i] = maxheap->vals[1+(i<<1)];
            maxheap->vals[1+(i<<1)] = tmp;
            i = 1+(i<<1);
        }
        else if(2+(i<<1)<maxheap->valNum &&
                maxheap->vals[2+(i<<1)]>maxheap->vals[1+(i<<1)]&&
                maxheap->vals[2+(i<<1)]>maxheap->vals[i]){
            tmp = maxheap->vals[i];
            maxheap->vals[i] = maxheap->vals[2+(i<<1)];
            maxheap->vals[2+(i<<1)] = tmp;
            i = 2+(i<<1);
        }
        else
            break;
    }
    return max;
}


struct heap* createHeap(int a[], int numsSize){
    struct heap* maxheap = (struct heap*)malloc(sizeof(struct heap));
    maxheap->maxSize = numsSize;
    maxheap->valNum = 0;
    maxheap->vals = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
        insertHeap(a[i], maxheap);
    return maxheap;
}

void heapSort(int a[], int numsSize){
    struct heap* maxheap = createHeap(a, numsSize);
    int* tmpArr = (int*)malloc(sizeof(int)*numsSize);
    int i;
    for(i=0;i<numsSize;i++)
        tmpArr[i] = extractHeap(maxheap);
    for(i=0;i<numsSize;i++)
        a[i] = tmpArr[numsSize-1-i];
}

void countingSort(int a[], int numsSize){
    int i, max = a[0];
    for(i=0;i<numsSize;i++)
        if(a[i]>max)
            max = a[i];
    int* tmpArr = (int*)malloc(sizeof(int)*numsSize);
    //下标不能从零开始，因为0本身可能也是数字，-1会导致指标为负
    int* cntArr = (int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++)
        cntArr[i] = 0;
    for(i=0;i<numsSize;i++)
        cntArr[a[i]]++;
    for(i=2;i<max+1;i++)
        cntArr[i] += cntArr[i-1];
    //逆序，排序稳定性
    for(i=numsSize-1;i>=0;i--){
        //这里的顺序也是由于指标导致的
        //第n个的指标为n-1
        cntArr[a[i]]--;
        tmpArr[cntArr[a[i]]] = a[i];
    }
    for(i=0;i<numsSize;i++)
        a[i] = tmpArr[i];
    return;
}

void radixSort(int a[], int numsSize){
    int cntArr[10] = {0};
    int* tmpArr = (int*)malloc(sizeof(int)*numsSize);
    int* tmpa = (int*)malloc(sizeof(int)*numsSize);
    int i, j, max = a[0], maxd = 0;
    for(i=0;i<numsSize;i++)
        if(a[i]>max)
            max = a[i];
    while(max){
        max /= 10;
        maxd++;
    }
    for(i=0;i<maxd;i++){
        for(j=0;j<numsSize;j++)
            tmpArr[j] = (a[j]/(int)pow(10, i))%10;
        for(j=0;j<10;j++)
            cntArr[j] = 0;
        for(j=0;j<numsSize;j++)
            cntArr[tmpArr[j]]++;
        for(j=1;j<10;j++)
            cntArr[j] += cntArr[j-1];
        for(j=numsSize-1;j>=0;j--){
            cntArr[tmpArr[j]]--;
            tmpa[cntArr[tmpArr[j]]] = a[j];
        }
        for(j=0;j<numsSize;j++)
            a[j] = tmpa[j];
    }
}

int Dselection(int a[], int begin, int end, int k){
    int numsSize = end-begin+1;
    if(numsSize<=5){
        bubbleSort(a+begin, numsSize);
        return a[begin+k];
    }
    int groupNum = numsSize/5 + (numsSize%5==0?0:1);
    int* medians = (int*)malloc(sizeof(int)*groupNum);
    int i;
    for(i=0;i<numsSize/5;i++)
        medians[i] = Dselection(a, i*5, i*5+4, 2);
    if(numsSize%5!=0)
        medians[i] = Dselection(a,i*5,numsSize-1,(numsSize%5-1)/2);
    //caution:三目运算符的优先级低
    int x = Dselection(medians, 0, groupNum-1, (groupNum-1)/2);
    int index = begin;
    for(i=begin;i<=end;i++)
        if(a[i]==x){
            index = i;
            break;
        }
    int tmp = a[begin];
    a[begin] = a[index];
    a[index] = tmp;
    int pivot = Dpartition(a, begin, end);
    if(pivot-begin==k)
        return a[pivot];
    else if(pivot-begin>k)
        return Dselection(a, begin, pivot-1, k);
    else
        //caution: k+begin-(pivot+1)
        //k是begin～end字段的第k大
        //k+begin是全局来看的第k大处在字段k位置时的指标
        //k+begin-(pivot+1)则是pivot+1～end子段对应的大小次序
        return Dselection(a, pivot+1, end, k+begin-(pivot+1));
    //这个算法也势必要破坏原来的顺序，因为需要pivot特性来保证大小关系的偏序
}
