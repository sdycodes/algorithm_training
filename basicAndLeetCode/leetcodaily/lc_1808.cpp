//
//  lc_1808.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/22.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_1808.h"

//TODO: LC 455. Assign Cookies
//贪心：不可分割、大对大
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    for(int i=(int)s.size()-1;i>=0;i--){
        for(int j=(int)g.size()-1;j>=0;j--){
            if(s[i]>=g[j]){
                res++;
                s.erase(s.begin()+i);
                g.erase(g.begin()+j);
                break;
            }
        }
    }
    return res;
}

//TODO: LC 45. Jump Game II
//贪心两步
int jump(vector<int>& nums) {
    if(nums.size()<=1)  return 0;
    int next = 0, cur = 0, ridx = 0;
    int res = 0;
    while(cur!=nums.size()-1){
        ridx = cur;
        next = 0;
        if(cur+nums[cur]>=nums.size()-1)    return res+1;
        for(int i=1;i<=nums[cur]&&i+cur<nums.size();i++){
            if(next<cur+nums[i+cur]+i){
                next = cur+nums[i+cur]+i;
                ridx = i;
            }
        }
        res++;
        cur += ridx;
    }
    return res;
}
//TODO: LC 15. 3Sum
//使用set过滤重复属于下策、后面有个更好的方法
vector<vector<int> > threeSum(vector<int>& nums) {
    if(nums.size()<3)  return {};
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    set<vector<int> > s;
    for(int left=0;left<nums.size()-2;left++){
        if(left!=0&&nums[left-1]==nums[left]) continue;
        int middle = left+1, right = (int)nums.size()-1;
        while(middle<right){
            int sum = nums[left]+nums[middle]+nums[right];
            if(sum==0){
                s.insert({nums[left], nums[middle], nums[right]});
                middle++;
                right--;
            }
            else if(sum<0) middle++;
            else    right--;
        }
    }
    for(auto i:s){
        res.push_back(i);
    }
    return res;
}

vector<vector<int> > threeSumv2(vector<int>& nums) {
    if(nums.size()<3)  return {};
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    for(int left=0;left<nums.size()-2;left++){
        if(left!=0&&nums[left-1]==nums[left]) continue;
        int middle = left+1, right = (int)nums.size()-1;
        while(middle<right){
            int sum = nums[left]+nums[middle]+nums[right];
            if(sum==0){
                res.push_back({nums[left], nums[middle], nums[right]});
                middle++;
                right--;
                while(middle<right&&nums[middle]==nums[middle-1])   //注意这里+1/-1有门道
                    middle++;       //要让循环停止时停留在不一样的元素上、不然还是会出现重复解
                while(middle<right&&nums[right]==nums[right+1])
                    right--;
            }
            else if(sum<0) middle++;
            else    right--;
        }
    }
    return res;
}

//TODO: LC 16. 3Sum Closest
//双指针碰撞夹逼
int threeSumClosest(vector<int>& nums, int target) {
    int dist = INT_MAX, sum, res = 0;
    int left, middle, right;
    sort(nums.begin(), nums.end());
    for(left=0;left<nums.size()-2;left++){
        if(left>=1&&nums[left]==nums[left-1])   continue;
        middle = left+1;
        right = (int)nums.size()-1;
        while(middle<right){
            sum = nums[left]+nums[right]+nums[middle];
            if(dist>abs(sum-target)){
                dist = abs(sum-target);
                res = sum;
            }
            if(sum==target) return target;
            else if(sum>target) right--;
            else    middle++;
            
        }
    }
    return res;
}

//TODO: LC 25. Reverse Nodes in k-Group
//这个题有着比较明显的递归特征、但是递归难道使用的空间不是和问题规模相关的吗
//居然过了、不过这个做法我自认为很巧妙
ListNode* reverse1K(ListNode* head, int k){
    if(k==1)    return head;
    ListNode* tmp = head, *pre = head;
    int i = k;
    while(tmp&&(--i)){
        pre = tmp;
        tmp = tmp->next;
    }
    if(tmp==NULL)   return head;
    pre->next = tmp->next;
    tmp->next = reverse1K(head, k-1);
    return tmp;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL||k==1)    return head;
    ListNode* tmp = head, *pre = head;
    bool first = true;
    while(tmp){
        tmp = reverse1K(tmp, k);
        if(first){
            head = tmp;
            first = false;
        }
        else
            pre->next = tmp;
        int i = k;
        while(tmp&&(i--)){
            pre = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}

//TODO: LC 30. Substring with Concatenation of All Words
//指针题目，mark独立自主完成的hard题
vector<int> findSubstring(string s, vector<string>& words) {
    if(words.size()==0) return {};
    int wlen = (int)words[0].length();
    int len = wlen*(int)words.size();
    if(len>s.length())  return {};
    map<int, string> mp; //记录每个位置是哪个单词
    map<string, int> index; //记录单词的索引
    vector<int> times(words.size(), 0);
    for(int i=0;i<words.size();i++){
        if(index.find(words[i])==index.end())
            index[words[i]] = i;
        times[index[words[i]]]++;
    }
    for(int i=0;i<=s.length()-wlen;i++){
        string cand = s.substr(i, wlen);
        if(find(words.begin(), words.end(), cand)!=words.end())
            mp[i] = cand;
    }
    vector<int> res;
    for(map<int, string>::iterator t=mp.begin();t!=mp.end();t++){
        map<int, string>::iterator r = t;
        vector<int> visited(words.size(), 0);
        int visitNum = 0;
        while(r!=mp.end()){
            if(visited[index[r->second]]==times[index[r->second]])
                break;
            visited[index[r->second]]++;
            visitNum++;
            if(visitNum==words.size()){
                res.push_back(t->first);
                break;
            }
            r = mp.find(r->first+wlen);
        }
    }
    return res;
}

//TODO: FLC 31. Next Permutation
//利用了序列增加的一个特性
//向左找第一个小的，从此向右找第一个大的
//交换后右侧子段逆序
void nextPermutation(vector<int>& nums) {
    if(nums.size()<=1)  return;
    int i=(int)nums.size()-2;
    while(i>=0&&nums[i]>=nums[i+1])
        i--;
    if(i==-1){
        reverse(nums.begin(), nums.end());
        return;
    }
    int j = (int)nums.size()-1;
    while(j>i&&nums[j]<=nums[i])
        j--;
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    reverse(nums.begin()+i+1, nums.end());
    return;
}

//TODO: LC 32. Longest Valid Parentheses
//动态规划、既然不是区间dp
int longestValidParentheses(string s) {
    vector<int> dp(s.length(), 0);
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')   dp[i] = 0;
        else if(s[i]==')'){
            if(i-1>=0&&s[i-1]=='(') dp[i] = (i-2>=0?dp[i-2]:0)+2;
            else{
                if(i-1>=0&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    dp[i] =((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0) + 2 + dp[i-1];
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

//TODO: LC 41. First Missing Positive
//桶排序的思想、位置和值对应关系
//注意那个循环，保证可以全部还完、还要判断是否不相等避免死循环
int firstMissingPositive(vector<int>& nums) {
    if(nums.size() == 0)    return 1;
    for(int i=0; i<nums.size();i++){
        if(nums[i] > 0){//下面的while是核心
            while(nums[i]>0 &&nums[i]<i+1&&nums[i]!=nums[nums[i]-1]){
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
        }
    }
    for(int i = 0; i < nums.size();i++)
        if(nums[i] != i+1)
            return i+1;
    return (int)nums.size() + 1;
}

//TODO: LC 42. Trapping Rain Water
//双指针的思想，记录下了双向遍历两个方向的位置，把两次遍历降为1次
//这取决于当右侧大的时候装水量取决于左侧，所以从左向右找
//当左侧大的时候，装水量取决于右侧，所以从右向左找
int trap(vector<int>& height) {
    int lm= 0, rm = 0;
    int res = 0;
    int l = 0, r = (int)height.size()-1;
    while(l<r){
        if(height[l]<height[r]){
            lm = max(lm, height[l]);
            res += lm-height[l];
            l++;
        }
        else{
            rm = max(rm, height[r]);
            res += rm-height[r];
            r--;
        }
    }
    return res;
}

//TODO: LC 48. Rotate Image 水题
void rotate(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    if(n<=1)    return;
    int half = n>>1;
    for(int i=0;i<half;i++)
        for(int j=0;j<half;j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    if(n%2==1){
        for(int i=0;i<half;i++){
            int tmp = matrix[i][half];
            matrix[i][half] = matrix[n-1-half][i];
            matrix[n-1-half][i] = matrix[n-1-i][n-1-half];
            matrix[n-1-i][n-1-half] = matrix[half][n-1-i];
            matrix[half][n-1-i] = tmp;
        }
    }
    return;
}

//TODO: LC 49. Group Anagrams
//序等价的赤裸裸应用
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    if(strs.size()==0)  return res;
    map<string, vector<string> > mp;
    for(string str : strs){
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(str);
    }
    for(auto each: mp)
        res.push_back(each.second);
    return res;
}

//TODO: LC 54. Spiral Matrix
//矩阵的螺旋问题leetcode常考题目
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    if(m==0)    return {};
    int n = (int)matrix[0].size();
    int dir = 0;
    int rl = n-1, dl = m-1, ll = 0, ul = 1;
    vector<int> res(m*n);
    int i = 0, j = 0, cnt = 0;
    while(cnt!=m*n){
        if(dir==0){
            while(j<=rl)
                res[cnt++] = matrix[i][j++];
            j--;    i++;    //调整两个方面：1、遍历方向溢出了，2、垂直方向更新
            dir = (dir+1)%4;
            rl--;
        }
        else if(dir==1){
            while(i<=dl)
                res[cnt++] = matrix[i++][j];
            i--;    j--;
            dir = (dir+1)%4;
            dl--;
        }
        else if(dir==2){
            while(j>=ll)
                res[cnt++] = matrix[i][j--];
            j++;    i--;
            dir = (dir+1)%4;
            ll++;
        }
        else if(dir==3){
            while(i>=ul)
                res[cnt++] = matrix[i--][j];
            i++;    j++;
            dir = (dir+1)%4;
            ul++;
        }
    }
    return res;
}
//TODO: LC 59. Spiral Matrix II
vector<vector<int> > generateMatrix(int n) {
    if(n==0)    return {{}};
    vector<vector<int> > matrix(n, vector<int>(n));
    int dir = 0;
    int rl = n-1, dl = n-1, ll = 0, ul = 1;
    int cnt = 1;
    int i = 0, j = 0;
    while(cnt<=n*n){
        if(dir==0){
            while(j<=rl)
                matrix[i][j++] = cnt++;
            j--;    i++;
            dir = (dir+1)%4;
            rl--;
        }
        else if(dir==1){
            while(i<=dl)
                matrix[i++][j] = cnt++;
            i--;    j--;
            dir = (dir+1)%4;
            dl--;
        }
        else if(dir==2){
            while(j>=ll)
                matrix[i][j--] = cnt++;
            j++;    i--;
            dir = (dir+1)%4;
            ll++;
        }
        else if(dir==3){
            while(i>=ul)
                matrix[i--][j] = cnt++;
            i++;    j++;
            dir = (dir+1)%4;
            ul++;
        }
    }
    return matrix;
}
//TODO: LC 55. Jump Game
bool canJump(vector<int>& nums) {
    if(nums.size()==0)  return true;
    vector<int> dp(nums.size(), false);
    dp[nums.size()-1] = true;
    for(int i=(int)nums.size()-2;i>=0;i--)
        for(int j=0;j<=nums[i]&&i+j<nums.size();j++)
            if((dp[i]=dp[i]||dp[i+j]))
                break;
    return dp[0];
}
