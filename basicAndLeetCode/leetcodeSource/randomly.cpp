//
//  randomly.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/7.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//


#include "stdHeader.h"

//TODO:leetcode 468 Validate IP Address
//1、单字符分割方法 2、大小范围问题 3、atoi 4、string方法substr、==
//单字符分割的简单方法 注意如果没有 sub里面是s
void split(string s, vector<string>& sub, char c){
    int pos;
    while((pos = (int)s.find(c))!=-1){
        sub.push_back(s.substr(0, pos));
        s = s.substr(pos+1);
    }
    sub.push_back(s);
}
bool valid6(string s){
    int i;
    if(s.length()>4||s.length()==0) return false;
    for(i=0;i<s.length();i++){
        if((s[i]-'0'<=9&&s[i]-'0'>=0) || (s[i]-'a'>=0&&s[i]-'a'<=5)|| (s[i]-'A'>=0&&s[i]-'A'<=5))
            continue;
        else
            return false;
    }
    return true;
}
//注意大小范围的问题 1？？后面两位无限制 2？？后两位有限制
//简便方法使用内置atoi函数 atoi(s.c_str());
bool valid4(string s){
    if(s.length()>=4||s.length()==0)
        return false;
    else if(s.length()==1)
        return s[0]-'0'>=0 && s[0]-'0'<=9;
    else if(s.length()==2)
        return s[0]-'0'>0 && s[0]- '0'<=9 && s[1]-'0'>=0 && s[1]-'0'<=9;
    else
        return s[0]-'0'>0&&s[0]-'0'<=2 && s[1]-'0'>=0 && s[1]-'0'<=9 && s[2]-'0'>=0 && s[2]-'0'<=9 && atoi(s.c_str())<256;
}
string validIPAddress(string IP) {
    vector<string> ipv6;
    vector<string> ipv4;
    split(IP, ipv6, ':');
    split(IP, ipv4, '.');
    int i;
    if(ipv6.size()==1 && ipv4.size()==4){
        for(i=0;i<ipv4.size();i++){
            if(valid4(ipv4[i]))
                continue;
            else
                return "Neither";
        }
        return "IPv4";
    }
    else if(ipv6.size()==8 && ipv4.size()==1){
        for(i=0;i<ipv6.size();i++){
            if(valid6(ipv6[i]))
                continue;
            else
                return "Neither";
        }
        return "IPv6";
    }
    return "Neither";
}

//TODO:leetcode 82 Remove Duplicates from Sorted List II
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//1、现检验是不是真的重复tmp->next==tag 2、前驱记录法 3、删头问题 4、缺陷：没free
ListNode* deleteDuplicates(ListNode* head) {
    struct ListNode *pre = NULL, *tmp = head, *tag;
    while(tmp!=NULL){
        for(tag=tmp->next;tag!=NULL&&tag->val==tmp->val;tag = tag->next)
            ;
        if(tmp->next==tag){
            pre = tmp;
            tmp = tmp->next;
        }
        else{
            if(pre==NULL){
                tmp = tag;
                head = tag;
            }
            else{
                pre->next = tag;
                tmp = tag;
            }
        }
    }
    return head;
}

//TODO:leetcode 605. Can Place Flowers
//大量的长度边界处理问题
//1、巧妙利用整型除法的特点进行微操作+1 -1
//2、更改循环变量要慎重（配合无条件增减i++、i=j）
//3、长度的计算要根据端点的确定条件来确定
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0, j, len;
    while(i<flowerbed.size()){
        if(flowerbed[i]==0){
            j = i+1;
            while(j<flowerbed.size()&&flowerbed[j]==0)
                j++;
            len = j-i;  //长度不再+1 因为右端点条件
            if(i==0&&j==flowerbed.size())   //&& || 分支配合
                n -= (len+1)/2;
            else if(i==0||j==flowerbed.size())
                n -= len/2;
            else
                n -= (len-1)/2;
            i = j;  //不能是j+1 无条件i++会多走一个
        }
        i++;    //这个在while循环不能少
    }
    return n<=0;
}

//TODO:leetcode 374. Guess Number Higher or Lower
//1、二分查找模板 2、保证覆盖正整数范围，避免溢出使用unsined long int
//3、二分查找pro 找不着能跳出来 while判断条件guessr>=guessl
int guess(int num){
    if(num>-1)  return -1;
    else if(num<-1) return 1;
    else return 0;
}
int guessNumber(int n) {
    unsigned long int guessl=1, guessr = n, guessm;
    int res;
    while(guessr>=guessl){
        guessm = (guessl+guessr)/2;
        res = guess((int)guessm);
        if(res==0)
            return (int)guessm;
        else if(res==-1)
            guessr = guessm-1;
        else
            guessl = guessm+1;
    }
    return 0;
}

//TODO:leetcode 375. Guess Number Higher or Lower II
//二分查找的特点是保证次数最少，但是不保证路径代价最少
//1、区间dp 极小化极大、dp[i,j]表示从i～j猜中任意数字的钱数
//2、vector声明方法
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            int global_min = INT_MAX;
            for (int k = j + 1; k < i; ++k) {
                int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
                global_min = min(global_min, local_max);
            }
            dp[j][i] = j + 1 == i ? j : global_min;
        }
    }
    return dp[1][n];
}

//TODO:leetcode 278. First Bad Version
//略区别于二分查找  这个找到的只有两种可能：是或不是 正常二分有三种(><=)
//所以只有一个打破局面的地方、否则会死循环
bool isBadVersion(int version){
    return version>=5;
}
int firstBadVersion(int n) {
    unsigned long int guessl=1, guessr = n, guessm;
    bool res;
    while(guessr!=guessl){
        guessm = (guessl+guessr)/2;
        res = isBadVersion((int)guessm);
        if(res)
            guessr = guessm;
        else
            guessl = guessm+1; //打破局面
    }
    return (int)guessl;
}

//TODO:leetcode 34. Find First and Last Position of Element in Sorted Array
//终极二分查找 找到左右端点
//相等的时候加入更多的判断
int bsearchr(int target, vector<int>& nums){
    if(nums.size()==0)
        return -1;
    unsigned long int l=0, r = nums.size()-1, m;
    while(r!=l){
        m = (l+r)/2;
        if(nums[m]>target)
            r = m==0?0:m-1;
        else if(nums[m]<target)
            l = m==nums.size()-1?m:m+1;
        else{
            if(m==nums.size()-1||nums[m+1]!=target)
                return (int)m;
            else
                l = m==nums.size()-1?m:m+1;
        }
    }
    return nums[(int)r]==target?(int)r:-1;
}
int bsearchl(int target, vector<int>& nums){
    if(nums.size()==0)
        return -1;
    unsigned long int l=0, r = nums.size()-1, m;
    while(r!=l){
        m = (l+r)/2;
        if(nums[m]<target)
            l = m==nums.size()-1?m:m+1;
        else if(nums[m]>target)
            r = m==0?0:m-1;
        else{
            if(m==0||nums[m-1]!=target)
                return (int)m;
            else
                r = m==0?0:m-1;
        }
    }
    return nums[(int)l]==target?(int)l:-1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {bsearchl(target, nums), bsearchr(target, nums)};
    return res;
}

//TODO:leetcode 372. Super Pow
//分而治之策略 整型除法保证全覆盖是y/2和y-y/2
//从前往后的增长 pow(*, 10)
int pow1337(int x, int y){
    if(y==0||x==1) return 1;
    if(y==1) return x%1337;
    return (pow1337(x, y/2)*pow1337(x, y - y/2))%1337;
}
int superPow(int a, vector<int>& b){
    int res = 1;
    for(int i=0;i<b.size();i++)
        res = (pow1337(res, 10)*pow1337(a, b[i]))%1337;
    return res;
}

//TODO:leetcode 205. Isomorphic Strings
//1、贪心策略 2、注意单射 所以需要一张记录表记录映射情况
bool isIsomorphic(string s, string t) {
    bool used[256] = {0};
    char a[256] = {0};
    for(int i=0;i<s.size();i++){
        if(a[s[i]]==0 && used[t[i]]==0){
            a[s[i]] = t[i];
            used[t[i]] = 1;
        }
        else if(a[s[i]]==t[i])
            continue;
        else
            return false;
    }
    return true;
}

//TODO:leetcode 89. Gray Code
//1、格雷code的特征：第n位先0后1，后n-1位排列和n-1位格雷码顺序一致，递归
//2、注意vector大小动态增长 所以循环判别要记录下来
vector<int> grayCode(int n){
    vector<int> res;
    if(n==0){
        res.push_back(0);
        return res;
    }
    if(n==1){
        res.push_back(0);
        res.push_back(1);
        return res;
    }
    res = grayCode(n-1);
    int l = (int)res.size(), i;
    for(i=0;i<l;i++)
        res.push_back(res[l-i-1]);
    while(i<res.size()){
        res[i] += (int)pow(2, n-1);
        i++;
    }
    return res;
}

//TODO:leetcode 811. Subdomain Visit Count
//很渣的一道题 关键是熟悉c++ map的用法
string itoa(int n){
    if(n==0) return "0";    //n==0 进不了循环 特判
    if(n==INT_MIN) return "-2147483648";    //负数问题 最大负数取绝对值溢出
    int abs = n>0?n:-n;
    string res = "";
    char table[] = {'0','1','2','3','4','5','6','7','8','9'};
    while(abs){
        res = table[abs%10] + res;
        abs /= 10;
    }
    return (n>0?"":"-") + res;
}
vector<string> subdomainVisits(vector<string>& cpdomains) {
    map<string, int> domain_times;
    int i, j;
    vector<string> tmp, domains;
    vector<int> times;
    for(i=0;i<cpdomains.size();i++){
        split(cpdomains[i], tmp, ' ');
        domains.push_back(tmp[1]);
        times.push_back(atoi(tmp[0].c_str()));
        tmp.clear();
    }
    for(i=0;i<times.size();i++){
        split(domains[i], tmp, '.');
        for(j=(int)tmp.size()-2;j>=0;j--)
            tmp[j] = tmp[j] + '.' + tmp[j+1];
        for(j=0;j<tmp.size();j++){
            if(domain_times.find(tmp[j])==domain_times.end())
                domain_times[tmp[j]] = times[i];
            else
                domain_times[tmp[j]] += times[i];
        }
        tmp.clear();
    }
    vector<string> res;
    map<string,int>::iterator it;
    for(it=domain_times.begin();it!=domain_times.end();it++)
        res.push_back(itoa(it->second)+ ' ' + it->first);
    return res;
}

//TODO:leetcode 75. Sort Colors
//快排比较慢 可以O(n);
void mswap(vector<int>& nums, int index1, int index2){
    int tmp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = tmp;
}
void sortColors(vector<int>& nums) {
    int i = 0, flag = 0;
    for(i=0;i<nums.size();i++)
        if(nums[i]==0)
            mswap(nums,i, flag++);
    for(i=flag;i<nums.size();i++)
        if(nums[i]==1)
            mswap(nums, i, flag++);
}

//TODO:leetcode 437. Path Sum III

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//好题 递归思想之后的具体实现细节
//因为要求的是路径 这个得连续，如何保证？
//使用了一个媒介函数sumup，sumup计算包含当前节点的路径的数量
//pathSum分而治之
//Definition for a binary tree node.

int sumup(TreeNode *root, int sum){
    return root==NULL?0:
    (sum==root->val?1:0) +
    sumup(root->left, sum - root->val) + sumup(root->right, sum - root->val);
}
int pathSum(TreeNode* root, int sum) {
    return root==NULL?0:
    sumup(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}


//TODO: LC 322. Coin Change
//经典多重背包找零钱问题
//为何不能贪心 因为本问题不保证一定有解考虑硬币为2，5，目标为6，贪心会选5，然后认为没有解
//dp可以找到三个2
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int i, j;
    dp[0] = 0;
    for(i=0;i<coins.size();i++)
        if(coins[i]<=amount)
            dp[coins[i]] = 1;
    for(i=0;i<=amount;i++){
        for(j=0;j<coins.size();j++){
            if(i-coins[j]>=0&&dp[i-coins[j]]!=-1)
                dp[i] = dp[i]==-1?(1+dp[i-coins[j]]):min(dp[i], 1 + dp[i-coins[j]]);
        }
    }
    return dp[amount];
}

//TODO: LC 781. Rabbits in Forest
//看似复杂 其实分析一下比较简单
int numRabbits(vector<int>& answers) {
    sort(answers.begin(), answers.end());
    int i=0, j, len, total = 0;
    while(i<answers.size()){
        j = i+1;
        while(j<answers.size()&&answers[j]==answers[i])
            j++;
        len = j - i;
        if(len<=answers[i]+1)
            total += answers[i]+1;
        else
            total += (len/(answers[i]+1)+((len%(answers[i]+1))?1:0))*(answers[i]+1);
        i = j;
    }
    return total;
}


//TODO: LC 23. Merge k Sorted Lists
//属于递归策略 很慢
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int i, r = -1, min = INT_MAX;
    for(i=0;i<lists.size();i++){
        if(lists[i]!=NULL && min>lists[i]->val){
            min = lists[i]->val;
            r = i;
        }
    }
    if(r==-1)   return NULL;
    ListNode* q = lists[r];
    lists[r] = lists[r]->next;
    q->next = mergeKLists(lists);
    return q;
}

//TODO: LC 517. Super Washing Machines
//单独切割个体思想
//两侧统一体思想
int findMinMoves(vector<int>& machines) {
    int i, sum = 0;
    for(i=0;i<machines.size();i++)
        sum += machines[i];
    if(sum%machines.size()!=0)  return -1;
    int aver = sum/machines.size();
    vector<int> l(machines.size(), 0);
    vector<int> r(machines.size(), 0);
    for(i=1;i<machines.size();i++)
        l[i] = l[i-1] + machines[i-1]-aver;
    for(i=(int)machines.size()-2;i>=0;i--)
        r[i] = r[i+1] + machines[i+1]-aver;
    vector<int> k(machines.size(), 0);
    for(i=0;i<machines.size();i++){
        if(l[i]>=0 &&r[i]>=0)
            k[i] = max(l[i], r[i]);
        else if(l[i]<0 && r[i]<0)
            k[i] = -l[i] - r[i];
        else
            k[i] = max(abs(l[i]), abs(r[i]));
    }
    int res = k[0];
    for(i=0;i<k.size();i++)
        res = max(res, k[i]);
    return res;
}

//TODO: LC 551. Student Attendance Record I
//水题
bool checkRecord(string s) {
    int i, acnt = 0;
    bool lc2 = false;
    for(i=0;i<s.length();i++){
        if(s[i]=='A') acnt++;
        else if(i>=2&&s[i]=='L' && s[i-1]=='L' &&s[i-2]=='L')
            lc2 = true;
    }
    return acnt<=1 && !lc2;
}

//TODO: LC 718. Maximum Length of Repeated Subarray
//LCString模板题 注意dp[i][j]含义：包含A[i]与B[j]的LCString
//所以返回值不是dp[][]
int findLength(vector<int>& A, vector<int>& B) {
    vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));
    int i, j, max = 0;
    for(i=1;i<A.size()+1;i++)
        for(j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1])  dp[i][j] = dp[i-1][j-1]+1;
            if(max<dp[i][j])    max = dp[i][j];
        }
    return max;
}
//TODO: LC 464. Can I Win
//门道颇多
//1、记忆化搜索map记录下了某中选择的情形之下的输赢
//2、回合问题如何处理，后者先走的输就是前者赢（这也是可以dp的原因）
//3、题目说的数字数量不超过30，用一个整数就可以实现记录选择状况
//4、int&作为函数参数传递时不能传表达式
bool memSearch(int chooseRec, int target, int maxChIn, map<int, bool>& m){
    if(m.find(chooseRec)!=m.end()) return m[chooseRec];
    for(int i=1;i<=maxChIn;i++)
        if((chooseRec&(1<<i))==0&&
           (i>=target||!memSearch(chooseRec|(1<<i), target-i, maxChIn, m))){
            m[chooseRec] = true;
            return true;
        }
    m[chooseRec] = false;
    return false;
}
bool canIWin(int maxChoosableInteger, int desiredTotal){
    if(maxChoosableInteger>=desiredTotal)   return true;
    if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)  return false;
    map<int, bool> m;
    int chooseRec = 0;
    return memSearch(chooseRec, desiredTotal, maxChoosableInteger, m);
}


//TODO: LC 406. Queue Reconstruction by Height
//greedy往往依赖顺序
int Ppartition(vector<pair<int, int> >& people, int begin, int end){
    int i = begin, j = end, r = people[begin].first, s = people[begin].second;
    while(i!=j){
        while(i<j&&people[j].first>=r)
            j--;
        while(i<j&&people[i].first<=r)
            i++;
        int tmp = people[i].first;
        people[i].first = people[j].first;
        people[j].first = tmp;
        tmp = people[i].second;
        people[i].second = people[j].second;
        people[j].second = tmp;
    }
    people[begin].first = people[i].first;
    people[begin].second = people[i].second;
    people[i].first = r;
    people[i].second = s;
    return i;
}
void quickSortPair(vector<pair<int, int> >& people, int begin, int end){
    if(begin<end){
        int pivot = Ppartition(people, begin, end);
        quickSortPair(people, begin, pivot-1);
        quickSortPair(people, pivot+1, end);
    }
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int> >& people) {
    quickSortPair(people, 0, (int)people.size()-1);
    vector<pair<int, int> > res(people.size());
    int i, j;
    for(i=0;i<people.size();i++){
        res[i].first = INT_MAX;
        res[i].second = -1;
    }
    int k;
    for(i=0;i<people.size();i++){
        k = people[i].second;
        for(j=0;j<people.size()&&k>0;j++){
            if(res[j].first>=people[i].first)
                k--;
        }
        while(res[j].second!=-1)
            j++;
        res[j].first = people[i].first;
        res[j].second = people[i].second;
    }
    return res;
}
//TODO: LC 853. Car Fleet
//栈特性解决（超越与覆盖）c++栈操作
int Vpartition(vector<int>& position, vector<int>& speed, int begin ,int end){
    int i = begin, j = end, r = position[begin], s = speed[begin];
    while(i!=j){
        while(i<j&&position[j]>=r)
            j--;
        while(i<j&&position[i]<=r)
            i++;
        int tmp = position[i];
        position[i] = position[j];
        position[j] = tmp;
        tmp = speed[i];
        speed[i] = speed[j];
        speed[j] = tmp;
    }
    position[begin] = position[i];
    speed[begin] = speed[i];
    position[i] = r;
    speed[i] = s;
    return i;
}
void sortCars(vector<int>& position, vector<int>& speed, int begin ,int end){
    if(begin<end){
        int pivot = Vpartition(position, speed, begin, end);
        sortCars(position, speed, begin, pivot-1);
        sortCars(position, speed, pivot+1, end);
    }
}
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    if(position.size() == 0)
        return 0;
    if(position.size() == 1)
        return 1;
    int i;
    sortCars(position,speed, 0, (int)speed.size()-1);
    stack<double> cf;
    vector<double> time(position.size());
    for(i=0;i<position.size();i++)
        time[i] =  (double)(target - position[i])/speed[i];
    for(i = 0; i < time.size(); i++){
        while(!cf.empty() && cf.top()<=time[i])
            cf.pop();
        cf.push(time[i]);
    }
    return (int)cf.size();
}

//TODO: LC 777.Swap Adjacent in LR String
//观察特征 辣鸡题
bool canTransform(string start, string end) {
    int reallen = 0, i, lcnt = 0, rcnt = 0;
    for(i = 0;i<start.length();i++){
        if(start[i]=='L')   lcnt++;
        else if(start[i]=='R')   rcnt++;
    }
    reallen = lcnt + rcnt;
    for(i = 0;i<end.length();i++){
        if(end[i]=='L')   lcnt--;
        else if(end[i]=='R')   rcnt--;
    }
    if(lcnt!=0||rcnt!=0)    return false;
    vector<vector<int> > rec(reallen, vector<int>(2, 0));
    int realcnt = 0;
    for(i=0;i<start.length();i++){
        if(start[i]=='L'){
            rec[realcnt][0] = 1;
            rec[realcnt][1] = i;
            realcnt++;
        }
        else if(start[i]=='R'){
            rec[realcnt][0] = 2;
            rec[realcnt][1] = i;
            realcnt++;
        }
    }
    for(i=0, realcnt = 0;i<end.length();i++){
        if(end[i]=='L'){
            if(rec[realcnt][0]==2) return false;
            if(i<rec[realcnt][1])   return false;
            realcnt++;
        }
        else if(end[i]=='R'){
            if(rec[realcnt][0]==1) return false;
            if(i>rec[realcnt][1])   return false;
            realcnt++;
        }
    }
    return true;
}
//TODO: LC 688. Knight Probability in Chessboard
//注意防止溢出 特别是指数 所以运算要分摊到每一次递归
//Hash的初步尝试 防止出现的碰撞：行数与列数的重合 乘法留出低位
//记忆化搜索比较慢 但是好写
double calKinds(map<int, double>& m, int N, int K, int r, int c){
    if(m.find((26*r+c)*1000+K)!=m.end())   return m[(26*r+c)*1000+K];
    double res = 0;
    if(K==0){
        res = (r>=0&&r<N&&c>=0&&c<N)?1:0;
        m[(26*r+c)*1000+K] = res;
        return res;
    }
    if(!(r>=0&&r<N&&c>=0&&c<N)){
        m[(26*r+c)*1000+K] = 0;
        return 0;
    }
    res = (calKinds(m, N, K-1, r-1, c+2) + calKinds(m, N, K-1, r-2, c+1) +
           calKinds(m, N, K-1, r-2, c-1) + calKinds(m, N, K-1, r-1, c-2) +
           calKinds(m, N, K-1, r+1, c-2) + calKinds(m, N, K-1, r+2, c-1) +
           calKinds(m, N, K-1, r+2, c+1) + calKinds(m, N, K-1, r+1, c+2))/8.0;
    m[(26*r+c)*1000+K] = res;
    return res;
}
double knightProbability(int N, int K, int r, int c) {
    map<int, double> m;
    if(K==0) return (r>=0&&r<N&&c>=0&&c<N);
    return (double)calKinds(m, N, K, r, c);
}

//TODO: LC 36. Valid Sudoku
//无脑水题、但是居然出现蛇皮bug
//注意index如果是表达式高度重视防止越界 如本题 board[i][j]-'0' '.'-'0'和'9'-'0'
bool isValidSudoku(vector<vector<char> >& board) {
    int i, j;
    vector<bool> rec(9, false);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            rec[j] = false;
        for(j=0;j<9;j++){
            if(board[i][j]!='.'&&rec[board[i][j]-'1']) return false;
            else if(board[i][j]!='.') rec[board[i][j]-'1'] = true;
        }
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            rec[j] = false;
        for(j=0;j<9;j++){
            if(board[j][i]!='.' && rec[board[j][i]-'1']) return false;
            else if(board[j][i]!='.') rec[board[j][i]-'1'] = true;
        }
    }
    int k, m, n;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            for(k=0;k<9;k++)
                rec[k] = false;
            for(m=i*3;m<i*3+3;m++){
                for(n=j*3;n<j*3+3;n++){
                    if(board[m][n]!='.'&&rec[board[m][n]-'1']) return false;
                    else if(board[m][n]!='.') rec[board[m][n]-'1'] = true;
                }
            }
        }
    return true;
}

//TODO: 741. Cherry Pickup
//来回相互影响 不能分开算
//往回走和去是一样的
//两个相互影响 不如同时出发 如果走到了同一格就只算一次
//同时出发 所以横纵坐标有关系x1+y1=t x2+y2=t
//转移方程dp(t, x1, x2) = grid(x1,t-x1)+(x1==x2?0:grid(x2, t - x2))+max(
//  dp(t-1, x1, x2),        //两个点两个方向移动产生的四种组合
//  dp(t - 1, x1, x2 - 1),
//  dp(t - 1, x1 - 1, x2),
//  dp(t - 1, x1 - 1, x2 - 1))
//t维度可以滚动压缩 所以逆序遍历
int cherryPickup(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = grid[0][0];
    int i, j, k;
    for(k=1;k<2*n-1;k++){
        for (i = min(n-1, k);i>=0&&i>=k-n+1;i--){
            for (j = min(n-1, k); j>=0 && j>=k-n+1;j--){
                int p = k - i, q = k - j;
                if (grid[i][p] == -1 || grid[j][q] == -1){
                    dp[i][j] = -1;
                    continue;
                }
                if(p>0 && j>0)
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(i>0){
                    if(j>0)
                        dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                    if(q>0)
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                if(dp[i][j] == -1)
                    continue;
                if(i == j)
                    dp[i][j] += grid[i][p];
                else
                    dp[i][j] += grid[i][p] + grid[j][q];
            }
        }
    }
    return max(dp[n-1][n-1], 0);
}
//TODO: 516. Longest Palindromic Subsequence
int longestPalindromeSubseq(string s) {
    int n = (int)s.length();
    vector<vector<int > > dp(n, vector<int>(n, 0));
    int i, j;
    for(i=0;i<n;i++)
        dp[i][i] = 1;
    for(i=n-2;i>=0;i--)
        for(j=i+1;j<n;j++){
            if(s[i]==s[j])
                dp[i][j] = dp[i+1][j-1] +2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    return dp[0][n-1];
}

//TODO: 228. Summary Ranges
//此类问题 跳跃式扫描问题 花瓶、座位等类似
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    string tmp;
    int i = 0, j;
    while(i<nums.size()){
        j = i+1;
        while(j<nums.size()&&nums[j]-nums[i]==j-i)
            j++;
        tmp = (j-1==i)?itoa(nums[i]):(itoa(nums[i]) + "->" + itoa(nums[j-1]));
        ans.push_back(tmp);
        i = j;
    }
    return ans;
}

//TODO: LC 354. Russian Doll Envelopes
//dp 经典 转化为LIS
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if(envelopes.size()<=1) return (int)envelopes.size();
    quickSortPair(envelopes, 0, (int)envelopes.size()-1);
    vector<int> dp(envelopes.size(), 1);
    for(int m=0;m<envelopes.size();m++)
        cout<<dp[m]<<' ';
    for(int m=0;m<envelopes.size();m++)
        cout<<'('<<envelopes[m].first<<' '<<envelopes[m].second<<')';
    int i, j, m = 1;
    for(i=1;i<envelopes.size();i++){
        for(j=0;j<i;j++){
            dp[i] = (envelopes[i].first>envelopes[j].first &&
                     envelopes[i].second>envelopes[j].second)?
            max(dp[i],dp[j]+1):dp[i];
        }
        m = max(m, dp[i]);
    }
    for(int m=0;m<envelopes.size();m++)
        cout<<dp[m]<<' ';
    return m;
}

//TODO: 779. K-th Symbol in Grammar
//找规律
int kthGrammar(int N, int K) {
    if(K<=2) return K==1?0:1;
    int x = 0;
    while(!(K<(1<<(x+1))&&K>=(1<<x)))
        x++;
    if(K==(1<<x))
        return x%2;
    else
        return kthGrammar(x+1, K-(int)pow(2, x))==1?0:1;
}

//TODO: LC 518. Coin Change 2
//循环的内外层顺序重要
//这里的问题是 假设硬币有1、2 面额为3的种类数有1+1+1 1+2两种
//但是如果硬币循环在内层，会把1+2 2+1算成两种，如果循环在外侧1走完走2，1就不会有干扰了
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(int i=0;i<coins.size();i++)
        for(int j=coins[i];j<=amount;j++){
            if(j-coins[i]>=0)
                dp[j] += dp[j-coins[i]];
        }
    return dp[amount];
}
//TODO: LC Excel Sheet Column Title
//很tricky
string convertToTitle(int n) {
    string res = "";
    char table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    while(n>0){
        if(n%26==0){
            res = 'Z' + res;
            n = n/26-1;
        }
        else{
            res = table[n%26-1] + res;
            n /= 26;
        }
    }
    return res;
}
