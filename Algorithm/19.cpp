/*
思路：
	首先确定行数和列数，如果行数或者列数为0则没有元素
	1.从左上角起，确定四个角的坐标
	2.首先从左到右遍历，加入vector
	3.然后从上到下，top+1，遍历到bottom，加入vector
	4.首先判断top！=bottom，避免只有一行的情况，重复遍历，然后从右到左遍历
	5.再判断left！=right，避免只有一列的情况，重复遍历
	6.缩小一圈矩阵
*/
class solution{
public:
	vector<int> printMatrix(vector<vector<int>> Matrix){
		int row=Matrix.size();
		int col=Matrix[0].size();
		vector<int> res;
		if(row==0||col==0)  //事实上不存在某行数或者某列数单独为0的情况，行数为0时，列数比为0
			return res;
		int left=0,right=col-1,top=0,bottom=row-1;
		while(left<=right&&top<=bottom)
		{
			for(int i=left;i<=right;i++)  //从左到右
				res.push_back(Matrix[top][i]);

			for(int i=top+1;i<=bottom;i++)  //从上到下
				res.push_back(Matrix[i][right]);

			if(top!=bottom)
			for(int i=right-1;i>=left;i--)  //从右到左
				res.push_back(Matrix[bottom][i]);

			if(left!=right)
			for(int i=bottom-1;i>top;i--)  //从下到上
				res.push_back(Matrix[i][left]);

			left++;right--;top++;bottom--;
		}
		return res;
	}
};