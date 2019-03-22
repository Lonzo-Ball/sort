#include <iostream>
#include <stdlib.h>


void swap(int* x,int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
//插入排序
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
int main(){
	
	srand(time(NULL));
	int N = 100;
	int *a = new int[N];
	for(int i = 0;i < N;++i)
	{
		a[i] = rand()%500;
	}
	
	//插入排序
	InsertSort(a,N);

	for(int i = 0;i < N;++i){
		std::cout<< a[i] << "  ";
	}
	std::cout<<std::endl;
	return 0;
}
