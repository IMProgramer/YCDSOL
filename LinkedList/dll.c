#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *pre;
	struct node *next;
	int data;
};

typedef struct node node;
node *first = NULL;
node *last = NULL;

void insert_first(int data){
	printf("insert_first(%d)\n",data);
	if(first==NULL){
		first = (node*)malloc(sizeof(node));
		last = first;
		first->data = data;
		first->pre = NULL;
		first->next = NULL;
	}else{
		node *new = (node*)malloc(sizeof(node));
		new->data = data;
		new->pre = NULL;
		new->next = first;
		first->pre = new;
		first = new;
	}
}

void delete(int data){
	printf("delete(%d)\n",data);
	if(first==NULL)
		return;
	node *n;
	for(n = first ; (n != NULL) && (n->data != data) ; n = n->next);
	
	// Only 1 node
	if(first==last){
		first = NULL;
		last = NULL;
	// first node
	}else if(n==first){
		first = first->next;
		first->pre = NULL;
		free(n);	
		
	// last node
	}else if(n==last){
		last = last->pre;
		last->next = NULL;
		free(n);
	
	// middle node
	}else{
		n->pre->next = n->next;
		n->next->pre = n->pre;
		free(n);
	}
	
}

void insert_after(int match,int data){
	printf("insert_after(%d,%d)\n",match,data);
	if(first==NULL){
		insert_first(data);
	}else{
		node *new = (node*)malloc(sizeof(node));
		new->data = data;
		node *find=first;
		
		while(find != NULL && find->data != match)
			find = find->next;
		
		new->next = find->next;
		new->pre = find;
		
		if(find->next == NULL)
			last = new;
		else
			find->next->pre = new;
		find->next = new;
		
	}
}

void insert_before(int match,int data){
	printf("insert_before(%d,%d)\n",match,data);
	if(first==NULL){
		insert_first(data);
	}else{
		node *new = (node*)malloc(sizeof(node));
		new->data = data;
		node *find=first;
		
		while(find != NULL && find->data != match)
			find = find->next;
		
		new->next = find;
		new->pre = find->pre;
		
		if(find->pre == NULL)
			first = new;
		else
			find->pre->next = new;
		find->pre = new;
		
	}
}


void insert_end(int data){
	printf("insert_end(%d)\n",data);
	if(first == NULL){
		insert_first(data);
	}else{
		node *new = (node*)malloc(sizeof(node));
		new->data = data;
		new->pre = last;
		last->next = new;
		new->next = NULL;
		last = new;
		
	}
}
void print_r(){
	if(last==NULL)
		printf("No data");
	
	else{
		node *n = last;
		printf("Reverse: %d",n->data);
		n=n->pre;
		while(n != NULL){
			printf(" <-> %d",n->data);
			n = n->pre;
		}
	}
	printf("\n");
}
void print(){
	if(last==NULL)
		printf("No data");
	
	else{
		node *n = first;
		printf("Forward: %d",n->data);
		n=n->next;
		while(n != NULL){
			printf(" <-> %d",n->data);
			n = n->next;
		}
		
	}
	printf("\n");
}
void main(){
	print();
	print_r();
	insert_first(3);
	print();
	print_r();
	insert_first(1);
	print();
	print_r();
	insert_after(1,2);	
	print();
	print_r();
	insert_after(3,5);
	print();
	print_r();
	insert_before(5,4);
	print();
	print_r();	
	insert_end(6);
	print();
	print_r();
	delete(1);
	print();
	print_r();
	delete(6);
	print();
	print_r();
	delete(4);
	print();
	print_r();	
}
