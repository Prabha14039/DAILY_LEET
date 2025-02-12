#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return 1;
        }
        sort(nums.begin(),nums.end());
        int count =1;
        int max = INT_MIN;
        for(int i {1} ;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1] == 1)
            {
                count ++;

            }
            if(max < count)
            {
                max = count;
            }
            else if(nums[i] - nums[i-1] != 1 && nums[i] != nums[i-1])
            {
                count = 1;
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;
    vector<int> nums =  {0,3,2,5,4,6,1,1};
    int ans = sol.longestConsecutive(nums);
    cout<<ans<<endl;
}
