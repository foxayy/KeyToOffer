/*
思路：
    这个问题应该使用递归来判断每一个结点
    二叉搜索树的后续遍历有个特点，最后一位是根，左子树的值都小于右子树的值
    1.如果向量中只存在一个值，成立
    2.假设这个序列是成立的，从后往前找到左子树（第一个小于根的树）
    3.遍历左子树，如果有大于根的值就false
    4.递归地判断左右子树是否同时符合条件
*/
class Solution {
public:
    bool judge(vector<int> &sequence,int front,int rear){
        if(front>=rear)  //如果向量中只有一个元素，自然成立
            return true;
        int i=rear;
        while(i>front&&sequence[i-1]>sequence[rear])  //右子树的值都大于等于根，找出第一个小于根的值
            i--;
        int j=i-1;
        for(j;j>=front;j--)  //遍历此时的左子树，如果有大于根的，则false
            if(sequence[j]>sequence[rear])
                return false;
        return judge(sequence,front,j)&&judge(sequence,j+1,rear-1);  //递归判断左右子树是否成立
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)
            return false;
        else
            return judge(sequence,0,sequence.size()-1);
    }
};