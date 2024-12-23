//O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        if(s.length() <= 1)
            return true;

        while(left < right)
        {
            if(!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if(!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
        
    }
};

bool IsPalindrome(std::string inputString)
{
    int left = 0;
    int right = inputString.length() - 1;
    while (left < right)
    {
        if (inputString[left] != inputString[right])
        {
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;
}

int main()
{
    std::vector<std::string> inputStrings = {"RACEACAR", "A", "ABCDEFGFEDCBA",
                                             "ABC", "ABCBA", "ABBA", "RACEACAR"};
    for (int i = 0; i < inputStrings.size(); i++)
    {
        std::cout << "Test Case # " << i+1 << std::endl;
        std::cout << std::string(100, '-') << std::endl;
        std::cout << "The input string is \'" << inputStrings[i] << "\' and the length of the string is " << inputStrings[i].size() << "." << std::endl;
        bool result = IsPalindrome(inputStrings[i]);
        std::cout << "\nIs it a palindrome?..... ";
        if (result)
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}