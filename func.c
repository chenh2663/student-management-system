#include"func.h"
//�ȽϺ���
int compare_iNum(const pnode *p1, const pnode *p2)
{

	return (*p1)->stu_Node->iNum - (*p2)->stu_Node->iNum;
}
//��Ȩ�޸ߵͶ��˻���������
int compare_limit(const p_acc_point *p1, const p_acc_point *p2)
{

	return (*p1)->account_date->limit - (*p2)->account_date->limit;
}
//��ӡ����ͷ
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
	printf("ѧ	��	��	��	ϵ	ͳ");
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
//��ӡ�ո�
void print_space()
{
	int i;
	for (i = 0; i < 40; ++i)
		printf(" ");

}
//�˶��˻����룬������Ȩ�ޣ�����1�ǽ�ʦȨ��    2��ѧ��Ȩ��     0���˺��������
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
	return 0;/*���˻�database����û���ҵ��˻���Ϣ����0    */
}


//��ʦ�˻�������
void teacher_acc(p_acc_point *p_acc, pnode *p_stu)
{
	int iNum;
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.�� ѯ ѧ �� �� Ϣ\n\n");
		print_space();
		printf("2.�� �� ѧ �� �� Ϣ\n\n");
		print_space();
		printf("3.�� �� ѧ �� �� Ϣ\n\n");
		print_space();
		printf("4.ɾ �� ѧ �� �� Ϣ\n\n");
		print_space();
		printf("5.�� ѯ       �� ��\n\n");
		print_space();
		printf("6.�� ��       �� ��\n\n");
		print_space();
		printf("7.�� ��       �� ��\n\n");
		print_space();
		printf("8.ɾ ��       �� ��\n\n");
		print_space();
		printf("9.�� ��\n\n\n");
		printf("ѡ��Ҫ���еĲ�����");
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

//1.��ʦ����������������������ѯѧ����Ϣ
void teacher_search(p_acc_point **p_acc, pnode **p_stu)
{
	int iNum, iNo;
	char name[20];
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.�� ѯ �� �� ѧ �� �� Ϣ\n\n");
		print_space();
		printf("2.ͨ �� ѧ �� �� ѯ\n\n");
		print_space();
		printf("3.ͨ �� �� �� �� ѯ\n\n");
		print_space();
		printf("4.�� �� �� һ ��\n\n");
		print_space();
		printf("5.ֱ �� �� ��\n\n");
		printf("ѡ��Ҫ���еĲ�����");
		scanf("%d", &iNum);
		switch (iNum)
		{
		case 1:teacher_search_all(p_stu); break;
		case 2: {
			printf("������ѧ��:");
			scanf("%d", &iNo);
			search_iNum(p_stu, iNo);
			break;
		}
		case 3:
		{
			printf("����������:");
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
//��ʦ����ѯ����ͬѧ��Ϣ
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
//����ѧ�Ų�����Ϣ
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
	printf("����ʧ�ܣ�������ѧ�Ų�����!!!\n");
	system("pause");
}
//��������������Ϣ
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
	printf("����ʧ�ܣ�����������������!!!\n");
	system("pause");

}
//ѧ���˻���ѯ��Ϣ
void student_acc(pnode *p_stu)
{


	int iNum, iNo;
	char name[20];
	while (1)
	{
		system("cls");
		print_head();
		print_space();
		printf("1.ͨ �� ѧ �� �� ѯ\n\n");
		print_space();
		printf("2.ͨ �� �� �� �� ѯ\n\n");
		print_space();
		printf("3.�� �� �� һ ��\n\n");
		print_space();
		printf("4.ֱ �� �� ��\n\n");
		printf("ѡ��Ҫ���еĲ�����");
		scanf("%d", &iNum);
		switch (iNum)
		{
		case 1: {
			printf("������ѧ��:");
			scanf("%d", &iNo);
			search_iNum(p_stu, iNo);
			break;
		}
		case 2:
		{
			printf("����������:");
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
//2.�� �� ѧ �� �� Ϣ
void  add_student(pnode *p_stu)
{
	int cnt = 0, i, iNum, flag = 0;//flag�����������ѧ��ѧ���Ƿ��Ѿ�����
	FILE *fp;
	printf("��������Ҫ¼��ѧ����ѧ��;");
	scanf("%d", &iNum);
	while (p_stu[cnt])
	{
		if (p_stu[cnt]->stu_Node->iNum == iNum && p_stu[cnt]->flag == 0)
			flag = 1;
		++cnt;
	}
	if (flag == 1)
	{
		printf("��ѧ����Ϣ�Ѵ��ڡ�\n");
		system("pause");
		return;

	}
	pstu pStuNew = (pstu)calloc(1, sizeof(stu));
	pnode p_stu_ponit_New = (pnode)calloc(1, sizeof(node));
	p_stu_ponit_New->stu_Node = pStuNew;
	p_stu[cnt] = p_stu_ponit_New;
	//p_stu[cnt - 1]->next = p_stu_ponit_New;
	printf("������¼���������Ա���ѧ������Ӣ��������������:\n");
	scanf("%s %c %f %f %f", p_stu[cnt]->stu_Node->name, &p_stu[cnt]->stu_Node->sex, &p_stu[cnt]->stu_Node->math, &p_stu[cnt]->stu_Node->Eng, &p_stu[cnt]->stu_Node->soft);
	p_stu[cnt]->stu_Node->iNum = iNum;
	p_stu[cnt]->stu_Node->total = p_stu[cnt]->stu_Node->Eng + p_stu[cnt]->stu_Node->math + p_stu[cnt]->stu_Node->soft;
	++cnt;
	qsort(p_stu, cnt, sizeof(pnode), compare_iNum);
	fp = fopen("student.txt", "w+");
	if (NULL == fp)
	{
		perror("д������ʧ�ܣ�");
	}
	for (i = 0; i < cnt; ++i) {

		fprintf(fp, "%d %s %c %5.2f %5.2f %5.2f %5.2f\n", p_stu[i]->stu_Node->iNum, p_stu[i]->stu_Node->name, p_stu[i]->stu_Node->sex, p_stu[i]->stu_Node->math, p_stu[i]->stu_Node->Eng, p_stu[i]->stu_Node->soft, p_stu[i]->stu_Node->total);
	}
	fclose(fp);
	system("pause");

}
//3.ɾ��ѧ����Ϣ
void  delete_student(pnode *p_stu)
{
	FILE *fp;
	int i = 0, cnt = 0, iNum, flag = 0;//flag������һ�ߺ�ѧ���Ƿ���ڣ���flag==0�򲻴�����falg==1�����
	printf("������Ҫɾ��ѧ����ѧ�ţ�\n");
	scanf("%d", &iNum);
	//���ڿɸ��ݽṹ�����ֱ�Ӵ�����ݵĸ���
	while (p_stu[cnt])
	{
		++cnt;//����ָ���д�����ݵĸ���
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
		printf("ɾ����Ϣ�ɹ�\n");
	}
	else {
		printf("���ݿ���û�и�ѧ����Ϣ.\n");

	}
	system("pause");

}

//��ѯ�˻�
void search_cc(p_acc_point *p_acc)
{
	int i = 0;
	system("cls");
	print_head();
	printf("�˺�           ����           Ȩ��(1Ϊ����Ա��2Ϊ��ͨѧ��)\n");
	while (p_acc[i])
	{
		if (p_acc[i]->flag == 0)
		{
			printf("%-15s%-15s%d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
		}	++i;
	}
	system("pause");
}
//�����˻���Ϣ
void  add_acc(p_acc_point *p_acc)
{

	//������ͬ���˺���ʾ������Ҫ����
	int cnt = 0, i, flag = 0;//flag����������˻��Ƿ��Ѿ�����
	char acc[20];
	FILE *fp;
	printf("��������Ҫ���ӵ��˻�:");
	scanf("%s", acc);

	while (p_acc[cnt])
	{
		if (strcmp(p_acc[cnt]->account_date->account, acc) == 0 && p_acc[cnt]->flag == 0)
			flag = 1;
		++cnt;
	}
	if (flag == 1)
	{
		printf("���˻���Ϣ�Ѵ��ڡ�\n");
		system("pause");
		return;

	}
	p_account pAccNew = (p_account)calloc(1, sizeof(account));
	p_acc_point p_acc_ponit_New = (p_acc_point)calloc(1, sizeof(acc_point));
	p_acc_ponit_New->account_date = pAccNew;
	p_acc[cnt] = p_acc_ponit_New;

	//p_stu[cnt - 1]->next = p_stu_ponit_New;
	printf("������¼�����롢Ȩ��(1����2�����м��Կո�����\n");
	scanf("%s %d", p_acc[cnt]->account_date->password, &p_acc[cnt]->account_date->limit);
	strcpy(p_acc[cnt]->account_date->account, acc);
	++cnt;
	qsort(p_acc, cnt, sizeof(p_acc_point), compare_limit);
	fp = fopen("account.txt", "w+");
	if (NULL == fp)
	{
		perror("д������ʧ�ܣ�");
	}
	for (i = 0; i < cnt; ++i) {

		fprintf(fp, "%s %s %d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
	}
	fclose(fp);
	system("pause");

}
//ɾ���˻���Ϣ
void  delete_acc(p_acc_point *p_acc)
{
	FILE *fp;
	int i = 0, cnt = 0, iNum, flag = 0;//flag������һ�ߺ�ѧ���Ƿ���ڣ���flag==0�򲻴�����falg==1�����
	char acc[20];
	printf("������Ҫɾ���˺��û�����\n");
	scanf("%s", acc);
	//���ڿɸ��ݽṹ�����ֱ�Ӵ�����ݵĸ���
	while (p_acc[cnt])
	{
		++cnt;//����ָ���д�����ݵĸ���
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
		printf("ɾ����Ϣ�ɹ�\n");
	}
	else {
		printf("���ݿ���û�и��˻���Ϣ.\n");

	}
	system("pause");

}
//����ѧ����Ϣ
void update_student(pnode *p_stu) {


	FILE *fp;
	int i = 0, iNum, iNo, cnt = 0;//flag������һ�ߺ�ѧ���Ƿ���ڣ���flag==0�򲻴�����falg==1�����
	float score;
	while (1)
	{
		system("cls");
		print_head();
		printf("������Ҫ����ѧ����Ϣ��ѧ��(����0000�ɷ�����һ��)��\n");
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
			printf("������ѡ��Ҫ���µ���Ϣ��\n");
			printf("1.  math \n2.  Eng \n3.  soft \n4.  ������һ��\n5.  ֱ���˳�\n ");
			printf("������ѡ��Ҫ�޸ĵ����ݣ�\n");
			scanf("%d", &iNum);
			switch (iNum)
			{
			case 1: {
				printf("��������ĺ��math������");
				scanf("%f", &score);
				p_stu[i]->stu_Node->math = score;
				break;
			}
			case 2: {
				printf("��������ĺ��Eng������");
				scanf("%f", &score);
				p_stu[i]->stu_Node->Eng = score;
				break;
			}
			case 3: {
				printf("��������ĺ��soft������");
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
			printf("����ѧ����Ϣ�ɹ�\n");
			system("pause");
			goto label_end;

		}//...if....else
		else {
			printf("δ���ҵ���ѧ����Ϣ������������\n");
			system("pause");
		}
	}
label_end:
	return;
}
//�����˻���Ϣ
void update_acc(p_acc_point *p_acc)
{
	FILE *fp;
	int i = 0, iNum, iNo, cnt = 0;//flag������һ�ߺ�ѧ���Ƿ���ڣ���flag==0�򲻴�����falg==1�����
	char acc[20] = { 0 }, pwd[20] = { 0 };

	while (1)
	{
		system("cls");
		print_head();
		printf("������Ҫ���µ��û���(����0000�ɷ�����һ��)��\n");
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
			printf("������ѡ��Ҫ���µ���Ϣ��\n");
			printf("1.  �˻��� \n2.  ���� \n3.  Ȩ�� \n4.  ���˻�������Ϣ\n 5.  ������һ��\n6.  ֱ���˳�\n ");
			printf("������ѡ��Ҫ�޸ĵ����ݣ�\n");
			scanf("%d", &iNum);
			switch (iNum)
			{
			case 1: {
				printf("��������ĺ���˻�����");
				scanf("%s", p_acc[i]->account_date->account);
				break;
			}
			case 2: {
				printf("��������ĺ�����룺");
				scanf("%s", p_acc[i]->account_date->password);
				break;
			}
			case 3: {
				printf("��������ĺ��Ȩ��(1Ϊ����Ա(��ʦ) 2Ϊ��ͨѧ��)��");
				scanf("%d", &p_acc[i]->account_date->limit);
				break;
			}
			case 4: {printf("��������ĺ��˻��������롢Ȩ��(�Կո���)��");
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
				perror("д������ʧ�ܣ�");
			}
			for (i = 0; i < cnt; ++i) {

				fprintf(fp, "%s %s %d\n", p_acc[i]->account_date->account, p_acc[i]->account_date->password, p_acc[i]->account_date->limit);
			}
			fclose(fp);
			printf("�����˻���Ϣ�ɹ�\n");
			system("pause");
			goto label_end;
		}
		else {
			printf("δ���ҵ����˻���Ϣ������������\n");
			system("pause");
		}

	}


label_end:
	return;


}