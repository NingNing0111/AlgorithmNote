#include <iostream.h>
#include"DSqString.h"
int main() {
	DSqString S1, S2, S3, S4;

	StrAssign_Sq(S1, "child");
	StrAssign_Sq(S2, "children");
	StrAssign_Sq(S3, "chinese chair technology ");
	StrAssign_Sq(S4, "");
	StrCopy_Sq(S4, S1);
	cout << "��S4�����ƺ��ֵΪ��";
	StrTraveres_Sq(S4);
	if (StrCompare_Sq(S1, S2)>0) cout << "��S1>��S2" << endl;
	else if (StrCompare_Sq(S1, S2) == 0)  cout << "��S1=��S2" << endl;
	else if (StrCompare_Sq(S1, S2)<0)  cout << "��S1<��S2" << endl;
	if (StrConcat_Sq(S3, S4)) {
		cout << "��S3��S4���ӳɹ�\n��" << endl;
		StrTraveres_Sq(S3);
	}
	else {
		cout << "����ʧ��" << endl;
	}
	if (SubString_Sq(S3, S4, 0, 4)) {
		cout << "ȡ�Ӵ��ɹ�\n��Ϊ��" << endl;
		StrTraveres_Sq(S4);
	}
	else {
		cout << "ȡ�Ӵ�ʧ��" << endl;
	}
	StrAssign_Sq(S1, "ch");
	StrAssign_Sq(S2, "abcd");
	cout << "�û�ǰS3��ֵΪ��" << endl;
	StrTraveres_Sq(S3);
	StrReplace_Sq(S3, S1, S2);
	cout << "�û���S3��ֵΪ��";
	StrTraveres_Sq(S3);
	visualization(S3,"show.dot");
	DestroyString_Sq(S1);
	DestroyString_Sq(S2);
	DestroyString_Sq(S3);
	DestroyString_Sq(S4);
	return 0;
}
