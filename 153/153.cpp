#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = (nums.size()/2);
        //cout<<"low | high | mid =" <<low<<" | " << high<<" | " <<mid<<endl;
        //{4,5,6,7,0,1,2}
        // l     m     h
        //       l   m h
        while(low < high)
        {
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
            mid = low + (high - low) / 2;
        }      

        return nums[low];
    }
};

int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    Solution *Obj= new Solution();
    int min = Obj->findMin(nums);
    cout<< "Minimum number = " << min <<endl;
    return 0;
}