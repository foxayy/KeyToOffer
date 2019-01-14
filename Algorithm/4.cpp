/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int length=pre.size();
        if(length==0)
            return NULL;
        TreeNode* head=new TreeNode(pre[0]);
        int root=0;
        vector<int> left_pre,left_vin;
        vector<int> right_pre,right_vin;
        for(int i=0;i<length;i++)        //寻找根的位置
            if(pre[0]==vin[i]){
                root=i;
                break;
            }
        for(int j=0;j<root;j++)              //找出左子树的前序和中序序列
        {
            left_pre.push_back(pre[j+1]);
            left_vin.push_back(vin[j]);
        }
        for(int k=root+1;k<length;k++)
        {
            right_pre.push_back(pre[k]);
            right_vin.push_back(vin[k]);
        }
        head->left=reConstructBinaryTree(left_pre,left_vin);
        head->right=reConstructBinaryTree(right_pre,right_vin);
        return head;
    }
};