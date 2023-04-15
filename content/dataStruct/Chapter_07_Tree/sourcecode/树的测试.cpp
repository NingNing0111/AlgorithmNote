typedef char TElemType;      // ��������Ԫ������TElemTypeΪ�ַ���
 # include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
 # include "iostream.h"     // ���ļ�������׼���������cout��cin
 # define MAX_TREE_SIZE  100         // ���н���������
 # define MAX_SON_SIZE  3            // ���Ķ�
 # include "CTree.h"                 // ���ļ����������ݶ������������ز���
 	
 void Visit(TElemType e)             // ���ʺ�������Ϊ�������
 {
   cout<<e<<' ';
 }

void main()
{
	CTree T;
	InitTree(T);                 
	char str[50];                          // ����ù�����ַ���ʾ����
	cout<<"����һ��"<<MAX_SON_SIZE<<"�����Ĺ�����ַ�����";
	cin>>str;
	CreateTree(T,str);                    // ������
	cout<<"������������"; 
	PreOrderTree(T,Visit); 
	cout<<endl<<"������������";
	PostOrderTree(T,Visit);
	cout<<endl<<"������������";
	LevelOrderTree(T,Visit); 
	cout<<endl<<"���������ʽ�����"<<MAX_SON_SIZE<<"����Ϊ��";
	PrintTree(T);
	cout<<endl;
	cout<<"������ȣ�"<<TreeDepth(T)<<endl;
	cout<<"��������ҵ�һ���ַ���";
	char ch;
	cin>>ch;
	if(SearchTree(T,ch))  cout<<"���ҳɹ���"<<endl;
	else cout<<"����ʧ�ܣ�"<<endl;
	DestroyTree(T);
}
