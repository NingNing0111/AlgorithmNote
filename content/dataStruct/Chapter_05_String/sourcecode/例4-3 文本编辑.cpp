# define MAX_LINE 1000           // ������������
# define Number 80                // �����û�����Ŀ��С
# include "stdlib.h"          // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"         // ���ļ�������׼���������cout��cin�����Ʒ�setw()

typedef struct Chunk {
  char str[Number];               // һ�������80���ַ� 
  struct Chunk *next;
}Chunk;  

typedef struct
{
   int num;
   int len;
   Chunk *next;
}headtype;

headtype Head[MAX_LINE];

void InitiHead()
{   // ͷ��������ʼ��
    int i;
    for(i=0;i<MAX_LINE;i++)
    {
       Head[i].len=0;     // ������0
    }
}// InitiHead

int MenuSelect(void)
{  // ѡ��˵�
 int i;
 i=0; 
 cout<<endl<<"   ���˵�";
 cout<<endl<<"1.�����ַ���";
 cout<<endl<<"2.ɾ���ַ���";
 cout<<endl<<"3.��ʾ�ַ���";
 cout<<endl<<"4.�˳����˵�"<<endl;
 while(i<=0||i>4)
  {
    cout<<endl<<"��ѡ�����˵���";
    cin>>i;
 }
 return(i);
}// MenuSelect

void EnterData()
{   // ��������
    Chunk *p;
    int i,j,m,LineNumber,k;
    char StrBuffer[100];
	InitiHead();       // ��ʼ��ͷ�������
    while(1)
    {
      cout<<"�������кţ��˳���������밴0��";
      cin>>LineNumber;
      if(LineNumber==0)break;
      if(LineNumber<0||LineNumber>=MAX_LINE)return;
      i=LineNumber;
      Head[i].num=LineNumber;
      Head[i].next=(Chunk *)malloc(sizeof(Chunk));   // ����һ������
      p=Head[i].next;
      m=1;                                          // ͳ�ƽ�����
      j=-1;                                         // ͳ�ƴ����ַ��ĸ���
      StrBuffer[0]=0;
      k=0;
      do
      {
       j++;
       if(!StrBuffer[k]) 
         {
           cout<<"�������"<<LineNumber<<"���ַ���������@������";
           cin>>StrBuffer;
           k=0;
         }
       if(j>=Number*m)   // �ַ������ǽ���С�����������������е�һ���½��
         {
           m++;             // �������1
           p->next=(Chunk *)malloc(sizeof(Chunk));   
           p=p->next;
         }
         p->str[j%Number]=StrBuffer[k++];   // ����ǰ�ַ��汴���²����Ľ����
      }while(p->str[j%Number]!='@');
      Head[i].len=j;
     }
}// EnterData

void DeleteLine()
{   // ɾ���в���
    Chunk *p,*q;
    int i,j,m,LineNumber;
    while(1)
    {
      cout<<"������Ҫɾ�����кţ��˳�ɾ�������밴0��";
      cin>>LineNumber;
      if(LineNumber==0)break;
      if(LineNumber<0||LineNumber>=MAX_LINE)  return;
      i=LineNumber;
      p=Head[i].next;          // pָ���i��
      m=0;
      if(Head[i].len>0)
       m=(Head[i].len-1)/Number+1;    // ͳ�Ƹ��н�����
      for(j=0;j<m;j++)
      {
       q=p->next;
       free(p);
       p=q;
      }
      Head[i].len=0;
      Head[i].num=0;
    }
}// DeleteLine

void List()
{  // ��ʾ����
     Chunk *p;
     int i,j,m,n;
     for(i=0;i<MAX_LINE;i++)
     {
        if(Head[i].len>0)
        {
          cout<<endl<<Head[i].num<<"  ";
          n=Head[i].len;
          m=1;
          p=Head[i].next;
          for(j=0;j<n;j++)
          if(j>=Number*m)            // jΪ����������
          {
           p=p->next;
           m++;
          }
          else   cout<<p->str[j%Number];
        }
     }
     cout<<endl;
}// List

int main()
 {
   int  choice;
   while(1)
    {
      choice=MenuSelect();
      switch(choice)
         {
          case 1: EnterData();
          break;
          case 2: DeleteLine();
          break;
          case 3: List();
          break;
          case 4: cout<<"�ɹ��˳���"<<endl;exit(0);
         }
      }
      return 0;
}
