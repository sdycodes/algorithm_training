#include <stdio.h>
#include <stdlib.h>
//*********************count sort****************
//这个非常类似三元组稀疏矩阵的转制放置元素的思想
//直接利用了元素的整数特性
int* countSort(int a[],int aSize,int diffnum){
	int *b, *c, i;
	//数组b用来输出
	b = (int *)malloc(aSize*sizeof(int));
	//数组c用来存放各个数字有几个
	c = (int *)malloc(diffnum*sizeof(int));
	//初始化为0
	for(i=0;i<diffnum;i++)
		c[i] = 0;
	//这一次循环记录下每个数字有几个
	for(i=0;i<aSize;i++)
		c[a[i]]++;
	//记录下每一个数值的数字应该在第几个，注意取位置还要-1
	for(i=1;i<diffnum;i++)
		c[i] = c[i] +c[i-1];
	//向输出数组放数字，注意要倒着放，因为c中记录的位置信息是最大的
	for(i = aSize-1;i>=0;i--){
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}	
	return b;
	
}
//关于基数排序（Radix Sort）是把数字分割，从最低有效位开始使用基数排序。
//***********************End*********************
//桶排序，假设了输入均匀分布，这样可以先在各个区间上排，然后在连起来




int main(int argc, char *argv[]) {
	int a[5] = {1,0,3,4,2};
	int *b;
	b = (int*)malloc(5*sizeof(int));
	b = countSort(a,5,5);
	int i = 0;
	
	while(i<5)
		printf("%d", b[i++]);
	
	return 0;
}