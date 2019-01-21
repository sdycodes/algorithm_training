//
//  lc_tagBT.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/18.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_tagBT.h"

//TODO: 概览
//group0:简单步进式选择回溯
//784 字母大小写序列
//401 二进制手表
//77 组合
//22 括号
//上面的题目都是采用返回结果的方式、这有助于使用记忆化搜索提速
//下面模板化的题更倾向于使用void 因为有些情况不知道返回什么好
//group1:模板化
//39 40 216 组合之和 I II III
//这三道的模板 关键特征：start的参数传递、循环内增添条件约束
//131 回文串判断 类似216 内部增加条件约束
//90 子集II 无条件出口 每个点可选可不选
//17 数字的字母组合 每个点必选但是有多种选择
//93 解码ip地址 每个点可选可不选但是总数固定 传参解决
//140 断词II  加入了记忆化搜索提速 特点是子问题的可继承性
//37 解数独    无脑经典、每个点的备选方案变麻烦了
//51 N皇后    观察特征 通过按行放置提速
//上面两个题没法通过记忆化提速 因为有后效性
//60 可能序列 为排列问题提供了解决方法（精髓：erase） 前面多是组合问题
//group2:变长匹配问题
//10 正则表达式匹配
//44 通配符匹配：唯一的非递归解决 因为这个题的特征决定了不会有太多的回溯点，所以用两个变量就可以记录，无需递归
//因为一遇到*，之前的'*'对应的回溯点就不必要了 pattern会更早的把string匹配完，不同仅出现在有连续星号的时候

//TODO: LC 784. Letter Case Permutation
//sol1: 正常做
vector<string> letterCasePermutation(string S) {
    vector<string> res;
    res.push_back(S);
    for(int i=0;i<S.length();i++){
        if((S[i]>='A'&&S[i]<='Z')||(S[i]>='a'&&S[i]<='z')){
            int size = (int)res.size();
            for(int j=0;j<size;j++){
                string tmp = res[j];
                tmp[i] = (S[i]>='A'&&S[i]<='Z')?(tmp[i]-'A'+'a'):(tmp[i]-'a'+'A');
                res.push_back(tmp);
            }
        }
    }
    return res;
}
//sol2: 递归回溯
vector<string> letterCasePermutation2(string S) {
    vector<string> res;
    if(S.length()==0)   return {""};
    vector<string> tmp = letterCasePermutation(S.substr(1));
    if(S[0]>='0'&&S[0]<='9')
        for(int i=0;i<tmp.size();i++)
            res.push_back(S[0]+tmp[i]);
    else if(S[0]>='a'&&S[0]<='z'){
        for(int i=0;i<tmp.size();i++){
            res.push_back(S[0]+tmp[i]);
            res.push_back((char)(S[0]-'a'+'A')+tmp[i]);
        }
    }
    else{
        for(int i=0;i<tmp.size();i++){
            res.push_back(S[0]+tmp[i]);
            res.push_back((char)(S[0]-'A'+'a')+tmp[i]);
        }
    }
    return res;
}

//TODO: LC 401. Binary Watch
//简单的递归回溯 步进选择式
vector<string> calBins(int num, int len){
    if(num>len) return {};
    if(num==0) {
        string a = "";
        while(len--)
            a += '0';
        return {a};
    }
    if(len==1){
        if(num==0) return {"0"};
        else return {"1"};
    }
    vector<string> bins;
    vector<string> tmp0 = calBins(num, len-1);
    vector<string> tmp1 = calBins(num-1, len-1);
    for(int i=0;i<tmp0.size();i++)
        bins.push_back('0'+tmp0[i]);
    for(int i=0;i<tmp1.size();i++)
        bins.push_back('1'+tmp1[i]);
    return bins;
}
vector<string> readBinaryWatch(int num) {
    vector<string> res;
    vector<string> bins;
    bins = calBins(num, 10);
    
    for(int i=0;i<bins.size();i++){
        int j, h = 0, minu = 0;
        for(j=4;j<10;j++)
            minu += (bins[i][j]=='1'?(1<<(9-j)):0);
        if(minu>59)  continue;
        for(j=0;j<4;j++)
            h += (bins[i][j]=='1'?(1<<(3-j)):0);
        if(h>11) continue;
        res.push_back(to_string(h)+':'+(minu<10?"0":"")+to_string(minu));
    }
    return res;
}

//TODO: 77. Combinations
//回溯 步进式选择 这里的技巧在于倒着选可以较为直接的使用给定的函数参数
vector<vector<int>> combine(int n, int k) {
    if(n<k) return {};
    if(k==1){
        vector<vector<int> > res;
        for(int i=0;i<n;i++)
            res.push_back({i+1});
        return res;
    }
    vector<vector<int> > choose = combine(n-1, k-1);
    vector<vector<int> > res = combine(n-1, k);
    for(int i=0;i<choose.size();i++){
        choose[i].push_back(n);
        res.push_back(choose[i]);
    }
    return res;
}

//TODO: LC 22. Generate Parentheses
//1、记忆化搜索提速、偶数对称提速
//2、注意可能得到的结果又重复 使用集合将其过滤
//3、子问题需要真包含，否则递归死循环
vector<string> generateParenthesis(int n, map<int, vector<string> >& memo) {
    if(memo.find(n)!=memo.end())   return memo[n];
    if(n==0){
        memo[0] = {""};
        return memo[0];
    }
    if(n==1){
        memo[1] = {"()"};
        return memo[1];
    }
    vector<string> res;
    set<string> s;
    for(int i=1;i<=n-1;i++){
        vector<string> l = generateParenthesis(i, memo);
        vector<string> r = i==n-i?l:generateParenthesis(n-i, memo);
        for(int j=0;j<l.size();j++)
            for(int k=0;k<r.size();k++)
                s.insert(l[j]+r[k]);
    }
    for(set<string>::iterator t = s.begin();t!=s.end();t++)
        res.push_back(*t);
    vector<string> m = generateParenthesis(n-1, memo);
    for(int i=0;i<m.size();i++)
        res.push_back('('+ m[i] +')');
    memo[n] = res;
    return res;
}
vector<string> wrapGenerateParenthesis(int n){
    map<int, vector<string> > memo;
    return generateParenthesis(n, memo);
}
//回溯算法 一般性模板
//回归的条件:左右括号用完
//回归的操作:把当前字符串放到带返回的vector中
//选择1条件：还有左括号
//选择1的递归关系：做括号数量-1，当前字符串后面加左括号
//选择2条件：右括号数量多于左
//选择2的递归关系：右括号数量-1，当前字符串后面加右括号
//选择n条件
//选择n的递归关系
//合并所有解至解空间
//为什么这样可以搜索所有的可能情况？因为是两个if就是只要满足条件都会选 不会出现非此即彼的情况
void backTrace22(vector<string>& res, int left, int right, string cur){
    if(left==0&&right==0)
        res.push_back(cur);
    if(left>0)
        backTrace22(res, left-1, right, cur+'(');
    if(right>left)
        backTrace22(res, left, right-1, cur+')');
}

//TODO: LC 39. Combination Sum
//之前的某到递归题目与之类似 698
//都是通过不断的缩小范围实现全遍历
//对于同一元素取多次还是取一次 取决于向下递归时start是否+1
//注意传递进去的是&引用吗！！res全局记录故传递& sol要保持住回溯的特性 所以可引可无
void backTrace39(vector<int> candidates, vector<vector<int> >& res, int target, vector<int> sol, int start){
    if(target<0||start>=candidates.size())   return;
    if(target==0){
        res.push_back(sol);
        return;
    }
    for(int i=start;i<candidates.size();i++){
        sol.push_back(candidates[i]);
        backTrace39(candidates, res, target-candidates[i], sol, i);
        sol.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> sol;
    vector<vector<int> > res;
    backTrace39(candidates, res, target, sol, 0);
    return res;
}


//TODO: LC 40. Combination Sum II
//几乎一样 这一次不允许使用多次 所以要把递归的start+1
//但是元素可能重复 导致可能会相同，所以排序 选完这一个之后进行自增
void backTrack40(vector<int> &candidates,int start,int target,vector<int> sol,vector<vector<int>> &res){
    if(0==target){
        res.push_back(sol);
        return;
    }
    if(0>target)
        return;
    for(int i=start;i<candidates.size();i++){
        sol.push_back(candidates[i]);
        backTrack40(candidates,i+1,target-candidates[i],sol,res);
        sol.pop_back();
        while(i<candidates.size()-1&&candidates[i]==candidates[i+1]) i++;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> sol;
    vector<vector<int>> res;
    backTrack40(candidates,0,target,sol,res);
    return res;
}

//TODO: LC 216. Combination Sum III
//几乎一样 这一次不允许使用多次 所以要把递归的start+1
//最后再筛选长度即可
void backTrace216(int n, vector<vector<int> >& res, vector<int> sol, int start){
    if(n==0){
        res.push_back(sol);
        return;
    }
    if(n<0) return;
    for(int i=start;i<=9;i++){
        sol.push_back(i);
        backTrace216(n-i, res, sol, i+1);
        sol.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > res;
    vector<vector<int> > res2;
    vector<int> sol;
    backTrace216(n, res, sol, 1);
    for(int i=0;i<res.size();i++)
        if(res[i].size()==k)
            res2.push_back(res[i]);
    return res2;
}

//TODO: LC 131. Palindrome Partitioning
//前三题的一次成功领会与应用：顺序可能点枚举问题模板化
//此问题增加了回文的限制条件、于是在循环内部加入判断
bool isParli(string s){
    for(int i=0;i<s.length()/2;i++)
        if(s[i]!=s[s.length()-i-1])
            return false;
    return true;
}
void backtrace131(vector<vector<string> >& res,string s, vector<string> split, int start){
    if(start==s.length()){
        res.push_back(split);
        return;
    }
    for(int i=start;i<s.length();i++){
        if(isParli(s.substr(start, i-start))){
            split.push_back(s.substr(start, i-start));
            backtrace131(res, s, split, i+1);
            split.pop_back();
        }
    }
    return;
}

//TODO: LC 90. Subsets II
//又一变式、这道题的出口是没有条件的，因为子集要把所有的可能情况度考虑到
void backtrace90(vector<vector<int> >& res, vector<int> sol, vector<int> nums, int start){
    res.push_back(sol);
    for(int i=start;i<nums.size();i++){
        sol.push_back(nums[i]);
        backtrace90(res, sol, nums, i+1);
        sol.pop_back();
        while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;
    }
    return;
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> sol;
    backtrace90(res, sol, nums, 0);
    return res;
}
vector<vector<string> > partition(string s) {
    vector<vector<string> > res;
    vector<string> split;
    backtrace131(res, s, split, 0);
    return res;
}

//TODO: LC 17. Letter Combinations of a Phone Number
//这又一道变式 删掉了外层循环 也解释了为什么之前可以把当前元素不考虑在内的情况枚举到
//因为循环i在不等于start的时候，就是不考虑当前点的情况
//这个内层循环是包含当前点的可能情况全枚举
void backtrace17(string digits, vector<string>& res, vector<vector<char> > table, string sol, int start){
    if(start==digits.length()){
        res.push_back(sol);
        return;
    }
    for(int j=0;j<table[digits[start]-'0'].size();j++){
        sol += table[digits[start]-'0'][j];
        backtrace17(digits, res, table, sol, start+1);
        sol = sol.substr(0, sol.length()-1);
    }
}
vector<string> letterCombinations(string digits) {
    if(digits.length()==0)
        return {};
    vector<vector<char> > table = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
        {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},
        {'w','x','y','z'}};
    vector<string> res;
    string sol= "";
    backtrace17(digits, res, table, sol, 0);
    return res;
}


//TODO: LC 93. Restore IP Addresses
//定数量变式、递归传递剩余次数信息、
//注意字符串转数字可能存在溢出问题导致算法失去正确性
void backtrace93(string s, vector<string>& res, int remain, string cur, int start){
    if(start>=s.length())   return;
    if(remain==0){
        string back = s.substr(cur.length()-3);
        if(back=="0"||(back.length()<=3&&back[0]!='0'&&atoi(back.c_str())<=255))
            res.push_back(cur+back);
        return;
    }
    for(int i=start;i<s.length();i++){
        string code = s.substr(start, i-start+1);
        if(code=="0"||(code.length()<=3&&code[0]!='0'&&atoi(code.c_str())<=255)){
            string rec = cur;
            cur += (code + ".");
            backtrace93(s, res, remain-1, cur, i+1);
            cur = rec;
        }
    }
    return;
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string cur = "";
    backtrace93(s, res, 3, cur, 0);
    return res;
}

//TODO: LC 140. Word Break II
//回溯与记忆化搜索的综合使用 backtrace带返回值 注意不要总是想自己处理特殊情况
//回溯与一般递归的不同在于函数的出口往往不是平凡问题(如字符串只有1～2个字符)的处理
//而是得到解的特征(如字符串在字典中、先前已经求解过即存在于memo)
vector<string> backtrace140(string s, vector<string>& wordDict, map<string, vector<string> >& memo){
    if(memo.find(s)!=memo.end())    return memo[s];
    vector<string> res;
    if(find(wordDict.begin(), wordDict.end(), s)!=wordDict.end())
        res.push_back(s);
    for(int i=0;i<s.length();i++){
        string begin = s.substr(0, i);
        if(find(wordDict.begin(), wordDict.end(), begin)!=wordDict.end()){
            vector<string> tmp = backtrace140(s.substr(i), wordDict, memo);
            for(int j=0;j<tmp.size();j++)
                res.push_back(begin+ ' '+ tmp[j]);
        }
    }
    memo[s] = res;
    return res;
}
vector<string> wordBreak2(string s, vector<string>& wordDict) {
    map<string, vector<string> > memo;
    return backtrace140(s, wordDict, memo);
}


//TODO: LC 37. Sudoku Solver
//经典回溯、思路简单、编程注意修复失败的更改
bool backtrace37(vector<vector<char> >& board, int r, int c){
    int i=0, j=0;
    for(i=r;i<9;i++){
        bool tag = false;
        for(j=(i==r?c:0);j<9;j++){
            if(board[i][j]=='.'){
                tag = true;
                break;
            }
        }
        if(tag) break;
    }
    if(i==9&&j==9) return true;
    set<char> candidates = {'1','2','3','4','5','6','7','8','9'};
    for(int k=0;k<9;k++){
        candidates.erase(board[i][k]);
        candidates.erase(board[k][j]);
    }
    int sr = i<3?0:(i<6?3:6), sc = j<3?0:(j<6?3:6);
    for(int u=0;u<3;u++)
        for(int v=0;v<3;v++)
            candidates.erase(board[u+sr][v+sc]);
    if(candidates.size()==0)    return false;
    for(set<char>::iterator t = candidates.begin();t!=candidates.end();t++){
        board[i][j] = *t;
        if(backtrace37(board, i, j))
            return true;
        board[i][j] = '.';  //尤其重要 回溯的修复意识
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    backtrace37(board, 0, 0);
}

//TODO: LC 51. N-Queens
//逐点遍历存在的问题：1、有重复 2、时间复杂度高
//观察特征，发现一行最多一个 这样递归过程可以向下缩小规模
bool canbeplace(vector<string> plate, int r, int c){
    int n = (int)plate.size();
    for(int i=0;i<n;i++){
        if(plate[i][c]=='Q'||plate[r][i]=='Q')
            return false;
        if(r-i>=0&&c+i<n&&plate[r-i][c+i]=='Q')
            return false;
        if(r+i<n&&c-i>=0&&plate[r+i][c-i]=='Q')
            return false;
        if(r-i>=0&&c-i>=0&&plate[r-i][c-i]=='Q')
            return false;
        if(r+i<n&&c+i<n&&plate[r+i][c+i]=='Q')
            return false;
    }
    return true;
}
void backtrace51(vector<vector<string> >& res, int n, int row, vector<string> plate){
    if(row==n){
        res.push_back(plate);
        return;
    }
    for(int j=0;j<n;j++){
        if(canbeplace(plate, row, j)){
            plate[row][j] = 'Q';
            backtrace51(res, n, row+1, plate);
            plate[row][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> plate(n, string(n, '.'));
    backtrace51(res, n, 0, plate);
    return res;
}


//TODO: LC 60. Permutation Sequence
//严格来说不算回溯 但是为回溯解决全排列问题提供模板
//使用vector选择元素后删除之、保证排列不会重复
string backtrace60(vector<int>& nums, int k){
    if(k==0){
        string ret = "";
        for(int i=0;i<nums.size();i++)
            ret += to_string(nums[i]);
        return ret;
    }
    int kinds = 1;
    for(int i=(int)nums.size()-1;i>0;i--)
        kinds *= i;
    string begin = to_string(nums[k/kinds]);
    nums.erase(nums.begin()+k/kinds);
    string post = backtrace60(nums, k-kinds*(k/kinds));
    return begin + post;
}
string getPermutation(int n, int k) {
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)
        nums[i] = i+1;
    return backtrace60(nums, k-1);
}

//TODO: LC 10. Regular Expression Matching
//回溯算法
//递归回溯、还是比较易于理解 但是时间复杂度高
bool isMatch(string s, string p) {
    if(p.empty())   return s.empty();
    if(p.length()>=2&&p[1]=='*')
        return isMatch(s, p.substr(2))||    //*把p的前一个吃掉能否匹配
        (!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1), p));
    //*复制前一个能否匹配、复制表现在递归下去的p还是p
    else    //没有*，只能当前字符匹配且后面子段匹配
        return (!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1), p.substr(1)));
}


//TODO: LC 44. Wildcard Matching
//迭代回溯 如果用递归回溯TLE，迭代回溯
bool isMatch2(string s, string p) {
    int tag1 = 0, tag2 = -1;
    int i = 0, j = 0;
    while(i<s.length()){
        //匹配成功 继续匹配
        if(i<s.length()&&j<p.length()&&(s[i]==p[j]||p[j]=='?')){
            i++;
            j++;
        }
        //当前是* 是一个可能回溯的点 记录下来
        else if(p[j]=='*'){
            tag1 = i;
            tag2 = j;
            j++;
        }
        //当前不能匹配且不是* 找到之前记录的回溯点回溯
        else if(tag2!=-1){
            j = tag2 + 1;
            i = ++tag1; //更新回溯：依据特征、本题是根据*匹配的字符串个数来确定
        }
        //无路可走 不能匹配
        else
            return false;
    }
    //匹配完s、检查p其余的部分是否全为*
    while(j<p.length()&&p[j]=='*')
        j++;
    return j==p.length();
}
