


void Print(int a[],int n){
	//���ÿ�ζ������������ı��
	time_t t=time(0);  //��ǰʱ��
	cout<<endl;
	cout<<"�ֶɿ�ʼ����->"<<endl;
	cout<<"���ι���ʱ�䣺"<<ctime(&t)<<endl;
	cout<<"���ζ�������������";
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout << endl;
} 

void auto_register(LinkQueue &q1,LinkQueue &q2){
	//�����ɿڽ��еǼ�
	int x;
	cout<<"���복���ţ��ٶ�С��100Ϊ�ͳ�������Ϊ������"<<endl;
	cout<<"����������������ÿո�ֿ���ֱ������-1Ϊֹ��"<<endl;
	while(1){
		cin>>x;
		if(x==-1) break;
		if(x<100) EnQueue_L(q1,x);
		else EnQueue_L(q2,x);
	} 
} 

void ferry_register(long &t1,int &mark,int &n){
	//���ֵ��ɿڽ��еǼ�
	if(mark==1){
		cout<<"�������ڶɿڵȴ��������ظ��Ǽǣ�"<<endl;
		return;
	} 
	mark=1;
	cout<<"�����ѵ��ɿڣ������ϴ���"<<endl;
	n=0;              //װ�س�����ʼΪ��
	t1=time(0);     //�ǼǶ��ֵ��ɿ�ʱ�� 
}

void auto_up_ferry(LinkQueue &q1,LinkQueue &q2,int a[10],int t1,int &mark,int &n){
	//�����϶���
	int i;
	long t2;
	if(QueueEmpty_L(q1)&&QueueEmpty_L(q2)){
		cout<<"��������������"<<endl;
		if(mark==1&&n!=0){
			t2=time(0)-t1;  //����ȴ�ʱ��
			cout<<"����δ�����г�"<<n<<"�����ѵȴ�"<<t2/60<<"��";
			cout<<t2%60<<"�룬�ȴ����������϶��֣�" <<endl;
			
		}
		return;
	} 
	if(mark!=1){
		cout<<"����δ�����������Ժ��϶��֣�"<<endl;
		exit(1);
	}
	do{
		i=n%5;
		while(!QueueEmpty_L(q1)&&n<10&&i<4){  //���������ͳ�
			DeQueue_L(q1,a[n++]);
			i++; 
		}
		//��10����������ӡ��Ʊ�ţ����¶�mark��n��0��ת���ܲ˵�
		if(n==10){Print(a,n);mark=0;n=0; return;} 
		if(i==4){if(!QueueEmpty_L(q2)) DeQueue_L(q2,a[n++]);}
		else {
			while(!QueueEmpty_L(q2)&& n<10&&i<5){
				DeQueue_L(q2,a[n++]);
				i++;
			}
		}
		if(n==10){Print(a,n);mark=0;n=0;return;}
	}while(!QueueEmpty_L(q1)||!QueueEmpty_L(q2));
	t2=time(0)-t1;   //�ǼǶ��ֵȴ�ʱ��
	cout<<"����δ�����г�"<<n<<"�����ѵȴ�"<<t2/60<<"��";
	cout<<t2%60<<"�룬�ȴ����������϶��֣�" <<endl; 
	return;
}

void ferry_set_sail(int a[10],int &mark,int &n){
	//�����������
	if(n==0||mark==0) cout<<"�������޳��������޶��֣�"<<endl;
	else {Print(a,n);mark=0;n=0;} 	
}

void OutputQueue(LinkQueue &q1,LinkQueue &q2){
	//��������Ŷӵȴ����
	cout<<"�ͳ��Ŷӵ������";
	QueuePtr p=q1.front;
	if(!p) cout<<"���޿ͳ��Ⱥ�"<<endl;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	} 
	cout <<endl;
	cout<<"�����Ŷӵ������";
	p=q2.front;
	if(!p) cout<<"���޻����Ⱥ�"<<endl;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	} 
	cout <<endl;
}

void end_run(LinkQueue &q1,LinkQueue &q2,int n){
	//������������ 
	if(!QueueEmpty_L(q1)||!QueueEmpty_L(q2)){
		cout<<"��������δ�ɽ�����ʱ���ܽ�����"<<endl;
		return;
	} 
	if(n!=0){
		cout<<"�������г������ܽ������У�"<<endl;
		return;
	}
	cout<<"����������У�"<<endl;
	exit(0);
} 

