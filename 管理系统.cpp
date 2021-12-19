#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
struct student{
	int num;  //ѧ�� 
	char name[20]; //���� 
	char sex[5]; //�Ա�
	char Class[30]; //�༶
	char room[20];  //�����
	int score; //�ɼ� 
	struct student *next;
};
struct student list;  //�������� 
void welcome(){   //���� 
	system("cls"); //���� 
	printf("**********************************************\n");
	printf("***********     ѧ������ϵͳ       ***********\n");
	printf("***********   1 --- ����ѧ����Ϣ   ***********\n");
	printf("***********   2 --- ɾ��ѧ����Ϣ   ***********\n");
	printf("***********   3 --- �޸�ѧ����Ϣ   ***********\n");
	printf("***********   4 --- ��ѯѧ����Ϣ   ***********\n");
	printf("***********   5 --- ���ѧ����Ϣ   ***********\n");
	printf("***********   6 --- ����ѧ����Ϣ   ***********\n");
	printf("***********   0 --- �˳�����ϵͳ   ***********\n");
	printf("**********************************************\n");
	printf("��ѡ���ܣ�");
}
//��ȡ�ļ� 
int read_FILE(struct student *head){  
	FILE*fpread=fopen("student_information.txt","r");
	struct student st;
	struct student *node,*end=NULL;
	end=head;
	if(fpread==NULL){
		return 0;
	}
	//���ļ��е����ݴ��뵽�ṹ�������� 
	while(fscanf(fpread,"%d %s %s %s %s %d",&st.num,st.name,st.sex,st.Class,st.room,&st.score)!=EOF){
		node=(struct student*)malloc(sizeof(struct student));
		*node=st;
		//β�巨 
		end->next=node;
		end=node;
		end->next=NULL;
	}
	return 1;
}
//�����ļ� 
int save_FILE(struct student *head){
	FILE *fpwrite=fopen("student_information.txt","w");
	if(fpwrite==NULL){
		return 0;
	}
	struct student *p=head->next;
	while(p!=NULL){
		//���ṹ���е��������뵽�ļ�ָ��fpwrite��ָ���ļ�λ�� 
		fprintf(fpwrite,"%d %s %s %s %s %d\n",p->num,p->name,p->sex,p->Class,p->room,p->score);
		p=p->next;
	}
	return 1;
} 
//���� ���� 
void add(struct student *head,struct student st){
	struct student*node=(struct student*)malloc(sizeof(struct student));
	*node=st;
	//ͷ�巨 
	node->next=head->next;
	head->next=node;
	save_FILE(head);
}
//����ѧ����Ϣ 
void add_printf(){
	system("cls");
	struct student st;
	printf("����������ѧ������Ϣ��\n");
	printf("ѧ�ţ�");
	scanf("%d",&st.num);
	printf("������");
	scanf("%s",st.name);
	printf("�Ա�");
	scanf("%s",st.sex);
	printf("�༶��");
	scanf("%s",st.Class);
	printf("����ţ�");
	scanf("%s",st.room);
	printf("�ɼ���");
	scanf("%d",&st.score);
	add(&list,st);
}
//����ѧ�Ų��� 
struct student *search_num(int num,struct student *head){
	while(head->next!=NULL){
		if(head->next->num==num){
			return head;  //Ҫ�ҵ���һ�� 
		}
		head=head->next;
	}
	return NULL;
}
//������������ 
struct student *search_name(char name[],struct student *head){
	while(head->next!=NULL){
		if(strcmp(name,head->next->name)==0){
			return head;  //Ҫ�ҵ���һ�� 
		}
		head=head->next;
	}
	return NULL;
}
//ɾ�� 
void delect(struct student *s){
	struct student *node=s->next;
	s->next=node->next;
	node->next=NULL;
	free(node);  //�ͷ�Ҫɾ���� 
}
//ɾ��ѧ����Ϣ 
void delect_printf(struct student *head){
	system("cls");
	int num;
	struct student *p;
	printf("������Ҫɾ��ѧ��ѧ��:");
	scanf("%d",&num);
	struct student *st=search_num(num,head);
	p=st;
	if(st==NULL){
		printf("û�д���");
		return; 
	}
	st=st->next;
	//��ʾҪɾ��ѧ������Ϣ 
	printf("_________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
	printf("_________________________________________________________\n");
	printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
	delect(p);
	save_FILE(head);
}
//�޸�ѧ����Ϣ 
void fix(struct student *head){
	system("cls");
	int num;
	printf("������Ҫ�޸�ѧ����ѧ�ţ�");
	scanf("%d",&num);
	//��ѧ�Ų��� 
	struct student *st=search_num(num,head);
	if(st==NULL){
		printf("û�д���");
		return; 
	}
	st=st->next;
	int choice=0;
	while(1){
		system("cls");
		//��ʾҪ�޸�ѧ������Ϣ 
		printf("_________________________________________________________\n");
		printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
		printf("_________________________________________________________\n");
		printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
		printf("_________________________________________________________\n");
		printf("�޸����� --- 1\n");
		printf("�޸��Ա� --- 2\n");
		printf("�޸İ༶ --- 3\n");
		printf("�޸������ --- 4\n");
		printf("�޸ĳɼ� --- 5\n");
		scanf("%d",&choice);
		//ѡ��Ҫ�޸ĵ����� 
		switch(choice){
			case 1:
				printf("������������");
				scanf("%s",st->name);
				break;
			case 2:
				printf("�������Ա�");
				scanf("%s",st->sex);
				break;
			case 3:
				printf("������༶��");
				scanf("%s",st->Class);
				break;
			case 4:
				printf("����������ţ�");
				scanf("%s",st->room);
				break;
			case 5:
				printf("������ɼ���");
				scanf("%d",st->score);
				break;
		}
		printf("�Ƿ�����޸���Ϣ��(yes:1 / no:0):");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	//��ʾ�޸ĺ����Ϣ 
	printf("_________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
	printf("_________________________________________________________\n");
	printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
	printf("_________________________________________________________\n");
	save_FILE(head);  //�����ļ� 
}
void search_printf(struct student *head){
	system("cls");
	int choice=0;
	printf("����ѧ�Ų�ѯ --- 1\n");
	printf("����������ѯ --- 2\n");
	printf("�������ѯ��ʽ��");
	scanf("%d",&choice);
	int num;
	struct student *st;
	char name[20];
	if(choice==1){
		printf("�������ѯ��ѧ�ţ�");
		scanf("%d",&num);
		st=search_num(num,head);
		if(st==NULL){
			printf("û�д���");
		}else{
			st=st->next;
			//��ʾ�ҵ�ѧ������Ϣ			
			printf("_________________________________________________________\n");
			printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
			printf("_________________________________________________________\n");
		}
	}else if(choice==2){
		printf("������Ҫ��ѯ��������");
		scanf("%s",name);
		st=search_name(name,head);
		if(st==NULL){
			printf("û�д���");
		}else{
			st=st->next;
			printf("_________________________________________________________\n");
			printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",st->num,st->name,st->sex,st->Class,st->room,st->score);
			printf("_________________________________________________________\n");
		}
	}
}
void print(){
	printf("_________________________________________________________\n");
	printf("|ѧ��\t|����\t|�Ա�\t|�༶\t\t|�����\t|�ɼ�\t|\n");
	printf("_________________________________________________________\n");
}
void print_printf(struct student *head){
	system("cls");
	struct student *p=head->next;
	print();
	if(p!=NULL){
		while(p!=NULL){
			//�������ѧ����Ϣ 
			printf("_________________________________________________________\n");
			printf("|%d|%s\t|%s\t|%s\t|%s\t|%d\t|\n",p->num,p->name,p->sex,p->Class,p->room,p->score);
			printf("_________________________________________________________\n");
			p=p->next;
		}
	}
}
//��ѧ�ŴӴ�С���� 
bool cmp_big_num(struct student e1,struct student e2){
	return e1.num>e2.num;
}
//��ѧ�Ŵ�С�������� 
bool cmp_small_num(struct student e1,struct student e2){
	return e1.num<e2.num;
}
//���ɼ��Ӵ�С���� 
bool cmp_big_score(struct student e1,struct student e2){
	return e1.score>e2.score;
}
//���ɼ���С�������� 
bool cmp_small_score(struct student e1,struct student e2){
	return e1.score<e2.score;
}
//���� 
void sort(struct student *head){
	system("cls");
	int choice=0;
	printf("����ѧ�ŴӴ�С���� --- 1\n");
	printf("����ѧ�Ŵ�С�������� --- 2\n");
	printf("���ճɼ��Ӵ�С���� --- 3\n");
	printf("���ճɼ���С�������� --- 4\n");
	printf("��ѡ������ʽ��");
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
	printf("��ӭ�´�ʹ��");
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
		printf("�Ƿ����������(yes:1 / no:2)");
		scanf("%d",&choice);
		if(choice==0){
			break;
		}
	}
	return 0;
}
