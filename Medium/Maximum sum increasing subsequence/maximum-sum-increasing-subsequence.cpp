//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[], int i, int n, int prev,vector<vector<int>>& dp)
	{
	    if(i==n)
	    {
	        return 0;
	    }
	    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
	    
	    int a = 0;
	    if(prev==-1 || arr[prev]<arr[i])
	    {
	        a = arr[i]+solve(arr,i+1,n,i,dp);
	    }
	    
	    int b =solve(arr,i+1,n,prev,dp);
	    
	    return dp[i][prev+1]=max(a,b);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n, vector<int> (n+1,-1));
	    return solve(arr,0,n,-1,dp);
	}  
	
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends