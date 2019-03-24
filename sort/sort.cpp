#include <iostream>
#include <stdlib.h>


void swap(int* x,int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

//1. 直接插入排序
//时间复杂度：平均O(N^2) 最好O(N) 最坏O(N^2)
//稳定性：稳定
void InsertSort(int a[],int n)
{
	for(int i = 1;i < n;++i){
		int EndIndex = i;
		while(EndIndex > 0 && a[EndIndex] < a[EndIndex-1]){
			swap(&a[EndIndex],&a[EndIndex-1]);
			EndIndex--;	
		}
	}
}
//2. 希尔排序
//时间复杂度：平均O(N^1.3) 最好O(N) 最坏O(N^2)
//稳定性：不稳定
void ShellSort(int *a,int n)
{
	for(int gap = n/2;gap > 0;gap /= 2){
	for(int i = gap;i < n;++i){
		int end = i;
		while(end > gap-1 && a[end] < a[end-gap]){
			swap(&a[end],&a[end-1]);
			end -= gap;
		}
	}
	}
}

//3. 选择排序
//时间复杂度：O(N^2)
//稳定性：不稳定
void SelectSort(int *a,int n)
{
	int begin = 0,end = n-1;
	int min = 0,max = 0;
	while(begin < end){
		for(int i = begin;i <= end;++i)
		{
			if(a[min] > a[i])
				min = i;
			if(a[max] < a[i])
				max = i;
		}

		swap(&a[begin],&a[min]);
		if(begin == max)
			max = min;
		swap(&a[end],&a[max]);

		++begin;
		--end;
	}
}
//4. 堆排序
//时间复杂度：O(N*lgN)
//稳定性：不稳定
void AdjuestDown(int *a,int root,int n)
{
	int parent = root;
	int child = 2*parent+1;
	while(child < n){
		if(child+1 < n && a[child] < a[child+1])
			child += 1;

		if(a[parent] < a[child])
		{
			swap(&a[parent],&a[child]);

			parent = child;
			child = 2*parent+1;
		}
		else
			break;
	}
}
void HeapSort(int *a,int n)
{
	//1. 建大堆
	for(int i = n-1-1/2;i >= 0;--i){
		AdjuestDown(a,i,n);
	}	

	//2. 堆排序
	for(int i = n-1;i > 0;--i){
		swap(&a[0],&a[i]);
		AdjuestDown(a,0,i);
	}
}

//5. 冒泡排序
void BubbleSort(int *a,int n)
{
	int border = n-1;  //一趟循环中可能需要交换的元素的边界
	for(int i = 0;i < border;++i){
		int flag = 0;
		int end = border;
		int EndChangeIndex;
		for(int j = 0;j < end;++j){
			if(a[j] > a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag = 1;

				 EndChangeIndex = j;
			}
		}

		if(flag == 0)
			break;	

		border =  EndChangeIndex;
	}
}

int main(){
	int a[] = {89,-11,99,-34,-78,888,-5643,1023,-9,0,23};
	int N = sizeof(a)/sizeof(a[0]);
	
	//InsertSort(a,N);
	//ShellSort(a,N);
	
	//SelectSort(a,N);	 
	//HeapSort(a,N);
	
	BubbleSort(a,N);

	for(int i = 0;i < N-1;++i){
		if(a[i] <= a[i+1])
			std::cout<< a[i] << "  ";
		else
			std::cout<< "sort error!" <<std::endl;
	}
	std::cout<< a[N-1] <<std::endl;
	return 0;
}
