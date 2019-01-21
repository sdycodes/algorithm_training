//
//  lc_1809.cpp
//  FAT
//
//  Created by shidingyuan on 2018/9/16.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_1809.h"
#include "lc_randomly.h"
//TODO: LC 68. Text Justification
//一道麻烦题 没营养
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int i = 0;
    while(i<words.size()){
        int cur = 0;
        int j = i-1;
        while(j<(int)words.size()&&cur<=maxWidth){
            j++;
            if(i==j)
                cur+= words[j].length();
            else
                cur += (1 + words[j].length());
        }
        cur -= (words[j].length()+j-i);
        j--;
        string item;
        if(i==j){
            item = words[i];
            for(int k=0;k<maxWidth-cur;k++)
                item+=" ";
        }
        else if(cur==maxWidth||j==words.size()-1){
            for(int k=i;k<j;k++)
                item += (words[k]+" ");
            item += words[j];
            cur += (j-i);
            while((cur++)<maxWidth)
                item += " ";
        }
        else{
            int blanks = maxWidth-cur;
            int sep = blanks/(j-i);
            int remain = blanks-sep*(j-i);
            string basic;
            while((sep--)>0)
                basic+=" ";
            int k = i;
            while(k<i + remain)
                item+=words[k++]+basic+" ";
            while(k<j)
                item += words[k++]+basic;
            item += words[j];
        }
        res.push_back(item);
        i = j+1;
    }
    return res;
}

//TODO: LC 71. Simplify Path
//虽是一道hard 但属于栈的简单应用
string simplifyPath(string path) {
    vector<string> sub;
    split(path, sub, '/');
    stack<string> paths;
    for(int i=0;i<sub.size();i++){
        if(sub[i]==".."){
            if(!paths.empty())
                paths.pop();
        }
        else if(sub[i]!=""&&sub[i]!="."){
            paths.push(sub[i]);
        }
    }
    string res = "";
    while(!paths.empty()){
        res = "/" + paths.top()+ res;
        paths.pop();
    }
    if(res=="")
        res = "/";
    return res;
}


//TODO: LC 79. Word Search
//简单的递归枚举，但是要注意visit在作为传递信息时的位置，
//否则可能产生提前返回没有修复visited造成意料之外的影响
bool searchExist(int r, int c, vector<vector<char> > board, string word, vector<vector<bool> >& visited){
    if(r<0||r>=board.size()||c<0||c>=board[0].size())   return false;
    if(visited[r][c])   return false;
    if(word.size()==1&&word[0]==board[r][c])    return true;
    if(board[r][c]!=word[0])  return false;
    visited[r][c] = true;
    bool res =  searchExist(r+1, c, board, word.substr(1), visited)||
    searchExist(r-1, c, board, word.substr(1), visited)||
    searchExist(r, c+1, board, word.substr(1), visited)||
    searchExist(r, c-1, board, word.substr(1), visited);
    visited[r][c] = false;
    return res;
}
bool exist(vector<vector<char>>& board, string word) {
    if(board.size()==0||board[0].size()==0) return false;
    if(word.size()==0)  return true;
    vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), 0));
    vector<pair<int, int> > cand;
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            if(board[i][j]==word[0])
                cand.push_back({i, j});
    for(int i=0;i<cand.size();i++)
        if(searchExist(cand[i].first, cand[i].second, board, word, visited))
            return true;
    return false;
}

//TODO: LC 80. Remove Duplicates from Sorted Array II
int removeDuplicates80(vector<int>& nums) {
    int len = (int)nums.size();
    for(int i=2;i<len;i++)
        if(nums[i]==nums[i-1]&&nums[i]==nums[i-2]){
            for(int j=i;j<nums.size()-1;j++)
                nums[j] = nums[j+1];
            i--;
            len--;
        }
    return len;
}

//TODO: LC 83. Remove Duplicates from Sorted List
//水题 但是可以把代码写漂亮
ListNode* deleteDuplicates83(ListNode* head) {
    ListNode *pre = NULL, *tmp = head;
    while(tmp!=NULL){
        if(pre!=NULL&&pre->val==tmp->val){
            pre->next = tmp->next;
            free(tmp);
            tmp = pre;
        }
        pre = tmp;
        tmp= tmp->next;
    }
    return head;
}

//TODO: LC 86. Partition List
//链表处理 pre常规套路、但是要注意直接顺序走完等特殊情况
ListNode* partition86(ListNode* head, int x) {
    ListNode *tmp = head, *flag = NULL;
    while(tmp!=NULL&&tmp->val<x){
        flag = tmp;
        tmp = tmp->next;
    }
    if(tmp==NULL)   return head;
    ListNode* pre = flag;
    while(tmp!=NULL){
        if(tmp->val<x){
            if(flag!=NULL){
                pre->next = tmp->next;
                tmp->next = flag->next;
                flag->next = tmp;
                flag = flag->next;
                tmp = pre;
            }
            else{
                pre->next = tmp->next;
                tmp->next = head;
                head = tmp;
                flag = head;
            }
        }
        pre = tmp;
        tmp = tmp->next;
    }
    return head;
}

//TODO: LC 剪枝的充分性 如果字符不相同返回false
bool isScramble(string s1, string s2) {
    bool res = false;
    if(s1.length()!=s2.length())
        return false;
    if(s1.length()==1)
        return s1[0]==s2[0];
    int cnt[256] = {0};
    for(int i=0;i<s1.length();i++)
        cnt[s1[i]]++;
    for(int i=0;i<s2.length();i++)
        cnt[s2[i]]--;
    for(int i = 0;i<256;i++)
        if(cnt[i] != 0)
            return false;
    for(int i=1;i<s1.length();i++){
        res =   (isScramble(s1.substr(0, i), s2.substr(0, i))&&
                 isScramble(s1.substr(i), s2.substr(i)))||
        (isScramble(s1.substr(0, i), s2.substr(s2.length()-i))&&
         isScramble(s1.substr(i),s2.substr(0,s2.length()-i)));
        if(res) return res;
    }
    return res;
}


//TODO: LC 76. Minimum Window Substring
//双指针问题模式：对左右游标的记录，对评价（如长度）的记录
//试探性解
bool includeT(int snum[], int tnum[]){
    for(int i=0;i<=255;i++)
        if(snum[i]<tnum[i])
            return false;
    return true;
}
string minWindow(string s, string t) {
    int snum[256] = {0}, tnum[256] = {0};
    for(int i=0;i<t.length();i++)
        tnum[t[i]]++;
    int recl = -1, recr = -1, len = INT_MAX;
    int l = 0, r = 0;
    for(r=0;r<s.length();r++){
        snum[s[r]]++;
        while(includeT(snum, tnum)){
            if(len>r-l+1){
                len = r-l+1;
                recl = l;
                recr = r;
            }
            snum[s[l]]--;
            l++;
        }
    }
    return recl==-1?"":s.substr(recl, recr-recl+1);
}

//TODO: LC 92. Reverse Linked List II
//水题：技巧是加一个头避免各种蛇皮问题
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* header = new ListNode(0);
    header->next = head;
    ListNode *prel=NULL, *left=header, *right=header;
    for(int rec= 0;rec<n; rec++){
        if(rec<m){
            prel = left;
            left = left->next;
        }
        right = right->next;
    }
    while(left!=right){
        prel->next = left->next;
        left->next = right->next;
        right->next = left;
        left = prel->next;
    }
    return header->next;
}

//TODO: LC 95. Unique Binary Search Trees II
//二叉搜索树决定了数字不能乱动
vector<TreeNode*> buildTrees95(int begin, int end){
    if(begin>end)   return {NULL};
    if(begin==end){
        TreeNode* tmp = new TreeNode(begin);
        return {tmp};
    }
    vector<TreeNode*> res;
    for(int i=begin; i<=end; i++){
        vector<TreeNode*> left = buildTrees95(begin, i-1);
        vector<TreeNode*> right = buildTrees95(i+1, end);
        for(int m=0;m<left.size();m++)
            for(int n=0;n<right.size();n++){
                TreeNode* tmp_root = new TreeNode(i);
                tmp_root->left = left[m];
                tmp_root->right = right[n];
                res.push_back(tmp_root);
            }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    if(n==0)    return {};
    return buildTrees95(1, n);
}

//TODO: LC 97. Interleaving String
//动态规划：双字符串匹配又一例
bool isInterleave(string s1, string s2, string s3) {
    if(s1.length()+s2.length()!=s3.length())
        return false;
    vector<vector<bool> > dp(s1.length()+1, vector<bool>(s2.length()+1, 0));
    dp[0][0] = true;
    for(int i=1;i<=s1.length();i++)
        dp[i][0] = dp[i-1][0]&&s1[i-1]==s3[i-1];
    for(int i=1;i<=s2.length();i++)
        dp[0][i] = dp[0][i-1]&&s2[i-1]==s3[i-1];
    for(int i=1;i<=s1.length();i++)
        for(int j=1;j<=s2.length();j++){
            dp[i][j] = (s3[i+j-1]==s1[i-1]&&dp[i-1][j])||
            (s3[i+j-1]==s2[j-1]&&dp[i][j-1]);
        }
    return dp[s1.length()][s2.length()];
}

//TODO: LC 1. Two Sum
//排序后两侧夹逼，注意找位置的时候不能map考虑碰撞
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> copyNum(nums.size());
    for(int i=0;i<nums.size();i++)
        copyNum[i] = nums[i];
    sort(nums.begin(), nums.end());
    int l = 0, r = (int)nums.size()-1;
    while(l!=r){
        if(nums[l]+nums[r]<target)
            l++;
        else if(nums[l]+nums[r]>target)
            r--;
        else
            break;
    }
    vector<int> res(2);
    for(int i=0;i<copyNum.size();i++)
        if(copyNum[i]==nums[l])
            res[0] = i;
    for(int i=0;i<copyNum.size();i++)
        if(copyNum[i]==nums[r]&&i!=res[0])
            res[1] = i;
    return res;
}

//TODO: LC 2. Add Two Numbers
ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int num){
    int tag = 0;
    ListNode* res;
    res = new ListNode((l1?l1->val:0) + (l2?l2->val:0) + num);
    if(res->val==0&&l1==NULL&&l2==NULL) return NULL;
    else if(res->val>=10){
        res->val-=10;
        tag = 1;
    }
    res->next = addTwoNumbersHelper(l1?l1->next:NULL, l2?l2->next:NULL, tag);
    return res;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbersHelper(l1, l2, 0);
}

//TODO: 3. Longest Substring Without Repeating Characters
//最优子结构，dp特征，注意初始化不仅仅要初始化dp数组，辅助数组也要初始化
int lengthOfLongestSubstring(string s) {
    if(s.length()==0) return 0;
    vector<int> dp(s.length(), 0), loc(256, -1);
    dp[0] = 1;
    loc[s[0]] = 0;
    int maxlen = 1;
    for(int i=1;i<s.length();i++){
        dp[i] = (loc[s[i]]==-1)?dp[i-1]+1:min(dp[i-1]+1, i-loc[s[i]]);
        loc[s[i]] = i;
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}
