typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*QueuePtr;
 
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;           //����

//��ʼ������
void InitQueue_L(LinkQueue &Q){
	Q.front=NULL;
	Q.rear=NULL;
} 

//�����ӵĳ���
int QueueLength_L(LinkQueue Q){
	QueuePtr p=Q.front;
	int k=0;
	while(p){
		k++;
		p=p->next;
	}	
	return k;
} 

//���Ӳ���
bool EnQueue_L(LinkQueue &Q,ElemType e){
	QueuePtr s;
	if((s=(LNode*)malloc(sizeof(LNode)))==NULL) return false;
	s->data=e;
	s->next=NULL;
	if(Q.rear==NULL) {
		Q.front=Q.rear=s;
	}else{
		Q.rear=Q.rear->next=s;
	}
	return true;
} 

//���Ӳ���
bool DeQueue_L(LinkQueue &Q,ElemType &e){
	QueuePtr p;

	if(Q.front==NULL) return false;
	p=Q.front;
	e=p->data;
	Q.front=p->next;
	if(Q.front==NULL)  Q.rear=NULL;
	free(p);
	return true;
} 

//ȡ����Ԫ�ز���
bool GetHead_L(LinkQueue &Q,ElemType &e){
	if(Q.front==NULL) return false;
	e=Q.front->data;
	return true;
} 
//�ж϶ӿղ���

bool QueueEmpty_L(LinkQueue &Q){
	if(!Q.front){
		return true;
	}else{
		return false;
	}
} 

//�������Ӳ���
void DestroyQueue_L(LinkQueue &Q){
	QueuePtr p,p1;
	p=Q.front;
	while(p){
		p1=p;
		p=p->next;
		free(p1);
	}
	Q.front=Q.rear=NULL; 
} 
void visualization(LinkQueue L, char* filename)//��ʽ�ṹ����ָ�룬������ֵ���� 
{   int temp,queueLength;
	queueLength=QueueLength_L(L);
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\nnode [shape = box];\n");  
	for(int i=0;i<queueLength;i++)
	if(DeQueue_L(L,temp))
    {
	    fprintf(stream, "box%d [label = \"%d\"];\n",i,temp);
	    if(i>0&&i<queueLength)
	    {
    		fprintf(stream, "box%d -> box%d;\n",i,i-1);	
    	}
    	EnQueue_L(L,temp);//������� ����ʽ�ṹ����ָ�룬������ֵ����  
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng showsqlist.dot -o showsqlist.png");
	system("showsqlist.png");
}
