#define QUENU_INIT_SIZE 100
#define QUENUINCREMENT 10
typedef struct {
	ElemType *queue;
	int front;
	int rear;
	int queuesize;
	int incrementsize;
}SqQueue;

//��ʼ������
void InitQueue_Sq(SqQueue &Q,int maxsize=QUENU_INIT_SIZE,int incresize=QUENUINCREMENT){
	Q.queue=(ElemType*)malloc(maxsize*sizeof(ElemType));
	if(!Q.queue) exit(01);
	Q.front=Q.rear=0;
	Q.queuesize=maxsize;
	Q.incrementsize=incresize; 
} 

//����еĳ���
int QueueLength_Sq(SqQueue Q){
	return (Q.rear-Q.front+Q.queuesize)%Q.queuesize;
} 

//���Ӳ���
bool EnQueue_Sq(SqQueue &Q,ElemType e){
	//�Ӷ�β����Ԫ�أ��ɹ��򷵻�true
	if((Q.rear+1)%Q.queuesize==Q.front) //������˳����������ռ�
	{
		Q.queue=(ElemType*)realloc(Q.queue,(Q.queuesize+Q.incrementsize)*sizeof(ElemType));
		if(!Q.queue) return false;
		if(Q.front>Q.rear)   //����ָ���ڶ�βָ����棬����ȷ��λ��
		{
			for(int i=Q.queuesize;i>=Q.front;i--){
				Q.queue[i+Q.incrementsize]=Q.queue[i];
			}		
			Q.front+=Q.incrementsize;
		} 
		Q.queuesize+=Q.incrementsize;
	} 
	Q.queue[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.queuesize;
	return true;
} 

//���Ӳ���
bool DeQueue_Sq(SqQueue &Q,ElemType &e){
	if(Q.front==Q.rear) return false;
	e=Q.queue[Q.front];
	Q.front=(Q.front+1)%Q.queuesize;
	return true;
} 

//ȡ����Ԫ�ز���
bool GetHead_Sq(SqQueue Q,ElemType &e){
	if(Q.front==Q.rear)  return false;
	e=Q.queue[Q.front];
	return true;
} 

bool QueueEmpty_Sq(SqQueue Q){
	return Q.front==Q.rear;
}

//����ѭ�����в���
void DestroyQueue_Sq(SqQueue &Q){
	free(Q.queue);
	Q.queuesize=0;
	Q.front=Q.rear=0;
} 
void visualization(SqQueue L, char* filename)
{   int temp;
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\nnode [shape = box];\n");  
	for(int i=0;i<L.queuesize;i++)
	if(DeQueue_Sq(L,temp))
    {
	    fprintf(stream, "box%d [label = \"%d\"];\n",i,temp);
	    if(i>0&&i<L.queuesize-1)
	    {
    		fprintf(stream, "box%d -> box%d;\n",i,i-1);	
    	}
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng showsqlist.dot -o showsqlist.png");
	system("showsqlist.png");
}
