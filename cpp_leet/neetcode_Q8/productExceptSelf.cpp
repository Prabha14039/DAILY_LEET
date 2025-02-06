#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int i = 0;
        while(i<nums.size())
        {
            int mult = 1;
            for(int j {0}; j<nums.size();j++)
            {
                if(i!=j)
                {
                   mult *= nums[j];
                }
            }
            result.push_back(mult);
            i++;
        }
        return result;
    }

    vector<int> O1_productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> preffix(nums.size(),1),suffix(nums.size(),1);
        int mult = 1;
        for(int i{1} ; i<nums.size();i++)
        {
            mult *= nums[i-1];
            preffix[i] = mult;
        }

        mult =1;
        int size = suffix.size();
        for(int i{size-2} ; i>=0;i--)
        {
            mult *= nums[i+1];
            suffix[i] = mult;
        }

        for(int i{0}; i<nums.size();i++)
        {
            result.push_back(preffix[i]*suffix[i]);
        }
        return result;
    }

    vector<int> O2_productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int mult = 1;

        for(int i{1} ; i<nums.size();i++)
        {
            mult *= nums[i-1];
            result[i] = mult;
        }

        mult =1;
        for(int i{int(result.size()-1)} ; i>=0;i--)
        {
            result[i] *= mult;
            mult *= nums[i];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,4,6};
    vector<int> ans = sol.O2_productExceptSelf(nums);
    for(int value: ans)
    {
        cout<<value<<endl;
    }
}
