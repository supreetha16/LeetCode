#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        if(!nums.empty())
        {
            prefixSum[0] = nums[0];
            for(int i = 1; i < nums.size(); ++i)
            {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
    }
private:
    vector<int> prefixSum; 
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl; // Output: 6
    cout << obj->sumRange(1, 3) << endl; // Output: 9
    delete obj;
    return 0;
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */