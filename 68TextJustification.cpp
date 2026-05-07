class Solution {
public:
    int MAX_WIDTH;
    string getLine(int i,int j ,int eachWordSpace,int extraSpaces,vector<string>& words){
        string s;
        for(int k=i;k<j;k++){
            s+=words[k];
            if(k==j-1){
                continue;
            }
            for(int space=1;space<=eachWordSpace;space++){
                s+=" ";
            }
            if(extraSpaces){
                s+=" ";
                extraSpaces--;
            }
        }
        while(s.length()<MAX_WIDTH){
            s+=" ";
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n=words.size();
        MAX_WIDTH=maxWidth;
        int i=0;
        while(i<n){
            int letterCount=words[i].length();
            int spaceCount=0;
            int j=i+1;
            while(j<n && words[j].length()+1+spaceCount+letterCount<=maxWidth){
                letterCount+=words[j].length();
                spaceCount++;
                j++;
            }
            int remainingSpaces= maxWidth-letterCount;
            int eachWordSpace= spaceCount==0?0: remainingSpaces/spaceCount;
            int extraSpaces= spaceCount==0?0: remainingSpaces%spaceCount;
            if(j==n){
                eachWordSpace=1;
                extraSpaces=0;
            }
            result.push_back(getLine(i,j,eachWordSpace,extraSpaces,words));
            i=j;

        }
        return result;
    }
};