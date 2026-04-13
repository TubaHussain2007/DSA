class Solution {
public:
    int myAtoi(string input) {
        int i =0, n= input.size();
        while(i<n && input[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i<n && input[i] == '-'){
            sign =-1;
            i++;
        }else if(i<n && input[i] == '+'){
            i++;
        }
        long long result = 0;
        while(i<n && isdigit(input[i])){
            result = result*10 + (input[i] - '0');
            i++;
            if(result*sign >= INT_MAX) return result = INT_MAX;
            if(result*sign <= INT_MIN) return result= INT_MIN;
        }
        return result * sign;
    }
};