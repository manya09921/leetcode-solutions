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
class Solution {
public:
    ListNode* partitionandmerge(int start, int end,vector<ListNode*>& lists ){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode* L1= partitionandmerge(start,mid,lists);
        ListNode* L2=partitionandmerge(mid+1,end,lists);
        return mergetwolists(L1,L2);
    }

    ListNode* mergetwolists(ListNode* L1, ListNode* L2){
        if(L1==NULL) return L2;
        if(L2==NULL) return L1;
        if(L1->val >= L2->val)
        {
            L2->next=mergetwolists(L2->next,L1);
            return L2;

        }
        else{
            L1->next=mergetwolists(L1->next,L2);
            return L1;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        return partitionandmerge(0,k-1,lists);
    }
};