//
//  lc_tagDC__.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/13.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_tagDC.h"

//TODO: 概览 分治算法的复杂 往往并不来自于分治本身
//不同加括号的方式
//矩阵搜索 传统的二分搜索递归的思想，简单、严格来说不能算分治，因为没有merge的过程
//右侧比较小的元素
//上两题这种和数组的顺序相关的题目历来不会做:( :(
//计数区间和 真正的分治题目，又一次使用了归并排序的一些特性
//增加运算符 本质是一个回溯 但是回溯的时候有难点在于乘法优先级的处理，需要额外传参


//TODO: LC 241. Different Ways to Add Parentheses
//分支还是套用了递归的思想 在表达式上常用
vector<int> diffWaysToCompute(string input) {
    int i =0;
    while(i<input.length()&&input[i]>='0'&&input[i]<='9')
        i++;
    if(input.length()==0)   return {};
    if(i==input.length())
        return {stoi(input)};
    vector<int> res;
    for(i=0;i<input.length();i++){
        if(input[i]=='+'){
            vector<int> l = diffWaysToCompute(input.substr(0, i));
            vector<int> r = diffWaysToCompute(input.substr(i+1, input.length()-i-1));
            for(int j=0;j<l.size();j++)
                for(int k=0;k<r.size();k++)
                    res.push_back(l[j]+r[k]);
        }
        else if(input[i]=='-'){
            vector<int> l = diffWaysToCompute(input.substr(0, i));
            vector<int> r = diffWaysToCompute(input.substr(i+1, input.length()-i-1));
            for(int j=0;j<l.size();j++)
                for(int k=0;k<r.size();k++)
                    res.push_back(l[j]-r[k]);
        }
        else if(input[i]=='*'){
            vector<int> l = diffWaysToCompute(input.substr(0, i));
            vector<int> r = diffWaysToCompute(input.substr(i+1, input.length()-i-1));
            for(int j=0;j<l.size();j++)
                for(int k=0;k<r.size();k++)
                    res.push_back(l[j]*r[k]);
        }
    }
    return res;
}

//TODO: LC 240. Search a 2D Matrix II
//二维二分搜索，中间列分割、右上左下的范围
bool binarySearch2D(vector<vector<int> >& matrix, int r1, int c1, int r2, int c2, int target){
    if(r1>r2||c1>c2)   return false;
    if(r1==r2&&c1==c2)  return matrix[r1][c1]==target;
    int midc = (c1+c2)>>1;
    int gu = r1, gd = r2;
    while(gu!=gd){
        int gm = (gu+gd)>>1;
        if(matrix[gm][midc]>target)
            gd = gm;
        else if(matrix[gm][midc]<target)
            gu = gm+1;
        else
            return true;
    }
    if(matrix[gu][midc]==target)
        return true;
    int midr = matrix[gu][midc]>target?gu-1:gu;
    return binarySearch2D(matrix, r1, midc+1, midr, c2, target)||
    binarySearch2D(matrix, midr+1, c1, r2, midc-1, target);
    //注意上面递归传参的一些小变化，否则不打破僵局，无限递归爆栈
}
bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.size()==0)    return false;
    return binarySearch2D(matrix, 0, 0, (int)matrix.size()-1, (int)matrix[0].size()-1, target);
}

//TODO: 315. Count of Smaller Numbers After Self
//distanc(iter1, iter2) 返回两个迭代器的距离
//lower_bound(begin, end, tar) 返回begin～end有序序列中第一个<=tar的位置
//插入排序的同时进行记录 STL是个二分查找 保证nlogn
//merge逆序计数的方法会遇到通相同数字的位置冲突问题
vector<int> countSmaller(vector<int>& nums){
    vector<int> t, res(nums.size());
    for (int i = (int)nums.size()-1;i>=0;i--){  //倒序保持排序稳定性
        int d = (int)distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
        res[i] = d; //从右往左拿 先前存在的元素都是在我右边且比我小的、//lowerbound找到第一个保证不会把重复的记下来
        t.insert(t.begin()+d, nums[i]);
    }
    return res;
}


//TODO: 327. Count of Range Sum
//merge 排序的又一大应用、inplace merge函数小技巧
int countNums(vector<long>& sums, int lower, int upper, int begin, int end){
    if(end-begin<=1)  return 0;
    int res = 0;
    int mid = (begin+end)>>1;
    res = countNums(sums, lower, upper, begin, mid) + countNums(sums, lower, upper, mid, end);
    //merge
    int l = mid, h = mid;   //只能从左到右找范围，因为随着左侧的sum增加，会导致满足lower和upper的值也都增加
    for(int i=begin;i<mid;i++){//所以只能从左到右
        while(l<end&&sums[l]-sums[i]<lower)  l++;
        while(h<end&&sums[h]-sums[i]<=upper)  h++;
        res += (h-l);
    }
    inplace_merge(sums.begin()+begin, sums.begin()+mid, sums.begin()+end);
    return res;
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    if(nums.size()==0) return  0;
    vector<long> sums(nums.size()+1, 0);
    for(int i=0;i<sums.size()-1;i++)
        sums[i+1] = sums[i] + nums[i];
    return countNums(sums, lower, upper, 0, (int)sums.size());
}



//TODO: LC 282. Expression Add Operators
void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
    if(num.size() == 0 && curNum == target)
        res.push_back(out);
    for(int i = 1; i <= num.length();i++){
        string cur = num.substr(0, i);
        if (cur.size() > 1 && cur[0] == '0') return;    //去除前导0情况
        string next = num.substr(i);
        if (out.size() > 0) {
            //参数diff是当前形成的多项式中的最后一项的大小，用来回溯恢复使用
            addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
            addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
            addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out+ "*" + cur, res);
        }
        else
            addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> res;
    addOperatorsDFS(num, target, 0, 0, "", res);
    return res;
}

