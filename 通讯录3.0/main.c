#include "linklist.h"

int main()
{

	int input = 1;
	linklist *head = LinklistCreate();
	LoadFromFile(head);
	User *p;
	while (input)
	{
		menu();
		printf("请选择功能：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			LinklistInsertHead(head);
			break;
		case SHOW:
			LinklistPrint(head);
			break;
		case FIND:
			p = LinklistNameSearch(head);
			if (p != NULL)
			{
				printf("ID\t姓名\t性别\t年龄\t电话\t\t住址\n");
				printf("%s\t%s\t%s\t%d\t%s\t%2s\n", p->id, p->name, p->sex, p->age, p->tel, p->addr);
			}
			break;
		case DELE:
			LinklistDelete(head);
			break;
		case REVISE:
			LinklistUpdata(head);
			break;
		case EXIT:
		    In_read(head);
			exit(EXIT_SUCCESS);
			
			break;
		}
	}
}