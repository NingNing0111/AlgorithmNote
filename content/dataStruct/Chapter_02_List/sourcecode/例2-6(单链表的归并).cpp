typedef int ElemType;      // ��������Ԫ������Ϊint
# include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "LinkList.h"     // ���ļ��а������������ݶ������������ز���

void MergeList_L(LinkList La, LinkList Lb, LinkList &Lc) 
{     // �鲢������ͷ���ǵݼ�����ĵ�����La��lb
// ��Ϊһ����ͷ���ǵݼ�����ĵ�����Lc
       LinkList pa,pb,pc;   
       Lc=(LNode *)malloc(sizeof(LNode));      // ����һ���յĵ�����Lc
       pa=La->next; pb=Lb->next;               // pa��pb�ֱ�ָ��La��Lb�Ŀ�ʼ���
       pc=Lc;                                  // pcָ��Lc��ͷ���
 while(pa&&pb)                           // La��Lb���ǿ�
 if(pa->data<=pb->data)                  // �����е�ǰԪ�رȽ�
{ pc->next=pa;pa=pa->next;pc=pc->next; }  // pa��ָ�����뵽Lc��
else 
{ pc->next=pb;pb=pb->next;pc=pc->next; }  // pb��ָ�����뵽Lc��
if(pa) pc->next=pa;                         // ����La�е�ʣ����
if(pb) pc->next=pb;                         // ����Lb�е�ʣ����
free(La);   free(Lb);                       // �ͷ�La��lb��ͷ���
}// MergeList_L

void main()
 { 
      LNode *ha,*hb,*hc;
      ElemType a[]={2,6,9,13,45};
      ElemType b[]={1,6,19,25,45,60};
      CreateList_L_Rear(ha,a,5);               // ����������ha
      cout<<"������ha��";
      ListTraverse_L(ha);                      // ��ʾ������ha
      CreateList_L_Rear(hb,b,6);               // ����������hb
      cout<<"������hb��";
      ListTraverse_L(hb);                       // ��ʾ������hb
      MergeList_L(ha,hb,hc);                    // �鲢ha��hbΪhc
      cout<<"�鲢��ĵ�����hc��";
      ListTraverse_L(hc);                       // ��ʾ������hc
 }
