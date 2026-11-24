#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> frq;
        for(int x : nums) frq[x]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minpq;
        for(auto& [num,count] : frq)
        {
            minpq.push({count,num});
            if(minpq.size()>k)
                minpq.pop();
        }
        while(!minpq.empty())
        {
            res.push_back(minpq.top().second);
            minpq.pop();
        }
        return res;        
    }
};
string printVector(vector<int>& v)
{
    stringstream ss;
    for(int i=0;i<v.size();i++)
    {
        ss << v[i]<<",";
    }
    return ss.str();
}
int main()
{
    vector<int> nums= {1,2,1,2,1,2,3,1,3,2};
    int k = 4;
    Solution *Obj= new Solution();
    vector<int> res = Obj->topKFrequent(nums,k);
    cout<<"k most frequent numbers = " << printVector(res)<<endl;
    return 0;
}