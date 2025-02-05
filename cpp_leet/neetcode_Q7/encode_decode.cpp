#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        vector<int> sizes;
        for(string &s : strs)
        {
            sizes.push_back(s.size());
        }
        string result = "";
        for(auto i : sizes)
        {
            result += to_string(i) + ',';
        }
        result+= "#";
        for(auto i : strs)
        {
            result+= i;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        vector<string> result;
        int i = 0;
        while(s[i] != '#')
        {
            string res =  "";
            while(s[i]!=',')
            {
                res += s[i];
                i++;
            }
            sizes.push_back(stoi(res));
            i++;
        }
        i++;
        for(auto cs : sizes)
        {
            result.push_back(s.substr(i,cs));
            i += cs;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"neet","code","love","you"};
    string s = sol.encode(strs);
    vector<string> result = sol.decode(s);
    cout<<s<<endl;
    for(auto i : result)
    {
        std::cout<<i<<',';
    }
}

