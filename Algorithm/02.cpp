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