class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int max_freq=INT_MIN,min_freq=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    max_freq=max(max_freq,freq[k]);
                    if(freq[k]!=0) min_freq=min(min_freq,freq[k]);
                }
                count+=(max_freq-min_freq);
            }
        }
        return count;
        
    }
};