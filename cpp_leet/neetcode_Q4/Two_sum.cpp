#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> B_twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        for(int i {0} ; i<nums.size();i++)
        {
            for (int j {i+1}; j<nums.size(); j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
                }
            }
        }
        return sol;
    }

    vector<int> O_twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> map;
        for(int i {0} ;i<nums.size();i++)
        {
            int value  = target-nums[i];
            if(map.find(value)!=map.end())
            {
                sol.push_back(map[value]);
                sol.push_back(i);
                return sol;
            }
            map[nums[i]] = i;
        }
        return sol;
    }

};

int main()
{
    Solution sol;
    vector<int> nums = {3,4,5,6};
    vector<int> ans = sol.O_twoSum(nums,7);
    for(auto value : ans)
    {
        std::cout<<value<<',';
    }

}
