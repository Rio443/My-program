#include<stdio.h>
#include<stdlib.h>

void insert_begin();
void insert_end();
void insert_after_node(int);
void insert_before_node(int);
void delete_begin();
void delete_end();
void delete_part(int);
void reverse();
struct Dnode{
	int data;
	struct Dnode *rlink,*llink;
};typedef struct Dnode node;

node *start;

node *createnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->llink=NULL;
	p->rlink=NULL;
	printf("\nEnter value:");
	scanf("%d",&p->data);
	return p;
}

node *createlist(int n)
{
	node *p,*q;
	p=start;
	while(n!=0)
	{
		p=createnode();
		if(start==NULL)
		{
			start=p;
			q=p;
		}
		else{
			q->rlink=p;
			p->llink=q;
			q=q->rlink;
		}
		n--;
	}
}

void insert_begin()
{
	node *p,*q;
	p=start;
	q=createnode();
	q->rlink=p;
	p->llink=q;
	start=q;
}
void insert_end()
{
	node *p,*q,*r;
	p=start;
	while(p!=NULL)
	{
		q=p;
		p=p->rlink;
	}
	r=createnode();
	q->rlink=r;
	r->llink=q;
}

void insert_after_node(int key)
{
	node *p,*q,*r;
	r=createnode();
	p=start;
	while(p->data!=key)
	{
		p=p->rlink;
	}
	q=p->rlink;
	r->rlink=q;
	q->llink=r;
	p->rlink=r;
	r->llink=p;
}
void insert_before_node(int key)
{
	node *p,*q,*r;
	r=createnode();
	p=start;
	while(p->data!=key)
	{
		q=p;
		p=p->rlink;
	}
	r->rlink=p;
	p->llink=r;
	q->rlink=r;
	r->llink=q;
}
void delete_begin()
{
	node *p;
	p=start;
	start=p->rlink;
}
void delete_end()
{
	node *p,*q;
	p=start;
	while(p->rlink!=NULL)
	{
		q=p;
		p=p->rlink;
	}
	q->rlink=NULL;
}
void delete_part(int key)
{
	node *p,*q,*r;
	p=start;
	while(p->data!=key)
	{
		q=p;
		p=p->rlink;
	}
	r=p->rlink;
	q->rlink=p->rlink;
	r->llink=q;
}
void reverse()
{
	node *p,*q,*r;
	p=start;
	p->rlink=NULL;
	p->llink=q;
	while(q!=NULL)
	{
		q->llink=q->rlink;
		q->rlink=p;
		p=q;
		q=q->llink;
	}
	start=q->llink;
}
void display()
{
	node *p;
	p=start;
	while(p!=NULL)
	{
		printf("%d,",p->data);
		p=p->rlink;
	}
}

int main()
{
	int n,c,key;
	printf("\nEnter the number limit of the list:");
	scanf("%d",&n);
	createlist(n);
	printf("\nThe entered values are...\n");
	display();
	    do{
			printf("\n########## ALL KIND OF LINKED LIST OPERATIONS ##########\n");
			printf("\n1.Insertion Operation");
			printf("\n2.Deletion Operation");
			printf("\n3.Reverse the list");
			printf("\nEnter your choice:");
			scanf("%d",&c);
			switch(c)
			{
				case 1:
					{
						printf("\n1.Insert node at the beggining");
						printf("\n2.Insert node at the end of the list");
						printf("\n3.Insert node after a node of the list");
						printf("\n4.Insert node before a node of the list\n");
						printf("\nEnter your choice:");
						scanf("%d",&c);
						switch(c)
						{
							case 1:
								{
									printf("\nBefore insert the node the list is...\n");
									display();
									insert_begin();
									printf("\nAfter insert the node node the list is...\n");
									display();
									break;
								}
							case 2:
							    {
							    	printf("\nBefore insert the node the list is...\n");
									display();
									insert_end();
									printf("\nAfter insert the node node the list is...\n");
									display();
									break;
								}	
							case 3:
								 {
			 	   	                printf("\nEnter the node value after which you insert the new node:");
								 	scanf("%d",&key);
							 		printf("\nBefore insert the node the list is...\n");
									display();
									insert_after_node(key);
									printf("\nAfter insert the node node the list is...\n");
									display();
									break;
								 }	
							case 4:
								 {
								   	printf("\nEnter the node value before which you insert the new node:");
								 	scanf("%d",&n); 
									insert_before_node(n);
									printf("\nAfter insert the node node the list is...\n");
									display();
									break; 	
						  		 }	 
						  	default:
							    {
							    	printf("\nInvalid Option.");
							    	break;
						   		}	 
						}
						break;
					}
				case 2:
			        {
		 			   	printf("\n1.Delete a node form the beggining of the list");
						printf("\n2.Delete a node from the end of the list");
						printf("\n3.Delete a particular node");
						printf("\nEnter your choice:");
						scanf("%d",&c);
						switch(c)
						{
							case 1:
								{
									printf("\nBefore delete the node the linked list is...\n");
									display();
									printf("\nAfter delete a node from the beggining the list is...\n");
									delete_begin();
									display();
									break;
								}
							case 2:
								 {
						 		    printf("\nBefore delete the node the linked list is...\n");
									display();
									printf("\nAfter delete a node from the end of the list is...\n");
								 	delete_end();
								 	display();
								 	break;
								 }	
							case 3:
								 {
								 	printf("\nBefore delete the node the linked list is...\n");
									display();
									printf("\nEnter the value you want to delete:");
									scanf("%d",&key);
									delete_part(key);
									printf("\nAfter delete a node from the end of the list is...\n");
									display();
								 	break;
							     }	 
							default:
							    {
							     	printf("\nInvalid Option");
						            break;	
					            }     
			  		    }
			  		    break;
			        }
				case 3:
					 {
					   	 printf("\nBefore traversal the list is...\n");
						 display();
						 printf("\nReverse of the linked list is...\n");
						 reverse();
						 display();
						 break;		
					 }		
				default:
					{
						printf("\nInvalid Option.");
						break;
					}
			}
			 printf("\nDo you want to continue?[1/0]");
			 scanf("%d",&c); 
	}while(c==1);
	return 0;
}





























