class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves = 0;
    
        for (int i = 0, j = s.size() - 1; i < j; ++i) {
            int k = j;
            for (; k > i; --k){
                if (s[i] == s[k]) {
                    for (; k < j; ++k) {
                        std::swap(s[k], s[k + 1]);
                        ++moves;
                    }
                    --j;
                    break;
                }
            }
            if (k == i)
                moves += s.size() / 2 - i;
        }
        return moves;
    }
};