//
//  lc_randomly.h
//  FAT
//
//  Created by shidingyuan on 2018/8/7.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_randomly_h
#define lc_randomly_h
#include "stdHeader.h"
void split(string s, vector<string>& sub, char c);
bool valid6(string s);
bool valid4(string s);
string validIPAddress(string IP);

ListNode* deleteDuplicates(ListNode* head);
bool canPlaceFlowers(vector<int>& flowerbed, int n);
int guess(int num);
int guessNumber(int n);
int getMoneyAmount(int n);
bool isBadVersion(int version);
int firstBadVersion(int n);
int bsearchr(int target, vector<int>& nums);
int bsearchl(int target, vector<int>& nums);
vector<int> searchRange(vector<int>& nums, int target);
int pow1337(int x, int y);
int superPow(int a, vector<int>& b);
bool isIsomorphic(string s, string t);
vector<int> grayCode(int n);
string itoa(int n);
vector<string> subdomainVisits(vector<string>& cpdomains);
void mswap(vector<int>& nums, int index1, int index2);
void sortColors(vector<int>& nums);



int sumup(TreeNode *root, int sum);
int pathSum(TreeNode* root, int sum);
int coinChange(vector<int>& coins, int amount);
int numRabbits(vector<int>& answers);
ListNode* mergeKLists(vector<ListNode*>& lists);
int findMinMoves(vector<int>& machines);
bool checkRecord(string s);
int findLength(vector<int>& A, vector<int>& B);
bool memSearch(int chooseRec, int target, int maxChIn, map<int, bool>& m);
bool canIWin(int maxChoosableInteger, int desiredTotal);
int Ppartition(vector<pair<int, int> >& people, int begin, int end);
void quickSortPair(vector<pair<int, int> >& people, int begin, int end);
vector<pair<int, int>> reconstructQueue(vector<pair<int, int> >& people);
int Vpartition(vector<int>& position, vector<int>& speed, int begin ,int end);
void sortCars(vector<int>& position, vector<int>& speed, int begin ,int end);
int carFleet(int target, vector<int>& position, vector<int>& speed);
bool canTransform(string start, string end);
double calKinds(map<int, double>& m, int N, int K, int r, int c);
double knightProbability(int N, int K, int r, int c);
bool isValidSudoku(vector<vector<char> >& board);
int cherryPickup(vector<vector<int>>& grid);
int longestPalindromeSubseq(string s);
vector<string> summaryRanges(vector<int>& nums);
int maxEnvelopes(vector<pair<int, int>>& envelopes);
int kthGrammar(int N, int K);
int change(int amount, vector<int>& coins);
string convertToTitle(int n);
#endif /* lc_randomly_h */
