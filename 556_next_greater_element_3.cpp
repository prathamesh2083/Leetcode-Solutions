class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n); // convert given number to string
        
        
        next_permutation(s.begin(),s.end());  // find next permutation of string s
        long long next=stol(s);  // convert next permuatated string in number
        return next<=n || next>INT_MAX || next<INT_MIN?-1:next;  // if next is less or equal than given number n or next in not in required range return -1 , else return next
    }
};
