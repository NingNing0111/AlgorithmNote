typedef int ElemType;     // ��������Ԫ������ElemTypeΪ����
# include "stdarg.h"      // ���ļ�����va_start()��va_arg()��va_end()�Ⱥ���
# include "stdlib.h"      // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iostream.h"    // ���ļ�������׼���������cout��cin
# include "string.h"      // ���ļ�����C++���Ķ��弰��ز���
 # include "Array.h"       // ���ļ��а����������ݶ������������ز���
 # define  M 20           // ������󳤶�
 # define  N 10           // ������󳤶�
 int len1,len2;           // ����ʵ�ʳ���
void SubString(char  *sub,char *str,int s,int len)
{
	char *p;
	int k;
	p=str+s;k=len;
	while(k)
	{*sub++=*p++;  k--;
	}
	*sub='\0';    // ��Ӵ�������
	sub=sub-len;   //  ָ�븴λ
}// SubString

void diagscan(Array mat,int &maxlen,int &jpos,int i,int j)
{   // ��öԽ����ϸ�������1�������maxlen����ʼλ��jpos
	int eq=0,len=0,sj;            // ��һ��ɨ�迪ʼ��eq��len��ʼ��
	ElemType e;
	while(i<len2&&j<len1)
	{	Value(e,mat,i,j);            // ��mat[i][j]��ֵ����e
	    if(e==1)
		{	len++;
			if(!eq)                 // ���ֵĵ�һ��1��������ʼλ�ã��ı�״̬
			{ sj=j;eq=1;  } 
		}
		else if(eq)                  // ���һ�������Ӵ�      
		{	if(len>maxlen)           // �ǵ�ĿǰΪֹ��õ�������Ӵ�
			{ maxlen=len;jpos=sj; }
			eq=0;len=0;              // ���¿�ʼ���µ�һ���������ֵ�1
		}
		i++;j++;                      // ��������öԽ����ϵ�ǰ����һԪ��
}
}// diagscan

void diagmax1(Array mat,int &maxlen,int &jpos)
{	// ������mat�����жԽ������������ֵ�1�������maxlen����ʼλ��jpos
int i,j,k,istart;
	istart=0;                          // ��һ���Խ�����ʼԪ�����±�
	for(k=-(len1-1);k<=len2-1;k++)  // ��ǰ�Խ���������Ϊk,����Ԫ��mat[i][j]����i-j=k
	{ i=istart;          // ���Խ��߼���֮ƽ�е����Ϸ��Խ�����ʼ������istart��Ϊ0
	  j=i-k;                                 // ����������ϵ�����Ӧ��������
	  diagscan(mat,maxlen,jpos,i,j);         // ��öԽ����ϸ�������1�ĳ���
	  if(k>=0) istart++;  // �����Խ���ƽ�е����·��Խ�����ʼ������istartΪ1,2,��
}
    DestroyArray(mat);
}// diagmax1

int maxsamesubstring(char *string1, char *string2, char *sub)
{  // ���㷨���ش�string1��string2��������Ӵ�sub���䳤��
   ElemType e;
   char *p1,*p2;;
   int maxlen,jpos;
   Array mat;                         // ��������
   int i,j;
   len1=strlen(string1);
   len2=strlen(string2);
   InitArray(mat,2,len2,len1);       // ����M��N�Ķ�ά����mat
   p1=string2;  p2=string1;
   for( i=0; i<len2; i++ )            //����������Ķ�Ӧ����mat[ ][ ]
    for( j=0; j<len1; j++ )
 if(*(p1+i)==*(p2+j))
          Assign(mat,1,i,j);          // ��1 ����mat[i][j]
       else  Assign(mat,0,i,j);       // ��0 ����mat[i][j]      
    diagmax1(mat,maxlen,jpos);
                                 // ���string1��string2��������Ӵ��ĳ���maxlen
                                 // �Լ�����string1�е���ʼλ��jpos
    if (maxlen==0) *sub='\0';
    else SubString(sub,string1,jpos,maxlen);  // ���������Ӵ�
    return maxlen;
}// maxsamesubstring

void main()
 {
	 char str1[M],str2[N],sub[N];
	 int length;
	 cout<<"�������һ������";
	 cin>>str1;
	 cout<<"������ڶ�������";
	 cin>>str2;
	 length=maxsamesubstring(str1,str2,sub);
	 cout<<"������Ӵ�Ϊ��"<<sub<<"������Ϊ��"<<length<<endl;
}
