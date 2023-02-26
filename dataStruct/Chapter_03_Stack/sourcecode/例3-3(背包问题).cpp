typedef int ElemType;     // ��ջԪ������Ϊint
# include "stdlib.h"      // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"     // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "SqStack.h"     // ���ļ�����˳��ջ���ݶ������������ز���

void Print(SqStack S,int w[],int n)
{        
	int k=S.top;
	while(k>=0)
	 cout<<w[S.stack[k--]]<<' ';
   cout<<endl;
}// Print

void knapsack( int w[], int T, int n ) 
{      // ��֪n����Ʒ������ֱ�Ϊ w[0], w[1], ��, w[n]�������������Ϊ T,
        // ���㷨�������ǡ����װ����������Ʒ��Ͻ�
    SqStack S;
	int k;
	InitStack_Sq(S);   k=0;               // �ӵ�0 ����Ʒ������
    do {
      while (T>0 && k<n ) 
       { if (T-w[k]>=0 )                  // ��k����Ʒ��ѡ����k��ջ
         { Push_Sq(S,k);  T-=w[k];        // ����ʣ���������w[k]
          }
          k++;                            // ����������һ����Ʒ
        }
     if(T==0)  Print(S,w,6);        // ���һ��⣬֮�����Ѱ����һ���
     Pop_Sq(S,k );  T+= w[k];       // �˳�ջ����Ʒ������ʣ���������w[k]
     k++;                                   // ����������һ����Ʒ
  } while (!StackEmpty_Sq(S)||k!=n );
}// knapsack

void main()
{int w[]={1,8,4,3,5,2},T=10;  // ���������Ϊ10
  knapsack(w,T,6);
}
