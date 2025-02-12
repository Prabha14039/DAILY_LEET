#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool isPalindrome(string s) {
        auto end_pos = remove(s.begin(),s.end(),' ');
        s.erase(end_pos,s.end());
        for(char &ch : s)
        {
            ch = tolower(ch);
            s.erase(
                    remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }),
                    s.end() );

                }
        string s_revers = s;
        reverse(s_revers.begin(),s_revers.end());
        for(int i {0}; i<s.size();i++)
        {
            if(s[i]!=s_revers[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Sol;
    bool ans = Sol.isPalindrome("Was it a car or a cat I saw?");
    std::cout<<ans;
}
