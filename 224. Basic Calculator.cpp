class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long number=0;
        long long result=0;
        int sign=1;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }else if(s[i]=='+'){
                result+=(number*sign);
                number=0;
                sign=1;
            }else if(s[i]=='-'){
                result+=(number*sign);
                number=0;
                sign=-1;
            }else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }else if(s[i]==')'){
                result+=(number*sign);
                number=0;
                int stackSign=st.top(); st.pop();
                int lastRes=st.top();st.pop();
                result*=stackSign;
                result+=lastRes;
            }
        }
        result+=(number*sign);
        return (int)result;
    }
};