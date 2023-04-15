typedef char ElemType;     // ˳��ջԪ������Ϊchar
# include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "SqStack.h"      // ���ļ�����˳��ջ���ݶ������������ز���
# include "string.h"       // ���ļ�����C++���ĵĶ��弰��ز���

char Proceed(char x1,char x2)
{           
   char Result;               // ����ȽϽ��
   char MidString[2];         
   Result='<';                
   MidString[0]=x2;           // ��x2��'\0'����һ���ַ���
   MidString[1]=0;
   if(((x1=='+'||x1=='-')&&strstr("+-)#", MidString)!=NULL)||
((x1=='*'||x1=='/')&&strstr("+-*/)#", MidString)!=NULL)||
(x1==')'&&strstr("+_*/)#", MidString)!=NULL))
        Result='>';  
     else if((x1=='('&&x2==')')||(x1=='#'&&x2=='#'))
     Result='=';  
          else if((x1=='('&&x2=='#')||(x1==')'&&x2=='(')||(x1=='#'&&x2==')'))
                 Result=' '; 
   return Result;
}// Proceed

bool Postfix(char *Mid_Expression,char *Post_Expression)
{   // ����׺���ʽmid_Expressionת��Ϊ��׺���ʽPost_Expression
   SqStack S;
   char x1,x2,x,y; // x1Ϊջ���������x2Ϊ��ǰ�������������Ƚ�x1��x2�����ȼ�
   int i=0,j=0;
   InitStack_Sq(S);                     // �����ջ��ʼ��
   Push_Sq(S,'#');                      // ջ���ý�����"#"
   x2=Mid_Expression[j];                // ���뵱ǰ�ַ���x2
   if(!GetTop_Sq(S,x1)) exit(0);        // ȡջ�������
   while(1)
   { if(x2!='+'&&x2!='-'&&x2!='*'&&x2!='/'&&x2!='('&&x2!=')'&&x2!='#')
	  { Post_Expression[i++]=x2;      // ������ַ�Ϊ��������ֱ���������׺���ʽ
        x2=Mid_Expression[++j];               // ������һ���ַ�
      }
      else if(Proceed(x1,x2)=='<')   // ���������������ȼ�����ջ������������ȼ�
	      { if(!Push_Sq(S,x2)) exit(0);           // ������������ջ
            if(!GetTop_Sq(S,x1)) exit(0);         // ȡջ�������
            x2=Mid_Expression[++j];               // ������һ���ַ�
	       }
          else if(Proceed(x1,x2)=='>')   
// ���������������ȼ�С��ջ������������ȼ� 
	            {
                  if(!Pop_Sq(S,x)) exit(0);        // ջ�������γ�ջ
                  Post_Expression[i++]=x;          // �������׺���ʽ
                  if(!GetTop_Sq(S,x1))  exit(0);    // ȡջ�������
	}
                  else if(Proceed(x1,x2)=='='&&x1=='('&&x2==')')  
  // ���������������ȼ�����ջ�������ε����ȼ� 
		                             // ��ջ�������Ϊ"("������������Ϊ")"
	                    { if(!Pop_Sq(S,y)) 
 exit(0);  // ����ջ������������������׺���ʽ
                         if(!GetTop_Sq(S,x1))  exit(0);  // ȡջ�������
                         x2=Mid_Expression[++j];         // ������һ���ַ�
	                  }
                    else if(Proceed(x1,x2)=='='&&x1=='#'&&x2=='#')  
   // ���������������ȼ�����ջ�������ε����ȼ� 
		                        // ��ջ�������������������Ϊ��Ϊ"#"
                        { Post_Expression[i]='\0'; // ��׺���ʽ�ý�����־
		                   return true;               // �ɹ�����
	                     }
                        else if(Proceed(x1,x2)==' ') break; //���ʽ�﷨���˳�
           } 
       cout<<"����"<<endl;
       return false;	
}// Postfix

void main( )
{
char Mid_Expression[80]={"A+(B-C/D)*E"},Post_Expression[80];
cout<<"��׺���ʽΪ��"<< Mid_Expression<<endl;
// ��׺���ʽת��Ϊ��׺���ʽ
Postfix(strcat(Mid_Expression,"#"),Post_Expression); 
cout<<"��׺���ʽΪ��"<<Post_Expression<<endl;
}
