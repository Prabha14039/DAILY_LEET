#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
    int Max = INT_MIN;
    int l=0,r=heights.size()-1;
    while(l<r)
    {
        int height = min(heights[l],heights[r]);
        int area = height * (r-l);
        Max = max(area,Max);
        if(heights[l]==heights[r])
        {
            l++;
            continue;
        }
        if (heights[l]>heights[r])
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return Max;
    }
};

int main()
{
    vector<int> numbers = {2,2,2};
    Solution sol;
    int result = sol.maxArea(numbers);
    cout<<result<<endl;
}
