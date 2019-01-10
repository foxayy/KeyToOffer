/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> stack;
        int temp;
        ListNode* r=head;
        if(r==NULL)
            return result;
        while(r!=NULL)
        {
            stack.push(r->val);
            r=r->next;
        }
        while(!stack.empty())
        {
            int temp=stack.top();
            result.push_back(temp);
            stack.pop();
        }
        return result;
    }
};