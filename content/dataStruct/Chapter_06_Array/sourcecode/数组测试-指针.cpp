 
 
 typedef int ElemType;    // ��������Ԫ������ElemTypeΪ����
 # include "stdarg.h"      // ���ļ�����VA_start()��va_arg()��va_end()�Ⱥ�����va_list����
 # include "stdlib.h"     // ���ļ�����malloc()��realloc()��free()�Ⱥ���
 # include "iostream.h"   // ���ļ�������׼���������cout��cin
 # include "iomanip.h"             // ���ļ��������Ʒ�setw()
 # include "Array.h"
 void main()
 {
   Array A;
   int i,j,k,dim=3,b1=3,b2=4,b3=2; // A[3][4][2]����
   ElemType e;
   InitArray(A,dim,b1,b2,b3); // ����3��4��2����ά����A
   cout<<"A.b=";
   for(i=0;i<dim;i++) // ˳�����A.b
     cout<<setw(2)<<*(A.b+i);
   cout<<endl;
   cout<<"A.c=";
   for(i=0;i<dim;i++) // ˳�����A.c
     cout<<setw(2)<<*(A.c+i);
   cout<<endl;
   cout<<b1<<"ҳ"<<b2<<"��"<<b3<<"�о���Ԫ������:"<<endl;
   for(i=0;i<b1;i++)
   { for(j=0;j<b2;j++)
     { for(k=0;k<b3;k++)
       { Assign(A,i*100+j*10+k,i,j,k); // ��i��100+j��10+k��ֵ��A[i][j][k]
         Value(e,A,i,j,k); // ��A[i][j][k]��ֵ����e
         cout<<"  "<<"A["<<i<<"]["<<j<<"]["<<"]="<<setw(2)<<e;  // ���A[i][j][k]
       }
       cout<<endl;
     }
    cout<<endl;
   }
   cout<<"A.base="<<endl;
   for(i=0;i<b1*b2*b3;i++) // ˳�����A.base
   { cout<<setw(4)<<*(A.base+i);
     if(i%(b2*b3)==b2*b3-1)
      cout<<endl;
   }
  cout<<"A.dim="<<A.dim<<endl;
   DestroyArray(A);
}
