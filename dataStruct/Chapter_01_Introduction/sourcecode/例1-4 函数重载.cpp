# include "iostream.h"                 // ���ļ�������׼���������cout��cin
int max(int a,int b)                    // ����1
{
  return(a>b?a:b);
}
float max(float a,float b,float c)       // ����2
 { float t=a;
      if(t<b) t=b;
   if(t<c) t=c;
   return t;
 }

void main( )
{
 cout<<"max(2,3)="<<max(2,3)<<endl;
 cout<<"max(2.3,5.6,3.1)="<<max(2.3,5.6,3.1)<<endl;
}
