#include <stdio.h>
#include <stdlib.h>

typedef struct dres{
        char name[64];
        float rating;
        int open; 
        int close;}res;

typedef struct node {
    struct dres res;
    struct node*next;
    }node;

node* list(int nres){//# of nodes goes here(n)
    node* head=NULL;
    node* temp=NULL;
    node* q=NULL;
    int i=0;
    while(i!=nres){
        temp=(node*)malloc(sizeof(node));
        &(temp->res);
        temp->next=NULL;
        if (head==NULL){
            head=temp;}
        else{
            q=head;
            while(q->next!=NULL){
                q=q->next;}
            q->next=temp;}
        i=i+1;
    };
    while(q!=NULL){
        printf("%d",q->res);
    }
    return head;};

int main(){
  int nres;
  printf("UwU\nhow many restuaraunts?\n");
  scanf("%d%*c",&nres);
  struct dres *p;
  p = malloc(sizeof(struct dres)*nres);
  node* h=NULL;
  h=list(nres);
  for(int i=1; i<=nres; i++){
    printf("Whats the name of the restaurant?\n");
    scanf("%s%*c",p[i].name);
    printf("How well liked is this restaurant?(rating)\n");
    scanf("%g%*c",&p[i].rating);
    printf("When does the restaurant open?\n");
    scanf("%d%*c",&p[i].open);
    printf("When does the restaurant close?\n");
    scanf("%d%*c",&p[i].close);}
    free(p);
    return 0;
 }