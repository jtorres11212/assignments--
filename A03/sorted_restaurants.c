#include <stdio.h>
#include <stdlib.h>

struct dres{
        char name[64];
        float rating;
        int open; 
        int close;};
struct node {
    struct dres res;//data
    struct node*next;
    };
struct node*insert_front(struct dres q,struct node* head){//data(struct dres), head
  struct node *n=malloc(sizeof(struct node));
    if (n == NULL){
        printf("ERROR: Out of space!\n");
        exit(1);
}
  n->res=q;
  n->next=head;
  return n;
}

void print(struct node*list){
    for(struct node*n=list;n!=NULL;n=n->next) {
        struct dres res=n->res;
        printf("  name:%s  open:%d close:%d  rating:%.1f\n",
        res.name, res.open, res.close, res.rating);
    }       
}
struct node* atnthnode(struct dres m, struct node* head){
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->res=m;
    new->next=NULL;
    struct node* temp = head;
    while(temp->next != NULL) { 
        if (temp->next->res.rating < new->res.rating) {
           new->next=temp->next;// insert new node between temp and temp->next
           temp->next=new;
           break;
        }
        temp=temp->next;
    }
    if (temp->next == NULL) {
        temp->next=new;
        new->next=NULL;
       // new node add at end
    }
    return new;
}
int main(){
  int nres;
  struct node* head=NULL;
  printf("UwU\nhow many restuaraunts?\n");
  scanf("%d%*c",&nres);
  struct dres *p;
  p = malloc(sizeof(struct dres)*nres);// array
  for(int i=0; i<nres; i++){
    printf("Whats the name of the restaurant?\n");
    scanf("%[^\n]%*c",p[i].name);
    printf("How well liked is this restaurant?(rating)\n");
    scanf("%g%*c",&p[i].rating);
    printf("When does the restaurant open?\n");
    scanf("%d%*c",&p[i].open);
    printf("When does the restaurant close?\n");
    scanf("%d%*c",&p[i].close);
  }
  head = insert_front(p[0], head);
  for(int i=1; i<nres; i++){
    if (p[i].rating < head->res.rating) { 
       atnthnode(p[i],head);
        }
    else{
        head=insert_front(p[i],head);
    }
  }
  print(head);

  struct node* current=head;
  struct node* deleted=head;
  while(current!=NULL){
    current=current->next;
    head=current;
    free(deleted);
    deleted=head;
  }
  free(p);
  return 0;
 }