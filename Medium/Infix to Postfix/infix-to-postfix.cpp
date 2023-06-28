//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
       
        if(c=='^'){
            return 3;
        }
        else if(c == '*' || c == '/'){
            return 2;
        }
        else if(c == '+' || c == '-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infixToPostfix(string s) {
         // Your code here
        stack<int> st;
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            // if operand then add it to string
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else{
                if(!st.empty()){
                    // Do operations according to associativity while maintainig the rules of parenthesis
                    if((st.top()=='+' || st.top()=='-') && (s[i]=='+' || s[i]=='-')){
                        while(!st.empty() && st.top() != '('){
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                        if(st.top() == '('){
                            st.pop();
                        }
                    }
                    // Do operations according to associativity while maintainig the rules of parenthesis
                    else if((st.top()=='*' || st.top()=='/') && (s[i]=='*' || s[i]=='/')){
                        while(!st.empty() && st.top() != '('){
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                        if(st.top() == '('){
                            st.pop();
                        }
                    }
                    // Do operations according to preference if higher peference operator is in stack while maintainig the rules of parenthesis
                    else if((st.top()=='*' || st.top()=='/' || st.top()=='^') && (s[i]=='+' || s[i]=='-')){
                        while(!st.empty() && st.top() != '('){
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                        if(st.top() == '('){
                            st.pop();
                        }
                    }
                    // Do operations according to preference if higher peference operator is in stack while maintainig the rules of parenthesis
                    else if((st.top()=='^') && (s[i]=='*' || s[i]=='/')){
                        while(!st.empty() && st.top() != '('){
                            ans+=st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                        if(st.top() == '('){
                            st.pop();
                        }
                    }
                    // This is the special case because this follow right to left associativity
                    else if(st.top()=='^' && s[i]=='^'){
                        ans+=s[i];
                    }
                    // If close parenthesis is encoutered then add to ans till open parenthesis is seen
                    else if(s[i]==')'){
                        while(st.top() != '('){
                            ans+=st.top();
                            st.pop();
                        }
                        st.pop();
                    }
                    // Push the operator in stack if it is of higher preference than top element of stack or its an open parenthesis
                    else{
                        st.push(s[i]);
                    }
                }
                // If stack is empty push operator
                else{
                    st.push(s[i]);
                }
            }
        }
        // Add all operators to ans till stack gets empty
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        // return ans string
        return ans;
    
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends