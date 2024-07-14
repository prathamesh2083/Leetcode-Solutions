class Solution {
public:
    bool iscap(char ch){
        return ch>='A' && ch<='Z';
    }
    bool issmall(char ch){
        return ch>='a' && ch<='z';
    }
    bool isnum(char ch){
        return ch>='0' && ch<='9';
    }
    string countOfAtoms(string s) {
        
       string ans="";
       int n=s.length();
       stack<pair<string,int>>st;
       for(int i=0;i<n;){

        if(s[i]=='('){
            string tmp(1,s[i]);
            st.push({tmp,1});
            i++;
        }
        else if(s[i]==')'){
             
           
            string cnt="";
            i++;
            while(i<n && isnum(s[i])){
                cnt+=s[i];
                i++;
            }
            if(cnt==""){
                cnt="1";
            }
            map<string,int>mp;
           
            while(!st.empty()){
                if(st.top().first=="("){
                    st.pop();
                    break;
                }
                st.top().second*=stoi(cnt);
                mp[st.top().first]+=st.top().second;
               
                st.pop();
            }
            while(!st.empty()){
                if(st.top().first=="("){
                  
                    break;
                }
                mp[st.top().first]+=st.top().second;
                st.pop();
            }
            for(auto  it=mp.begin();it!=mp.end();it++){
                st.push({it->first,it->second});
            }


        }
        else if(iscap(s[i])) {
             
             string element="";
             element+=s[i];
             i++;
             while(i<n && issmall(s[i])){
                element+=s[i];
                i++;
             }
             string cnt="";
             while(i<n && isnum(s[i])){
                cnt+=s[i];
                i++;
             }
             if(cnt=="") cnt="1";
            // cout<<element<<" "<<cnt<<endl;
             st.push({element,stoi(cnt)});
        }
     
       }
       map<string,int>mp;
       while(!st.empty()){
        mp[st.top().first]+=st.top().second;
        st.pop();
       }
        for(auto  it=mp.begin();it!=mp.end();it++){
                ans+=it->first+(it->second>1?to_string(it->second):"");
            }
        return ans;
    }
};
