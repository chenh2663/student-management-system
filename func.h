#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//�˻���Ϣ
typedef struct {

	char account[50];
	char password[50];
	int limit;
}account, *p_account;
typedef struct acc_point {
	p_account account_date;//account_date����˻����ݽڵ�
	int flag;//flag����Ƿ�ɾ��
}acc_point, *p_acc_point;

//ѧ����Ϣ�Լ��ṹ��
typedef struct student {
	int iNum;
	float math;
	float Eng;
	float soft;
	float total;
	char sex;
	char name[20];

}stu, *pstu;
typedef struct node {
	pstu stu_Node;//stu_Node���ѧ�����ݽڵ�
	int flag;//flag����Ƿ�ɾ��
}node, *pnode;

//�˶��˺�����
int acc_check(char *, char *, p_acc_point *);
void print_head();
void teacher_search(p_acc_point *, pnode *);
void teacher_acc(p_acc_point *, pnode *);
void teacher_search_all(pnode *);
void search_iNum(pnode *, int);
void search_name(pnode *, char name);
void student_acc(pnode *);
void  add_student(pnode *);
void  delete_student(pnode *);
void search_cc(p_acc_point *);
int compare_iNum(const pnode *, const pnode *);
int compare_limit(const p_acc_point *, const p_acc_point *);
void  add_acc(p_account *);
void  delete_acc(p_acc_point *);
void update_student(pnode *);
void update_acc(p_acc_point *); 
