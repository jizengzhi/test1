#include "linklist.h"

linklist *LinklistCreate()
{
    //定义一个头结点，在堆区开辟空间
    linklist *head = (linklist *)malloc(sizeof(linklist));
    //给指针域赋初始值为空
    head->next = NULL;
    return head;
}
//判断单链表是否为空
bool LinklistIsEmpty(linklist *head)
{
    return head->next == NULL ? 1 : 0;
}

//头插法添加用户
void LinklistInsertHead(linklist *head)
{
    User user;
    printf("ID: ");
    scanf("%s", user.id);

    printf("姓名：");
    scanf("%s", user.name);

    printf("性别：");
    scanf("%s", user.sex);

    printf("年龄：");
    scanf("%d", &user.age);

    printf("电话：");
    scanf("%s", user.tel);

    printf("住址：");
    scanf("%s", user.addr);

    linklist *tmp = (linklist *)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->user = user;
    tmp->next = head->next;
    head->next = tmp;
    FILE *fp = fopen("./a.txt", "a");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    if (1 != fwrite(tmp, sizeof(linklist), 1, fp))
    {
        perror("fwrite");
        return;
    }
    fclose(fp);
    return;
}
//查看用户
void LinklistPrint(linklist *head)
{
    printf("ID\t姓名\t性别\t年龄\t电话\t\t住址\n");
    linklist *p = head->next;
    while (p != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%s\t%2s\n", p->user.id, p->user.name, p->user.sex, p->user.age, p->user.tel, p->user.addr);
        p = p->next;
    }
}

//按照姓名搜索用户
User *LinklistNameSearch(linklist *head)
{
    char name[10] = {0};
    printf("请输入要查找的姓名：");
    scanf("%s", name);
    if (LinklistIsEmpty(head))
    {
        printf("通讯录为空\n");
        return NULL;
    }
    linklist *p = head->next;
    while (p != NULL)
    {
        if (strcmp(p->user.name, name) == 0)
        {
            return &p->user;
        }
        p = p->next;
    }
    printf("请输入正确的姓名\n");
    return NULL;
}
//按照姓名修改数据
void LinklistUpdata(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("链表为空");
        return;
    }
    char name[10] = {0};
    printf("请输入要修改的姓名：");
    scanf("%s", name);

    User newuser;
    printf("ID: ");
    scanf("%s", newuser.id);

    printf("姓名：");
    scanf("%s", newuser.name);

    printf("性别：");
    scanf("%s", newuser.sex);

    printf("年龄：");
    scanf("%d", &newuser.age);

    printf("电话：");
    scanf("%s", newuser.tel);

    printf("住址：");
    scanf("%s", newuser.addr);

    linklist *p = head;
    int flag = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->user.name, name) == 0)
        {
            p->user = newuser;

            flag = 1;
        }
        if (flag == 0)
        {
            printf("姓名%s不存在,修改失败\n", name);
        }
    }
}
//删除用户信息
void LinklistDelete(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("链表为空");
        return;
    }
    char name[10] = {0};
    printf("请输入要删除的姓名：");
    scanf("%s", name);
    linklist *p = head;
    int flag = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->next->user.name, name) == 0)
        {
            linklist *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            tmp = NULL;
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("姓名%s不存在,删除失败\n", name);
    }
}

void Look(linklist *head)
{
    linklist *tmp = head->next;
    FILE *fp = fopen("./a.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return;
    }
    while (fread(tmp, sizeof(linklist), 1, fp) != 0)
    {
        tmp->next = head->next;
        head->next = tmp;
    }
}
// void initiate(Ptxl ptxl)
// {
// 	ptxl->count = 0;
// }

//界面
void menu()
{
    printf("*********************************\n");
    printf("****         通讯录          ****\n");
    printf("*********************************\n");
    printf("      [1] 添加用户\n");
    printf("      [2] 查看用户\n");
    printf("      [3] 搜索用户\n");
    printf("      [4] 删除用户信息\n");
    printf("      [5] 修改用户信息\n");
    printf("      [0] 退出\n");
    printf("**********************************\n");
}
//读取文件
void LoadFromFile(linklist *head)
{
    FILE *fp;
    fp = fopen("./a.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    linklist *tmp2 = head;
    int ret;
    // person *tmp = PERSONCREATE();
    // while ((ret = fread(tmp, sizeof(person), 1, fp)) != 0)
    // {
    linklist *tmp = LinklistCreate();
    while (1)
    {
        linklist *tmp = LinklistCreate();
        if (ret = fread(tmp, sizeof(linklist), 1, fp) == 0)
            break;
        while (tmp2->next != NULL && strcmp(tmp2->user.name, tmp->user.name) < 0)
        {
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
    }
    if (feof(fp) == 0)
    {
        perror("feof");
        exit(-1);
    }
    else
        printf("通讯录加载成功！\n");
    fclose(fp);
}
//保存到文件
void In_read(linklist *head)
{
    linklist *p = head->next;
    FILE *fp = fopen("./a.txt", "r+");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    while (p != NULL)
    {
        if (1 != fwrite(p, sizeof(linklist), 1, fp))
        {
            perror("fwrite");
            return;
        }
        p = p->next;
    }
    fclose(fp);
}