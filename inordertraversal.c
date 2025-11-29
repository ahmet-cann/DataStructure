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
        root->sol = NULL;
        root->sag= NULL;
        root->data = x ;

        return root;
    }

    if(x>agac->data){
        agac->sag=ekle(agac->sag,x);        
        return agac;
    }

    if(x<agac->data){
        agac->sol=ekle(agac->sol,x);
        return agac;
    }

    return agac;
}


void nodeyaz(node* agac){
    if(agac==NULL){
        return;
    }
    nodeyaz(agac->sol);
    printf("%d  ",agac->data);
    nodeyaz(agac->sag);

}


int main(){
    node* agac= NULL;
    agac = ekle(agac,23);
    agac =ekle(agac,15);
    agac =ekle(agac,12);
    agac =ekle(agac,18);
    agac =ekle(agac,29);
    agac =ekle(agac,40);
    agac =ekle(agac,37);
    agac =ekle(agac,50);
    agac =ekle(agac,2);
    agac =ekle(agac,46);
    nodeyaz(agac);
    return 0;
}