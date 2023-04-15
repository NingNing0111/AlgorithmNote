# include "LinkList.h"
typedef LinkList LinkStack;             // ��ջ�Ľ��ṹ�͵�������ͬ
void InitStack_L(LinkStack &S)
 {  
   S=NULL;  
  }// InitStack_L

int StackLength_L(LinkStack S)
{
  int k=0;
  LinkStack p=S;
	while(p)
    { k++;
      p=p->next;                            // ������һ����㡣
    }
   return k;
}// StackLength_L

bool Push_L( LinkStack &S, ElemType e) 
{      //����ջ��ջ������Ԫ��e
      LinkStack p;
      if((p=(LNode *)malloc(sizeof(LNode)))==NULL) return false;  // �洢����ʧ��
      p->data=e;  
      p->next=S;                      // �����µ�ջ��Ԫ��
      S=p;                            // �޸�ջ��ָ��
      return true;
     }// Push_L

bool Pop_L( LinkStack &S, ElemType &e) 
{     // ɾ����ջջ��Ԫ�أ�����e������ֵ
LinkStack p;
   if(S)                          // ջ�ǿ�
	  { p=S;S=S->next;            // �޸�ջ��ָ��
	    e=p->data;                // Ԫ��e������ֵ
	    free(p);                  // �ͷŽ��ռ�
	    return true; 
   }
   else return false;            // ջ�գ���ջʧ��
 }// Pop_L

bool GetTop_L(LinkStack S,ElemType &e)
{    
  if(S)                    // ջ�ǿ�
	  { e=S->data;           // Ԫ��e������ֵ
	    return true;  
 }
   else return false;      // ջ�գ�ȡջ��Ԫ��ʧ��
 }// GetTop_L
 
bool StackEmpty_L(LinkStack S)
{
 if(!S) return true;
 else return false;
}// StackEmpty_L

void DestroyStack_L(LinkStack &S )
{
  LinkStack p,p1;
  p=S;
  while(p) 
  { p1=p;
    p=p->next;
    free(p1);                                // �ͷ�p1��ָ�Ŀռ�
   }
   S=NULL;                                    // S�ÿ�
 }// DestroyStack_L
