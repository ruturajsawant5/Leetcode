class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            //std::cout<<c<<" ";
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(st.empty())
                    return false;
                char poped = st.top();
                st.pop();
                if(c == '}' && poped != '{')
                    return false;
                else if(c == ')' && poped != '(')
                    return false;
                else if(c == ']' && poped != '[')
                    return false;
                
            }
            
        }
        if(st.size() == 0)
            return true;
        else 
            return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // create an empty stack to store opening brackets
        for (char c : s) { // loop through each character in the string
            if (c == '(' || c == '{' || c == '[') { // if the character is an opening bracket
                st.push(c); // push it onto the stack
            } else { // if the character is a closing bracket
                if (st.empty() || // if the stack is empty or 
                    (c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; // the string is not valid, so return false
                }
                st.pop(); // otherwise, pop the opening bracket from the stack
            }
        }
        return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};