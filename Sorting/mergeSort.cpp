/*
 *NOTE: READ AT YOUR OWN RISK
 *LANGUAGE: C++
 *WRITTEN BY: Manish Kumar Mishra (mkmishra1997)
 */
 
#include <bits/stdc++.h>
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define all(c) c.begin(),c.end()
#define ll long long
#define rep(i,n) for(typeof(n) i=0;i<n;i++)
#define reps(i,n) for(typeof(n) i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
void merge(int l[],int m,int r[],int n,int a[],int o)
{
	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{
		if(l[i]<r[j])
		{
			a[k++]=l[i++];
		}
		else if(l[i]>r[j])
		{
			a[k++]=r[j++];
		}
		else
		{
			a[k++]=l[i++];
			j++;
		}
	}
	while(i<m)
		a[k++]=l[i++];
	while(j<n)
		a[k++]=r[j++];
}
void mergeSort(int A[],int n)
{
	if(n<2)
		return ;
	int mid= n>>1;
	int L[mid],R[n-mid];
	int i=0,j=0,k=0;
	for(;i<mid;)
		L[i++]=A[k++];
	for(j=mid,k=0;j<n;)
		R[k++]=A[j++];
	mergeSort(L,mid);
	mergeSort(R,n-mid);
	merge(L,mid,R,n-mid,A,n);
}
int main(int argc, char const *argv[])
{
	int A[12],i=0,n;
	printf("Enter the array\n");
	printf("Enter the size\n");
	scanf("%d",&n);
	printf("Now enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("Now the sorted array is using merge sort\n");
	mergeSort(A,n);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}
