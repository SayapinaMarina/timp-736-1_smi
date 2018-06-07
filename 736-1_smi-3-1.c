#include <stdlib.h>
#include <stdio.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

node *head=NULL;
node *tail=NULL;

typedef node* list;

void init(int value)
{
	node *tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	tail = tmp;
}

void vvod(int data)
{
	node *tmp = malloc(sizeof(node));
	tmp->value=data;
	tmp->prev=tail;
	tmp->next=NULL;
	tail=tmp;
	tmp->prev->next=tmp;
}

int isEmpty()
{
	if ((head==NULL)&&(tail==NULL)) 
		return 1;
	else 
		return 0;
}

node *find_num(int k)
{
	node *tmp=head;
	int i=1;
	while (i!=k)
{
		tmp=tmp->next;
		i++;
}
		return tmp;
}

node *find_data(int k)
{
	node *tmp=head;
	while (tmp!=NULL && tmp->value!=k) tmp=tmp->next;
		return tmp;
}

void out()
{
	node *tmp=head;

	printf("%d",tmp->value);
	printf(" ");
	tmp;
	while (tmp->next!=NULL)
{
	tmp=tmp->next;
	printf("%d",tmp->value);
	printf(" ");
}
	printf("\n");
}

void  removel(int m)
{
	node *tmp=find_num(m);
	if (tmp==head)
{
		tmp->next->prev=NULL;
		head=tmp->next;
		free(tmp);
}
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		free(tmp);
		out();
}

void removed(int m)
{
	node *tmp=find_data(m);
	if (tmp==head)
{
		tmp->next->prev=NULL;
		head=tmp->next;
		free(tmp);
}
	else 
{
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		free(tmp);
}
		out();
}

void destroy()
{
	node *tmp=head;
	node *tmp1=NULL;
	while (tmp->next!=NULL)
{
		tmp1=tmp->next;
		free (tmp);
		tmp=tmp1;
		tmp1=tmp->prev;
}
		head=NULL;
		tail=NULL;
}

void append(int a, int b)
{
	node* tmp=find_num(a);
	node* tmp1=(node*) malloc(sizeof(node));
	tmp1->value=b;
	tmp1->prev=tmp;
	tmp1->next=tmp->next;
	tmp1->next->prev=tmp1;
	tmp1->prev->next=tmp1;
	out();
}

void prepend (int c,int d)
{
	node* tmp=find_num(c);
	node* tmp2=(node*) malloc(sizeof(node));
	tmp2->value=d;
	tmp2->next=tmp;
	tmp2->prev=tmp->prev;
	tmp2->next->prev=tmp2;
	tmp2->prev->next=tmp2;
	out();
}

int main()
{
	int n,data,k,m,a,b,c,d;
	scanf("%d",&n);
	scanf("%d", &data);
	init(data);
	for (int i=1;i<n;i++)
{
	scanf ("%d", &data);
	vvod(data);
}
	if (isEmpty()==0) out();
		scanf("%d",&k);
	if (isEmpty()==0) removel(k);
		scanf("%d",&m);
	if (isEmpty()==0) removed(m);
		scanf("%d",&a);
		scanf("%d",&b);
		append(a,b);
		scanf("%d",&c);
		scanf("%d",&d);
		prepend (c,d);
		printf("\n");
		destroy();
	return 0;
}

