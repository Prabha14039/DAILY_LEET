#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) { //O(n3)
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i {0};i<nums.size();i++)
        {
            for(int j {i+1}; j<nums.size();j++)
            {
                for (int k {j+1} ; k<nums.size();k++)
                {
                    if (i!=j && j!=k && k!=i && nums[i]+nums[j]+nums[k] ==0)
                    {
                        result.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(),result.end());
    }

    vector<vector<int>> twop_threeSum(vector<int>& nums) { //O(n3)
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i {0};i<nums.size();i++)
        {
            int j {i+1},k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    result.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return vector<vector<int>>(result.begin(),result.end());
    }
};


int main()
{
    vector<int> numbers = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> result = sol.twop_threeSum(numbers);
    for(auto i:result)
    {
        cout<<"{";
        for(int value : i)
        {
            cout<<value<<',';
        }
        cout<<"}"<<endl;
    }
}
