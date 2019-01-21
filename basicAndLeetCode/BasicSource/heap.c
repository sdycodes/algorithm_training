#include <stdio.h>

//本代码包括：
//一、最大堆性质维护（maxheapify）
//二、建堆（buildheap）
//三、堆排序（heapsort）
//四、优先队列（priority queue）
//		func1:找最大
//		func2:提取最大
//		func3:增加优先级



//最大堆性质维护是核心，可以利用之，主动破坏实现排序
//自下而上的意义：下层保证对，再处理上层


//************Max heapify(最大堆性质维护)**************
//维护前提：左右子树都已经是最大堆，只是可能大小关系有点问题
void maxheapify(int arr[], int i, int size){
	int temp;
	//移位可以加速，但要注意移位和*2的关系，优先级比加法低
	//体会这里大于等于 为什么？（三个数里选最大的）
	//指标判断放在最前面，利用短路运算提高效率
	if((i<<1)+2<size&&arr[(i<<1)+1]>=arr[i]&&arr[(i<<1)+1]>=arr[(i<<1)+2]){
		temp = arr[(i<<1)+1];
		arr[(i<<1)+1] = arr[i];
		arr[i] = temp;
		//注意数组越界访问的问题，一般这种函数都是要有size作为参数，并且判断条件也不能少
		maxheapify(arr, (i<<1)+1,size);
	}
	else if((i<<1)+2<size&&arr[(i<<1)+2]>=arr[i]&&arr[(i<<1)+2]>=arr[(i<<1)+1]){
		temp = arr[(i<<1)+2];
		arr[(i<<1)+2] = arr[i];
		arr[i] = temp;
		maxheapify(arr, (i<<1)+2,size);
	}
	//只有左孩子
	//注意判定条件右孩子指标等于即越界
	else if((i<<1)+1<size&&(i<<1)+2==size&&arr[(i<<1)+1]>arr[i]){
		temp = arr[i];
		arr[i] = arr[(i<<1)+1];
		arr[(i<<1)+1] = temp;
		//孩子不够肯定到底了，不用递归
	}
}
//************End**********************************

//*****************build heap建堆********************
//从底层孩子的父亲向上建堆
void buildHeap(int a[], int aSize){
	int i;
	//高度注意指标的问题
	for(i=(aSize/2-1);i>=0;i--)
		maxheapify(a, i, aSize);
}
//*******************End****************************


//*******************heapsort**********************
void heapsort(int a[], int aSize){
	int i,temp;
	for(i=aSize-1;i>=1;i--){
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		//aSize一定要自减
		//最顶上的一定是当前最大，直接拿掉（放在数组尾部），换上去底层孩子，子树依然最大，堆维护
		aSize--;
		maxheapify(a, 0, aSize);
	}
}
//********************End***************************

//*********************priority queue***************
//function1:getMaximum
int getMaximun(int a[]){
	return a[0];
}

//function2:extractMaximun
int extractMaximum(int a[], int aSize){
	int temp;
	temp = a[0];
	a[0] = a[aSize-1];
	a[aSize-1] = temp;
	maxheapify(a, 0, aSize);
	return temp;
}
//function3:increase priority
void increaseKey(int a[], int i, int newkey){
	a[i] = newkey;
	int temp;
	while(i>0){
		if(a[i]>a[i-1>>1]){
			temp = a[i];
			a[i] = a[i-1>>1];
			a[i-1>>1] = temp;
			i = i-1>>1;
		}
	}
}
//function 2 3都利用堆维护的性质，先打破再重建，但是打破的时候注意不能破坏子堆是最大堆的特征
//所以基本上是头和尾去交换来打破。还有insert方法，因需要使用realloc就算了。
//其核心思想：在尾部加一个最小元素（-32768），然后增加优先级
/*堆思想的核心：维护最大堆性质，但是维护的前提是子堆已经是最大堆，所以所有试图使用这个性质的func都必须
在增删元素时保持此性质，包持的方法就是只改变头（一定是最大的）或者尾（可以把底层孩子看成最大堆）
*/

//********************End***************************

int main(int argc, char *argv[]) {
	int a[10] = {16,4,10,14,7,9,3,2,8,1};
	maxheapify(a,1,10);
	int b[10] = {3,4,2,1,6,7,9,0,5,8};
	buildHeap(b,10);
	int i=0;
	while(i!=10)
		printf("%d ", a[i++]);
	//heapsort(b,10);
	increaseKey(b, 4,100);
	i = 0;
	printf("\n");
	while(i!=10)
		printf("%d ",b[i++]);
}