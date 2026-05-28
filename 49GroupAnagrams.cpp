class Solution {
public:
    string generate(string&str){
        int arr[26]={0};
        for(int i=0;i<str.size();i++){
            arr[str[i]-'a']++;
        }
        string new_word="";
        for(int i=0;i<26;i++){
            int freq=arr[i];
            if(freq>0){
                new_word+=string(freq,i+'a');
            }
        }
        return new_word;


    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<n;i++){
            string new_word=generate(strs[i]);
            mpp[new_word].push_back(strs[i]);
        }
        for(auto&it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};