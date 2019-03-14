#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//账户信息
typedef struct {

	char account[50];
	char password[50];
	int limit;
}account, *p_account;
typedef struct acc_point {
	p_account account_date;//account_date存放账户数据节点
	int flag;//flag标记是否删除
}acc_point, *p_acc_point;

//学生信息以及结构体
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
	pstu stu_Node;//stu_Node存放学生数据节点
	int flag;//flag标记是否删除
}node, *pnode;

//核对账号密码
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
