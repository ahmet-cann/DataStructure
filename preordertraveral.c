#include<stdio.h>
#include<stdlib.h> 

typedef struct node{
    struct node* sag;
    struct node* sol;
    int data;
}node;

node* ekle(node* agac , int deger){
    if(agac==NULL){
        node* kok =  (node*)malloc(sizeof(node));
        kok->sag=NULL;
        kok->sol= NULL;
        kok->data= deger;
        return  kok;
    }

    if(deger>agac->data){
        agac->sag=ekle(agac->sag,deger);
        return agac;
    }
    if(deger<agac->data){
        agac->sol = ekle(agac->sol,deger);
        return agac;
    }

    return agac;
}

void yaznode(node* agac){
    if(agac==NULL){
        return; 
    }
    printf("%d ", agac->data); 
    yaznode(agac->sol);
    yaznode(agac->sag);


}


int main(){
    node* agac = NULL;
    agac = ekle(agac,10);
    agac = ekle(agac,20);
    agac = ekle(agac,15);
    agac = ekle(agac,40);
    agac = ekle(agac,3);
    agac = ekle(agac,19);
    agac = ekle(agac,8);
    agac = ekle(agac,56);
    yaznode(agac);
    return 0 ;
}