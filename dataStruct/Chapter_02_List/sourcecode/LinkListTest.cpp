typedef  int ElemType;
# include "stdlib.h"     
# include "iostream.h"   
# include "iomanip.h"     
# include "LinkList.h"

int  main()
{
      LinkList mylist;
      int i,j,temp,forLocate,forGet,forInsert,forDelete,a[]={6,8,16,2,34,56,7,10,22,45};
      InitList_L(mylist);   
      cout<<"�ҳ�ʼ����һ��ͷ��㡣"<<endl;
      CreateList_L_Front(mylist,a,10);          
      cout<<"�Ҵ�����һ����ͷ���ĵ�������Ϊ��"<<ListLength_L(mylist)<<endl;
      cout<<endl<<"���е�Ԫ������Ϊ��"<<endl;
      ListTraverse_L(mylist);
      
      cout<<endl<<"<====����ִ�ж�λԪ�ز���,��Ҫ�ҵ�Ԫ��ֵ��"<<endl;
      cout<<"�����룺";
      cin>>forLocate;
      j = LocateElem_L_2(mylist,forLocate);
      if(j!=-1&&GetElem_L(mylist,1,temp)) 
	  cout<<"�ҵ��ˣ����ǵ�"<<j+2<<"��Ԫ�أ����У�"<<temp<<"�ǵ�һ��Ԫ�أ�====>"<<endl;
      else cout<<"û�ҵ����Ԫ�أ�"<<endl;
	  //�������ʹ������һ��������
      //LinkList q = LocateElem_L(mylist,forLocate);
	  //cout<<q->data<<endl;
      
      cout<<endl<<"<====����ִ��ȡԪ�ز���,��Ҫ�ҵڼ���Ԫ�أ�"<<endl;
      cout<<"�����룺";
      cin>>forGet;
      if(GetElem_L(mylist,forGet,temp)) 
      cout<<"��"<<forGet<<"��Ԫ�ص�ֵ��:"<<temp<<"====>"<<endl;
      else cout<<"Ԫ�ز����ڣ�"<<endl;
      
      
	  cout<<endl<<"<====����ִ�в������,��Ҫ��ʲôԪ�ز���˳���"<<endl;
	  cout<<"�����룺";
	  cin>>forInsert;
	  cout<<"���뵽�ڼ���λ�ã�"<<endl;
	  cout<<"�����룺";
	  cin>>temp;
	  if(!ListInsert_L(mylist, temp, forInsert))
	  {cout<<"����ʧ��!"<<endl; return 0;} 
	  else cout<<"==>����ɹ�������������Ϊ��====>"<<endl;
	  ListTraverse_L(mylist);
	  
	  
	  cout<<endl<<"<====����ִ��ɾ������,��Ҫɾ���ڼ���Ԫ�أ�"<<endl;
	  cout<<"�����룺";
	  cin>>forDelete;
	  if(!ListDelete_L(mylist,forDelete,temp)) 
      {cout<<"ɾ��ʧ��!"<<endl; return 0;} 
	  else cout<<"ɾ���ɹ���ɾ���������Ϊ��====>"<<endl;
	  ListTraverse_L(mylist);
	  
      //ListVisualization_L(mylist,"showlinklist.dot");
      
      cout<<endl<<"<====����ִ�����ٲ���***"<<endl;
      DestroyList_L(mylist);
      cout<<"���ٳɹ�====>"<<endl;
  }
