typedef int ElemType;
typedef struct DuNode  {
 ElemType data;
struct  DuNode *prior;
struct  DuNode *next;
}DuLNode,*DuLinkList;

void InitList_DuL(DuLinkList &L)
{  
L=(DuLNode *)malloc(sizeof(DuLNode));  // ������һ�������������Ҫ�����ڿռ�
if(!L)   exit(1);                        // �洢����ʧ��
L->next=NULL;                            // ��ͷ���ĺ��ָ�����ÿ�
L->prior=NULL;                           // ��ͷ����ǰ��ָ�����ÿ�
}

int ListLength_Dul(DuLinkList L ) 
{     
  		DuLinkList  p;
		int k=0;
		p=L->next;                           
 		 while(p)             //��p��ָ��Ľ�㻹��ֵ
  		 { k++;  p=p->next; }            
         return k;
}// ListLength_Dul


bool ListInsert_DuL(DuLinkList &L,int i,ElemType e) 
    {
       // �ڴ�ͷ����˫������L�е�i�����֮ǰ����Ԫ��e
  DuLinkList p,s,q;
   int j;
   q=L;  j=0;
   while(q->next&&j<i-1)  { q=q->next; j++; }   // Ѱ�ҵ�i-1�����,����qָ��˽��
   if(j!=i-1)   return false;                   // i��λ�ò�����
   s=(DuLNode *)malloc(sizeof(DuLNode));
   if(!s)   exit(1);                            // �洢����ʧ��
   s->data=e;  
   if(q->next)                                   // �����λ�ò��Ǳ�β
   { 
	p=q->next;                                  // pָ��������λ��
	s->prior=p->prior;                          // �޸�ָ��
    p->prior->next=s;      
    s->next=p;
    p->prior=s; 
   }
   else                                     // �����λ���Ǳ�β
   { 
     q->next=s;
	 s->prior=q;
	 s->next=NULL;
   }
return true;
}

bool ListDelete_DuL(DuLinkList &L, int i, ElemType &e)
{
           // ɾ������ͷ����˫������L�еĵ�i����㣬����e������ֵ
DuLinkList p;
  int j;
  p=L;  j=0;
 while(p->next&&j<i){ p=p->next; j++; }      // Ѱ�ҵ�i�����,����pָ��˽��
   if(j!=i)   return false;                 // i��λ�ò�����
   if(p->next)                              // ��ɾ���Ĳ��Ǳ�β���
     p->next->prior=p->prior;               // ���p��ǰ����Ϊ���p�ĺ�̵�ǰ��
     p->prior->next=p->next;                // ���p�ĺ����Ϊ���p��ǰ���ĺ��                              
     e=p->data;                     
     free(p);                                    
  return true;
 }
