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