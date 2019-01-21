//
//  lc_tagSTK.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/21.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_tagSTK.h"
#include "lc_randomly.h"

//TODO: 概览

//有效括号、函数执行时间、基本计算器
//上三题是比较基本的题目，应用了栈的特点进行模拟
//基本思想是未来会用到的暂是存储、栈天然的性质与函数、括号相合

//日常温度、下一个更大元素II
//这两题都是研究下一个更大，后者因为循环队列有个小操作
//此外还有一个特点是出栈时更新、这一点和函数执行时间很像、不同的是前者的更新是单独的数组、而后者的更新仍在栈中

//二叉树之字形遍历：两个栈


//TODO: LC 20. Valid Parentheses
//栈的基本题
bool isValid(string s) {
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            stk.push(s[i]);
        else{
            if(!stk.empty()&&
               ((s[i]==')'&&stk.top()=='(')||
                (s[i]==']'&&stk.top()=='[')||
                (s[i]=='}'&&stk.top()=='{')))
                stk.pop();
            else return false;
        }
    }
    return stk.empty();
}


//TODO: LC 636. Exclusive Time of Functions
//这个题从函数就可以发现要用栈 这里用栈直接模拟了实际运行情况
//还要多一个量记录开始/重新开始运行的时间
vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<int, int> > s;
    vector<int> res(n, 0);
    for(int i=0;i<logs.size();i++){
        vector<string> sub;
        split(logs[i], sub,':');
        int func = atoi(sub[0].c_str());
        int time = atoi(sub[2].c_str());
        if(sub[1]=="start"){
            if(!s.empty())
                res[s.top().first]+=(time-s.top().second);
            s.push({func, time});
        }
        else{
            res[func] += (time-s.top().second+1);
            s.pop();
            if(!s.empty())
                s.top().second = time+1;
        }
    }
    return res;
}

//TODO: LC 224. Basic Calculator
//好题 但是不难 有不少细节处理
//1、+-运算符不能最后一起算 因为是栈倒序，会让-计算错误
//2、所以必须得及时计算 但是中缀运算符得不到下一个数，所以只能拿到下一个运算符算前一个
//算前一个的时候要注意栈顶的条件，不仅是非空，而且不能是括号
int calculate(string s) {
    stack<int> num;
    stack<char> sign;
    string ns;
    for(int i=0;i<s.length();i++)
        if(s[i]!=' ')
            ns += s[i];
    int i = 0;
    while(i!=ns.length()){
        if(ns[i]=='('){
            sign.push(ns[i]);
            i++;
        }
        else if(ns[i]=='+'||ns[i]=='-'){
            if(!sign.empty()&&sign.top()!='('){
                char ac = sign.top();
                sign.top() = ns[i];
                int right = num.top();
                num.pop();
                int left = num.top();
                num.top() = (ac=='+'?(left+right):(left-right));
            }
            else    sign.push(ns[i]);
            i++;
        }
        else if(ns[i]==')'){
            while(sign.top()!='('){
                char ac = sign.top();
                sign.pop();
                int right = num.top();
                num.pop();
                int left = num.top();
                num.pop();
                num.push(ac=='+'?(left+right):(left-right));
            }
            sign.pop();
            i++;
        }
        else{
            int n = 0;
            while(ns[i]>='0'&&ns[i]<='9'){
                n = n*10+(ns[i]-'0');
                i++;
            }
            num.push(n);
        }
    }
    while(!sign.empty()){
        char ac = sign.top();
        sign.pop();
        int right = num.top();
        num.pop();
        int left = num.top();
        num.pop();
        num.push(ac=='+'?(left+right):(left-right));
    }
    return num.top();
}

//TODO: LC 739. Daily Temperatures
//也是经典栈、本质思想是未来可能会用到的暂时存在栈里
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> s;
    for(int i=0;i<temperatures.size();i++){
        while(!s.empty()&&temperatures[s.top()]<temperatures[i]){
            res[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
}

//TODO: LC 503. Next Greater Element II
//上一题的小变式: 循环队列的简单处理方式，把前n-1个复制到后面
vector<int> nextGreaterElements(vector<int>& nums) {
    if(nums.size()==0)  return {};
    vector<int> res(nums.size(), -1);
    stack<int> s;
    int len = (int)nums.size();
    nums.insert(nums.end(), nums.begin(), nums.end()-1);
    for(int i=0;i<nums.size();i++){
        while(!s.empty()&&nums[s.top()]<nums[i]){
            res[s.top()%len] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

//TODO: LC 103. Binary Tree Zigzag Level Order Traversal
//我觉得自己能想出来两个栈相互倒的骚操作还是很好玩的
//这样还有一个好处是不用处理烦人的层次标记，很容易就知道这一层是否遍历完了
//注意第二个栈走的时候下一层又要顺着走了，所以要先右后左、逆序入栈顺序出栈
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if(root==NULL)  return {};
    vector<vector<int> > res;
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    while(!stk1.empty()||!stk2.empty()){
        vector<int> tmp;
        if(!stk1.empty()){
            while(!stk1.empty()){
                TreeNode* t = stk1.top();
                stk1.pop();
                tmp.push_back(t->val);
                if(t->left) stk2.push(t->left);
                if(t->right)    stk2.push(t->right);
            }
        }
        else{
            while(!stk2.empty()){
                TreeNode* t = stk2.top();
                stk2.pop();
                tmp.push_back(t->val);
                if(t->right) stk1.push(t->right);
                if(t->left)    stk1.push(t->left);
            }
        }
        res.push_back(tmp);
    }
    return res;
}
