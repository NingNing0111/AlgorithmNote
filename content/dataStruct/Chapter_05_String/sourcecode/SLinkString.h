typedef struct LNode {
	char str;
	struct LNode *next;
}SNode,*SLinkString;

//����ֵ����
void StrAssign_L(SLinkString &S, char * chars) {
	//���ַ���chars��ֵ����ʽ��S
	SLinkString p, q;
	S = (SLinkString)malloc(sizeof(LNode));
	if (!(*chars)) S->next = NULL;
	else {
		p = S;
		while (*chars) {
			q = (SLinkString)malloc(sizeof(LNode));
			q->str = *chars;
			p->next = q;
			p = q;
			chars++;
		}
		q->next = NULL;
	}
}

//�����Ʋ���
void StrCopy_L(SLinkString &S, SLinkString T) {
	//����ʽ��T���Ƶ�S��
	SLinkString p, q, r;
	while (S->next) {
		p = S;
		S = S->next;
		free(p);
	}
	r = T->next;
	p = S;
	while (r) {
		q = (SLinkString)malloc(sizeof(LNode));
		if (!p) {
			cout << "����" << endl;
			exit(0);
		}
		q->str = r->str;
		p->next = q;
		p = q;
		r = r->next;
	}
	p->next = NULL;
}

//�󴮳�����
int StrLength_L(SLinkString S) {
	int n = 0;
	SLinkString p = S->next;   //������ָ��
	while (p) {
		n++;
		p = p->next;
	}
	return n;
}

//���Ƚϲ���
int StrCompare_L(SLinkString S, SLinkString T) {
	SLinkString p = S->next, q = T->next;
	while (p&&q) {
		if (p->str > q->str) return 1;
		else if (p->str < q->str) return -1;
		p = p->next;
		q = q->next;
	}
	if (p) return 1;
	else if (q) return -1;
	return 0;
}

//�����Ӳ���
bool StrConcat_L(SLinkString &S, SLinkString T) {
	SLinkString p, q = S->next, r = T->next;
	while (q->next) q = q->next;
	while (r) {
		p = (SLinkString)malloc(sizeof(LNode));
		if (!p) return false;
		p->str = r->str;
		q->next = p;
		q = p;
		r = r->next;
	}
	q->next = NULL;
	return true;
}

//ȡ�Ӵ��Ĳ���
bool SubString_L(SLinkString S, SLinkString &Sub, int pos, int len) {
	SLinkString p, q, r;
	int i;
	if (len<0 || len>StrLength_L(S) - pos + 1) return false; //lenֵ������
	p = S->next; i = 1;
	while (p&&i < pos) {
		p = p->next;
		i++;
	}
	if (i != pos) return false; //posλ�ò�����
	while (Sub->next) {
		q = Sub;
		Sub = Sub->next;
		free(q);
	}
	r = Sub;
	for (i = 1; i <= len; i++) {
		q = (SLinkString)malloc(sizeof(LNode));
		q->str = p->str;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return true;
}

//�Ӵ��Ķ�λ����
bool Index_L(SLinkString S, SLinkString T, int &pos) {
	int i;
	SLinkString Sub;
	StrAssign_L(Sub, "");   //��ʼ��
	for (i = 1; i < StrLength_L(S) - StrLength_L(T); i++) {
		SubString_L(S, Sub, i, StrLength_L(T));
		//cout << Sub->next->str << endl;
		if (!StrCompare_L(Sub, T)) {
			//cout << Sub->next->str << endl;
			pos = i;
			//cout << i << endl;
			return true;
		}
	}
	//cout << "fail" << endl;
	return false;
}

//�����Ӵ��Ĳ���
bool StrInsert_L(SLinkString &S, int pos, SLinkString T) {
	SLinkString p, q, r, h;
	int i = 0;
	p = S;
	while (p&&i < pos-1) {
		p = p->next;
		i++;
	}
	q = p->next;
	if (i != pos-1) return false;
	r = T->next;
	while (r) {
		h = (SLinkString)malloc(sizeof(LNode));
		h->str = r->str;
		p->next = h; h->next = q;
		p = h; r = r->next;
	}
	return true;
}

//ɾ���Ӵ��Ĳ���
bool StrDelet_L(SLinkString &S, int pos, int len) {
	//����ʽ���ĵ�pos���ַ�����ʼɾ��
	SLinkString p = S, r, q;
	if (len < 0 || StrLength_L(S) - pos + 1 < len) return false;
	int i = 0;
	while (p&&i < pos-1) {
		p = p->next;
		i++;
	}
	if (i != pos-1) return false;
	q = p->next;
	for (i = 1; i <= len; i++) {
		r = q;
		p->next = q->next;
		q = q->next;
		free(r);
	}
	return true;
}

//�û��Ӵ��Ĳ���
void StrReplace_L(SLinkString &S, SLinkString T, SLinkString V) {
	int pos = 1;
	while (Index_L(S, T, pos)) {
		StrDelet_L(S, pos, StrLength_L(T));
		StrInsert_L(S, pos, V);
		//pos=pos+StrLength_L(V);
	}
}

//���ı�������
void StrTraveres_L(SLinkString S) {
	SLinkString p = S->next;
	while (p) {
		cout << p->str;
		p = p->next;
	}
	cout << endl;
}

//��ʽ���ĳ�������
void DestroyString_L(SLinkString &S) {
	SLinkString p, p1;
	p = S;
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	S = NULL;
}
void visualization(SLinkString S, char* filename)
{   int temp;
	FILE *stream;  
	SLinkString p = S->next;
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\n node [shape = record] \n ");  
    int i=1;
    fprintf(stream, "S[label=\"\ͷ�ڵ�\"]; S%d[label=\"<L>%c|<R>*\"];\n  S->S%d:L[label=\"head\"] \n; ",i,p->str,i);
		i++;
		p=p->next;
	while(p){
		fprintf(stream, "S%d[label=\"<L>%c|<R>*\"];\n S%d:R->S%d:L \n; ",i,p->str,i-1,i,p->str);
		i++;
		p=p->next;
		if(p&&!p->next){
			fprintf(stream, "S%d[label=\"<L>%c|<R>NULL\"];\n S%d:R->S%d:L \n; ",i,p->str,i-1,i,p->str);
			p=p->next;
		}
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng show.dot -o show.png");
	system("show.png");
}

