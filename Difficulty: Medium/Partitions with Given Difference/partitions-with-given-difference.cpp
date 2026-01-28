class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(int x: arr) sum=sum+x;
        if(sum<diff || (sum+diff)%2!=0) return 0;
        int target=(sum+diff)/2;
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};