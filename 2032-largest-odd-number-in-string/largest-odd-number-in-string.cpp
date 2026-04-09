class Solution {
public:
    bool IsOdd(char & digit){
        return ((digit - '0') % 2 == 1);
    }
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i = n-1; i>=0; i--){
            if(IsOdd(num[i])) return num.substr(0, i+1);
        }
        return "";
    }
};