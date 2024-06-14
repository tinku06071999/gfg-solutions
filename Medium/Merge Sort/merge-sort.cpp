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
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int temp[r-l+1];
         int left = l;
         int right = mid+1;
         int i=0;
         while(left <= mid && right <= r){
             if(arr[left] <= arr[right]){
                 temp[i++] = arr[left++];
             }else{
                 temp[i++] = arr[right++];
             }
         }
         while(left <= mid) temp[i++] = arr[left++];
         while(right <= r) temp[i++] = arr[right++];
         
         for(int i=l; i<=r; i++){
             arr[i] = temp[i-l];
         }
        
        // while(left <= mid && right <= r){
        //     if(arr[left] <= arr[right]){
        //         left++;
        //     }else{
        //         int val = arr[right];
        //         int idx = right;
                
        //         while(idx > left){
        //             arr[idx] = arr[idx-1];
        //             idx--;
        //         }
        //         arr[left] = val;
        //         left++;
        //         mid++;
        //         right++;
        //     }
        // }
        
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l>= r)return;
        
       int mid = (l+r)/2;
       
       mergeSort(arr, l , mid);
       mergeSort(arr, mid+1, r);
       merge(arr, l, mid, r);
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