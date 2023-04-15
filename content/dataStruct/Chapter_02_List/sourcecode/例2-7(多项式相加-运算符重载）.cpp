# include "stdlib.h"         // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"        // ���ļ�������׼���������cout��cin�Լ�setw()��
typedef struct                          // ����ʽ������ΪLinkList�����ݶ���
{ float coef;                           // ϵ��
  int exp;                              // ָ��
}ElemType;   
bool operator==(const ElemType &e1,const ElemType &e2) // ���������"=="
{
	 return e1.exp==e2.exp;
}

bool operator!=(const ElemType &e1,const ElemType &e2)  // ���ص��������
{
	 return e1.exp!=e2.exp;
} 

bool operator>(const ElemType &e1,const ElemType &e2)  // ����С�������
{
	 return e1.exp>e2.exp;
}

ostream& operator<<(ostream& ostr,const ElemType &x)   
    // ���ز����������ostream��C++��ͨ���������
{
	 ostr<<x.coef<<' '<<x.exp<<' ';
     return ostr;
}

# include "LinkList.h"

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
{       // ��ab��bhΪͷָ��ĵ�����ֱ��ʾ����ʽA(x)��B(x)
// ��chΪͷָ��ĵ������ʾA(x)��B(x)�͵Ķ���ʽC(x) 
LinkList pa, pb, pc;
      float x;
      pa=ah->next; pb=bh->next;              // pa��pb�ֱ�ָ������ʼ���
      ch=(LNode *)malloc(sizeof(LNode));      // ����ͷ���
      pc=ch;
      while(pa&&pb)                            // pa��pb�ǿ�
      { 
if(pa->data>pb->data)              // ���pa��ָ�����ڽ��pb��ָ��
{  attach(pa->data.coef, pa->data.exp,pc);  // ���pa���Ƶ�ch��
             pa=pa->next; 
}
else if(pa->data==pb->data)     // ���pa��ָ�����ڽ��pb��ָ��
 { x=pa->data.coef+pb->data.coef;
                if(x!=0)                   // ָ���Ͳ�Ϊ0
  attach(x,pa->data.exp,pc);  // ��ָ���Ͳ����½�㣬���뵽ch��
                pa=pa->next;
                pb=pb->next;
               }
            else  
			{ attach(pb->data.coef, pb->data.exp,pc); // ���pa��ָ��С�ڽ��pb��ָ��
              pb=pb->next;                             // ���pb���Ƶ�ch��
            }
        }
       while(pb)                                    // pb�ǿ�
       { attach(pb->data.coef, pb->data.exp,pc);   // ��bh��ʣ���㸴�Ƶ�ch��ȥ
         pb=pb->next;
        }
       while(pa)                                    // pa�ǿ�
        { attach(pa->data.coef,pa->data.exp,pc);     // ��ah��ʣ���㸴�Ƶ�ch��ȥ
          pa=pa->next;
}
pc->next=NULL;      // ��ch�������һ������ָ����Ϊ�� 
}// polyadd


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