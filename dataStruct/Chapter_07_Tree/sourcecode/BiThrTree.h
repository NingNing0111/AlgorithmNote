typedef struct BiThrNode {
 TElemType data;                                // ����ֵ  
   BiThrNode *lchild,*rchild;                     // ���Һ���ָ��
   unsigned short LTag:1;                         // ���־��ռ1 bit
   unsigned short RTag:1;                         // �ұ�־��ռ1 bit
 }BiThrNode, *BiThrTree;

void CreateBiThrTree(BiThrTree &BT)
 {    // ����������������н���ֵ����������������BT
   TElemType a;
   cin>>a;                                   // �������ֵ
   if(a==Nil)                                // ����ֵΪ��
     BT=NULL;
   else                                      // ����ֵ��Ϊ��
   { BT=(BiThrTree)malloc(sizeof(BiThrNode)); // ���ɸ����(����)
     if(!BT)
       exit(1);
     BT->data=a;                             // ��ֵ����T��ָ���
     CreateBiThrTree(BT->lchild);            // �ݹ鹹��������
     if(BT->lchild)                          // ������
       BT->LTag=0;                           // �����־��ֵ(ָ��)
else BT->LTag=1;                        // �����־��ֵ(����)
     CreateBiThrTree(BT->rchild);            // �ݹ鹹��������
     if(BT->rchild)                          // ���Һ���
       BT->RTag=0;                           // ���ұ�־��ֵ(ָ��)
else BT->RTag=1;                        // ���ұ�־��ֵ(����)
   }
 }// CreateBiThrTree

BiThrTree pre;       // ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
void InThreading(BiThrTree p)
{ // ����PΪ�����Ķ���������������������������֮��preָ�����һ�����
   if(p)                                   // ��������������
   { InThreading(p->lchild);               // �ݹ�������������
     if(!p->lchild)                       // û������
     { p->LTag=1;                         // ���־Ϊ����(ǰ��)
       p->lchild=pre;                     // ����ָ��ָ��ǰ��
     }
     if(!pre->rchild)                     // ǰ��û���Һ���
     { pre->RTag=1;                       // ǰ�����ұ�־Ϊ����(���)
       pre->rchild=p;                     // ǰ���Һ���ָ��ָ������(��ǰ���p)
     }
     pre=p;                               // ����preָ��p��ǰ��
     InThreading(p->rchild);              // �ݹ�������������
   }
 }// InThreading

void InThreading_head(BiThrTree &head,BiThrTree BT)
 { // ����BTΪ�����Ķ���������������������������һ��ͷ���head
   if(!(head=(BiThrTree)malloc(sizeof(BiThrNode))))  // ����ͷ��㲻�ɹ�
     exit(1);
   head->LTag=0;                                 // ��ͷ��㣬���־Ϊָ��
   head->RTag=1;                                 // �ұ�־Ϊ����
   head->rchild=head;                            // �Һ���ָ���ָ
   if(!BT)                                       // ��������T�գ�������ָ���ָ
     head->lchild=head;
   else // ������T�ǿ�
   { head->lchild=BT;                             // ͷ��������ָ��ָ������
     pre=head;                                     // pre(ǰ��)�ĳ�ֵָ��ͷ���
     InThreading(BT);                     // ����BTΪ���Ե�Ķ�������������������
// preָ��������������һ�����
     pre->rchild=head;                    // ���һ�������Һ���ָ��ָ��ͷ���
     pre->RTag=1;                         // ���һ�������ұ�־Ϊ����
     head->rchild=pre;                    // ͷ�����Һ���ָ��ָ�����һ�����
   }
 }// InThreading_head

BiThrTree FirstNode(BiThrTree head)
{  // �����������������в����������еĵ�һ�����
    BiThrTree p=head->lchild;
while(p->LTag==0)                // ��p��ָ���һֱ�ҵ�������������߽��
      p=p->lchild;                   // pָ��������
return p;
}// FirstNode

BiThrTree LastNode(BiThrTree head)
{    // �����������������в����������е����һ�����
return head->rchild;
}// LastNode

BiThrTree PreNode(BiThrTree p)
{   // �����������������в���p������ǰ��
BiThrTree pre;
pre=p->lchild;                         // ��p����ָ���򸳸�pre
if(p->LTag==0)                         // ���־Ϊ����
while(pre->RTag==0)                 // ��pre��ָ���һֱ�ҵ����ұ߽��
pre=pre->rchild;                 // preָ������Һ���
return pre;
}// PreNode

BiThrTree PostNode(BiThrTree p)
{   // �����������������в���p��������
BiThrTree post;
post=p->rchild;                        // ��p����ָ���򸳸�post
if(p->RTag==0)                         // �ұ�־Ϊ����
while(post->LTag==0)                // ��post��ָ���һֱ�ҵ�����߽��
post=post->lchild;                // preָ������Һ���
return post;
}// PostNode

void InOrderTraverse_Thr(BiThrTree head,void Visit(TElemType))
 { // �����������������head(ͷ���)
   BiThrTree p;
   p=FirstNode(head);                    // �����������еĵ�һ�����
   while(p!=head)                        // δ������
   {   Visit(p->data);                    // ����p��ָ���
    p=PostNode(p);                     // pָ����������
   }
}// InOrderTraverse_Thr

void InOrderTraverse_Thr_Reverse(BiThrTree head,void Visit(TElemType))
 {   // �������������������head(ͷ���)
   BiThrTree p;
   p=LastNode(head);                     // �����������е����һ�����
   while(p!=head)                        // δ������
   {   Visit(p->data);                    // ����p��ָ���
      p=PreNode(p);                     // pָ��������ǰ��
   }
}// InOrderTraverse_Thr_Reverse

void PrintBiThrTree(BiThrTree BT)
{    // �Թ�������ʽ���һ������������BT��BTΪ�������ĸ����
		cout<<BT->data;                      // ���������ֵ
		if(BT->LTag==0||BT->RTag==0)         // ���ӻ��Һ��Ӵ���
		{  cout<<'(';   
		   if(BT->LTag==0)                   // ����������
			  PrintBiThrTree(BT->lchild);    // �ݹ����������
		if(BT->RTag==0)                      // ����������
		{   cout<<',';
			PrintBiThrTree(BT->rchild);      // �ݹ����������
		}
		cout<<')';
		}
}// PrintBiThrTree

void DestroyBiTree(BiThrTree &BT)
 {  // ������BTΪ����������������
   if(BT)                                       // �ǿ���
   { if(BT->LTag==0)                            // ��������
       DestroyBiTree(BT->lchild);               // ����������
     if(BT->RTag==0)                            // ��������
       DestroyBiTree(BT->rchild);               // ����������
     free(BT);                                  // �ͷŸ����
     BT=NULL;                                   // BT�ÿ�
   }
 }// DestroyBiTree

void DestroyBiThrTree(BiThrTree &head)
 {    // ������ͷ���head������������
   if(head)                                  // ͷ������
   { if(head->lchild)                        // ��������
       DestroyBiTree(head->lchild);          // �ݹ�����ͷ���lchild��ָ������
     free(head);                             // �ͷ�ͷ���
     head=NULL;                              // head�ÿ�
   }
 }// DestroyBiThrTree
