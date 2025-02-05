#include<bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> solution;
        unordered_map<int,int> map;
        for(auto i:nums)
        {
            map[i]++;
        }
        vector<pair<int,int>> list(map.begin(),map.end());
        sort(list.rbegin(), list.rend());
        for(int i {0};i<k;i++)
        {
            solution.push_back(list[i].first);
        }
        return solution;
    }

    vector<int> O_topKFrequent(vector<int>& nums, int k) {
        vector<int> solution;
        unordered_map<int,int> map;
        for(auto i:nums)
        {
            map[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        for(auto const& value:map)
        {
            heap.push({value.second,value.first});
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        for(int i {0} ; i<k ; i++)
        {
            solution.push_back(heap.top().second);
            heap.pop();
        }
        return solution;
    }
};

int main()
{
    Solution Sol;
    vector<int> ques = {1,2,2,3,3,3};
    vector<int> result = Sol.O_topKFrequent(ques, 2);
    for(auto i :result)
    {
        cout<<i<<endl;
    }
}
