//
//  lc_tagTreeRecur.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/12.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//


#include "lc_tagTreeRecur.h"
//TODO:概览：
//group0:字符串
//Tools：包括通过字符串创建二叉树（略区别于leetcode规则）、按层展示二叉树
//606 通过树构建字符串
//297 树序列化与反序列化 参考了606 这些题目往往与遍历序有关
//652 找到重复树 单遍历序加入标记(空子树加入'#')使其唯一化
//体现的技巧是通过在遍历中加入符号(如括号、null等)保证单方式(前中后序)遍历顺序也是唯一的

//group1:树与递归
//814 二叉树剪枝 递归初阶
//655 打印二叉树 关键是位置的确定 行数为深度，简单 列数永远是子段的中间，所以递归

//group2:遍历
//230 简单树的遍历 第K小元素
//129 带前驱的遍历 求根到叶节点数字和
//872 DFS遍历 叶相似的树 记录叶节点
//508 记忆化搜索 最常见子树和 因为要把所有子树的和全部计算，自上而下会产生大量重复
//99 中序遍历 问题I BST中序后是单调序列，
//          问题II 如何求一个交换使得序列变成单调？找到峰和谷且左右两侧(如果存在)顺序是单调的
//96 非同构二叉树数量 简单动态规划

//group3:祖先问题
//235 BST的最近公共祖先LCA 记录BST中查找路径，逆序查找LCA
//865 所有最深节点的LCA，抓住深度的特征
//这类题目往往是看LCA的孩子的特征，BST就看搜索路径、deepest node就考虑深度
//236 没有任何特殊性的LCA 如果孩子无特征的通性求解方法：递归求解 还有一些对递归的更深入理解

//group4:搜索后效性问题
//687 最长同值路径
//124 最大路径和
//两个题思路基本一致，往往路径问题要这样做，因为后效性
//底层节点要向上层几点提供三个值：不包含自己的路径最大值、包含自己且可以向上连接(至多包含左右子树之一)的最大值、
//包含自己的最大值(可能跨越左右导致不能和上层节点连接)

//group5:递归增强性质
//222 完全二叉树的节点个数 利用了完全二叉树的性质，向下递归成为满二叉树，一类特殊的的递归使性质加强
//761 特殊01串 观察串的性质 两端夹至中部使性质消失返回或者不能拆分的最小特征串(其实还是再往下一层发现性质消失返回的)
//726 思路简单的暴力递归
//698 递归暴搜：递归与分治的不同没有merge、但这个递归也有点缩小范围、递归传递的参数和变换维度有关
//TODO: Tools
TreeNode* createByLayer(vector<string> nums, int start){
    if(nums[start]=="null") return NULL;
    if(start>=nums.size()) return NULL;
    TreeNode* root = new TreeNode(atoi(nums[start].c_str()));
    root->left = createByLayer(nums, (start<<1)+1);
    root->right = createByLayer(nums, (start<<1)+2);
    return root;
}
TreeNode* createTreefromString(string a){
    vector<string> nums;
    int i = 1;
    while(i<a.length()){
        if(a[i]=='n'){
            nums.push_back("null");
            i += 4;
        }
        else if((a[i]>='0'&&a[i]<='9')||a[i]=='-'){
            int j = i+1;
            while(a[j]>='0'&&a[j]<='9')
                j++;
            nums.push_back(a.substr(i, j-i));
            i = j;
        }
        i++;
    }
    return createByLayer(nums, 0);
}

void showByLayer(TreeNode* root){
    if(!root){
        cout<<"NULL"<<'\n';
        return;
    }
    vector<string> nums;
    queue<TreeNode*> Q;
    Q.push(root);
    nums.push_back(to_string(root->val));
    while(!Q.empty()){
        TreeNode* tmp = Q.front();
        Q.pop();
        if(tmp->left==NULL&&tmp->right==NULL)
            continue;
        nums.push_back(tmp->left==NULL?"null":to_string(tmp->left->val));
        if(tmp->left) Q.push(tmp->left);
        nums.push_back(tmp->right==NULL?"null":to_string(tmp->right->val));
        if(tmp->right) Q.push(tmp->right);
    }
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<' ';
    return;
}


//TODO: LC 606. Construct String from Binary Tree
//左右不完全对称递归
string tree2str(TreeNode* t) {
    if(t==NULL) return "";
    if(t->left==NULL&&t->right==NULL) return to_string(t->val);
    return to_string(t->val) + "("+tree2str(t->left)+")" + (t->right?"("+tree2str(t->right)+")":"");
}

//TODO: LC 297. Serialize and Deserialize Binary Tree
//mark 完全自主的一道hard
//参考了（）式的表达方法
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root==NULL) return "";
    if(root->left==NULL&&root->right==NULL) return to_string(root->val);
    return to_string(root->val) + "("+serialize(root->left)+")" + "("+serialize(root->right)+")";
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data=="")    return NULL;
    if(data[data.length()-1]!=')'){
        TreeNode* root = new TreeNode(atoi(data.c_str()));
        return root;
    }
    int i = 0;
    while(i<data.length()&&data[i]!='(')
        i++;
    TreeNode* root = new TreeNode(atoi(data.substr(0, i).c_str()));
    int lefnum = 1;
    int j = i+1;
    while(j<data.length()){
        if(data[j]=='(') lefnum++;
        else if(data[j]==')') lefnum--;
        if(lefnum==0) break;
        j++;
    }
    root->left = deserialize(data.substr(i+1,j-i-1));
    root->right = deserialize(data.substr(j+2, data.length()-j-3));
    return root;
}


//TODO: LC 652. Find Duplicate Subtrees
//重要思想：树的特征表示 前序/后续序列 这个序列是其对应完全二叉树来说唯一
//技巧：1、to_string 不再使用itoa 2、unordered_map默认值为0
string preorder(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& times) {
    if(!root) return "#";
    string str = to_string(root->val) + "," + preorder(root->left, res, times) + "," + preorder(root->right, res, times);
    times[str]++;
    if(times[str]==2) {
        res.push_back(root);
    }
    return str;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> res;
    unordered_map<string, int> times;
    preorder(root, res, times);
    return res;
}

//TODO: LC 814. Binary Tree Pruning
//递归 注意短路运算的坑
TreeNode* pruneTree(TreeNode* root) {
    if(!root) return NULL;
    if(root->left==NULL&&root->right==NULL) return root->val==0?NULL:root;
    root->left=pruneTree(root->left);
    root->right=pruneTree(root->right);
    if(root->left==NULL&&root->right==NULL)
        return root->val==0?NULL:root;
    return root;
}

//TODO: LC 655. Print Binary Tree
//看上去是BFS 但是递归更简单
void putNode(TreeNode* root, int l, int r, int d, vector<vector<string> >& res){
    int mid  = (l+r)>>1;
    res[d][mid] = to_string(root->val);
    if(root->left) putNode(root->left, l, mid, d+1, res);
    if(root->right) putNode(root->right, mid+1, r, d+1, res);
    return;
}
int calDepth(TreeNode* root){
    if(!root) return 0;
    if(root->left==NULL&&root->right==NULL)  return 1;
    return 1+ max(calDepth(root->left), calDepth(root->right));
}
vector<vector<string>> printTree(TreeNode* root) {
    int depth = calDepth(root);
    int wide = (int)pow(2, depth)-1;
    vector<vector<string> > res(depth, vector<string> (wide, ""));
    putNode(root, 0, wide, 0, res);
    return res;
}

//TODO: LC 230. Kth Smallest Element in a BST
//遍历
int kthSmallest(TreeNode* root, int k) {
    vector<int> nums;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* tmp = Q.front();
        Q.pop();
        nums.push_back(tmp->val);
        if(tmp->left) Q.push(tmp->left);
        if(tmp->right) Q.push(tmp->right);
    }
    sort(nums.begin(), nums.end());
    return nums[k-1];
}


//TODO: LC 129. Sum Root to Leaf Numbers
//水题
void calLeafNum(TreeNode* root, vector<int>& sums, int pre){
    if(!root)   return;
    if(root->left==NULL&&root->right==NULL){
        sums.push_back(pre*10+root->val);
        return;
    }
    if(root->left)  calLeafNum(root->left, sums, pre*10+root->val);
    if(root->right) calLeafNum(root->right, sums, pre*10+root->val);
    return;
}
int sumNumbers(TreeNode* root) {
    vector<int> sums;
    calLeafNum(root, sums, 0);
    return accumulate(sums.begin() , sums.end() , 0);
}

//TODO: LC 872. Leaf-Similar Trees
//本质DFS
void getLeafValSeq(TreeNode* root, vector<int>& seq){
    if(!root) return;
    if(root->left==NULL&&root->right==NULL) seq.push_back(root->val);
    if(root->left)  getLeafValSeq(root->left, seq);
    if(root->right)  getLeafValSeq(root->right, seq);
    return;
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1, seq2;
    getLeafValSeq(root1, seq1);
    getLeafValSeq(root2, seq2);
    if(seq1.size()!=seq2.size())    return false;
    for(int i=0;i<seq1.size();i++)
        if(seq1[i]!=seq2[i])    return false;
    return true;
}

//TODO: LC 508. Most Frequent Subtree Sum
//记忆化搜索意图明显
int calSubtreeSum(TreeNode* root, map<TreeNode*, int>& memo){
    if(!root) return 0;
    if(memo.find(root)==memo.end())
        memo[root] = root->val+calSubtreeSum(root->left, memo)+calSubtreeSum(root->right, memo);
    return memo[root];
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    if(!root) return {};
    map<TreeNode*, int> memo;
    map<int, int> times;
    int maxtime = 1;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* tmp = Q.front();
        Q.pop();
        int sum = calSubtreeSum(tmp, memo);
        if(times.find(sum)!=times.end())
            times[sum]++;
        else times[sum] = 1;
        maxtime = max(maxtime, times[sum]);
        if(tmp->left) Q.push(tmp->left);
        if(tmp->right) Q.push(tmp->right);
    }
    map<int, int>::iterator t = times.begin();
    vector<int> res;
    while(t!=times.end()){
        if(t->second==maxtime)
            res.push_back(t->first);
        t++;
    }
    return res;
}

//TODO: LC 99. Recover Binary Search Tree
//中序遍历  交换的算法
void inorderTraverse(TreeNode* root, vector<TreeNode*>& seq){
    if(root){
        inorderTraverse(root->left, seq);
        seq.push_back(root);
        inorderTraverse(root->right, seq);
    }
}
void recoverTree(TreeNode* root) {
    vector<TreeNode*> seq;
    inorderTraverse(root, seq);
    for(int i=0;i<seq.size();i++)
        cout<<seq[i]->val<<' ';
    TreeNode* high = seq[0];
    TreeNode* low = seq[0];
    for(int i=0;i<seq.size()-1;i++){
        if(i==0&&seq[i]->val>seq[i+1]->val) high = seq[i];
        else if(i!=0&&seq[i]->val>seq[i-1]->val&&seq[i]->val>seq[i+1]->val&&seq[i-1]->val<seq[i+1]->val)
            high = seq[i];
    }
    for(int i=1;i<seq.size();i++){
        if(i==seq.size()-1&&seq[i]->val<seq[i-1]->val) low = seq[i];
        else if(i!=seq.size()-1&&seq[i]->val<seq[i-1]->val&&seq[i]->val<seq[i+1]->val&&seq[i-1]->val<seq[i+1]->val)
            low = seq[i];
    }
    int tmp = high->val;
    high->val = low->val;
    low->val = tmp;
}

//TODO: LC 96. Unique Binary Search Trees
//其实是动态规划
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i-1;j++)
            dp[i] += dp[j]*dp[i-1-j];
    }
    return dp[n];
}





//TODO: LC 235. Lowest Common Ancestor of a Binary Search Tree
//二重循环的break问题
void calSearchPath(TreeNode* tmp, TreeNode* p, vector<TreeNode*>& path){
    while(tmp->val!=p->val){
        path.push_back(tmp);
        if(tmp->val>p->val)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    path.push_back(p);
}
TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path1, path2;
    calSearchPath(root, p, path1);
    calSearchPath(root, q, path2);
    int i, j;
    bool tag = false;
    for(i=(int)path1.size()-1;i>=0;i--){
        for(j=(int)path2.size()-1;j>=0;j--){
            if(path1[i]==path2[j]){
                tag = true;
                break;
            }
        }
        if(tag)    break;
    }
    return path1[i];
}


//TODO: LC 865. Smallest Subtree with all the Deepest Nodes ！good
//如果想先找到最深的再反求共同祖先 需要记录路径 比较繁琐
//不如直接跟据左右子树的深度自顶向下求解
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int ld = calDepth(root->left);
    int rd = calDepth(root->right);
    if(ld==rd)  return root;
    return ld>rd?subtreeWithAllDeepest(root->left):subtreeWithAllDeepest(root->right);
}

//TODO: LC 236. Lowest Common Ancestor of a Binary Tree
//加深了对递归的理解：一切取决于出口的定义
//比如本题的出口是找到了p或q退出，那么递归情况左右返回的值如果不是空只表示返回的节点的子树包含了至少一个节点
//但并不一定都包含，所以需要综合考虑左右两棵子树来判断
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root||root==p||root==q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(l&&r)    return root;
    return l?l:r;
}

//TODO: LC 687. Longest Univalue Path
//基本思路和最大路径和一样
//注意res的下溢问题
vector<int> calLongestPath(TreeNode* root, int& res){
    if(!root)   return {0, 0, 0};
    if(root->left==NULL&&root->right==NULL) return {1, 1, 1};
    vector<int> inc(3);
    vector<int> l = calLongestPath(root->left, res);
    vector<int> r = calLongestPath(root->right, res);
    inc[0] = max(max(l[0],l[2]), max(r[0], r[2]));
    bool leq = root->left&&(root->val==root->left->val);
    bool req = root->right&&(root->val==root->right->val);
    if(leq&&req)    inc[1] = 1+max(l[1], r[1]);
    else if(leq||req)   inc[1] = 1 + (leq?l[1]:r[1]);
    else    inc[1] = 1;
    inc[2] = 1 + (leq?l[1]:0) + (req?r[1]:0);
    res = max(res, max(inc[0], max(inc[1], inc[2])));
    return inc;
}
int longestUnivaluePath(TreeNode* root) {
    int res = 0;
    calLongestPath(root, res);
    return res==0?0:res-1;
}

//TODO: LC 124. Binary Tree Maximum Path Sum
//因为自下而上的后效性 为上层提供3个数字 不包含自己、包含且可以复用（只有一条路）、包含且不可以复用（跨越了根）
//不是dp、也不需要memo search 因为只走一次
vector<int> calMaxPath(TreeNode* root, int& res){
    if(!root)   return {INT_MIN, INT_MIN, INT_MIN};
    if(root->left==NULL&&root->right==NULL) return {root->val, root->val, root->val};
    vector<int> inc(3);
    vector<int> l = calMaxPath(root->left, res);
    vector<int> r = calMaxPath(root->right, res);
    inc[0] = max(max(l[0],l[2]), max(r[0], r[2]));
    inc[1] = max(root->val+max(l[1], 0), root->val+max(r[1], 0));
    inc[2] = root->val + max(l[1], 0) + max(r[1], 0);
    res = max(res, max(inc[0], max(inc[1], inc[2])));
    return inc;
}
int maxPathSum(TreeNode* root){
    int res = root->val;
    calMaxPath(root, res);
    return res;
}

//TODO: LC 222. Count Complete Tree Nodes
//如何利用性质  递归直至成为满二叉树
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int l = 0, r = 0;
    TreeNode* tmp = root;
    while(tmp){
        tmp = tmp->left;
        l++;
    }
    tmp = root;
    while(tmp){
        tmp = tmp->right;
        r++;
    }
    if(l==r) return (1<<l) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//TODO: LC 761. Special Binary String !good
//观察特征：
//special保证1M0中部M一定也是special的，M中1和0一样多
//如果M不是special会进行很多无效劳动（可以进行优化），但是不影响结果，原样返回
//如果M是special，就会进入递归状态，M可能会有很多个special，按照深度从大到小排序返回
//类比括号匹配 1对应（，0对应的），
//不会再出现1M0
string makeLargestSpecial(string S) {
    vector<string> pairs;
    int lefnum = 0;
    int pre= -1;
    for(int i=0;i<S.length();i++){
        if(S[i]=='1')   lefnum++;
        else if(S[i]=='0')  lefnum--;
        if(lefnum==0){
            pairs.push_back('1' + makeLargestSpecial(S.substr(pre+2, i-pre-2)) + '0');
            pre = i;
        }
        else if(lefnum<0)
            return  S;
    }
    sort(pairs.begin(), pairs.end(), greater<string>());
    string res = "";
    for(int i=0;i<pairs.size();i++)
        res += pairs[i];
    return res;
}

//TODO: LC 726. Number of Atoms
//繁琐的递归
void calElemNum(string formula, int times, map<string, int>& cnt){
    if(formula.length()==0) return;
    int i = 0;
    while(i<formula.length()){
        if(formula[i]>='A'&&formula[i]<='Z'){
            int j = i+1;
            while(j<formula.length()&&formula[j]>='a'&&formula[j]<='z')
                j++;
            string elem = formula.substr(i, j-i);
            if(j==formula.length()||(formula[j]<'0'||formula[j]>'9')){
                cnt[elem] += times;
                i = j;
            }
            else{
                int k = j+1;
                while(k<formula.length()&&formula[k]>='0'&&formula[k]<='9')
                    k++;
                int num = stoi(formula.substr(j, k-j));
                cnt[elem] += num*times;
                i = k;
            }
        }
        else if(formula[i]=='('){
            int j = i+1;
            int lefnum = 1;
            while(lefnum!=0){
                if(formula[j]=='(') lefnum++;
                else if(formula[j]==')') lefnum--;
                j++;
            }
            if(j==formula.length()||(formula[j]>'9'||formula[j]<'0')){
                calElemNum(formula.substr(i+1, j-i-2), times, cnt);
                i = j;
            }
            else{
                int k = j+1;
                while(k<formula.length()&&formula[k]>='0'&&formula[k]<='9')
                    k++;
                int factor = stoi(formula.substr(j, k-j));
                calElemNum(formula.substr(i+1, j-i-2), times*factor, cnt);
                i = k;
            }
        }
    }
    return;
}
string countOfAtoms(string formula) {
    map<string, int> cnt;
    calElemNum(formula, 1, cnt);
    map<string, int>::iterator t = cnt.begin();
    vector<string> elem_cnt;
    while(t!=cnt.end()){
        elem_cnt.push_back(t->first+(t->second==1?"":to_string(t->second)));
        t++;
    }
    sort(elem_cnt.begin(), elem_cnt.end());
    string res = "";
    for(int i=0;i<elem_cnt.size();i++)
        res += elem_cnt[i];
    return res;
}

//TODO: LC 698. Partition to K Equal Sum Subsets
//其实就是暴搜
//递归问题和分治的区别：有无merge过程
//如何思考子问题 两个变换维度：子数组和与子数组的个数
bool calPartition(vector<int> nums, int set, vector<bool>& visited, int cur, int tar, int start){
    if(set==1)  return true;    //已经分好了
    if(cur==tar) return calPartition(nums, set-1, visited, 0, tar, 0); //这个组的和够了，考察少一个组的情况
    for(int i=start;i<nums.size();i++){ //这个组的和不够，一个一个加入尝试，从start开始
        if(!visited[i]){
            visited[i] = true;
            if(calPartition(nums, set, visited, cur+nums[i], tar, i+1))
                return true;
            visited[i] = false;
        }
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%k!=0)    return false;
    vector<bool> visited(nums.size(), false);
    return calPartition(nums, k, visited, 0, sum/k, 0);
}
