#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;
        //prefix array
        vector<int> aPrefixArr ;
        aPrefixArr.resize(nums.size());
        aPrefixArr[0]= nums[0];

        stringstream ssp ,ssn;
        ssn<< nums[0] << ",";
        ssp<< aPrefixArr[0] << ",";

        int *pStart,*pEnd;
        pStart = &aPrefixArr[0];
        pEnd = pStart;
        cout <<"Start : " << *pStart<<endl;
        if(*pStart == k)
        {
            cout << "First pos == K ,count = " << ++count<<endl;
        }

        for (int i =1;i< nums.size();i++)
        {
            aPrefixArr[i] = aPrefixArr[i-1] + nums[i];
            ssn<< nums[i] << ",";
            ssp<< aPrefixArr[i] << ",";
            //pStart = &aPrefixArr[i-1];
            int j= i-1;

            cout<< "i = " << i << " | Prefix[i] : "<<aPrefixArr[i]<< " | j = "<< aPrefixArr[j]<< endl;
            if(aPrefixArr[i] == k)
            {
                cout << "       Prefix = k , count = " << ++count<<endl;
                //count++;
            }
            if(k>=0? aPrefixArr[i]> k :  aPrefixArr[i]< k)
            {
                //while(k>=0?aPrefixArr[i]- *pStart < k :aPrefixArr[i]- *pStart > k)
                while(aPrefixArr[i]- aPrefixArr[j] != k && j>=0)
                {
                    j--;
                }
                if(aPrefixArr[i]- aPrefixArr[j] == k)
                    cout << "        aPrefixArr[i] = k , count = " << ++count<<endl;
                    //count++;
            }
        }
        cout <<"Array : " << ssn.str()<<endl;
        cout <<"Sums Array : " << ssp.str()<<endl;

        return count;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    //{-2, -3, -5}; -5 , res = 2
    //{7,3, 4, 7, 2, -3, 1, 4, 2};k = 7,res= 5
    //{1,2,4,5,7,8,3,2}; 11 res = 2
    //{10, -10, 10, -10} , k=0, res=4
    //{0, 0, 0, 0} k=0; res=10
    int k = 0;
    Solution *obj = new Solution();
    int result =obj->subarraySum(nums,k);
    cout<<"Number of Subarray with sum = " << k << " is " << result<<endl;
    return 0;
}