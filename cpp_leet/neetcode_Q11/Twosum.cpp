#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { //O(n2);
        vector<int> result ;
        for(int i {0} ; i<numbers.size();i++)
        {
            for(int j {i+1} ; j<numbers.size();j++)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }
        return result;
    }

    vector<int> Map_twoSum(vector<int>& numbers, int target) { //O(n2);
            vector<int> result;
            unordered_map<int,int> map;
            for(int i {0}; i<numbers.size();i++)
            {
                int value = target - numbers[i];
                if(map.find(value)!=map.end())
                {
                    result.push_back(map[value]+1);
                    result.push_back(i+1);
                    return result;
                }
                map[numbers[i]]= i;
            }
            return result;
    }

    vector<int> Optimal_twoSum(vector<int>& numbers, int target) { //O(n2);
        vector<int> result;
        int i = 0,j = numbers.size()-1;
        while(i<numbers.size())
        {
            if(numbers[i]+numbers[j]==target)
            {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return result;
    }

};

int main()
{
    vector<int> numbers = {1,2,3,4};
    int target = 3;
    Solution sol;
    vector<int> result = sol.Optimal_twoSum(numbers, target);
    for(auto i:result)
    {
        cout<<i<<endl;
    }
}
