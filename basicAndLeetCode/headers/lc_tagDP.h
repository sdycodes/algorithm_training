//
//  lc_tagDP.h
//  FAT
//
//  Created by shidingyuan on 2018/8/16.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagDP_h
#define lc_tagDP_h

#include "stdHeader.h"

int minPathSum(vector<vector<int>>& grid);
int minimumTotal(vector<vector<int>>& triangle);
int uniquePaths(int m, int n);
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
bool stoneGame(vector<int>& piles);
bool PredictTheWinner(vector<int>& nums);
int numDecodings(string s);
int minDistance(string word1, string word2);
bool wordBreak(string s, vector<string>& wordDict);
int maxProduct(vector<int>& nums);
vector<int> getSmallerSquare(int n);
int numSquares(int n);
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines);
int maximalSquare(vector<vector<char>>& matrix);
int largestRectangleArea(vector<int>& heights);
int maximalRectangle(vector<vector<char>>& matrix);
int deleteAndEarn(vector<int>& nums);
int removeBoxes(vector<int>& boxes);
int maxCoins(vector<int>& nums);

#endif /* lc_tagDP_h */
