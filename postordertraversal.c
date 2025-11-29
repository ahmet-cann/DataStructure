#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* sag;
    struct node* sol;
    int data;
}node;

node* ekle(node* agac,int x){
    if(agac==NULL){
        node* root = (node*)malloc(sizeof(node));
        root->sag=NULL;
        root->sol=NULL;
        root->data=x;
        return root;
    }
    if(x<agac->data){
        agac->sol=ekle(agac->sol,x);
        return agac;
    }
    if(x>agac->data){
        agac->sag= ekle(agac->sag,x);
        return agac;
    }
    return agac;
}

void nodeyaz(node* agac){
    if(agac==NULL){
        return;
    }

    nodeyaz(agac->sol);
    nodeyaz(agac->sag);
    printf("%d  ",agac->data);
   
}

int main(){
    node* agac=NULL;
    agac = ekle(agac,10);
    agac = ekle(agac,5);
    agac = ekle(agac,8);
    agac = ekle(agac,18);
    agac = ekle(agac,50);
    agac = ekle(agac,25);
    agac = ekle(agac,9);
    agac = ekle(agac,37);
    agac = ekle(agac,23);
    nodeyaz(agac);
    return 0;
}