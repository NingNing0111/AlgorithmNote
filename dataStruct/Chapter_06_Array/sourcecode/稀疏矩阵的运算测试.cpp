typedef int ElemType;         // �������Ԫ������ElemTypeΪ����
# include "stdlib.h"           // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"          // ���ļ�������׼���������cout��cin�����Ʒ�setw()


# include "TSMatrix.h"        // ���ļ�������Ԫ��˳������ݶ������������ز���

 void main()
 {
   TSMatrix A,B,C;
   cout<<"��������A��";
   CreateSMatrix(A);                    // ��������A
   TraverseSMatrix(A);                   // �������A
   CopySMatrix(A,B);                     // �ɾ���A���ƾ���B   
   cout<<"�ɾ���A���ƾ���B1��"<<endl;
   TraverseSMatrix(B);                    // �������B
   DestroySMatrix(B);                     // ��������B
   cout<<"��������B2��(�����A���С�������ͬ���С��зֱ�Ϊ";
cout<<A.m<<","<<A.n<<")"<<endl;
   CreateSMatrix(B);                      // ��������B
   TraverseSMatrix(B);                    // �������B
   AddSMatrix(A,B,C);                      // ������ӣ�C=A+B
   cout<<"����C1(A+B)��"<<endl;
   TraverseSMatrix(C);                     // �������C
   SubtSMatrix(A,B,C);                     // ���������C=A-B
   cout<<"����C2(A-B)��"<<endl;
   TraverseSMatrix(C);                    // �������C
   TransposeSMatrix(A,C);                 // ����C�Ǿ���A��ת�þ���
   cout<<"����C3(A��ת��)��"<<endl;
   TraverseSMatrix(C);                    // �������C
   cout<<"��������A2��";
   CreateSMatrix(A);                      // ��������A
   TraverseSMatrix(A);                    // �������A
   cout<<"��������B3��(����Ӧ�����A2��������ͬ="<<A.n<<")"<<endl;
   CreateSMatrix(B);                      // ��������B
   TraverseSMatrix(B);                     // �������B
   MultSMatrix(A,B,C);                     // ������ˣ�C=A��B
   cout<<"����C4(A��B)��"<<endl;
   TraverseSMatrix(C);                     // �������C
 }
