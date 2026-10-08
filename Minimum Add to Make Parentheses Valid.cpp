class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(s[i]);
            else{
                if(st.empty()) count++;
                else st.pop();
            }
        }
        return count+st.size();
    }
};