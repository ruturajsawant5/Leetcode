#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Function to check if a number is strobogrammatic
bool IsStrobogrammatic(const std::string& num) 
{
    std::unordered_map<char, char> dict = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    int left = 0;
    int right = num.size() - 1;
    
    while (left <= right) {
        if (dict.find(num[left]) == dict.end() || dict[num[left]] != num[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Driver code
int main() {
    std::vector<std::string> nums = {
        "609",
        "88",
        "962",
        "101",
        "123"
    };

    int i = 0;
    for (const auto& num : nums) {
        std::cout << i + 1 << ".\tnum: " << num << std::endl;
        std::cout << "\n\tIs strobogrammatic: " << (IsStrobogrammatic(num) ? "true" : "false") << std::endl;
        std::cout << std::string(100, '-') << std::endl;
        i++;
    }

    return 0;
}
