/* 
思路：
    要将链表从尾到头遍历，则需要借助栈来实现
    1.用一个辅助指针（链表遍历必要）遍历一遍链表
    2.每遍历一个结点，将结点值入栈
    3.依次取栈顶元素，并弹出栈顶元素，然后装入结果vector
*/
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