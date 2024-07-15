//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
         // Your code here
         int l=low;
         int r=mid+1;
         vector<int> temp;
         
         while(l<=mid&&r<=high){
             if(arr[l]<=arr[r]){
                 temp.push_back(arr[l]);
                 l++;
             }
             else{
                 temp.push_back(arr[r]);
                 r++;
             }
         }
         while(l<=mid){
             temp.push_back(arr[l]);
             l++;
         }
         while(r<=high){
             temp.push_back(arr[r]);
             r++;
         }
         
         for(int i=low;i<=high;i++){
             arr[i]=temp[i-low];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l==r) return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};






//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
