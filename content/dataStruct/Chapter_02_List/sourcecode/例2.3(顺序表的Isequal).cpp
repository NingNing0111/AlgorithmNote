typedef int ElemType;    // ˳�����Ԫ������Ϊint
# include "stdlib.h"     // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"    // ���ļ�������׼���������cout��cin�����Ʒ�setw()�Ⱥ��� 
# include "SqList.h"     // ���ļ��а����������ݶ������������ز���
	
void CreateList_Sq(SqList &L, int a[])
{ int i=0;
  if(L.length==0)
  for(int i=0;i<=sizeof(a);i++)
      ListInsert_Sq(L,i,a[i]);
}


bool Isequal(SqList La, SqList Lb, ElemType &e)
{  bool found; 
   int i,k;
   SqList Lc;
   int La_len = ListLength_Sq(La);    //��� 
   int Lb_len = ListLength_Sq(Lb);    //���
   if(La_len != Lb_len)  return false;
   else
   {    
        InitList_Sq(Lc);           //��ʼ��Lc
        for(k=0;k<=La_len;k++)     //����La�ĸ���ƷLc
        {
            GetElem_Sq(La,k,e);
            ListInsert_Sq(Lc,k,e);
        }
    found = true;
    for(k=0;k<=Lb_len, found; k++)
    {
        GetElem_Sq(Lb,k,e);        //ȡLb�е�k������Ԫ��
        i = LocateElem_Sq(Lc,e);   //��Lc�н��в�ѯ
        if(i==0) found = false;    //La�в����ں͸�����Ԫ����ͬ��Ԫ��
        else ListDelete_Sq(Lc,i,e); //��Lc��ɾ��������Ԫ��
    }
    if(found && ListEmpty_Sq(Lc))   return true;
    else return false;
    DestroyList_Sq(Lc);
   }
}



int main()
{    SqList La,Lb;
     int i,j,temp;
     ElemType a[]={1,2,3,4,5};
     ElemType b[]={3,1,2,4,5};
     
     InitList_Sq(La);
     InitList_Sq(Lb);
     CreateList_Sq(La,a);
     CreateList_Sq(Lb,b);
     ListTraverse_Sq(La);
     ListTraverse_Sq(Lb);
     
    if(Isequal(La, Lb, temp)==true)
     cout<<"���"<<endl;
    else
     cout<<"�����"<<endl;
     
     
}