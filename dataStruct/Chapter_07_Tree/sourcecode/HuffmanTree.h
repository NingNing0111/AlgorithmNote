typedef struct {
 int weight;            
 int parent,lchild,rchild;
}HTNode,*HuffmanTree;                // ��̬��������洢��������;

typedef struct {
   int weight;                         // ����Ȩֵ
   char bit[MAXBIT];                    // ��ű������е�����
   int start;                           // �������ʼ�±�
}HTCode,*HuffmanCode;                  // ��̬��������洢����������

void select(HuffmanTree HT,int i,int &x1,int &x2)
 {  // ���ع�������HT��ǰi�������Ȩֵ��С��Ȩֵ��С�����ĸ�������
// x1Ϊ�������(Ȩֵ)��С��, x2Ϊ�������(Ȩֵ)��С��
    int m1,m2;
	 m1=m2=MAXVALUE;                       // ��ֵΪȨֵ���ֵ
     x1=x2=0;
     for(int j=0;j<i;j++)
     { if(HT[j].weight<m1&&HT[j].parent==-1)    
       {  m2=m1;
          x2=x1;
          m1=HT[j].weight;
          x1=j;
        }
       else if(HT[j].weight<m2&&HT[j].parent==-1)
       {   m2=HT[j].weight;
           x2=j;
        }
     }
}// select

void HuffmanTreeing(HuffmanTree &HT,int *w,int n)
{   // w�д��n��Ȩֵ,����n��Ҷ�ӽ��Ĺ�������HT
  int i,s1,s2;
  HT=(HuffmanTree)malloc((2*n-1)*sizeof(HTNode)); // ������������Ĵ洢�ռ�
  for(i=0;i<2*n-1;i++)                      // �����ʼ��
   { if(i<n)HT[i].weight=w[i];               // ��Ȩֵ
     else  HT[i].weight=0;
     HT[i].parent=-1;                         // ˫����Ϊ��
     HT[i].lchild=-1;                         // ������Ϊ��
     HT[i].rchild=-1;                         // �Һ�����Ϊ��
   }
  for(i=n;i<2*n-1;i++)                         // �������������n-1����Ҷ�ӽ��
  {  select(HT,i,s1,s2);            // ѡ���������Ȩֵ��С�ʹ�С�����ö�����
            // �¶��������������ĵ�i��������,��Ȩֵ��s1��s2��Ȩֵ֮��
HT[i].weight=HT[s1].weight+HT[s2].weight;  
      HT[i].lchild=s1;                 //�¶����������Һ��ӷֱ���s1��s2
      HT[i].rchild=s2;
      HT[s1].parent=HT[s2].parent=i;      // ����ĵ�i��������s1��s2��˫��
   }
}// HuffmanTreeing


void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int n)
 {    // ��n���ַ�(Ҷ�ӽ��)�Ĺ���������HC
	 int i,j;
	 int child,parent;
	 HTCode cd;                                // ��ʱ��ű���
	 HC=(HuffmanCode)malloc(n*sizeof(HTCode)); // ���䱣��n���ַ��ı���ռ�
	 for(i=0;i<n;i++)                          // ��n��Ҷ�ӵĹ���������
	 { cd.start=MAXBIT-1;                      // ���ȳ���������һλΪMAXBIT-1
	   cd.weight=HT[i].weight;                 // ȡ�ñ����Ӧ��Ȩֵ
       child=i;                                // �ӵ�i��Ҷ��㿪ʼ
       parent=HT[child].parent;                // parentָ��child˫�׽��
       while(parent!=-1)              
       {    if(HT[parent].lchild==child)       // child����˫�׵�����
		    cd.bit[cd.start]='0';              // ���֦��ֵΪ'0'
       else                                    // child����˫�׵��Һ���
		   cd.bit[cd.start]='1';               // ���֦��ֵΪ'1'
       cd.start--;                             // ��ʼλ����ǰ��һλ
       child=parent;                           // childָ����˫��
       parent=HT[child].parent;                // parentָ��child˫�׽��
      }
      for(j=cd.start+1;j<MAXBIT;j++)
		  HC[i].bit[j]=cd.bit[j];             // ����ÿ��Ҷ�ӵı���
        HC[i].start=cd.start+1;               // ����Ҷ���������ʼλ
        HC[i].weight=cd.weight;               // ��������Ӧ��Ȩֵ
    }
}// HuffmanCoding


