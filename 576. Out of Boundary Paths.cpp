class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int MOD;
    int paths(vector<vector<vector<int>>>&dp,int m,int n,int move,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        if(move<=0){
            return 0;
        }
        if(dp[i][j][move]!=-1){
            return dp[i][j][move];
        }
        int cnt=0;
        for(int p=0;p<4;p++){
            int x=dx[p]+i;
            int y=dy[p]+j;
            cnt=(cnt+paths(dp,m,n,move-1,x,y))%MOD;
        }
        return dp[i][j][move]=cnt;
    }
    int findPaths(int m, int n, int move, int row, int col) {
        MOD=1e9+7;
        vector<vector<vector<int>>>dp(55,vector<vector<int>>(55, vector<int>(55,-1)));
        
        return paths(dp,m,n,move,row,col);
    }
};
