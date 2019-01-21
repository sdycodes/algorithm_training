//
//  lc_tagDP.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/16.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_tagDP.h"

//TODO: 概览
//group0:路径选择、直观子问题
//64 最小路径和 自下而上的备选方案
//120 三角形路径和 自上而下的备选方案
//62 独一无二路径 直观子问题
//63 有障碍物的独一无二路径 注意约定要以方便为准

//group1:胜负问题
//877 石子游戏
//486 预测赢家
//两题类似、后者性质更弱一些 考虑点就是第二个人玩看作是子问题

//group2:几何问题
//764 最大加号 辅助信息 极大化极小
//221 最大正方形 正方形具有良好的性质（面积和变长正相关且对称、这使得dp便于考虑）
//85 最大矩形 矩形的面积和变长关系不明显，导致研究左上角相互覆盖变得很难，思路是二维压缩成一维
//而一维问题是84 涉及栈的特性 也是好题
//84 直方图中的最大矩形 栈的暂存维护单调性

//group3:数组与区间问题
//740 删除得分  这个问题的选择影响方式是数字的大小 从此考虑构造dp
//546 删除盒子 单纯的区间不足以记录全部的有效信息，因为外面可以对此区间构成影响，注意和无后效性的区别
//为了记录这个额外信息，需要根据特性增加dp矩阵维度
//312 戳气球 戳破的气球影响到的是两侧的气球、所以这是突破口 最后戳破的气球可以作为分割点、此外两侧加点变成开区间十分巧妙
//注意点：区间dp的更新顺序，for len 0 to n for left 0 to n-k 主对角线向右上更新
//152 简单区间dp  更新顺序未遵从前述，因为行数是倒序（区间分割需要的dp数据在矩阵中是‘7’形）
//279 完美平方数 水题

//group4:字符串
//91 解码方式 注意dp[i] i是len还是index
//72 编辑距离 经典题目
//139 单词分割 枚举分割点
//上面三道，由于字符串不存在变长问题，所以比较简单，dp方式一般是从头拓展 下面两到涉及变长通配符
//10 正则表达式匹配
//44 通配符匹配(在回溯的源文件里)
//这两道的问题是*的匹配长度不确定，导致了后效性，所以是用dp并不是一个很好的方法，使用回溯法
//对于回溯的理解还比较肤浅，目前认为有两类 递归法和迭代法
//递归法写即所想、思路简单 迭代法记录迭代点 更新迭代点根据题目特性、较难


//TODO: LC 64. Minimum Path Sum
//经典选择模型 dp提供备择方案（从这个点向右or下）
int minPathSum(vector<vector<int> >& grid){
    int m = (int)grid.size(), n = (int)grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[m-1][n-1] = grid[m-1][n-1];
    for(int i=m-2;i>=0;i--)
        dp[i][n-1]  = dp[i+1][n-1] + grid[i][n-1];
    for(int j=n-2;j>=0;j--)
        dp[m-1][j] = dp[m-1][j+1] + grid[m-1][j];
    for(int i = m-2;i>=0;i--)
        for(int j = n-2;j>=0;j--)
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
    return dp[0][0];
}

//TODO: LC 120. Triangle
//经典选择模型、运用了滚动数组 dp提供备择方案（从前一层哪个点落到这一层）
//虽然一个倒着 一个正着 但是都是提供选择方案
int minimumTotal(vector<vector<int>>& triangle) {
    int n = (int)triangle.size();
    int res = INT_MAX;
    vector<int> dp(n, INT_MAX);
    vector<int> pre(n, INT_MAX);
    dp[0] = triangle[0][0];
    for(int i=1;i<n;i++){
        int j = 0;
        while(dp[j]!=INT_MAX){
            pre[j] = dp[j];
            dp[j] = INT_MAX;
            j++;
        }
        j =0;
        while(pre[j]!=INT_MAX){
            dp[j] = min(dp[j], pre[j]+triangle[i][j]);
            dp[j+1] = min(dp[j+1], pre[j]+triangle[i][j+1]);
            j++;
        }
    }
    for(int i=0;i<n;i++)
        res = min(res, dp[i]);
    return res;
}

//TODO: LC 62. Unique Paths
//子问题
int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int>(n, 0));
    for(int i=0;i<n;i++)
        dp[m-1][i] = 1;
    for(int i=0;i<m;i++)
        dp[i][n-1] = 1;
    for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
            dp[i][j] = dp[i+1][j]+dp[i][j+1];
    return dp[0][0];
}

//TODO: LC 63. Unique Paths II
//和前一问有一些不同 关键是位置上的路径数含义的约定要适合
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = (int)obstacleGrid.size(), n = (int)obstacleGrid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[m-1][n-1] = (obstacleGrid[m-1][n-1]==1?0:1);
    for(int i=n-2;i>=0;i--)
        dp[m-1][i] = obstacleGrid[m-1][i]==0?dp[m-1][i+1]:0;
    for(int i=m-2;i>=0;i--)
        dp[i][n-1] = obstacleGrid[i][n-1]==0?dp[i+1][n-1]:0;
    for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
            dp[i][j] = (obstacleGrid[i][j]==1?0:(dp[i+1][j]+dp[i][j+1]));
    return dp[0][0];
}

//TODO: LC 877. Stone Game
//区间dp 这个和之前一道很像 当时用了记忆化搜索
//关键是找对判断胜负的逻辑
//本题：<=2必赢, >2模拟半轮（选一头使对方输）不能模拟一轮（因为拿掉一个以后情况就变了）
bool stoneGame(vector<int>& piles) {
    int n = (int)piles.size();
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    for(int i=0;i<n;i++)
        dp[i][i] = true;
    for(int i=n-2;i>=0;i--)
        for(int j = i+1;j<n;j++)
            dp[i][j] = (j-i+1<=2)||(!dp[i+1][j])||(!dp[i][j-1]);
    return dp[0][n-1];
}

//TODO: LC 486. Predict the Winner
//这个题和前面有区别：两个性质消失（不一定是偶数组、和可能相等）
//所以需要一个dpa辅助数组记录相应的信息来帮助判断
bool PredictTheWinner(vector<int>& nums) {
    int n = (int)nums.size();
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    vector<vector<int> > dpa(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        dp[i][i] = true;
        dpa[i][i] = nums[i];
    }
    for(int i=n-2;i>=0;i--)
        for(int j = i+1;j<n;j++){
            dp[i][j] = (j-i+1<=2)||(!dp[i+1][j])||(!dp[i][j-1])||(nums[j]-dpa[i][j-1]>=0)||(nums[i]-dpa[i+1][j]>=0);
            dpa[i][j] = j-i+1<=2?max(nums[i],nums[j])-min(nums[i], nums[j]):max(nums[j]-dpa[i][j-1],nums[i]-dpa[i+1][j]);
        }
    return dp[0][n-1];
}


//TODO: LC 764. Largest Plus Sign
//几何问题 存储大量的辅助信息
//同时注意几个循环实在不好和在一起 循环上下限和顺序都不一样
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int> > grid(N, vector<int>(N, 1));
    vector<vector<int> > l(N, vector<int>(N, 1));
    vector<vector<int> > r(N, vector<int>(N, 1));
    vector<vector<int> > u(N, vector<int>(N, 1));
    vector<vector<int> > d(N, vector<int>(N, 1));
    for(int i=0;i<mines.size();i++)
        grid[mines[i][0]][mines[i][1]] = 0;
    for(int i=0;i<N;i++){
        l[i][0] = (grid[i][0]==0?0:1);
        r[i][N-1] = (grid[i][N-1]==0?0:1);
        u[0][i] = (grid[0][i]==0?0:1);
        d[N-1][i] = (grid[N-1][i]==0?0:1);
    }
    for(int i=0;i<N;i++)
        for(int j=1;j<N;j++)
            l[i][j] = grid[i][j]==0?0:(1+l[i][j-1]);
    for(int i=0;i<N;i++)
        for(int j=N-2;j>=0;j--)
            r[i][j] = grid[i][j]==0?0:(1+r[i][j+1]);
    for(int i=1;i<N;i++)
        for(int j=0;j<N;j++)
            u[i][j] = grid[i][j]==0?0:(1+u[i-1][j]);
    for(int i=N-2;i>=0;i--)
        for(int j=0;j<N;j++)
            d[i][j] = grid[i][j]==0?0:(1+d[i+1][j]);
    int res = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            res = max(res, min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j])));
    return res;
}

//TODO: LC 221. Maximal Square
//几何问题2:正方形的特殊性、良好的重叠性质
//dp是一个范围还是一个点（包含该点的最优解）
//如果是后者，实时更新结果，注意初始化也要更新
int maximalSquare(vector<vector<char>>& matrix) {
    int m = (int)matrix.size();
    if(m==0)    return 0;
    int n = (int)matrix[0].size();
    if(n==0)    return 0;
    vector<vector<int> > dp(m, vector<int>(n, 0));
    int res = 0;
    for(int i=0;i<n;i++){
        dp[0][i] = matrix[0][i]=='0'?0:1;
        res = max(res, dp[0][i]);
    }
    for(int i=0;i<m;i++){
        dp[i][0] = matrix[i][0]=='0'?0:1;
        res = max(res, dp[i][0]);
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++){
            dp[i][j] = matrix[i][j]=='0'?0:(1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])));
            res = max(res, dp[i][j]);
        }
    return res*res;
}

//TODO: LC 84. Largest Rectangle in Histogram good&hard
//这个题是为85打基础的、本题蛮力n^2、优化到n，这适合使用栈的暂存特性
//dp适合于把指数降到多项式
//本题维护了一个单调的栈
int largestRectangleArea(vector<int>& heights) {
    if(heights.size()==0) return 0;
    heights.push_back(-1);  //保证最后全部元素出栈、否则单调顺序没有机会
    stack<int> s;
    int res = 0;
    for(int i=0;i<heights.size();i++){
        if(s.empty()||heights[i]>heights[s.top()])  //栈空或单调、入栈
            s.push(i);
        else{   //不再单调，意味着栈内的元素不能继续向右延伸了、开始出栈并计算能够达到的面积
            int r = s.top();
            s.pop();    //由入栈是和栈顶的比较判断来看，栈内元素单调增，所以栈顶元素向左的延伸也是有限度的
            res = max(res, heights[r]*(s.empty()?i:(i-s.top()-1)));
            //向右延伸到i、向左延伸到当前栈顶(也就是r左边最近且<heights[r]的元素)
            i--;   //i--是因为for循环i++，但是目前只处理了一个栈顶，接下来可能持续出栈，所以停在当前位置
        }
    }
    return res;
}

//TODO: LC 85. Maximal Rectangle
//二位的另一种处理方法、压缩成一维
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = (int)matrix.size();
    if(m==0)    return 0;
    int n = (int)matrix[0].size();
    if(n==0) return 0;
    int res = 0;
    for(int i=0;i<m;i++){
        vector<int> histogram(n, 0);
        for(int j=0;j<n;j++){
            int l = i;
            while(l>=0&&matrix[l][j]=='1'){
                histogram[j]++;
                l--;
            }
        }
        res = max(res, largestRectangleArea(histogram));
    }
    return res;
}

//TODO: LC 740. Delete and Earn
//子问题构造的巧妙性、从受影响的方式进行思考、
//本题受影响的方式是大小关系、而且恰好是一种相邻的方式
//所以从此入手构造子问题
int deleteAndEarn(vector<int>& nums) {
    if(nums.size()==0)  return 0;
    int cnt[10001] = {0};
    for(int i=0;i<nums.size();i++)
        cnt[nums[i]]++;
    int dp[10001] = {0};
    dp[1] = cnt[1];
    for(int i=2;i<=10000;i++)
        dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i);
    return dp[10000];
}


//TODO: LC 546. Remove Boxes WTF
//此类的题目归纳为不自己包含的子问题，其解法依赖于一些子问题以外的信息。
//这类问题通常没有定义好的重现关系，所以不太容易递归求解。
//为解决这类问题需要修改问题定义，使其包含一些外部信息变成自包含子问题。
//区间dp、滚动数组注意循环次序
int removeBoxes(vector<int>& boxes){
    if(boxes.size()==0)
        return 0;
    int n = (int)boxes.size();
    vector<vector<vector<int> > > dp(n,vector<vector<int> >(n,vector<int>(n,0)));
    //初始化、当前点有k个前缀、获得的分数(1+k)^2
    for(int i=0;i<n;i++)
        for(int k=0;k<=i;k++)
            dp[i][i][k] = (1+k)*(1+k);
    for(int len=1;len<n;len++) //枚举子段长
        for(int j = len;j<n;j++){   //len长度下所有可能的结尾
            int i = j - len + 1;    //由结尾j和长度len确定开头i
            for(int k = 0;k<i;k++){   //由开头i位置确定所有可能的前缀长
                int res = (1+k)*(1+k) + dp[i][j][0]; //初始化res:不考虑i～j段内的连续问题
                for(int m = i;m<=j;m++) //前缀长度向内部拓展
                    res = boxes[m]==boxes[i-1]?max(res, dp[i][m-1][0]+dp[m][j][k+1]):res;
                dp[i-1][j][k] = res;    //前缀拓展完成，找到了外部有k长度前缀时i～j区间的最大得分
            }
        }
    return dp[0][n-1][0];
}

//TODO: LC 312. Burst Balloons
//乍一看不是子问题自包含、好像要增加维度(因为当前选择会改变处境、伪后效性)
//所谓无后效性，是子问题的最优解和大问题无关，选择戳破的集合为M，剩余为N，那么N的最优解之和N有关
//因此从这个无后效性开始着手构造dp
//发现看上去的相互影响其实可以通过最后戳破点分割使导致的伪后效性限制在边界上
//规范化带来极大的便利，规范化造成研究的区间变成了开区间，这样选取的分割点一定在两者之间，是真分割
//这种属于区间切割其实本质还是区间dp
//区间dp高度注意循环顺序的问题、一般套路长度最外、某端点次外、斜对角线上三角
//区间dp的需求是横折形
int maxCoins(vector<int>& nums) {
    int m = (int)nums.size();
    if(m==0)    return 0;
    int arr[m+2];
    for(int i=1;i<m+1;i++)
        arr[i] = nums[i-1];
    arr[0] = 1;
    arr[m+1] = 1;   //规范化 两侧两个1、防止溢出
    int n = (int)nums.size()+2;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int k=2;k<n;k++){
        for(int left = 0;left<n-k;left++){
            int right = left + k;
            for(int i=left+1;i<right; i++)  //i是最后一个被戳破的气球，另外左右两端是开区间，因为规范化了
                dp[left][right] = max(dp[left][right],
                                      arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right]);
        }
    }
    return dp[0][n-1];
}

//TODO: LC 152. Maximum Product Subarray
//明显的区间dp 但是最后超内存限制 预处理删掉连续的-1
//遇到1也删除 但是注意这样结果至少是1
int maxProduct(vector<int>& nums) {
    int res = INT_MIN;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==1){
            nums.erase(nums.begin()+i);
            res = 1;
            i--;
        }
        if(nums[i]==-1&&nums[i+1]==-1){
            nums.erase(nums.begin()+i);
            nums[i] = 1;
            i--;
        }
    }
    int n = (int)nums.size();
    if(n==0)    return 1;
    vector<vector<int> > dp(n, vector<int>(n, INT_MIN));
    for(int i=0;i<n;i++){
        dp[i][i] = nums[i];
        res = max(res, dp[i][i]);
    }
    for(int i=n-2;i>=0;i--)
        for(int j = i+1;j<n;j++)
            for(int k=i+1;k<=j;k++){
                dp[i][j] = max(dp[i][k-1]*dp[k][j], dp[i][j]);
                res = max(res, dp[i][j]);
            }
    return res;
}

//TODO: LC 279. Perfect Squares
//较为明显的子问题
vector<int> getSmallerSquare(int n){
    int i = 1;
    vector<int> res;
    while(i*i<=n){
        res.push_back(i*i);
        i++;
    }
    return res;
}
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        vector<int> choose = getSmallerSquare(i);
        for(int j=0;j<choose.size();j++){
            dp[i] = min(dp[i], 1+dp[i-choose[j]]);
        }
    }
    return dp[n];
}

//TODO: LC 91. Decode Ways
//为了不让可能溢出的情况特判。加了一个头 整体位置都向后错开了一位，容易出错
//需要考虑0的问题
int numDecodings(string s) {
    if(s.length()==0)   return 0;
    vector<int> dp(s.length()+1, 0);
    dp[0] = 1;
    dp[1] = s[0]=='0'?0:1;
    for(int i=2;i<=s.length();i++)
        dp[i] = (s[i-1]=='0'?0:dp[i-1]) + ((s[i-2]!='0'&&stoi(s.substr(i-2, 2))<=26)?dp[i-2]:0);
    return dp[s.length()];
}

//TODO: LC 72. Edit Distance
//经典题目 又一次注意到i表示index还是长度的问题
int minDistance(string word1, string word2) {
    int m = (int)word1.length(), n = (int)word2.length();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i=0;i<=n;i++)
        dp[0][i] = i;
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = min(dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1),
                           min(dp[i-1][j]+1, dp[i][j-1]+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    return dp[m][n];
}

//TODO: LC 139. Word Break
//和91几乎一样 这一次没有加头 因为特判简单而且算字符串指标太麻烦
bool wordBreak(string s, vector<string>& wordDict) {
    int n = (int)s.length();
    vector<bool> dp(n, false);
    for(int i=0;i<n;i++)
        for(int j=i;j>=0;j--){
            string w = s.substr(j, i-j+1);
            if(find(wordDict.begin(), wordDict.end(), w)!=wordDict.end()&&(j==0||dp[j-1])){
                dp[i] = true;
                break;
            }
        }
    return dp[n-1];
}

