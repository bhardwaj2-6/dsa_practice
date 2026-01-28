class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int sum=0;
        int n=arr.size();
        for(int x:arr){
            sum=sum+x;
        }
        int half=sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(half+1,false));
        dp[0][0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<half+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        int s1=0;
        for(int j=half;j>=0;j--){
            if(dp[n][j]){
                s1=j;
                break;
            }
        }
        return sum-(2*s1);
    }
};
