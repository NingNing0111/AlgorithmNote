# include "stdio.h"
# include "stdlib.h"
    void main()
     {int a,e;
      DuLinkList head,p,q;
      p=q=head=(DuLNode*)malloc(sizeof(DuLNode));
      scanf("%d",&a);
      while(a!=0)
       {p=(DuLNode*)malloc(sizeof(DuLNode));
        p->data=a;
        p->prior=q;
        q->next=p;
        q=p;
        scanf("%d",&a);}
        q->next=head;
		head->prior=q;
        printf("����֮ǰ��˫��������:");
        p=head->next;
        while(p!=head)
        {printf("%3d,",p->data);
         p=p->next;}
         printf("\n");
        if(ListInsert_DuL(head,1,7))
		{
			printf("����ɹ�\n");
			printf("����֮���˫��������:");
            p=head->next;
            while(p!=head)
			{printf("%3d,",p->data);
            p=p->next;}
            printf("\n");
		}  
		else printf("����ʧ��\n");
        
        if(ListDelete_DuL(head,1,e))
		{	
			printf("ɾ���ɹ�\n");
            printf("��ɾ����Ԫ���ǣ�%d\n",e);
           printf("ɾ��֮���˫��������:");
           p=head->next;
          while(p!=head)
		  {printf("%3d,",p->data);
           p=p->next;}
           printf("\n");
		}
        else printf("ɾ��ʧ��\n");
       }