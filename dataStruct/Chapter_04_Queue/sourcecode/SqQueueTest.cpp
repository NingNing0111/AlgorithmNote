typedef int ElemType;
#include <iomanip.h>
#include <iostream.h>
#include "SqQueue.h"

int main(){
	SqQueue myQueue;
	int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88};
	InitQueue_Sq(myQueue,10,10);   //��ʼ��ѭ������
	for(i=0;i<12;i++){
		if(!EnQueue_Sq(myQueue,a[i])){
			cout<<"����ʧ�ܣ�"<<endl;
			return 1;
		}
	} 
	if(!GetHead_Sq(myQueue,x)){
		cout<<"ȡ����Ԫ��ʧ�ܣ�"<<endl;
		return 1;
	}
	cout<<"��ǰ����Ԫ�������ǣ�"<<x<<endl;
	cout<<"��ǰ˳����еĳ����ǣ�"<<QueueLength_Sq(myQueue)<<endl;
	visualization(myQueue,"showsqlist.dot");
	cout<<"���γ��Ե�����Ԫ������Ϊ��";
	while(!QueueEmpty_Sq(myQueue)){
		if(!DeQueue_Sq(myQueue,x)){
			cout<<"����ʧ��"<<endl;
			return 1; 
		}
		cout<<x<<' ';
	} 
	cout <<endl;
	cout<<"��ǰ˳����еĳ����ǣ�"<<QueueLength_Sq(myQueue)<<endl;
	cout<<endl;
	DestroyQueue_Sq(myQueue); 
	return 0;
}