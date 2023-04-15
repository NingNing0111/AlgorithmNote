typedef int ElemType;    // ˳�����Ԫ������Ϊint
# include "stdio.h"  
# include "stdlib.h"     // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"    // ���ļ�������׼���������cout��cin�����Ʒ�setw()�Ⱥ��� 
# include "SqList.h"     // ���ļ��а����������ݶ������������ز���
	
void CreateList_Sq(SqList &L, int a[])
{ int i=0;
  if(L.length==0)
  for(int i=0;i<=sizeof(a);i++)
      ListInsert_Sq(L,i,a[i]);
}

	
void Purge(SqList &La,SqList Lb, ElemType &e)
{
    InitList_Sq(La);          //��ʼ��La,������һ���µģ��յ����Ա�La,����ŵ�����д
    while(!ListEmpty_Sq(Lb))     //Lb���Ԫ����δ��δ������
    {
        ListDelete_Sq(Lb,0,e);    //��Lb��ɾ����һ������Ԫ�ظ�ֵ��e
        if(LocateElem_Sq(La,e)==-1)     //��La�в�����ֵ��e��ȵ�����Ԫ��
           ListInsert_Sq(La,La.length,e);   //����������La�����һ������Ԫ��֮��
    }
    DestroyList_Sq(Lb); //�������Ա�
}



int main()
{	
	int temp;
	SqList Lb;
	InitList_Sq(Lb, 30, 5);
	int a[5] = {3,2,2,1,4};
	CreateList_Sq(Lb,a);
    ListTraverse_Sq(Lb);
    
    SqList La;
    InitList_Sq(La, 30, 5);
    Purge(La, Lb, temp);
    ListTraverse_Sq(La);
    
    return 0; 
 }	