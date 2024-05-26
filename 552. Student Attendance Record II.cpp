class Solution {
public:
int MOD;
// Top-down dp
    int solve(int n,int currlate,int ab,vector<vector<vector<int>>>&dp){
       
        if(n==0){
            return 1;
        }
        if(dp[n][currlate][ab]!=-1){
            return dp[n][currlate][ab];
        }
         int ans=0;
         ans=(ans+solve(n-1,0,ab,dp))%MOD;
         if(ab<1){
            // assign absent
           ans=(ans+solve(n-1,0,ab+1,dp))%MOD;
         }
         if(currlate<2){
            ans=(ans+solve(n-1,currlate+1,ab,dp))%MOD;
         }
         return dp[n][currlate][ab]=ans;

    }
    int checkRecord(int n) {
        MOD=1e9+7;
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        //return solve(n,0,0,dp);


        // Bottom-up Dp
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(3,vector<int>(4,0)));
        // dp[n][ab][late]
        for(int ab=0;ab<=1;ab++){
            for(int late=0;late<=2;late++){
                dp[0][ab][late]=1;
            }
        }
        for(int i=1;i<=n;i++){
             for(int ab=0;ab<=1;ab++){
            for(int late=0;late<=2;late++){
                dp[i][ab][late]=(dp[i-1][ab+1][0])%MOD;
                 dp[i][ab][late]=(dp[i][ab][late]+dp[i-1][ab][0])%MOD;
                  dp[i][ab][late]=(dp[i][ab][late]+dp[i-1][ab][late+1])%MOD;
            }
        }
        }
        return dp[n][0][0]%MOD;

       
    }
};
