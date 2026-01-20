class Solution {
  public:
  
    bool solved(vector<int>& arr, int sum, int n){
        vector<vector<bool>> t(n+1, vector<bool>(sum+1));
        for(int i=0;i<n;i++){
            t[i][0]=true;
        }
        for(int j=1;j<sum;j++){
            t[0][j]=false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }  
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            return solved(arr,sum/2,n);
        }
        
    }
};