# include "string"                  // ���ļ�����C++���Ķ��弰��ز���
# include "iostream"                // ���ļ�������׼���������cout��cin
using namespace std;                 // ָ�����ռ䣬����C++�Ĺ涨
void main()
 {
	string s1="abcd",s2="123",s3;           // ��s1�ʹ�s2������ֵ
	cout<<"��s1��ֵΪ��"<<s1<<endl;        // �����s1
	s1=s1+s2;                               // ��s2�����ڴ�s1֮��
	cout<<"��s1�ʹ�S2���Ӻ��ֵΪ��"<<s1<<endl;
	if(s1>s2) cout<<"s1>s2"<<endl;        // ��s1�ʹ�s2���бȽ�
	else if(s1==s2) cout<<"s1=s2"<<endl;
	       else cout<<"s1<s2"<<endl;
	s1.insert(2,s2);        // ����s2���뵽��s1�еĵ�2��λ��֮ǰ
	cout<<"�����Ĵ�s1Ϊ��"<<s1<<endl;
	s3=s1.substr(4,5);    // �Ӵ�s1�е�42��λ�ÿ�ʼȡ����Ϊ5���Ӵ�
	cout<<"�Ӵ�s3Ϊ��"<<s3<<endl;
}
