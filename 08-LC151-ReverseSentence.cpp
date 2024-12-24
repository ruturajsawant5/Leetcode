class Solution {
public:
    //pass by val vs ref
    void reverse(string &s, int l, int r)
    {
        while(l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--; 
        }
    }
    string reverseWords(string s) {
        // Step 1: Remove extra spaces in place
        int n = s.size();
        int i = 0; // To traverse the string
        int j = 0; // To build the string with single spaces

        // Remove leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            // Copy non-space characters
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            // Skip extra spaces
            while (i < n && s[i] == ' ') i++;
            // Add a single space between words (if more words exist)
            if (i < n) {
                s[j++] = ' ';
            }
        }

        // Remove trailing spaces
        if (j > 0 && s[j - 1] == ' ') j--;

        // Resize the string to the new valid size
        s.resize(j);

        // Step 2: Reverse the entire string
        reverse(s, 0, s.size() - 1);

        // Step 3: Reverse each word
        for (int start = 0, end = 0; end <= (s.size() - 1); end++) {
            if (s[end] == ' ' || end == s.size() - 1) {
                reverse(s, start, (end == s.size() - 1) ? end : end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};








#include <iostream>
#include <regex>
#include <string>

// A function that reverses characters from startRev to endRev in place
void StrRev(std::string &str, int startRev, int endRev) {
    while (startRev < endRev) {
        char temp = str[startRev];
        str[startRev] = str[endRev];
        str[endRev] = temp;
        startRev++;
        endRev--;
    }
}

std::string ReverseWords(std::string sentence) {
    sentence = std::regex_replace(sentence, std::regex("^ +| +$|( ) +"), "$1");

    int strLen = sentence.length() - 1;
    
    StrRev(sentence, 0, strLen);

    for (int start = 0, end = 0; end <= strLen; ++end) {
        if (end == strLen || sentence[end] == ' ') {
            int endIdx = (end == strLen) ? end : end - 1;
            StrRev(sentence, start, endIdx);
            start = end + 1;
        }
    }

    return sentence;
}


// Driver code
int main()
{
    std::vector<std::string> 
		stringToReverse = {"Hello World",
							"a   string   with   multiple   spaces",
							"Case Sensitive Test 1234",
							"a 1 b 2 c 3 d 4 e 5",
							"     trailing spaces",
							"case test interesting an is this"};

    for (int i = 0; i < stringToReverse.size(); i++)
    {
        std::cout << i + 1 << ".\tOriginal string: '" << stringToReverse[i] << "'" << std::endl;
        std::cout << "\tReversed string: '" << ReverseWords(stringToReverse[i]) << "'" << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}