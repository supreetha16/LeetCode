#include<iostream>
#include<sstream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        cout<<"Slow|fast : " << slow<< "|"<<fast<<endl;
        do
        {
            cout<<"Slow|fast : " << slow->val << "|"<<fast->val<<endl;
            if(fast->next == NULL || fast->next->next == NULL)
            {
                return false;
            }
            slow= slow->next;
            fast = fast->next->next;
        }while(slow != fast );
        return true;
    }
};

void printLL(ListNode *node1)
{
    stringstream ss;
    ListNode *ptr = node1;
    while (ptr != NULL)
    {
        ss << ptr->val <<",";
        ptr= ptr->next;
    }
    cout<<"LL = " <<ss.str()<<endl;
}

int main()
{
    ListNode *Head = new ListNode(3);
    ListNode *nodeptr = new ListNode(2);
    Head->next = nodeptr;
    nodeptr->next= new ListNode(0);
    nodeptr = nodeptr->next;
    nodeptr->next= new ListNode(4);
    nodeptr = nodeptr->next;
    //nodeptr->next = Head->next;

    //printLL(Head);
    Solution *Obj= new Solution();
    cout<< "Has cycle ? " << Obj->hasCycle(Head)<<endl;
    return 0;
}