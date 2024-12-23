class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;

        if(s.size() <= 1)
            return;

        while(l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;

            l++;
            r--;
        }
        
    }
};