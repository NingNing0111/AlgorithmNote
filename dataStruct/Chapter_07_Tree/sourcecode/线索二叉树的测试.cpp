typedef char TElemType;       // ��������Ԫ������TElemTypeΪ�ַ���
TElemType Nil='#';            // ��'#'��ʾ��
# include "stdlib.h"          // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"         // ���ļ��������Ʒ�setw()
# define MAX_BITREE_SIZE 100  // �������е��������
# include "BiThrTree.h"       // ���ļ������������������ݶ������������ز���
	
void Visit(TElemType e)       // ���ʺ�������Ϊ�������
 {
   cout<<e<<' ';
 }

void main()
 {
   int i;
   BiThrTree head,BT,p,c;
   cout<<"�밴�������������(��'#'��ʾ����Ϊ��)��"<<endl;
   CreateBiThrTree(BT);                    // ����������BT
   InThreading_head(head,BT);              // ����������������BT,headָ��ͷ���
   cout<<"�����������������������";
   InOrderTraverse_Thr(head,Visit);         // ���������������������
   cout<<endl<<"�������������������������";
   InOrderTraverse_Thr_Reverse(head,Visit); // �����������������������
   cout<<endl<<"�Թ�������ʽ�������������������";
  if(head->lchild!=head)                     // �����������ǿ�
    PrintBiThrTree(head->lchild);            // �Թ�������ʽ�����������������
   DestroyBiThrTree(head);                   // ������������������
  }	
