typedef int ElemType;      // ��ջԪ������Ϊint
# include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "LinkStack.h"    // ���ļ�������ջ���ݶ������������ز���
	
void main()
 {
 LinkStack mystack;
  int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88};
  InitStack_L(mystack);                 // ��ʼ����ջ
  for(i=0;i<12;i++)
    if(!Push_L(mystack,a[i]))            // a[i]���ν���ջ
     { cout<<"��ջʧ�ܣ�"<<endl;
       return;
     }
	if(!GetTop_L(mystack,x))             // ȡջ��Ԫ�ز���ֵ��x
    {  cout<<"ȡջ��Ԫ��ʧ�ܣ�"<<endl;
       return;
     }
	cout<<"��ǰջ������Ԫ���ǣ�"<<x<<endl;
	cout<<"��ǰ��ջ�ĳ����ǣ�"<<StackLength_L(mystack)<<endl;
// ����ջ�ĳ��Ȳ����
	cout<<"���γ�ջ������Ԫ������Ϊ��";
    while(!StackEmpty_L(mystack))       // ��ջ�Ƿ�ǿ�
	{  if(!Pop_L(mystack,x))              // ջ��Ԫ�س�ջ����ֵ��x
       {  cout<<"��ջʧ�ܣ�"<<endl;
          return;
       }
	   cout<<x<<' ';
	}
	cout<<endl;
	cout<<"��ǰ��ջ�ĳ����ǣ�"<<StackLength_L(mystack)<<endl;
	cout<<endl;
	DestroyStack_L(mystack);             // ������ջ
  }
