# include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iostream.h"     // ���ļ�������׼���������cout��cin
# define MAXVALUE  10000       // Ҷ����Ȩֵ���ֵ
# define MAXBIT  10           // ������λ��
# include "HuffmanTree.h"      // ���ļ�����������������͹���������Ĳ���
void main()
{
   int i,j,*w,n;
   HuffmanTree HT;
   HuffmanCode HC;
   cout<<"������Ȩֵ�ĸ�����";
   cin>>n;
   w=(int*)malloc(n*sizeof(int));         // ��̬���ɴ��n��Ȩֵ�Ŀռ�
   cout<<"����������"<<n<<"��Ȩֵ(����)��";
   for(i=0;i<=n-1;i++)
     cin>>w[i];                            // ��������Ȩֵ
   HuffmanTreeing(HT,w,n);                 // ����w�����n��Ȩֵ����շ�����HT
   HuffmanCoding(HT,HC,n);                 // n���շ����������HC
   for(i=0;i<n;i++)                        // ��������շ�������
   {   cout<<"Weight="<<HT[i].weight<<"  Code="; 
       for(j=HC[i].start;j<MAXBIT;j++)
		     cout<<HC[i].bit[j];
	   cout<<endl;
 }
}
