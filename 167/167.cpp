#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int pStart,pEnd;
        pStart = 0;
        pEnd=getIndex(numbers,target);

        //{1, 2, 3, 4, 4, 9, 56, 90}, key = 8, res= 4,5
        while(pStart < pEnd)
        {
            int sum = numbers[pStart] + numbers[pEnd];
            if(sum == target){
                res.push_back(pStart + 1);
                res.push_back(pEnd + 1);
                break;
            }
            else if(sum < target)
                pStart++;
            else
                pEnd--;
        }

        return res;
    }
private:
    int getIndex(vector<int>& numbers, int target)
    {
        int index = numbers.size()-1;
        //cout << "start index = " << index<<endl;
        //find the point which is <= target
        while((target>0?numbers[index] >target: numbers[index] < target) && index>=0)
        {
            index--;
            //cout << "while index = " << index<<endl;
        }
        cout<<"end Index = " << index <<" | value : "<< numbers[index]<<endl;
        return index;
    }
};

int main()
{
    vector<int> nums={-1,0};
    //{1, 2, 3, 4, 4, 9, 56, 90}, key = 8, res= 4,5
    //{-1,0} , key = -1
    int target = -1;
    Solution *Obj = new Solution();
    vector<int> res = Obj->twoSum(nums,target);
    for(int i : res)
        cout << i << " ";
    return 0;
}