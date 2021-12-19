#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
struct student{
	int num;  //学号 
	char name[20]; //姓名 
	char sex[5]; //性别
	char Class[30]; //班级
	char room[20];  //宿舍号
	int score; //成绩 
	struct student *next;
};
struct student list;  //定义链表 
void welcome(){   //界面 
	system("cls"); //清屏 
	printf("**********************************************\n");
	printf("***********     学生管理系统       ***********\n");
	printf("***********   1 --- 增加学生信息   ***********\n");
	printf("***********   2 --- 删除学生信息   ***********\n");
	printf("***********   3 --- 修改学生信息   ***********\n");
	printf("***********   4 --- 查询学生信息   ***********\n");
	printf("***********   5 --- 输出学生信息   ***********\n");
	printf("***********   6 --- 排序学生信息   ***********\n");
	printf("***********   0 --- 退出管理系统   ***********\n");
	printf("**********************************************\n");
	printf("请选择功能：");
}
//读取文件 
int read_FILE(struct student *head){  
	FILE*fpread=fopen("student_information.txt","r");
	struct student st;
	struct student *node,*end=NULL;
	end=head;
	if(fpread==NULL){
		return 0;
	}
	//将文件中的数据传入到结构体数组中 
	while(fscanf(fpread,"%d %s %s %s %s %d",&st.num,st.name,st.sex,st.Class,st.room,&st.score)!=EOF){
		node=(struct student*)malloc(sizeof(struct student));
		*node=st;
		//尾插法 
		end->next=node;
		end=node;
		end->next=NULL;
	}
	return 1;
}
//保存文件 
int save_FILE(struct student *head){
	FILE *fpwrite=fopen("student_information.txt","w");
	if(fpwrite==NULL){
		return 0;
	}
	struct student *p=head->next;
	while(p!=NULL){
		//将结构体中的数据输入到文件指针fpwrite所指的文件位置 
		fprintf(fpwrite,"%d %s %s %s %s %d\n",p->num,p->name,p->sex,p->Class,p->room,p->score);
		p=p->next;
	}
	return 1;
} 
//增加 链表 
void add(struct student *head,struct student st){
	struct student*node=(struct student*)malloc(sizeof(struct student));
	*node=st;
	//头插法 
	node->next=head->next;
	head->next=node;
	save_FILE(head);
}
//增加学生信息 
void add_printf(){
	system("cls");
	struct student st;
	printf("请输入新增学生的信息：\n");
	printf("学号：");
	scanf("%d",&st.num);
	printf("姓名：");
	scanf("%s",st.name);
	printf("性别：");
	scanf("%s",st.sex);
	printf("班级：");
	scanf("%s",st.Class);
	printf("宿舍号：");
	scanf("%s",st.room);
	printf("成绩：");
	scanf("%d",&st.score);
	add(&list,st);
}
//根据学号查找 
struct student *search_num(int num,struct student *head){
	while(head->next!=NULL){
		if(head->next->num==num){
			return head;  //要找的上一个 
		}
		head=head->next;
	}
	return NULL;
}
//根据姓名查找 
struct student *search_name(char name[],struct student *head){
	while(head->next!=NULL){
		if(strcmp(name,head->next->name)==0){
			return head;  //要找的上一个 
		}
		head=head->next;
	}
	return NULL;
}
//删除 
void delect(struct student *s){
	struct student *node=s->next;
	s->next=node->next;
	node->next=NULL;
	free(node);  //释放要删除的 
}
//删除学生信息 
void delect_printf(struct student *head){
	system("cls");
	int num;
	struct student *p;
	printf("请输入要删除学生学号:");
	scanf("%d",&num);
	struct student *st=search_num(num,head);
	p=st;
	if(st==NULL){
		printf("没有此人");
		return; 
	}
	st=st->next;
	//显示要删除学生的信息 
	printf("_________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
	printf("_________________________________________________________\n");
	printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
	delect(p);
	save_FILE(head);
}
//修改学生信息 
void fix(struct student *head){
	system("cls");
	int num;
	printf("请输入要修改学生的学号：");
	scanf("%d",&num);
	//按学号查找 
	struct student *st=search_num(num,head);
	if(st==NULL){
		printf("没有此人");
		return; 
	}
	st=st->next;
	int choice=0;
	while(1){
		system("cls");
		//显示要修改学生的信息 
		printf("_________________________________________________________\n");
		printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
		printf("_________________________________________________________\n");
		printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
		printf("_________________________________________________________\n");
		printf("修改姓名 --- 1\n");
		printf("修改性别 --- 2\n");
		printf("修改班级 --- 3\n");
		printf("修改宿舍号 --- 4\n");
		printf("修改成绩 --- 5\n");
		scanf("%d",&choice);
		//选择要修改的内容 
		switch(choice){
			case 1:
				printf("请输入姓名：");
				scanf("%s",st->name);
				break;
			case 2:
				printf("请输入性别：");
				scanf("%s",st->sex);
				break;
			case 3:
				printf("请输入班级：");
				scanf("%s",st->Class);
				break;
			case 4:
				printf("请输入宿舍号：");
				scanf("%s",st->room);
				break;
			case 5:
				printf("请输入成绩：");
				scanf("%d",st->score);
				break;
		}
		printf("是否继续修改信息？(yes:1 / no:0):");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	//显示修改后的信息 
	printf("_________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
	printf("_________________________________________________________\n");
	printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
	printf("_________________________________________________________\n");
	save_FILE(head);  //保存文件 
}
void search_printf(struct student *head){
	system("cls");
	int choice=0;
	printf("按照学号查询 --- 1\n");
	printf("按照姓名查询 --- 2\n");
	printf("请输入查询方式：");
	scanf("%d",&choice);
	int num;
	struct student *st;
	char name[20];
	if(choice==1){
		printf("请输入查询的学号：");
		scanf("%d",&num);
		st=search_num(num,head);
		if(st==NULL){
			printf("没有此人");
		}else{
			st=st->next;
			//显示找到学生的信息			
			printf("_________________________________________________________\n");
			printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
			printf("_________________________________________________________\n");
		}
	}else if(choice==2){
		printf("请输入要查询的姓名：");
		scanf("%s",name);
		st=search_name(name,head);
		if(st==NULL){
			printf("没有此人");
		}else{
			st=st->next;
			printf("_________________________________________________________\n");
			printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
			printf("_________________________________________________________\n");
		}
	}
}
void print(){
	printf("_________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|班级\t\t|宿舍号\t|成绩\t|\n");
	printf("_________________________________________________________\n");
}
void print_printf(struct student *head){
	system("cls");
	struct student *p=head->next;
	print();
	if(p!=NULL){
		while(p!=NULL){
			//依次输出学生信息 
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",p->num,p->name,p->sex,p->Class,p->room,p->score);
			printf("_________________________________________________________\n");
			p=p->next;
		}
	}
}
//按学号从大到小排序 
bool cmp_big_num(struct student e1,struct student e2){
	return e1.num>e2.num;
}
//按学号从小到大排序 
bool cmp_small_num(struct student e1,struct student e2){
	return e1.num<e2.num;
}
//按成绩从大到小排序 
bool cmp_big_score(struct student e1,struct student e2){
	return e1.score>e2.score;
}
//按成绩从小到大排序 
bool cmp_small_score(struct student e1,struct student e2){
	return e1.score<e2.score;
}
//排序 
void sort(struct student *head){
	system("cls");
	int choice=0;
	printf("按照学号从大到小排序 --- 1\n");
	printf("按照学号从小到大排序 --- 2\n");
	printf("按照成绩从大到小排序 --- 3\n");
	printf("按照成绩从小到大排序 --- 4\n");
	printf("请选择排序方式：");
	scanf("%d", &choice);
	int flag=0;
	for(struct student *p=head->next;p!=NULL;p=p->next){
		for(struct student *q=p->next;q!=NULL;q=q->next){
			switch (choice){
				case 1:
					if(!cmp_big_num(*p,*q)){
						flag=1;
					}
					break;
				case 2:
					if(!cmp_small_num(*p,*q)){
						flag=1;
					}
					break;
				case 3:
					if(!cmp_big_score(*p,*q)){
						flag=1;
					}
					break;
				case 4:
					if(!cmp_small_score(*p,*q)){
						flag=1;
					}
					break;
			}
			if(flag==1){
				struct student t=*q;
				*q=*p;
				*p=t;
				t.next=p->next;
				p->next=q->next;
				q->next=t.next;
			}
		}
	}
}
void bye(){
	system("cls");
	printf("欢迎下次使用");
	exit(0);
}
int main(){
	int choice=0;
	read_FILE(&list);
	while(true){
		welcome();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				add_printf();
				break;
			case 2:
				delect_printf(&list);
				break;
			case 3:
				fix(&list);
				break;
			case 4:
				search_printf(&list);
				break;
			case 5:
				print_printf(&list);
				break;
			case 6:
				sort(&list);
				break;
			case 0:
				bye();
				break;
		}
		printf("是否继续操作？(yes:1 / no:2)");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	return 0;
}
