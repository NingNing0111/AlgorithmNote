 typedef int ElemType;   // �������Ԫ������ElemTypeΪ����
 # include "iostream.h"   // ���ļ�������׼���������cout��cin
 # include "iomanip.h"             // ���ļ��������Ʒ�setw()
 # include "stdlib.h"  // ���ļ�����malloc()
 # include"TSMatrix.h" // ��Ԫ��˳���洢�ṹ��ϡ������������㺯��

 void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
 { // ������ϡ�����M��ת�þ���T
   int p,q,col,*num,*cpot;
   num=(int*)malloc((M.n)*sizeof(int)); // ��Mÿ��(Tÿ��)����Ԫ�ظ���
   cpot=(int*)malloc((M.n)*sizeof(int)); // ��Tÿ����һ������Ԫ�ص�λ��
   T.m=M.n; // T������=M������
   T.n=M.m; // T������=M������
   T.t=M.t; // T�ķ���Ԫ�ظ���=M�ķ���Ԫ�ظ���
   if(T.t) // T�Ƿ������
   { for(col=0;col<M.n;++col) // ��M�ĵ�1�е����һ��
       num[col]=0; // ��������ֵ��Ϊ0
     for(p=0;p<M.t;++p) // ����M��ÿһ������Ԫ��
       ++num[M.data[p].j]; // ���������ڵ��н���ͳ��
     cpot[0]=0; // T�ĵ�1�еĵ�1������Ԫ��T.data�е����Ϊ1
     for(col=1;col<M.n;++col) // ��M(T)�ĵ�2��(��)�����һ��(��)
       cpot[col]=cpot[col-1]+num[col-1]; // ��T�ĵ�col�е�1������Ԫ��T.data�е����
     for(p=0;p<M.t;++p) // ����M��ÿһ������Ԫ��
     { col=M.data[p].j; // ������M�е���������col
       q=cpot[col]; // qָʾM��ǰ��Ԫ����T�е����
       T.data[q].i=M.data[p].j; // ��M��ǰ��Ԫ��ת�ø���T
       T.data[q].j=M.data[p].i;
       T.data[q].e=M.data[p].e;
       ++cpot[col]; // T��col�е���һ������Ԫ��T.data�е���űȵ�ǰԪ�ص���Ŵ�1
     }
   }
   free(num); // �ͷ�num��cpot��ָ��Ķ�̬�洢�ռ�
   free(cpot);
 }

 void main()
 {
   TSMatrix A,B;
   cout<<"��������A��";
   CreateSMatrix(A); // ��������A
   TraverseSMatrix(A); // �������A
   FastTransposeSMatrix(A,B); // B��A��ת�Ⱦ���
   cout<<"����B(A�Ŀ���ת��)��"<<endl;
   TraverseSMatrix(B); // �������B
 }