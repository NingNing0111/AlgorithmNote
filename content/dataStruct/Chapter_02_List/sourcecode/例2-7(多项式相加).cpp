# include "stdlib.h"
# include "iostream.h"
# include "iomanip.h"
typedef struct                          // ����ʽ������ΪLinkList�����ݶ���
{ float coef;                           // ϵ��
  int exp;                              // ָ��
}ElemType;   
# include "LinkList(����ʽ���).h"

void attach (float c, int e, LinkList &pc)
{
// ����ϵ��Ϊc��ָ��Ϊe���½�㣬����������pc��ָ���ĺ���
// ���Ӻ�pcָ��������Ľ�� 
 LinkList p;
  p=(LNode *)malloc(sizeof(LNode));
  p->data.coef=c;
  p->data.exp=e;
  pc->next=p;
  pc=p;
}
void polyadd( LinkList ah, LinkList bh, LinkList &ch)
{
// ��ab��bhΪͷָ��ĵ�����ֱ��ʾ����ʽA(x)��B(x),��chΪͷָ��ĵ�����
//��ʾA(x)��B(x)�͵Ķ���ʽC(x)��Ϊ���ڼ��㣬���㷨���ƻ�A(x)��B(x)��C(x)��ٿռ� 
 LinkList pa, pb, pc;
  float x;
  pa=ah->next; pb=bh->next;
  ch=(LNode *)malloc(sizeof(LNode));
  pc=ch;
  while (pa&&pb)
  { 
if (pa->data.exp>pb->data.exp) {attach (pa->data.coef, pa->data.exp,pc);
                               pa=pa->next; }
else if(pa->data.exp==pb->data.exp) { x=pa->data.coef+pb->data.coef;
                            if(x!=0) attach(x,pa->data.exp,pc); 
                            pa=pa->next;
                            pb=pb->next;
                          }
       else  { attach (pb->data.coef, pb->data.exp,pc);
               pb=pb->next;
             }
  }
   while(pb)
   { attach(pb->data.coef, pb->data.exp,pc);
     pb=pb->next;
   }
 while(pa)
    { attach(pa->data.coef,pa->data.exp,pc);
      pa=pa->next;
}
pc->next=NULL;      // ��ch�������һ������ָ����Ϊ�� 
}

void main()
{
  LinkList A,B,C;
  ElemType a[]={{3,14},{2,8},{1,0}};
  ElemType b[]={{8,14},{-3,10},{10,6}};
  CreateList_L_Rear(A,a,3);
  cout<<"����ʽA��";
  ListTraverse_L(A);
  CreateList_L_Rear(B,b,3);
  cout<<"����ʽB��";
  ListTraverse_L(B);
  polyadd(A,B,C);
  cout<<"����ʽ��ӵĽ��C��";
  ListTraverse_L(C);
}
