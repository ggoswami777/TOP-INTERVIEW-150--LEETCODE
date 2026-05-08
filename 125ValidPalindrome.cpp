class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto c :s){
            if(isalnum(c)){
                ans.push_back(c);
            }
        }
        int j=ans.size()-1;
        for(int i=0;i<ans.size()/2;i++){
            if(tolower(ans[i])!=tolower(ans[j])){
                return false;
            }
            j--;
        }
        return true;
    }
};