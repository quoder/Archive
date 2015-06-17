/*
 *NOTE: READ AT YOUR OWN RISK
 *LANGUAGE: C++
 *WRITTEN BY: Manish Kumar Mishra (mkmishra1997)
 */
 
#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
using namespace std;
int heapSize=0,arrayLength=0;
int parent(int i)
{
	return floor(i/2);
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void maxHeapify(int *A,int i)
{
	int l=left(i);
	int r=right(i);
	int largest=i;
	if(l<heapSize&&A[i]<A[l])
		largest=l;		
	if(r<heapSize&&A[largest]<A[r])
		largest=r;
	if(largest!=i)
	{
		swap(A[i],A[largest]);
		maxHeapify(A,largest);
	}
}
void buildMaxHeap(int *A)
{
	for(int i=floor((arrayLength-2)/2);i>=0;i--)
	{
		maxHeapify(A,i);
	}
}
void heapSort(int *A)
{
	buildMaxHeap(A);
	for(int i=arrayLength-1;i>=1;i--)
	{
		swap(A[0],A[i]);
		heapSize--;
		maxHeapify(A,0);
	}
}
int main()
{

	printf("Enter the number of elements in the array\n");
	int N;
	scanf("%d",&N);
	arrayLength=N;
	heapSize=arrayLength;
	int A[N];
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	printf("The size of the entered array is: %d",arrayLength);
	printf("\n");
	printf("The sorted array is\n");
	heapSort(A);
	for(int i=0;i<arrayLength;i++)
		printf("%d ",A[i]);
	return 0;
}
