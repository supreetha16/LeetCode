#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //[n1,n2],sum
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>> maxpq;
        for(int x:nums1)
        {
            for(int y :nums2)
            {
                maxpq.push({{x,y},x+y});
                if(maxpq.size()>k)
                    maxpq.pop();
            }
        }

        vector<vector<int>> res;
        while(!maxpq.empty())
        {
            pair<int,int> val = maxpq.top().first;
            res.push_back({val.first,val.second});
            maxpq.pop();
        }
        return res;
    }
};
string printVector(vector<vector<int>>& v)
{
    stringstream ss;
    for(auto& x:v)
    {
        for(auto& y:x)
            ss << y <<",";
    }
    return ss.str();
}
int main()
{
    vector<int> nums1= {1,7,11};
    vector<int> nums2= {2,4,6};
    int k = 3;
    Solution *Obj= new Solution();
    vector<vector<int>> res = Obj->kSmallestPairs(nums1,nums2,k);
    cout<<"k most frequent numbers = " << printVector(res)<<endl;
    return 0;
}