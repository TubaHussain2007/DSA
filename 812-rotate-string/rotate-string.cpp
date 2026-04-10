class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return 0;
        }
        string str = s;
        for(int i = 0; i <s.size(); i++){
            if(str == goal){
                return 1;
            }else{
                char ch = s[i];
                str.erase(str.begin());
                str += ch;
            }
        }
        return 0;
    }
};