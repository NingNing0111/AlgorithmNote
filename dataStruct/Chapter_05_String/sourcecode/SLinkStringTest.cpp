#include <iostream.h>
#include"SLinkString.h"
int main() {
	SLinkString S1, S2, S3, S4;
	int x;
	StrAssign_L(S1, "child");
	StrAssign_L(S2, "children");
	StrAssign_L(S3, "chinese chair technology ");
	StrAssign_L(S4, "");
	StrTraveres_L(S1);
	
	StrCopy_L(S4, S1);
	cout << "��S4�����ƺ��ֵΪ��";
	StrTraveres_L(S4);
	if (StrCompare_L(S1, S2)>0) cout << "��S1>��S2" << endl;
	else if (StrCompare_L(S1, S2) == 0)  cout << "��S1=��S2" << endl;
	else if (StrCompare_L(S1, S2)<0)  cout << "��S1<��S2" << endl;
	if (StrConcat_L(S3, S4)) {
		cout << "��S3��S4���ӳɹ�\n��" << endl;
		StrTraveres_L(S3);
	}
	else {
		cout << "����ʧ��" << endl;
	}
	if (SubString_L(S3, S4, 9, 5)) {
		cout << "ȡ�Ӵ��ɹ�\n��Ϊ��" << endl;
		StrTraveres_L(S4);
	}
	else {
		cout << "ȡ�Ӵ�ʧ��" << endl;
	}
	StrAssign_L(S1, "ch");
	StrAssign_L(S2, "abcd");
	//StrDelet_L(S2, 1, 2);
	//StrTraveres_L(S2);
	//StrInsert_L(S2, 1, S1);
	//StrTraveres_L(S2);
	
	cout << "�û�ǰS3��ֵΪ��" << endl;
	StrTraveres_L(S3);
	StrReplace_L(S3, S1, S2);
	cout << "�û���S3��ֵΪ��";
	StrTraveres_L(S3);
	visualization(S3,"show.dot");
	DestroyString_L(S1);
	DestroyString_L(S2);
	DestroyString_L(S3);
	DestroyString_L(S4);
	return 0;
}
