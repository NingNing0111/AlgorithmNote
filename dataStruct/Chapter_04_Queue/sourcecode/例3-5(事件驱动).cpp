
typedef int ElemType;       // ����Ԫ������Ϊint
# include "stdlib.h"        // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"       // ���ļ�������׼���������cout��cin�Լ�setw()��
# include "time.h"          // ��ͷ�ļ��а�����time����ctime����������
# include "LinkQueue.h"     // ���ļ������������ݶ������������ز���

void Print(int a[],int n)
{        // ���ÿ�ζ������������ı��
long t=time(0);        // ��ǰ����ϵͳʱ�䱻������t�У���λΪ��
cout<<endl;
cout<<"�ֶɿ�ʼ��->"<<endl;
cout<<"���ι���ʱ�䣺"<<ctime(&t)<<endl;
	     // ctime(&t)������ֵΪ���ݲ���tת���õ������ں�ʱ����ַ���
cout<<"�����ֶ�����������";
for(int i=0;i<n;i++) cout<<a[i]<<' ';
cout<<endl;
}// Print

void auto_register(LinkQueue &q1,LinkQueue &q2)
 {    // �����ɿڽ��еǼ�
	   int x;
   cout<<"���복���ţ��ٶ�С��100Ϊ�ͳ�������Ϊ������"<<endl;
cout<<"����������������ÿո�ֿ���ֱ������-1Ϊֹ��"<<endl;
	   while(1)
	   { cin>>x;
		 if(x==-1) break;
		 if(x<100) EnQueue_L(q1,x);     // �ͳ���q1��
		 else EnQueue_L(q2,x);          // ������q2��
	    }
  }// auto_register

void ferry_register(long &t1,int &mark,int &n)
 {   // ���ֵ��ɿڽ��еǼ�
	   if(mark==1)
	   { cout<<"�������ڶɿڵȴ�����Ҫ�ظ��Ǽǣ�"<<endl;
	     return;
	    }
	    mark=1;                     // ���ֵ��ڰ��Ǽ�
	    cout<<"�����ѵ��ɿڣ������ϴ���"<<endl;
	    n=0;                      // װ�س�������ʼΪ0
	    t1=time(0);               // �ǼǶ��ֵ��ɿ�ʱ��
  }// ferry_register

void auto_up_ferry(LinkQueue &q1,LinkQueue &q2,int a[10],int t1,int &mark,int &n) 
 {      // �������ֶ�
	  int i;
	  long t2;
	  if(QueueEmpty_L(q1)&&QueueEmpty_L(q2))
	  { cout<<"��������������"<<endl;
		if(mark==1&&n!=0)
		 { t2=time(0)-t1;        // ���㵽ĿǰΪֹ���ֵȴ���ʱ��
		   cout<<"����δ�����г�"<<n<<"�����ѵȴ�"<<t2/60<<"��";
		   cout<<t2%60<<"�룬�ȴ����������϶��֣�"<<endl;
		  }
		  return;
	    }
		if(mark!=1)
		 { cout<<"����δ�����������Ժ��϶��֣�"<<endl;
		   return;
		  }
		 do
		  { i=n%5;
			 while(!QueueEmpty_L(q1)&&n<10 && i<4)    // ������4���ͳ�
			 {	 DeQueue_L(q1,a[n++]);
				 i++;
		      }
			    // ��10������,��ӡ�����ţ����¶�mark��n��0��ת���ܲ˵�
			  if(n==10) {Print(a,n);mark=0;n=0;return; }
			            // ��4���ͳ�����Ž�һ������������4�����ɻ�����
			     if(i==4) { if(!QueueEmpty_L(q2)) DeQueue_L(q2,a[n++]); }
			 else
	  			 { while(!QueueEmpty_L(q2) && n<10 && i<5)
				   { DeQueue_L(q2,a[n++]);
				     i++;
				    }
			     }
	           if(n==10) {Print(a,n);mark=0;n=0;return; }  // ��10������
		      }while(!QueueEmpty_L(q1)||!QueueEmpty_L(q2));//do-while
		 t2=time(0)-t1;        // �ǼǶ��ֵȴ���ʱ��
	    	 cout<<"�������г�"<<n<<"�����ѵȴ�"<<t2/60<<"��";
			 cout<<t2%60<<"�룬�ȴ����������϶��֣�"<<endl;
		 	 return;
	      }// auto_up_ferry

	 void ferry_set_sail(int a[10],int &mark,int &n)
	 {
                  // �����ֶ���
	    if(n==0||mark==0)
		   cout<<"�������޳�����������޶��֣�����Ҫ�𺽣�"<<endl;
		 else {  Print(a,n);mark=0;n=0;  }
	 }// ferry_set_sail

void OutputQueue(LinkQueue &q1,LinkQueue &q2)
{    // ��������Ŷӵȴ����
cout<<"�ͳ��Ŷӵ������";
QueuePtr p=q1.front;
if(!p) cout<<"��ʱ�޿ͳ��Ⱥ�"<<endl;
	  while(p)
	  {	cout<<p->data<<' ';
	    p=p->next;
	  }
cout<<endl;
cout<<"�����Ŷӵ������";
	  p=q2.front;
	  if(!p) cout<<"��ʱ�޻����Ⱥ�"<<endl;
	  while(p)
	  {	cout<<p->data<<' ';
	    p=p->next;
	   }
cout<<endl;
}// OutputQueue

void end_run(LinkQueue &q1,LinkQueue &q2,int n)
{      // ������������
if(!QueueEmpty_L(q1)||!QueueEmpty_L(q1))
	  {	cout<<"��������δ�ɽ����ݲ��ܽ�����"<<endl;
		return;
	   }
	 if(n!=0)
	  {	cout<<"�������г������ܽ�������������֣�"<<endl;
		return;
	  }
	  cout<<"�������н�����"<<endl;
	  exit(0);
}// end_run

void main()
{
LinkQueue q1,q2;   // q1��q2���зֱ�洢���ɽ��Ŀͳ��ͻ���
InitQueue_L(q1);   // ��ʼ��q1
InitQueue_L(q2);   // ��ʼ��q2
int flag,mark=0;   // flag�����û�ѡ��,mark�ǼǶ��ֵ��ɿ�
int a[10],n=0;     // ����a��¼�����ϵ�ÿ��������,n��¼�����ĸ���
long t1;           // t1�Ǽ�ʱ��
do{                // ��ʾ���ܲ˵��������û�ѡ��
    cout<<"���ܲ˵���"<<endl;
   cout<<"1---�����ɿڽ��еǼ�"<<endl;
   cout<<"2---���ֵ��ɿڽ��еǼ�"<<endl;
   cout<<"3---�������ֶ�"<<endl;
   cout<<"4---�����ֶ���"<<endl;
   cout<<"5---�����ǰ�����Ŷ����"<<endl;
   cout<<"6---������������"<<endl<<endl;
   cout<<"���������ѡ��(1-6)��";
   do{
	      cin>>flag;
	      if(flag<1||flag>6) cout<<"����˵��Ŵ����䣺";
     }while(flag<1||flag>6);  //�ڲ�do-while
   // ���ݲ�ͬ���������Ӧ����
   switch(flag)
   {case 1:auto_register(q1,q2); break;
	    case 2:ferry_register(t1,mark,n);break;
	    case 3:auto_up_ferry(q1,q2,a,t1,mark,n);  break;
	    case 4:ferry_set_sail(a,mark,n); break;
	    case 5:OutputQueue(q1,q2); break;
	    case 6:end_run(q1,q2,n); break;
   }
}while(1);                  // ���do_while 
DestroyQueue_L(q1);
DestroyQueue_L(q2);
}
