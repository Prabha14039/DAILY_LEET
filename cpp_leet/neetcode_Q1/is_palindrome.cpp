#include<bits/stdc++.h>

class Solution {
    int reverse(int x)
    {
        int rev_num = 0;
        while(x>0)
        {
            rev_num = rev_num *10 + x % 10;
            x /= 10;
        }
        return rev_num;
    }
    public:
        bool isPalindrome(int x) {
            if(x<0)
            {
                return false;
            }
            int rev_num = reverse(x);
            if(rev_num != x)
            {
                return false;
            }
            return true;
        }
};

int main()
{
    Solution Sol;
    int x;
    std::cin>>x;
    bool ans = Sol.isPalindrome(x);
    std::cout<<ans;
}
