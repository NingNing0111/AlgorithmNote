typedef int ElemType;     // ��ջԪ������Ϊint
# include "stdlib.h"      // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"     // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "LinkStack.h"   // ���ļ�������ջ���ݶ������������ز���

void TransFrom(long N,int d )
{
LinkStack S;             // ��˳��ջ����ջ�����ԣ��˴�����ջ
int x;
  InitStack_L(S);
while(N)
   { Push_L(S,N % d);
     N=N/d;
    }
while(!StackEmpty_L(S))
{ Pop_L(S,x);
     cout<<x;
}
   cout<<endl;
}// TransFrom

void main()
{ int num,dec;              // num���ʮ��������dec��Ž���
  cout<<"����һ��ʮ��������";
  cin>>num;
  cout<<"����Ҫת���Ľ��ƣ�";
cin>>dec;  
cout<<"ת�����"<<dec<<"������Ϊ��"; 
  TransFrom(num,dec);                 // ��������ת������
}	
