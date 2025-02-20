#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> st;
        for(string ch : tokens)
        {
            if(ch == "*")
            {
                int temp = st.top();
                st.pop();
                int result = st.top() * temp;
                st.pop();
                st.push(result);
            }

            else if(ch == "/")
            {
                int temp = st.top();
                st.pop();
                int result = st.top() / temp;
                st.pop();
                st.push(result);
            }

            else if(ch == "+")
            {
                int temp = st.top();
                st.pop();
                int result = st.top() + temp;
                st.pop();
                st.push(result);
            }

            else if(ch == "-")
            {
                int temp = st.top();
                st.pop();
                int result = st.top() - temp;
                st.pop();
                st.push(result);
            }

            else
            {
                int value = stoi(ch);
                st.push(value);
            }
        }
        return st.top();
    }
    int recursive(vector<string> &tokens)
    {
        return dfs(tokens);
    }
private:
    int dfs(vector<string> & tokens)
    {
        string str = tokens.back();
        tokens.pop_back();

        if(str != "/" && str!="*" && str!="+" && str!="-")
        {
            return stoi(str);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);

        if(str == "/")
        {
            return left / right;
        }
        else if(str == "*")
        {
            return right * left;
        }
        else if(str == "-")
        {
            return left - right;
        }
        else if(str == "+")
        {
            return right + left;
        }
        return 0;
    }
};

int main()
{
    Solution stack ;
    vector<string> tokens = {"4","13","5","/","+"};
    int ans =stack.evalRPN(tokens);
    int value = stack.recursive(tokens);
    cout<<"using stack: "<<ans<<endl<<"using recursive function: "<<value;
}
