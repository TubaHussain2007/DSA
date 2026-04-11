class Solution {
public:
    static bool comparator(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        vector<pair<char, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), comparator);

        string ans;
        for (auto &p : vec) {
            ans += string(p.second, p.first);
        }

        return ans;
    }
};