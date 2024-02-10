class Solution {
public:
    int odd(string s,int i){
        int n=s.length();
        if(i==0 || i==n-1){
            return 0;
        }
        int cnt=0;
        int j=i-1,k=i+1;
        while(j>=0 && k<n && s[j]==s[k]){
            cnt++;
            j--;
            k++;
        }
        return cnt;
    }
    int even(string s,int i){
        int n=s.length();
        if( i==n-1){
            return 0;
        }
        int cnt=0;
        if(s[i]==s[i+1]){
            cnt++;
            int j=i-1,k=i+2;
             while(j>=0 && k<n && s[j]==s[k]){
            cnt++;
            j--;
            k++;
        }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
           cnt+=1+odd(s,i)+even(s,i);
        }
        return cnt;
    }
};
