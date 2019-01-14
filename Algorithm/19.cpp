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