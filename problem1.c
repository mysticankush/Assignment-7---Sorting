/*  Program for counting number of inversions in an array
 * Compilation : gcc problem1.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 5-08-2021
 * Assignment_5 -> Recursion
*/
#include<stdio.h>

//Function to merge two sorted subarrays
int merge(int a[],int l,int mid,int r)
{
    int i=l,j=mid+1;
    int idx=0;
    int mergedarray[r-l+1];
    int inversions=0;
    while(i<=mid && j<=r)
    {
        if(a[i]>a[j])
        {
            mergedarray[idx++]=a[j++];
            //If a[i] > a[j] then it means all the elements from i to mid will be greater than a[j] because array a from l to mid is sorted . 
            //Therefore , count all the elements as the part of inversion from i to mid
            inversions+=(mid-i+1);
        }
        else
        {
            mergedarray[idx++]=a[i++];
        }
    }
    while(i<=mid)
    {
        mergedarray[idx++]=a[i++];
    }
    while(j<=r)
    {
        mergedarray[idx++]=a[j++];
    }
    idx=0;
    //overriding the array a with mergedarray
    for(int i=l;i<=r;i++)
    {
        a[i]=mergedarray[idx++];
    }
    return inversions;
}
//Function to return the number of inversions
int mergesort(int a[],int l,int r)
{
    int inversions=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        //calling the left subarray from l to mid
        inversions+=mergesort(a,l,mid);
        //calling the right subarray from mid+1 to r 
        inversions+=mergesort(a,mid+1,r);
        inversions+=merge(a,l,mid,r);
    }
    return inversions;
}
int main() {
    //taking input of sizeo of array
    int n;
    scanf("%d",&n);
    int a[n+2];
    //taking input the elements of the array
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //calling the function of merge sort and count number of inversions
    int inversions=mergesort(a,0,n-1);
    printf("Number of Inversions are -> %d",inversions);
}
