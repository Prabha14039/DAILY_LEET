#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isValid(string s) {
        if(s.size()==0)
        {
            return true;
        }
        unordered_map<char,char> map ={{'}','{'},
                                       {']','['},
                                       {')','('}};
        stack<char> st;
        for(char const &ch : s)
        {
            if(map.find(ch)!=map.end())
            {
                if ( !st.empty() && map[ch]==st.top() )
                    st.pop();
                else
                    return false;
            }
            else
                st.push(ch);
        }
        return st.empty();
    }
};
int main()
{
    Solution sol;
    string s = "([{])";
    bool ans = sol.isValid(s);
    cout<<ans<<endl;
}
