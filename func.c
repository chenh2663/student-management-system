#include"func.h"
//比较函数
int compare_iNum(const pnode *p1, const pnode *p2)
{

	return (*p1)->stu_Node->iNum - (*p2)->stu_Node->iNum;
}
//按权限高低对账户进行排序
int compare_limit(const p_acc_point *p1, const p_acc_point *p2)
{

	return (*p1)->account_date->limit - (*p2)->account_date->limit;
}
//打印窗口头
void print_head()
{
	int i;
	for (i = 0; i < 120; ++i)
	{
		printf("*");
	}
	printf("\n\n");
	for (i = 0; i < 38; ++i)
	{
		printf("*");
	}
	printf("学	生	管	理	系	统");
	for (i = 0; i < 38; ++i)
	{
		printf("*");
	}
	printf("\n\n");

	for (i = 0; i < 120; ++i)
	{
		printf("*");
	}
	printf("\n\n");
}
//打印空格
void print_space()
{
	int i;
	for (i = 0; i < 40; ++i)
		printf(" ");

}
//核对账户密码，并返回权限，返回1是教师权限    2是学生权限     0是账号密码错误
int acc_check(char *acc, char *pwd, acc_point **p)
{
	int i = 0;
	while (p[i] != NULL)
	{
		if (strcmp(p[i]->account_date->account, acc) == 0 && strcmp(p[i]->account_date->password, pwd) == 0)
		{
			return p[i]->account_date->limit;
		}
		++i;
	}
	return 0;/*在账户database里面没有找到账户信息返回0    */
}


//教师账户主界面
void teacher_acc(p_acc_point *p_acc, pnode *p_stu)
{
	int iNum;
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.查 询 学 生 信 息\n\n");
		print_space();
		printf("2.增 加 学 生 信 息\n\n");
		print_space();
		printf("3.更 新 学 生 信 息\n\n");
		print_space();
		printf("4.删 除 学 生 信 息\n\n");
		print_space();
		printf("5.查 询       账 户\n\n");
		print_space();
		printf("6.增 加       账 户\n\n");
		print_space();
		printf("7.更 新       账 户\n\n");
		print_space();
		printf("8.删 除       账 户\n\n");
		print_space();
		printf("9.退 出\n\n\n");
		printf("选择要进行的操作：");
		scanf("%d", &iNum);
		switch (iNum)
		{
		case 1:teacher_search(p_acc, p_stu); break;
		case 2:add_student(p_stu); break;
		case 3:update_student(p_stu); break;
		case 4:delete_student(p_stu); break;
		case 5:search_cc(p_acc); break;
		case 6:add_acc(p_acc); break;
		case 7: update_acc(p_acc); break;
		case 8:delete_acc(p_acc); break;
		case 9:exit(1);
		}
	}
	system("pause");
}

//1.教师——————————查询学生信息
void teacher_search(p_acc_point **p_acc, pnode **p_stu)
{
	int iNum, iNo;
	char name[20];
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.查 询 所 有 学 生 信 息\n\n");
		print_space();
		printf("2.通 过 学 号 查 询\n\n");
		print_space();
		printf("3.通 过 姓 名 查 询\n\n");
		print_space();
		printf("4.返 回 上 一 层\n\n");
		print_space();
		printf("5.直 接 退 出\n\n");
		printf("选择要进行的操作：");
		scanf("%d", &iNum);
		switch (iNum)
		{
		case 1:teacher_search_all(p_stu); break;
		case 2: {
			printf("请输入学号:");
			scanf("%d", &iNo);
			search_iNum(p_stu, iNo);
			break;
		}
		case 3:
		{
			printf("请输入姓名:");
			scanf("%s", name);
			search_name(p_stu, name);
			break;
		}
		case 4:goto label_end;
		case 5:	exit(0);
			/*default:
				goto label_again;*/
		}

	}
label_end:
	return;
}
//教师：查询所有同学信息
void teacher_search_all(pnode *p_stu)
{
	int i = 0;
	while (p_stu[i])
	{
		if (p_stu[i]->flag == 0)
		{
			printf("%-6d	%-15s	%c	%-5.2f	%-5.2f	%-5.2f	%-5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
		}
		++i;
	}
	system("pause");

}
//按照学号查找信息
void search_iNum(pnode *p_stu, int iNum)
{
	int i = 0;
	while (p_stu[i])
	{
		if (p_stu[i]->stu_Node->iNum == iNum)
		{
			printf("%-6d	%-15s	%c	%-5.2f	%-5.2f	%-5.2f	%-5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
			system("pause");
			return;
		}
		++i;

	}
	printf("查找失败！！！该学号不存在!!!\n");
	system("pause");
}
//按照姓名查找信息
void search_name(pnode *p_stu, char name[])
{
	int i = 0;
	while (p_stu[i])
	{
		if (strcmp(p_stu[i]->stu_Node->name, name) == 0)
		{
			printf("%-6d	%-15s	%c	%-5.2f	%-5.2f	%-5.2f	%-5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
			system("pause");
			return;
		}
		++i;
	}
	printf("查找失败！！！该姓名不存在!!!\n");
	system("pause");

}
//学生账户查询信息
void student_acc(pnode *p_stu)
{


	int iNum, iNo;
	char name[20];
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.通 过 学 号 查 询\n\n");
		print_space();
		printf("2.通 过 姓 名 查 询\n\n");
		print_space();
		printf("3.返 回 上 一 层\n\n");
		print_space();
		printf("4.直 接 退 出\n\n");
		printf("选择要进行的操作：");
		scanf("%d", &iNum);
		switch (iNum)
		{
		case 1: {
			printf("请输入学号:");
			scanf("%d", &iNo);
			search_iNum(p_stu, iNo);
			break;
		}
		case 2:
		{
			printf("请输入姓名:");
			scanf("%s", name);
			search_name(p_stu, name);
			break;
		}
		case 3:goto label_end;
		case 4:	exit(0);
			/*default:
				goto label_again;*/
		}
	}
label_end:
	return;
}
//2.增 加 学 生 信 息
void  add_student(pnode *p_stu)
{
	int cnt = 0, i, iNum, flag = 0;//flag用来标记增加学生学号是否已经存在
	FILE *fp;
	printf("请输入需要录入学生的学号;");
	scanf("%d", &iNum);
	while (p_stu[cnt])
	{
		if (p_stu[cnt]->stu_Node->iNum == iNum && p_stu[cnt]->flag == 0)
			flag = 1;
		++cnt;
	}
	if (flag == 1)
	{
		printf("该学生信息已存在。\n");
		system("pause");
		return;

	}
	pstu pStuNew = (pstu)calloc(1, sizeof(stu));
	pnode p_stu_ponit_New = (pnode)calloc(1, sizeof(node));
	p_stu_ponit_New->stu_Node = pStuNew;
	p_stu[cnt] = p_stu_ponit_New;
	//p_stu[cnt - 1]->next = p_stu_ponit_New;
	printf("请依次录入姓名、性别、数学分数、英语分数、软件分数:\n");
	scanf("%s %c %f %f %f", p_stu[cnt]->stu_Node->name, &p_stu[cnt]->stu_Node->sex, &p_stu[cnt]->stu_Node->math, &p_stu[cnt]->stu_Node->Eng, &p_stu[cnt]->stu_Node->soft);
	p_stu[cnt]->stu_Node->iNum = iNum;
	p_stu[cnt]->stu_Node->total = p_stu[cnt]->stu_Node->Eng + p_stu[cnt]->stu_Node->math + p_stu[cnt]->stu_Node->soft;
	++cnt;
	qsort(p_stu, cnt, sizeof(pnode), compare_iNum);
	fp = fopen("student.txt", "w+");
	if (NULL == fp)
	{
		perror("写入数据失败：");
	}
	for (i = 0; i < cnt; ++i) {

		fprintf(fp, "%d %s %c %5.2f %5.2f %5.2f %5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
	}
	fclose(fp);
	system("pause");

}
//3.删除学生信息
void  delete_student(pnode *p_stu)
{
	FILE *fp;
	int i = 0, cnt = 0, iNum, flag = 0;//flag检测便利一边后学号是否存在，若flag==0则不存在若falg==1则存在
	printf("请输入要删除学生的学号：\n");
	scanf("%d", &iNum);
	//后期可根据结构体改造直接存放数据的个数
	while (p_stu[cnt])
	{
		++cnt;//计算指针中存放数据的个数
	}
	while (p_stu[i])
	{
		if (p_stu[i]->stu_Node->iNum == iNum && p_stu[i]->flag == 0)
		{
			p_stu[i]->flag = 1;
			flag = 1;
			break;
		}
		++i;
	}
	if (flag == 1)
	{
		fp = fopen("student.txt", "w+");
		qsort(p_stu, cnt, sizeof(pnode), compare_iNum);
		for (i = 0; i < cnt; ++i) {
			if (p_stu[i]->flag == 0)
			{
				fprintf(fp, "%d %s %c %5.2f %5.2f %5.2f %5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
			}
		}
		fclose(fp);
		printf("删除信息成功\n");
	}
	else {
		printf("数据库中没有该学生信息.\n");

	}
	system("pause");

}

//查询账户
void search_cc(p_acc_point *p_acc)
{
	int i = 0;
	system("cls");
	print_head();
	printf("账号           密码           权限(1为管理员，2为普通学生)\n");
	while (p_acc[i])
	{
		if (p_acc[i]->flag == 0)
		{
			printf("%-15s%-15s%d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
		}	++i;
	}
	system("pause");
}
//增加账户信息
void  add_acc(p_acc_point *p_acc)
{

	//输入相同的账号提示出错需要完善
	int cnt = 0, i, flag = 0;//flag来标记增加账户是否已经存在
	char acc[20];
	FILE *fp;
	printf("请输入需要增加的账户:");
	scanf("%s", acc);

	while (p_acc[cnt])
	{
		if (strcmp(p_acc[cnt]->account_date->account, acc) == 0 && p_acc[cnt]->flag == 0)
			flag = 1;
		++cnt;
	}
	if (flag == 1)
	{
		printf("该账户信息已存在。\n");
		system("pause");
		return;

	}
	p_account pAccNew = (p_account)calloc(1, sizeof(account));
	p_acc_point p_acc_ponit_New = (p_acc_point)calloc(1, sizeof(acc_point));
	p_acc_ponit_New->account_date = pAccNew;
	p_acc[cnt] = p_acc_ponit_New;

	//p_stu[cnt - 1]->next = p_stu_ponit_New;
	printf("请依次录入密码、权限(1或者2），中间以空格间隔：\n");
	scanf("%s %d", p_acc[cnt]->account_date->password, &p_acc[cnt]->account_date->limit);
	strcpy(p_acc[cnt]->account_date->account, acc);
	++cnt;
	qsort(p_acc, cnt, sizeof(p_acc_point), compare_limit);
	fp = fopen("account.txt", "w+");
	if (NULL == fp)
	{
		perror("写入数据失败：");
	}
	for (i = 0; i < cnt; ++i) {

		fprintf(fp, "%s %s %d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
	}
	fclose(fp);
	system("pause");

}
//删除账户信息
void  delete_acc(p_acc_point *p_acc)
{
	FILE *fp;
	int i = 0, cnt = 0, iNum, flag = 0;//flag检测便利一边后学号是否存在，若flag==0则不存在若falg==1则存在
	char acc[20];
	printf("请输入要删除账号用户名：\n");
	scanf("%s", acc);
	//后期可根据结构体改造直接存放数据的个数
	while (p_acc[cnt])
	{
		++cnt;//计算指针中存放数据的个数
	}
	while (p_acc[i])
	{
		if (strcmp(p_acc[i]->account_date->account, acc) == 0)
		{
			p_acc[i]->flag = 1;
			flag = 1;
			break;
		}
		++i;
	}
	if (flag == 1)
	{
		fp = fopen("account.txt", "w+");
		qsort(p_acc, cnt, sizeof(p_acc_point), compare_limit);
		for (i = 0; i < cnt; ++i) {
			if (p_acc[i]->flag == 0)
			{
				fprintf(fp, "%s %s %d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
			}
		}
		fclose(fp);
		printf("删除信息成功\n");
	}
	else {
		printf("数据库中没有该账户信息.\n");

	}
	system("pause");

}
//更新学生信息
void update_student(pnode *p_stu) {


	FILE *fp;
	int i = 0, iNum, iNo, cnt = 0;//flag检测便利一边后学号是否存在，若flag==0则不存在若falg==1则存在
	float score;
	while (1)
	{
		system("cls");
		print_head();
		printf("请输入要更新学生信息的学号(输入0000可返回上一层)：\n");
		scanf("%d", &iNo);
		if (iNo == 0000) {
			break;
		}
		while (p_stu[i])
		{
			if (p_stu[i]->stu_Node->iNum == iNo)
			{
				break;
			}
			++i;
			++cnt;
		}
		while (p_stu[cnt])
		{
			++cnt;
		}
		if (p_stu[i] != NULL)
		{
			printf("请输入选择要更新的信息：\n");
			printf("1.  math \n2.  Eng \n3.  soft \n4.  返回上一层\n5.  直接退出\n ");
			printf("请输入选择要修改的内容：\n");
			scanf("%d", &iNum);
			switch (iNum)
			{
			case 1: {
				printf("请输入更改后的math分数：");
				scanf("%f", &score);
				p_stu[i]->stu_Node->math = score;
				break;
			}
			case 2: {
				printf("请输入更改后的Eng分数：");
				scanf("%f", &score);
				p_stu[i]->stu_Node->Eng = score;
				break;
			}
			case 3: {
				printf("请输入更改后的soft分数：");
				scanf("%f", &score);
				p_stu[i]->stu_Node->soft = score;
				break;
			}
			case 4:goto label_end;
			case 5:
				exit(0);
			}//...........switch

			p_stu[i]->stu_Node->total = p_stu[i]->stu_Node->Eng + p_stu[i]->stu_Node->math + p_stu[i]->stu_Node->soft;

			fp = fopen("student.txt", "w+");
			qsort(p_stu, cnt, sizeof(pnode), compare_iNum);
			for (i = 0; i < cnt; ++i) {
				if (p_stu[i]->flag == 0)
				{
					fprintf(fp, "%d %s %c %5.2f %5.2f %5.2f %5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
				}
			}
			fclose(fp);
			printf("更新学生信息成功\n");
			system("pause");
			goto label_end;

		}//...if....else
		else {
			printf("未能找到该学生信息，请重新输入\n");
			system("pause");
		}
	}
label_end:
	return;
}
//更新账户信息
void update_acc(p_acc_point *p_acc)
{
	FILE *fp;
	int i = 0, iNum, iNo, cnt = 0;//flag检测便利一边后学号是否存在，若flag==0则不存在若falg==1则存在
	char acc[20] = { 0 }, pwd[20] = { 0 };

	while (1)
	{
		system("cls");
		print_head();
		printf("请输入要更新的用户名(输入0000可返回上一层)：\n");
		scanf("%s", acc);
		if (strcmp(acc, "0000") == 0)//
			break;
		while (p_acc[i])
		{
			if (strcmp(p_acc[i]->account_date->account, acc) == 0)
			{
				break;
			}
			++i;
			++cnt;
		}
		while (p_acc[cnt])
		{
			++cnt;
		}
		if (p_acc[i] != NULL)
		{
			printf("请输入选择要更新的信息：\n");
			printf("1.  账户名 \n2.  密码 \n3.  权限 \n4.  该账户所有信息\n 5.  返回上一层\n6.  直接退出\n ");
			printf("请输入选择要修改的内容：\n");
			scanf("%d", &iNum);
			switch (iNum)
			{
			case 1: {
				printf("请输入更改后的账户名：");
				scanf("%s", p_acc[i]->account_date->account);
				break;
			}
			case 2: {
				printf("请输入更改后的密码：");
				scanf("%s", p_acc[i]->account_date->password);
				break;
			}
			case 3: {
				printf("请输入更改后的权限(1为管理员(教师) 2为普通学生)：");
				scanf("%d", &p_acc[i]->account_date->limit);
				break;
			}
			case 4: {printf("请输入更改后账户名、密码、权限(以空格间隔)：");
				scanf("%s %s %d", p_acc[i]->account_date->account, p_acc[i]->account_date->password, &p_acc[i]->account_date->limit);
				break;
			}
			case 5:goto label_end;
			case 6:
				exit(0);
			}//...........s
			qsort(p_acc, cnt, sizeof(p_acc_point), compare_limit);
			fp = fopen("account.txt", "w+");
			if (NULL == fp)
			{
				perror("写入数据失败：");
			}
			for (i = 0; i < cnt; ++i) {

				fprintf(fp, "%s %s %d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
			}
			fclose(fp);
			printf("更新账户信息成功\n");
			system("pause");
			goto label_end;
		}
		else {
			printf("未能找到该账户信息，请重新输入\n");
			system("pause");
		}

	}


label_end:
	return;


}