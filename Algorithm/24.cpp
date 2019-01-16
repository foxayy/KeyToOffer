/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    //vector<vector<int>> res;  可设置为全局变量，也可以用如下方法用引用传递
    //vector<int>path;
    void dfsfind(TreeNode *node,int sum,vector<vector<int>> &res,vector<int> &path){
        path.push_back(node->val);
        if(node->left==NULL&&node->right==NULL)
            if(sum==node->val)
                res.push_back(path);
        if(node->left)
            dfsfind(node->left,sum-node->val,res,path);
        if(node->right)
            dfsfind(node->right,sum-node->val,res,path);
        path.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> path;
        if(root)
            dfsfind(root,expectNumber,res,path);  //深度优先搜索，记录路径
        return res;
    }
};