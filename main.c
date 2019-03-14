#include"func.h"
int main()
{
	int iNum, i, cnt = 0, ret;
	char ch_account[100] = { 0 }, ch_password[100] = { 0 };
	//创建存储账户链表
	p_account s_acc = (p_account)calloc(1, sizeof(account));
	p_account pAccNew;
	p_acc_point p_acc_ponit_New, a_acc[100] = { 0 };
	//创建存储学生信息的链表
	pstu s_stu = (pstu)calloc(1, sizeof(stu));
	pstu pStuNew;
	pnode  p_stu_ponit_New, a_stu[100] = { 0 };
	///
	FILE *fp1 = fopen("account.txt", "r+");
	FILE *fp2 = fopen("student.txt", "r+");
	if (NULL == fp1)
	{
		perror("加载账号密码失败:");
	}
	//加载账户信息..............
	while ((memset(s_acc, 0, sizeof(account)), fflush(stdin), fscanf(fp1, "%s	%s	%d", s_acc->account, s_acc->password, &s_acc->limit)) != EOF)
	{

		p_account pAccNew = (p_account)calloc(1, sizeof(account));
		*pAccNew = *s_acc;
		p_acc_point p_acc_ponit_New = (p_acc_point)calloc(1, sizeof(acc_point));
		p_acc_ponit_New->account_date = pAccNew;
		a_acc[cnt++] = p_acc_ponit_New;
	}
	free(s_acc);
	s_acc = NULL;
	fclose(fp1);
	//printf("%s   %s  %d", p_acc_head->account_date->account, p_acc_head->account_date->password, p_acc_head->account_date->limit);
	//账户加载完成...........
	//开始加载学生信息..........
	if (NULL == fp2)
	{
		perror("加载学生信息失败:");
	}
	cnt = 0;
	while ((memset(s_stu, 0, sizeof(stu)), fflush(stdin), fscanf(fp2, "%d %s %c %f %f %f %f", &s_stu->iNum, s_stu->name, &s_stu->sex, &s_stu->math, &s_stu->Eng, &s_stu->soft, &s_stu->total)) != EOF)
	{
		pstu pStuNew = (pstu)calloc(1, sizeof(stu));
		*pStuNew = *s_stu;
		pnode p_stu_ponit_New = (pnode)calloc(1, sizeof(node));
		p_stu_ponit_New->stu_Node = pStuNew;
		a_stu[cnt++] = p_stu_ponit_New;
	}
	free(s_stu);
	s_stu = NULL;
	fclose(fp2);
	////////////账户信息加载完成
	while (1)
	{
		print_head();
		i = 0;
		printf("请登录账号密码:\n");
		printf("user_account:");
		scanf("%s", ch_account);
		printf("user_password:");
	label_password:
		while (1)
		{
			ch_password[i] = getch();

			if (ch_password[i] == '\r')
				break;
			else if (ch_password[i] == '\b')// 输入密码删除完之后还会继续删除
			{
				--i;
				printf("\b");
				printf(" ");
				printf("\b");

			}
			else {
				printf("*");
			}
			++i;
		}//输入密码的while
		ch_password[i] = '\0';
		ret = acc_check(ch_account, ch_password, a_acc);
		if (ret == 0)
		{
			printf("\n账号或密码错误，请重新输入.\n");
			for (i = 0; i < 5; ++i)
			{
				printf("\b\r%d秒后重新进入登录界面.\n", 5 - i);
				Sleep(1000);
			}
		}
		else if (ret == 1)
		{	/*进入教师界面  ，ret为1   拥有全部权限*/
			teacher_acc(a_acc, a_stu);
		}
		else if (ret == 2)
		{
			student_acc(a_stu);
			/*进入学生界面  ，ret为2  拥有部分权限*/

		}
		system("cls");
		printf("账号不存在或错误，请重新输入.\n\n");
		system("pause");
	}
	/*核对账号密码  目前是暴力遍历，后期可改成 动态数组+哈希*/
	//student_acc(a_stu);
}