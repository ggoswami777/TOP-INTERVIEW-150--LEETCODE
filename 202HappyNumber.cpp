class Solution {
public:
    int next(int n){
        int newNum=0;
        while(n!=0){
            int num=n%10;
            newNum+=num*num;
            n=n/10;
        }
        return newNum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=next(n);
        while(fast!=1 && fast!=slow){
            slow=next(slow);
            fast=next(next(fast));
        }
        return fast==1;
    }
};