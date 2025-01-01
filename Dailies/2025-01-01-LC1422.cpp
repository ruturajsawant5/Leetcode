class Solution {
public:
    int maxScore(string s) {

        int ones = std::count(s.begin(), s.end(), '1');
        int max = 0;
        int zeroes = 0;

        //traverse excl last element
        for(int i = 0; i < s.size() - 1 ; i++) {
            if(s[i] == '0')
                zeroes++;
            else
                ones--;
            max = std::max(max, zeroes+ones);
        }

        return max;
    }
};