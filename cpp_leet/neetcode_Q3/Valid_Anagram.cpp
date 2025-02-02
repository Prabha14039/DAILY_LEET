#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
            return false;

        unordered_map<char,int> hash_map;

        for (auto i : s) {
            hash_map[i]++;
        }

        for (auto value : t) {
            if(hash_map.find(value)==hash_map.end())
                return false;
            else if(hash_map[value] == 0)
                return false;
            hash_map[value]--;
        }

        for (auto value : t) {
            if(hash_map.find(value)!=hash_map.end() && hash_map[value]!=0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    bool ans = sol.isAnagram("jar","jam" );
    cout<<ans;

}

