#include<iostream>
#include<sstream>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> k;
        k.push(nums2[0]);

        map<int,int> m;
        for(int i=1;i<nums2.size();i++)
        {
            //cout<<"item | map top : " << nums2[i] << " | " << k.top()<<endl;
            if(nums2[i]>k.top())
            {
                m[k.top()]= nums2[i];
                cout<<"map[" <<k.top()<<"] = " << nums2[i]<<endl;
                k.pop();
                k.push(nums2[i]);
                
            }
        }
        for(int i=0;i<nums1.size();i++)
        {
            cout<<"m.count(" << nums1[i] << ") = " << m.count(nums1[i])<<"  map["<<nums1[i]<<"]= " << m[nums1[i]]<<endl;
            if(m.count(nums1[i]))
                res.push_back(m[nums1[i]]);
            else
                res.push_back(-1);
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
    //vector<int> nums2 = {1, 3, 4, 2};
    //vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1,2,3,4};
    vector<int> nums1 = {2,4};
    vector<int> res;

    cout<< " Main Array : " << printVector(nums2)<<endl;
    cout<< " Sub Array : " << printVector(nums1)<<endl;
    Solution *Obj =new Solution();
    res = Obj->nextGreaterElement(nums1,nums2);
    cout<< " Result : " << printVector(res)<<endl;
    return 0;
}