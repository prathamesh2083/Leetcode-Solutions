class Solution {
public:
    long long sumDigitDifferences(vector<int>& v) {
        long long ans=0;
        int n=v.size();
        
       vector<vector<int>>count(11,vector<int>(10,0));
        for(int i=0;i<n;i++){
            int num=v[i];
            int ind=0;
            while(num){
                int rem=num%10;
                num=num/10;
                count[ind][rem]++;
                ind++;
            }
        }
      
        for(int i=0;i<count.size();i++){
            
            for(int j=0;j<10;j++){
                for(int k=j+1;k<10;k++){
                    ans+=count[i][j]*count[i][k];
                }
            }
        }
        return ans;
    }
};
