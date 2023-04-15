# define N 9	
typedef int ElemType;      // ѭ������Ԫ������Ϊint
# include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "SqQueue.h"      // ���ļ�����ѭ���������ݶ������������ز���

void division(int R[N][N],int n, int result[ ],int &group) 
{    // ��֪ R[N][N]�Ǳ��Ϊ0 ��n-1�� n��Ԫ�صĹ�ϵ����,�Ӽ����ֵĽ��
    // ����result����,result[k]��ֵ�Ǳ��Ϊ k ��Ԫ���������
int i,j,pre=n;  
int clash[N];
   SqQueue Q;
   InitQueue_Sq(Q,n+1);                       // �����������Ϊ n+1�Ŀն���
   for(int e=0; e<n; e++)  EnQueue_Sq (Q,e);  // ȫ����Ŀ����
     while (!QueueEmpty_Sq(Q)) 
{ DeQueue_Sq(Q,i); 
       if(i<=pre ) 
{ group ++;                              // ����һ���µ���
         for(j=0; j<n; j++)  
clash[j]=0;
	  }
     if (clash[i]==0) 
{ result[i] = group;                // ���Ϊi ��Ԫ����group ��
       for(j=0; j<n; j++ ) clash[j]+= R[i][j];   // ��Ӻ� i��ͻ����Ϣ
     }
     else EnQueue_Sq(Q,i);             // ���Ϊi��Ԫ�ز����뵱ǰ��,���½���
	  pre=i; 
  } 
}// division

void main()
{ int i,j,result[N],group=0; 
int R[N][N]={{0,1,0,0,0,1,0,0,0},{1,0,0,0,1,1,0,1,1},{0,0,0,0,0,1,1,0,0},
{0,0,0,0,1,0,0,0,1},{0,1,0,1,0,0,1,0,1},{1,1,1,0,0,0,1,0,0},
{0,0,1,0,1,1,0,0,0},{0,1,0,0,0,0,0,0,0},{0,1,0,1,1,0,0,0,0}};
  division (R,N,result,group);
  cout<<"�ܹ���"<<group<<"��С�顣"<<endl;
  cout<<"����������£�"<<endl;
  for( i=0;i<N;i++)
	   cout<<result[i]<<' ';
  cout<<endl;
 for( i=1;i<=group;i++)
  { cout<<"��"<<i<<"С�����ĿΪ��";
	   for( j=0;j<N;j++)
		  if(result[j]==i) cout<<j<<' ';
	  cout<<endl;
  }
}
