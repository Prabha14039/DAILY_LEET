#include<bits/stdc++.h>
#include <set>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    set<int> Set;
    for ( auto i : nums) {
        Set.insert(i);
    }
    if (Set.size()!=nums.size())
        return true;
    return false;
    }
};

int main()
{
    int size;
    cin>>size;
    Solution sol;
    vector<int> nums;
    for (int i {0} ;i < size ; i++) {
        int value;
        cin>>value;
        nums.push_back(value);

    }
    bool ans = sol.hasDuplicate(nums);
    cout<<ans;

}
