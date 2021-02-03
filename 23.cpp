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
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX_VALUE string::npos

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
    
    // return true only if held ListNode* has a non-nullptr next state
    bool canAdvance() const
    {
        if(node==nullptr) return false;
        return (node->next!=nullptr);
    }

    // return value held by the handled ListNode
    int value() const
    {
        if(node==nullptr) return MAX_VALUE;
        return node -> val;
    }
};

// helper to see if all NodePtrs in some collection are 'finished'
bool stillRunning(const vector<NodePtr*> node_ptrs)
{
    for(int idx=0; idx<node_ptrs.size(); idx++)
    {
        if(node_ptrs[idx]->canAdvance()) return true;
    }

    // only false if all non-advancing
    return false;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // declared list to merge to
        ListNode* mergedList;

        // declare some set of pointers
        vector<NodePtr*> ptrs(lists.size(), nullptr);

        // set pointers to each start of 'lists'
        for(int idx=0; idx<lists.size(); idx)
        {
            ptrs[idx] = new NodePtr(lists[idx]);
        }

        // declare loop buffers here
        NodePtr* min_ptr;
        int min_value;

        // in each loop, exactly 1 node_ptr must advance
        while(stillRunning(ptrs))
        {
            // min_value should always be replaced
            min_value = MAX_VALUE;

            for(int idx = 0; idx<ptrs.size(); idx++)            
            {
                if(ptrs[idx]->canAdvance())
                {
                    if(ptrs[idx]->value()<min_value)
                    {
                        min_ptr = ptrs[idx];
                    }
                }
            }

            // create new node here ('add on' to merged_list)
        }
    }
};

int main()
{

    // prepare some set of pointers
    

}