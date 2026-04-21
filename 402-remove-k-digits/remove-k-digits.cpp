class Solution {
   public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (nums[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while(res.size() !=0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};