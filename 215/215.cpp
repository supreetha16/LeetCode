#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minpq ;
        for (int x : nums) 
        {
            minpq.push(x); 
            if (minpq.size() > k)
            minpq.pop(); 
        }
        return minpq.top();
    }
};

int main()
{
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int k = 4;

    Solution *Obj=new Solution();
    cout <<"kth largest number = " <<Obj->findKthLargest(nums,k)<<endl;
    return 0;
}