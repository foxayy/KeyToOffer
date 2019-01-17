/*
思路：
    这个问题应该使用DFS思想，中间加入记录路径
    1.传入一个结点，把这个结点加入path
    2.判断左右孩子，如果都没有，就看期望和是否等于结点值，如果成立，则加入result
    3.然后依次判断左右子树
    4.最后弹出path的最后一个，以进行下一条路径的查找
*/
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