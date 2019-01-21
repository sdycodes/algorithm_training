//
//  lc_tagST_BIT.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/20.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "lc_tagST_BIT.h"

//TODO: 概览
//group0 区间管理、线段树
//基本法、线段树管理
//线段树section中记录了一套支持懒标记且空间复杂度在2N的算法
//操作：建树、下传、单点查询、区间查询、单点修改、区间修改
//线段树的好处是操作很快，如果是logn的话基本就是常数了
//但是空间复杂度很高，如果考察的区间范围在1e8以上基本内存gg
//通常会使用更加平衡时间空间的方法
//699 下落正方形 三元组的管理方法（左右记录） 不合并
//218 天际线  (这个比较复杂 需要看前面的情况)
//850 长方形重叠面积   条带化思想、区间重叠管理   处理合并
//715 区间模型  前面三个问题的全面管理方式总结（有点低效）
//上面4题属于元组管理的方式，记录各个不重叠的区间和有关信息
//处理的复杂度一般为O(n) 但是空间复杂度比线段树低很多
//732 我的日历  另一种管理方式，只记录端点的信息，这个和题目的性质有关
//总之三种方式：线段树管理所有的点，空间大 速度快 元组管理出现的区间 端点法之记录端点信息
//group1 树状数组
//特点是批量操作求和会比较快
//493 反转对 限制条件（两倍以上）的逆序计数问题、前面发现更小的元素会进行批量操作增加逆序数、这是树状数组的特征
//group3 补充
//又做了几个题 区间管理新方式

//TODO: 线段树 支持懒操作且空间复杂度在2N
void buildSegTree(vector<int> nums, int k, segTreeNode st[], int a, int b, int& tag){
    st[k].l= a;
    st[k].r = b;
    if(st[k].r==st[k].l){
        st[k].s = nums[tag++];
        return;
    }
    int mid = (a+b)/2;
    buildSegTree(nums, k+1, st, a, mid, tag);
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    buildSegTree(nums, rc, st, mid+1, b, tag);
    st[k].s = st[k+1].s + st[rc].s;
    return;
}
void down(int k, segTreeNode st[]){
    int lc = k + 1; //分别计算左右孩子的下标 这里采用压缩存储的方法
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    st[lc].f += st[k].f;    //传到左树
    st[rc].f += st[k].f;   //传到右树 注意懒标记是累加的
    st[lc].s += (st[lc].r-st[lc].l+1)*st[k].f; //右侧求和
    st[rc].s += (st[rc].r-st[rc].l+1)*st[k].f; //左侧求和  //注意这里是增加父节点下传的f
    st[k].s = st[lc].s + st[rc].s;   //父节点更新    //注意父节点的值是重新赋值
    st[k].f = 0;           //标记清零
}

void modifyNode(int index, int delta, int k, segTreeNode st[]){
    if(st[k].l==st[k].r){
        st[k].s += delta;
        return;
    }
    if(st[k].f!=0)  down(k, st);
    int mid = (st[k].l+st[k].r)>>1;
    if(index<=mid)  modifyNode(index, delta, k+1, st);
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    modifyNode(index, delta, rc, st);
    st[k].s = st[k+1].s + st[rc].s;
}
void modifySeg(int a, int b, int delta, int k, segTreeNode st[]){
    if(a<=st[k].l&&st[k].r<=b){     //这个节点代表的区间全部需要改、更新懒标记、更新和
        st[k].s += (st[k].r-st[k].l+1)*delta;
        st[k].f += delta;
        return;     //一定要返回、没必要继续
    }
    if(st[k].f!=0)  down(k, st);    //上面没有返回、说明不是完全覆盖的、用到子节点、下传懒标记
    int mid = (st[k].l+st[k].r)>>1;
    if(a<=mid) modifySeg(a, b, delta, k+1, st);
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    if(mid<b) modifySeg(a, b, delta, rc, st);
    st[k].s = st[k+1].s + st[rc].s;
    return;
}

int searchNode(int index, int k, segTreeNode st[]){
    if(st[k].l==st[k].r)
        return st[k].s;
    if(st[k].f!=0)  down(k, st);
    int mid = (st[k].l + st[k].r)>>1;
    if(index<=mid)  return searchNode(index, k+1, st);
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    return searchNode(index, rc, st);
}

int searchSeg(int a, int b, int k, segTreeNode st[]){
    if(a<=st[k].l&&st[k].r<=b)
        return st[k].s;
    if(st[k].f!=0) down(k, st);
    int mid = (st[k].l + st[k].r)>>1;
    int rc = k+st[k].r-st[k].l+2-((st[k].r^st[k].l)&1);
    int res = 0;
    if(a<=mid) res += searchSeg(a, b, k+1, st);
    if(mid<b) res += searchSeg(a, b, rc, st);
    return res;
}

//TODO: LC 699. Falling Squares
//本来这题是一道很好的线段树题目，节点维护区间最大值
//无奈数字范围太大无法建立一棵树，所以只能牺牲时间节省空间，也就是n方算法
//使用三元组记录各个可能出现的区间的最高值
vector<int> fallingSquares(vector<pair<int, int> >& positions) {
    vector<int> maxheight;
    vector<vector<int> > tuples;
    int preh = 0;
    for(int i=0;i<positions.size();i++){
        vector<int> lrh = {positions[i].first, positions[i].first+positions[i].second, positions[i].second};
        int maxh = 0;
        for(int j=0;j<tuples.size();j++)
            if(!(tuples[j][1]<=lrh[0]||tuples[j][0]>=lrh[1]))
                maxh = max(maxh, tuples[j][2]);
        lrh[2] += maxh;
        tuples.push_back(lrh);
        preh = max(preh, lrh[2]);
        maxheight.push_back(preh);
    }
    return maxheight;
}

//TODO: 218. The Skyline Problem
vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int> > heights;
    vector<pair<int, int> > res;
    for(int i = 0;i<buildings.size();i++) {
        heights.push_back(make_pair(buildings[i][0], -buildings[i][2]));
        heights.push_back(make_pair(buildings[i][1], buildings[i][2]));
    }
    sort(heights.begin(), heights.end());   //自动按照两个关键字排序
    multiset<int> layers;
    layers.insert(0);   //插入一个0，保证第一栋建筑物的天际线可以被添加
    int pre_height = 0;
    for(auto it = heights.begin();it!=heights.end();it++) {
        if(it->second<0)              // a new building begin
            layers.insert(-it->second);
        else{                              // an existing building end
            auto it2 = layers.find(it->second);
            layers.erase(it2);
        }
        if(*layers.rbegin() != pre_height) {
            pre_height = *layers.rbegin();
            res.push_back(make_pair(it->first, pre_height));
        }
    }
    return res;
}

//TODO: LC 850. Rectangle Area II
//区间问题、条带化（降维处理）
int rectangleArea(vector<vector<int> >& rectangles) {
    vector<int> xs(rectangles.size()<<1);
    for(int i=0;i<rectangles.size();i++){
        xs[i] = rectangles[i][0];
        xs[rectangles.size()+i] = rectangles[i][2];
    }
    sort(xs.begin(), xs.end());
    for(int i=1;i<xs.size();i++)
        if(xs[i]==xs[i-1]){
            xs.erase(xs.begin()+i-1);
            i--;
        }
    long int sum = 0;
    for(int i=1;i<xs.size();i++){
        long int width = (long int)xs[i]-xs[i-1];
        vector<vector<int> > segs;
        for(int j=0;j<rectangles.size();j++){
            if(rectangles[j][2]<=xs[i-1]||rectangles[j][0]>=xs[i]) continue;
            int newt = rectangles[j][3], newb = rectangles[j][1];
            for(int k=0;k<segs.size();k++){
                if(segs[k][0]>newt||segs[k][1]<newb) continue;
                newt = max(newt, segs[k][1]);
                newb = min(newb, segs[k][0]);
                segs.erase(segs.begin()+k);
                k--;
            }
            segs.push_back({newb, newt});
        }
        for(int j=0;j<segs.size();j++)
            sum += (long int)width*(segs[j][1]-segs[j][0]);
    }
    return sum%((int)1e9+7);
}


//TODO: LC 715. Range Module
//非线段树式的区间管理方法、牺牲了时间logn-> n
//减少了空间2n->c
class RangeModule {
public:
    vector<vector<int> > v; //记录所有的区间
    void addRange(int left, int right) {
        vector<vector<int> > res;
        int tag = 0;
        for (int i = 0; i <v.size(); ++i) {
            if (v[i][1]<left) { //这个区间在待添加区间的左侧
                res.push_back(v[i]);
                tag++;  //tag的作用是保序、记录与待添加区间交错的区间处理之后应该插入的位置
            }
            else if(v[i][0] > right)   //在待添加区间的右侧
                res.push_back(v[i]);
            else {  //有重叠，取大，相当于合并
                left = min(left, v[i][0]);
                right = max(right, v[i][1]);
            }
        }
        //找到适当位置插入
        res.insert(res.begin() + tag, {left, right});
        v = res;
    }
    bool queryRange(int left, int right) {
        for (int i=0;i<v.size();i++)    //全遍历找到完全包含目标区间的区间
            if (v[i][0] <= left&&v[i][1] >= right)
                return true;
        return false;
    }
    void removeRange(int left, int right) {
        vector<vector<int> > res, t;
        int tag = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i][1] < left) {  //完全在左边
                res.push_back(v[i]);
                tag++;
            }
            else if (v[i][0] > right)  //完全在右边
                res.push_back(v[i]);
            else{   //插入删除之后的区间
                if (v[i][0] < left)
                    t.push_back({v[i][0], left});
                if (v[i][1] > right)
                    t.push_back({right, v[i][1]});
            }
        }
        //找到合适位置将其插入
        res.insert(res.begin() + tag, t.begin(), t.end());
        v = res;
    }
};

//TODO: LC 732. My Calendar III
//区间管理又一例：这一次只维护端点
//之所以这样，本题的特点是找到最大的重叠深度，如果一个区间在最深处，
//那么其端点也在最深处，而且，map自动按照关键字排序，这就意味着如果连续走start类型的点
//就会连续的增加深度，走过一个end点，就相当于少了一个区间，所以十分巧妙
//研究重叠深度的特征是不需要考虑是由哪个区间引起的，对于深度来说都是等价的
class MyCalendarThree {
public:
    map<int, int> deg;
    MyCalendarThree() {}
    int book(int start, int end) {
        deg[start]++;
        deg[end]--;
        int res = 0, tmp = 0;
        for(map<int, int>::iterator t=deg.begin();t!=deg.end();t++){
            tmp += t->second;
            res = max(res, tmp);
        }
        return res;
    }
};
//TODO: 树状数组基本操作 姑且称之为一个类
class BinaryIndexArray {
public:
    vector<int> c;
    //创建树状数组
    BinaryIndexArray(vector<int> nums) {
        c.resize(nums.size()+1, 0);
        for(int i=1;i<nums.size()+1;i++){
            int index = i-(i&(-i))+1;
            while(index<=i){
                c[i] += nums[index-1];
                index++;
            }
        }
    }
    //更新元素
    void update(int i, int val) {
        int delta = val - sumRange(i,i);
        int x = i+1;
        while(x<=c.size()-1){
            c[x] += delta;
            x += (x&(-x));
        }
        return;
    }
    //计算区间和
    int sumRange(int i, int j) {
        int k = i;
        int r = 0, l = 0;
        while(k>0){
            l += c[k];
            k -= (k&-k);
        }
        k = j+1;
        while(k>0){
            r += c[k];
            k -= (k&-k);
        }
        return r-l;
    }
};

//TODO: LC 493. Reverse Pairs
//之所以使用树状数组、因为有区间特征
//排好序之后、得到的是顺序排列的位置
//遍历原来的数组的逆序，对每一个元素，一方面是这个元素产生的逆序加到结果中，也就是区间1～nums[i]的和
//另一方面是它会造成的逆序，就是nums[i]*2以后的元素具有的逆序数都要+1
//其实树状数组的本质就是站在区间的角度看数组，至于这个数组维护的是什么，完全可以根据自己的需要来定义
//只要它的性质满足区间继承即可 比如这个题的sum数组记录的并不是每个节点的区间和，而是这个节点下属的节点增加了多少次逆序数
//父节点之间的重叠性又和逆序的性质完美契合
//此外，通过map的映射机制，可以保证那些被多更新的点没有机会加入到结果中，保证了正确性
int reversePairs(vector<int>& nums) {
    if(nums.size()==0)   return 0;
    reverse(nums.begin(), nums.end());
    int res = 0;
    vector<long long> tempNum(2*nums.size(), 0);
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        tempNum[cnt++] = nums[i];
        tempNum[cnt++] = nums[i] * 2LL;
    }
    sort(tempNum.begin(), tempNum.end());
    map<long long, int> mp;
    mp[tempNum[0]] = 1;
    int pre = 2;
    for (int i = 1;i<cnt;i++)
        if (tempNum[i]!=tempNum[i-1])
            mp[tempNum[i]] = pre++;
    vector<int> sum(nums.size()*2, 0);
    //下面维护了一个树状数组
    for (int i=0;i<nums.size();i++){
        //求前缀和
        for(int k=mp[nums[i]]-1;k>0;k-=(k&-k))
            res += sum[k];
        //更新前缀和: nums[i]出现 意味着在他后面的2*nums[i]都会增加逆序数
        for(int k=mp[nums[i]*2LL];k<sum.size();k+=(k&-k))
            sum[k] += 1;
    }
    return res;
}


//TODO: LC 56. Merge Intervals
//学会了排序比较运算的重载、leetcode里面比较函数需要加static关键字
bool less_start(const Interval &a, const Interval &b){
    return a.start==b.start?(a.end<b.end):(a.start<b.start);
}
//这个题目排序使用的是左端点、体会
vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), less_start);
    for(int i=0;i<intervals.size();i++){
        int j = i+1;
        while(j<intervals.size()&&intervals[j].start<=intervals[i].end){
            intervals[i].end = max(intervals[j].end, intervals[i].end);
            intervals.erase(intervals.begin() + j);
        }
    }
    return intervals;
}
//插入区间
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    merge(intervals);
    return intervals;
}
