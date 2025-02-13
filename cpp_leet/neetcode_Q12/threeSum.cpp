#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int i =0 ,j=i+1,k=nums.size()-1;
        while(i<nums.size())
        {
            if(nums[j]+nums[k] == -nums[i] && i!=j && j!=k && i!=k)
            {
                result.push_back({nums[i],nums[j],nums[k]});
                i++;
            }
            if(nums[j]+nums[k]>-nums[i] && k>j)
            {
                k--;
                continue;
            }
            else if(nums[j]+nums[k]<-nums[i] && j<k)
            {
                j++;
                continue;
            }

            i++;
            j = i+1;
            k = nums.size()-1;
        }
        return result;
    }
};


int main()
{
    vector<int> numbers = {-1,0,-1,2,-4};
    Solution sol;
    vector<vector<int>> result = sol.threeSum(numbers);
    for(auto i:result)
    {
        for(int value : i)
        {
            cout<<value<<endl;
        }
    }
}
