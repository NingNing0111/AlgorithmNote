typedef char ElemType;         // ��������Ԫ������ElemTypeΪ�ַ���
# include "stdlib.h"           // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iostream.h"         // ���ļ�������׼���������cout��cin
# include "DSqString.h"        // ���ļ�����DSqString���͵Ļ�������
# include "GList.h"            // ���ļ��а�����������ݶ������������ز���

void main()
 {
   char p[80];
   DSqString t,hsub;
   GList n,m;
   InitGList(n);                        // ��ʼ�������n��nΪ�ձ�
   cout<<"�չ����n�����="<<GListDepth(n)<<"��n�Ƿ�գ�";
cout<<GListEmpty(n)<<"(1:�� 0:��)"<<endl;
   cout<<"����������n(��д��ʽ���ձ�()����ԭ�ӣ�(a)��������(a,(b),c))��"<<endl;
   cin>>p;                                // �����������n���ַ�������p
   StrAssign_Sq(t,p);                     // ��pת��ΪDSqString���͵�t
   StrAssign_Sq(hsub,"");
   CreateGList(n,t);                      // ����t���������n
   cout<<"�����n�ĳ���="<<GListLength(n);
   cout<<"�����="<<GListDepth(n)<<"��n�Ƿ�գ�"<<GListEmpty(n);
cout<<"(1:�� 0:��)"<<endl;
   cout<<"���������n��";
   Traverse_GL(n);                          // ���������n
   CopyGList(m,n);                          // ���ƹ����m=n
   cout<<endl<<"���ƹ����m=n��m�ĳ���="<<GListLength(m);
   cout<<"��m�����="<<GListDepth(m)<<endl;
   cout<<"���������m��";
   Traverse_GL(m);                          // ���������m
   DestroyGList(m);                         // ���������m���ͷŴ洢�ռ�
   m=GetHead(n);                            // ���ɹ����n�ı�ͷԪ�أ�����mָ��
   cout<<endl<<"m��n�ı�ͷԪ�أ�����m��";
   Traverse_GL(m);                          // ���������m
   DestroyGList(m);                         // ���������m���ͷŴ洢�ռ�
   m=GetTail(n);                   // �������n�ı�β����Ϊ���������mָ��
   cout<<endl<<"m����n�ı�β�γɵĹ�������������m��";
   Traverse_GL(m);                          // ���������m
   InsertFirst_GL(m,n);  // �������n�嵽�����m�У�����Ϊm�ĵ�1��Ԫ��(��ͷ)
   cout<<endl;
   cout<<"��������nΪm�ı�ͷ�����������m��";
   Traverse_GL(m);                           // ���������m
   DeleteFirst_GL(m,n);                // ɾ�������m�ı�ͷ������nָ��ɾ���ı�ͷ
   cout<<endl<<"ɾ��m�ı�ͷ������nָ��m�ı�ͷ�����������m��";
   Traverse_GL(m);                        // ���������m
   cout<<endl<<"���������n(�����m��ԭ��ͷ)��";
   Traverse_GL(n);                          // ���������n
   cout<<endl;
   DestroyGList(m);                         // ���������m��n�����ͷŴ洢�ռ�
   DestroyGList(n);  
 }
