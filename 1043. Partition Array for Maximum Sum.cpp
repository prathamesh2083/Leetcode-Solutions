class Solution {
public:
    int solve(vector<int>&v,int k,int i,vector<int>&dp){
        
        if(dp[i]!=-1){
            return dp[i];
        }
         int sum=0;
         int mx=0;
         for(int j=1;j<=k && i+j<=v.size();j++){
             mx=max(mx,v[j+i-1]);
            sum=max(sum,mx*j+solve(v,k,i+j,dp));
         }
         return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n=v.size();
        vector<int>dp(n+10,-1);
        return solve(v,k,0,dp);
    }
};
