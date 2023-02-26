
# include "stdio.h"
# include "stdlib.h"
# include "malloc.h"
# define LEN sizeof(SLNode)
typedef  int DataType;
 typedef struct SLNode
    {
     DataType data;
     struct SLNode *next;
     }SLNode,*NK;
/* ͨ������ */
void MergeList_L(NK La, NK Lb, NK &Lc) 
{
 // �鲢������ͷ���ǵݼ�����ĵ�����La��lb��Ϊһ����ͷ���ǵݼ�����ĵ�����Lc
   NK pa,pb,pc;   
   Lc=(SLNode *)malloc(LEN);           // ����һ���յĵ�����Lc
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
}
 

void creat(NK &head)
{ SLNode *p,*q;
  DataType a;
  head=(SLNode *)malloc(LEN);
  q=p=head;
  scanf("%d",&a);
  while(a!=0)
  {
   p=(SLNode *)malloc(LEN);
   p->data=a;
   q->next=p;
   q=p;
    scanf("%d",&a);
   }
   q->next=NULL;
 }

 void print(SLNode *head)
  {
	 head=head->next;
    while(head!=NULL)
    {
      printf("%4d",head->data);
      head=head->next;
    }
  }
void main()
 { SLNode *ha,*hb,*hc;
  creat(ha);
  print(ha); printf("\n");
  creat(hb);
  print(hb); printf("\n");
 MergeList_L(ha,hb,hc) ;
   print(hc); printf("\n");
  getchar();
  getchar();
  }