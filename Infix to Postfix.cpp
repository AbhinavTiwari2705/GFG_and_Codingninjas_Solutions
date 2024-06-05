class Solution {
  public:
    // Function to return precedence of operators.
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string result;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If the character is an operand, add it to the output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                result += c;
            }
            // If the character is '(', push it to the stack.
            else if (c == '(') {
                st.push('(');
            }
            // If the character is ')', pop and output from the stack
            // until an '(' is encountered.
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            // An operator is encountered.
            else {
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all the operators from the stack.
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
