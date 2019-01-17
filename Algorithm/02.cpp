/*
思路：
    要把一个空格字符替换成一个字符串，其中包含3个字符
    1.遍历字符串，找出空格位置
    2.将空格位置替换成第一个字符
    3.按照顺序表的插入方式在这个空格字符后面插入两个字符
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int i,j;
        for(i=0;i<length;i++)
        {
            if(str[i]==' ')
            {
                for(j=length-1;j>i;j--)
                    str[j+2]=str[j];
                str[j]='%';
                str[j+1]='2';
                str[j+2]='0';
                length=length+2;
            }
        }
	}
};