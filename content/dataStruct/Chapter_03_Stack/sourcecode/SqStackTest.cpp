typedef int ElemType;         // ˳��ջԪ������Ϊint   
# include "stdio.h"         
# include "stdlib.h"          // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "SqStack.h"         // ���ļ�����˳��ջ���ݶ������������ز���
# include "iostream.h"        // ���ļ�������׼���������cout��cin
# include "iomanip.h"    // ���ļ�������׼���������cout��cin�����Ʒ�setw()�Ⱥ��� 

int main()
 {
 SqStack mystack;
  int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88,90,3,9};
  InitStack_Sq(mystack,10,10);             // ��ʼ��˳��ջ
  for(i=0;i<12;i++)                   
  if(!Push_Sq(mystack,a[i]))               // a[i]���ν�˳��ջ
     { cout<<"��ջʧ�ܣ�"<<endl;
       return 0;
     }
	if(!GetTop_Sq(mystack,x))             // ȡջ��Ԫ�ز���ֵ��x
    {  cout<<"ȡջ��Ԫ��ʧ�ܣ�"<<endl;
       return 0;
     }
       
	cout<<"��ǰջ������Ԫ���ǣ�"<<x<<endl;
	cout<<"��ǰ˳��ջ�ĳ����ǣ�"<<StackLength_Sq(mystack)<<endl; 
	cout<<"���γ�ջ������Ԫ������Ϊ��";
    while(!StackEmpty_Sq(mystack))        // ��ջ�Ƿ�ǿ�
	{ if(!Pop_Sq(mystack,x))              // ջ��Ԫ�س�ջ����ֵ��x
       {  cout<<"��ջʧ�ܣ�"<<endl;
          return 0;
       }
	   cout<<x<<' ';
	}
	cout<<endl;
	cout<<"��ǰ˳��ջ�ĳ����ǣ�"<<StackLength_Sq(mystack)<<endl;
	cout<<endl;
	DestroyStack_Sq(mystack);           // ����˳��ջ

  }
