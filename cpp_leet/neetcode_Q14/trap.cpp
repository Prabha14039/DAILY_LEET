#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;

        for(int i {0} ; i<height.size();i++)
        {
            int leftMax = height[i];
            int rightMax = height[i];
            for(int j= 0;j<i;j++)
            {
                leftMax = max(leftMax,height[j]);
            }

            for(int k= i+1;k<height.size();k++)
            {
                rightMax = max(rightMax,height[k]);
            }

            res += min(leftMax,rightMax)-height[i];
        }
        return res;
    }
    int trap_two(vector<int> &height)
    {
        int res = 0;
        int l = 0, r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];
        while(l<r)
        {
            if(leftMax<rightMax)
            {
                l++;
                leftMax = max(leftMax,height[l]);
                res += leftMax- height[l];
            }
            else
            {
                r--;
                rightMax = max(rightMax,height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
int main()
{

    Solution sol;
    vector<int> nums = {0,2,0,3,1,0,1,3,2,1};
    int res = sol.trap_two(nums);
    cout<<res;
}
