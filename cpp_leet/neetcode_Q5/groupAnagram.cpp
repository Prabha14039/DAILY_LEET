#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto const& value : strs)
        {
            string Sorted = value;
            sort(Sorted.begin(),Sorted.end());
            map[Sorted].push_back(value);
        }
        vector<vector<string>> result;
        for(auto const& value : map)
        {
            result.push_back(value.second);
        }
        return result;
    }
    vector<vector<string>> O_groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;
        vector<string> ans;
        for(auto const& s: strs)
        {
            vector<int> map(26,0);
            for(char c : s)
            {
                map[c - 'a']++;
            }
            string key = to_string(map[0]);
            for(int i = 1;i<map.size();i++)
            {
                key += ',' + to_string(map[i]);
            }
            result[key].push_back(s);
        }
        vector<vector<string>> sol;
        for(auto const& value : result)
        {
            sol.push_back(value.second);
        }
        return sol ;
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> res =  sol.groupAnagrams(strs);
    for(auto const& value: res)
    {
        std::cout<<value.front();
    }
}
