#include<iostream>
#include<algorithm>
using namespace std;
mergesort(int *num,int l,int r, int m)
{
    int i ,j ,k;
    int n1=(m-l+1);
    int n2=(r-m);
    int L[n1],R[n2];
    for(int i =0;i<n1;i++) L[i]=num[l+i];
    for(int i =0;i<n2;i++) R[i]=num[m+1+i];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            num[k]=L[i];
            i++;
        }
        else
        {
            num[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        num[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        num[k]=R[j];
        j++;
        k++;
    }
}
mergearray(int* arr,int l,int r)
{
    if(r>l)
    {
        int m = (l+(r-1))/2;
        mergearray(arr,l,m);
        mergearray(arr,m+1,r);
        mergesort(arr,l,r,m);
    }
}
ternarysearch(int arr[],int l,int r,int x){
    if(r>=l)
    {
        int mid1=(l+((r-l)/3));
        int mid2=(r-((r-l)/3));
        if(arr[mid1]==x) return mid1;
        else if(arr[mid2]==x) return mid2;
        else if(arr[mid1]>x) return ternarysearch(arr,l,mid1-1,x);
        else if(arr[mid2]<x) return ternarysearch(arr,mid2+1,r,x);
        else return ternarysearch(arr,mid1+1,mid2+1,x);
    }
    else return -1;
}
printarray(int arr[],int s)
{
    for(int i =0;i<s;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    mergearray(arr,0,5);
    cout<<"Sorted Array: "<<endl;
    printarray(arr,5);
    cout<<"Index of 3 the sorted array: "<<ternarysearch(arr,0,5,3)+1<<endl;
    cout<<endl;
}

