typedef int ElemType;
#include <iomanip.h>
#include <iostream.h>
#include "LinkQueue.h"

int main(){
	LinkQueue myqueue;
	int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88};
	InitQueue_L(myqueue);
	for(i=0;i<12;i++){
		if(!EnQueue_L(myqueue,a[i])){
			cout<<"����ʧ�ܣ�"<<endl;
			return 1;
		}
	}
	if(!GetHead_L(myqueue,x)){
		cout<<"ȡ����Ԫ��ʧ��"<<endl;
		return 1;
	}
	cout<<"��ǰ����Ԫ�������ǣ�"<<x<<endl;
	cout<<"��ǰ���ӵĳ����ǣ�"<<QueueLength_L(myqueue)<<endl;
	visualization(myqueue,"showsqlist.dot");
	cout<<"���γ��ӵ�����Ԫ������Ϊ��"<<endl;
	while(!QueueEmpty_L(myqueue)){
		if(!DeQueue_L(myqueue,x)){
			cout<<"����ʧ�ܣ�"<<endl;
			return 1;
		}	
		cout<<x<<' ';
	} 
	cout<<endl;
	cout<<"��ǰ���ӵĳ����ǣ�"<<QueueLength_L(myqueue)<<endl;
	DestroyQueue_L(myqueue);
	return 0;
}