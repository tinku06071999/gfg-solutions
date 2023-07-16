//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int pivotidx(vector<int>& vec){
      int s=0;
        int e=vec.size()-1;
        int mid=s+(e-s)/2;
        
        while(s<e)
        {
            if(vec[mid]>=vec[0])
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
  }
 
int Search(vector<int> vec, int k) {
    //code here
     int s=0,e = vec.size()-1;
        int mid = s+(e-s)/2;
        int pivot = pivotidx(vec);
      
        if(vec[e] == k)return e;
        if(vec[s]==k)return s;
        if(vec[pivot]<=k && k<=vec[e]){
            e = vec.size()-1;
            s = pivot;
            mid = s+(e-s)/2;
           
            while(s<=e){
                if(vec[mid]==k)return mid;
                else if(vec[mid]<k)s = mid+1;
                else e = mid-1;
                mid = s+(e-s)/2;
            }
        }
        else{
            s = 0;
            e = pivot-1;
            mid = s+(e-s)/2;
            while(s<=e){
                if(vec[mid]==k)return mid;
                else if(vec[mid]<k)s = mid+1;
                else e = mid-1;
                mid = s+(e-s)/2;
           
            }
        }
        return -1;
}