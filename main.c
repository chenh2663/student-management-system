#include"func.h"
int main()
{
	int iNum, i, cnt = 0, ret;
	char ch_account[100] = { 0 }, ch_password[100] = { 0 };
	//�����洢�˻�����
	p_account s_acc = (p_account)calloc(1, sizeof(account));
	p_account pAccNew;
	p_acc_point p_acc_ponit_New, a_acc[100] = { 0 };
	//�����洢ѧ����Ϣ������
	pstu s_stu = (pstu)calloc(1, sizeof(stu));
	pstu pStuNew;
	pnode  p_stu_ponit_New, a_stu[100] = { 0 };
	///
	FILE *fp1 = fopen("account.txt", "r+");
	FILE *fp2 = fopen("student.txt", "r+");
	if (NULL == fp1)
	{
		perror("�����˺�����ʧ��:");
	}
	//�����˻���Ϣ..............
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
	//�˻��������...........
	//��ʼ����ѧ����Ϣ..........
	if (NULL == fp2)
	{
		perror("����ѧ����Ϣʧ��:");
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
	////////////�˻���Ϣ�������
	while (1)
	{
		print_head();
		i = 0;
		printf("���¼�˺�����:\n");
		printf("user_account:");
		scanf("%s", ch_account);
		printf("user_password:");
	label_password:
		while (1)
		{
			ch_password[i] = getch();

			if (ch_password[i] == '\r')
				break;
			else if (ch_password[i] == '\b')// ��������ɾ����֮�󻹻����ɾ��
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
		}//���������while
		ch_password[i] = '\0';
		ret = acc_check(ch_account, ch_password, a_acc);
		if (ret == 0)
		{
			printf("\n�˺Ż������������������.\n");
			for (i = 0; i < 5; ++i)
			{
				printf("\b\r%d������½����¼����.\n", 5 - i);
				Sleep(1000);
			}
		}
		else if (ret == 1)
		{	/*�����ʦ����  ��retΪ1   ӵ��ȫ��Ȩ��*/
			teacher_acc(a_acc, a_stu);
		}
		else if (ret == 2)
		{
			student_acc(a_stu);
			/*����ѧ������  ��retΪ2  ӵ�в���Ȩ��*/

		}
		system("cls");
		printf("�˺Ų����ڻ��������������.\n\n");
		system("pause");
	}
	/*�˶��˺�����  Ŀǰ�Ǳ������������ڿɸĳ� ��̬����+��ϣ*/
	//student_acc(a_stu);
}