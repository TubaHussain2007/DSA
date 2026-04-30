class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5 = 0, cnt_10 = 0;
        for(int bill : bills){
            if(bill == 5){
                cnt_5++;
            }
            else if(bill == 10){
                if(cnt_5 > 0){
                    cnt_5--;
                    cnt_10++;
                } else {
                    return false;
                }
            }
            else { // bill == 20
                if(cnt_10 > 0 && cnt_5 > 0){
                    cnt_10--;
                    cnt_5--;
                } else if(cnt_5 >= 3){
                    cnt_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};