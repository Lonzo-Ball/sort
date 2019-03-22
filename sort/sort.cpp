#include <iostream>

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
	
	int a[] = {10,-1,5,9,-44,-98,56,0,0,111};
	int size = sizeof(a)/sizeof(a[0]);
	
	//插入排序
	InsertSort(a,size);

	for(int i = 0;i < size;++i){
		std::cout<< a[i] << "  ";
	}
	std::cout<<std::endl;
	return 0;
}
