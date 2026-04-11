class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int n =  s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i : freq){
            if(i!=0) return false;
        }
        return true;
    }
};