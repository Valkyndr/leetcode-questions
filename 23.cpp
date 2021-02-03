/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class NodePtr
{
    // point to some ListNode
    ListNode* node;

    public:

    // constructor MUST initialise node
    NodePtr() = delete;
    NodePtr(ListNode* node): node(node) {}

    // can only advance internal node pointer to next 
    // (operation is idempotent if already at end, but returns false)
    bool advance() 
    {
        if(node!=nullptr) node = node -> next;
    }
    
    // return value held by the handled ListNode
    int value() const
    {
        return node -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // declared list to merge to
        ListNode* mergedList;

        // declare some set of pointers
        vector<NodePtr> ptrs(lists.size());

        
    }
};

int main()
{

    // prepare some set of pointers
    

}