typedef struct CTNode {
TElemType data;                     // ����ֵ
  struct CTNode *child[MAX_SON_SIZE]; // ����ָ����,ָ���ӽ��
}CTNode,*CTree;                       // ��������

# define MS 10                        // ջ�ռ�Ĵ�С

void InitTree(CTree &T)
{ 
	T=NULL;
}// InitTree

void CreateTree(CTree &T,char *S)
{ // ���ݹ�����ַ���S��������MAX_SON_SIZE����������Ӧ�Ĵ洢�ṹ,Tָ������
    CTree stack[MS],p;        // stack������Ϊ�洢���н��ָ���ջʹ�� 
	int i=0,d[MS];            // d������Ϊ�洢���ӽ�����ӵ�˫�׽��
	int top=-1;               // top��Ϊ����ջ��ջ��ָ��
	T=NULL;                   // ������ָ���ÿ�
	while(S[i])
	{ switch(S[i])
	  { case ' ':break;         // �Կո����κδ���
		case '(': top++;stack[top]=p; d[top]=0;break;
			                    // Pָ���stackջ��O��dջ��������ɨ��ĺ��ӽ��
                                  // �����ӵ�stackջ��Ԫ����ָ���ĵ�һ��ָ����
		case ')': top--;break;     // stack��d��ջ
		case ',':d[top]++;         // ������ĺ��ӽ�㽫���ӵ�stackջ��Ԫ��
                                   // ��ָ������һ��ָ����
			    break;
		default:
			if(!(p=(CTree)malloc(sizeof(CTNode)))) // �������
            exit(1);
			p->data=S[i];
			for(int i=0;i<MAX_SON_SIZE;i++)
			 p->child[i]=NULL; // ʹp����Ϊ�����������ӵ�˫�׽���Ӧ��ָ����
			if(!T) T=p;
			else stack[top]->child[d[top]]=p;
		}
		i++;                       // ׼��������һ���ַ�
	}
}// CreateTree

void PreOrderTree(CTree T,void Visit(TElemType))
{  // ���������Tָ����ָ�����
	if(T) {
		Visit(T->data);                         // ���ʸ����
		for(int i=0;i<MAX_SON_SIZE;i++)
			  PreOrderTree(T->child[i],Visit);  // �ݹ����ÿһ������
	}	
}// PreOrderTree

void PostOrderTree(CTree T,void Visit(TElemType))
{  // ���������Tָ����ָ�����
	if(T) 
	 {     for(int i=0;i<MAX_SON_SIZE;i++)
			  PostOrderTree(T->child[i],Visit);  // �ݹ����ÿһ������
			Visit(T->data);   // ���ʸ����
	}
}// PostOrderTree

typedef CTree ElemType;            // ���������Ԫ������ElemTypeΪCTree
# include "SqQueue.h"               //����ѭ���������ݶ������������ز���
void LevelOrderTree(CTree T,void Visit(TElemType))
{     // ���������Tָ����ָ�����
	SqQueue Q;                           // ����һ������Q����Ԫ������ΪCTree 
	CTree p;
    InitQueue_Sq(Q,MAX_TREE_SIZE,10);         // ��ʼ��ѭ������
	if(T) EnQueue_Sq(Q,T);                    // �ǿյĸ�ָ�����
	while(!QueueEmpty_Sq(Q))                  // �����зǿ�ʱִ��ѭ��
	{	DeQueue_Sq(Q,p);                      // �Ӷ�����ɾ��һ�����ָ��
	    Visit(p->data);                       // �������ֵ
		for(int i=0;i<MAX_SON_SIZE;i++)       // �ǿյĺ��ӽ��ָ�����ν���
			if(p->child[i])
		     EnQueue_Sq(Q,p->child[i]);
	}
}// LevelOrderTree

bool SearchTree(CTree T,TElemType &e)
{    // ����Tָ����ָ������в���Ԫ��e�����ҳɹ�������true�����򷵻�false
	if(!T) return false;                   // ���շ���false
	else {
		if(T->data==e) {
			e=T->data;return true;          // ���ؽ��ֵ������true
		}
		for(int i=0;i<MAX_SON_SIZE;i++)     // ��ÿ��������������
			if(SearchTree(T->child[i],e)) return true;
			return false;                   // ���Ҳ��ɹ�����false
	}
}// SearchTree   

void PrintTree(CTree T)
{  // �Թ������ʽ�������������洢����
	int i;
	if(T) {
		cout<<T->data<<' ';                      // ���������ֵ
		for(i=0;i<MAX_SON_SIZE;i++)              // ��T����Ƿ�������
			if(T->child[i]) break;
			if(i<MAX_SON_SIZE)                  // ������ʱ���µݹ�
			{	cout<<'(';                       // ������������
				PrintTree(T->child[0]);          // �����һ������
	        for(i=1;i<MAX_SON_SIZE;i++)          // ��������������
			{	if(T->child[i]) cout<<',';
				PrintTree(T->child[i]);
			}
			cout<<')';                          // ���������������
		}
	}
}// PrintTree

int TreeDepth(CTree T)
{  // ����ָ��T��ָ����������
	if(!T) return 0;                    // ���������Ϊ0
	else {
		int max=0;                      // �������������е�������,��ֵΪ0
		for(int i=0;i<MAX_SON_SIZE;i++) // �����һ����������Ȳ���������k
		{	int k=TreeDepth(T->child[i]);
			if(k>max) max=k;              // �ѵ�ǰ�������ߵ�ֵ���� max
		}
		return max+1;                    // ����������ȣ������������������ȼ�1
	}
}// TreeDepth

void DestroyTree(CTree &T)
{
	if(T){
		for(int i=0;i<MAX_SON_SIZE;i++)       // ������������������
			DestroyTree(T->child[i]);
		free(T);                              // ���������
		T=NULL;                               // T�ÿ�
	}
}// DestroyTree

