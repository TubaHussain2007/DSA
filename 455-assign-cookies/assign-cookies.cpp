class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
        int n = Student.size();
        int m = Cookie.size();

        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int l =0, r=0;

        while(l<n && r<m){
            if(Cookie[r] >= Student[l]){
                l++;
            }
            r++;
        }
        return l;
    }
};