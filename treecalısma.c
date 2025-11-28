#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* sag;
    struct node* sol;
    int data;
} node;

node* ekle(node* agac, int x){
    if(agac == NULL){
        node* root = (node*)malloc(sizeof(node));
        root->sag = NULL;
        root->sol = NULL;
        root->data = x;
        return root;
    }

    if(agac->data < x){
        agac->sag = ekle(agac->sag, x);
        return agac;
    }

    if(agac->data > x){
        agac->sol = ekle(agac->sol, x);
        return agac;
    }

    return agac; 
}

void dolas(node* agac){
    if(agac == NULL){
        return;
    }

    dolas(agac->sol);
    printf("%d ", agac->data);
    dolas(agac->sag);
}

void enkucuk(node* agac){
    if(agac == NULL){
            return;
    }

    while(agac->sol != NULL){
        agac=agac->sol;
        printf("\n%d",agac->data);
    }
}

void enbuyuk(node* agac){
    if(agac == NULL){
        return;
    }
    while(agac->sag != NULL){
        agac = agac->sag;
        printf("\n%d",agac->data);
    }
}

node* delNode(node* agac , int aranan){
    if(agac == NULL){
        return NULL;   
    }

    if(aranan > agac->data){
        agac->sag = delNode(agac->sag, aranan);
        return agac;
    }

    if(aranan < agac->data){
        agac->sol = delNode(agac->sol, aranan);
        return agac;
    }

    if(agac->sol == NULL && agac->sag == NULL){
        free(agac);
        return NULL;
    }

    if(agac->sol == NULL){
        node* temp = agac->sag;
        free(agac);
        return temp;
    }

    
    if(agac->sag == NULL){
        node* temp = agac->sol;
        free(agac);
        return temp;
    }

  
    node* temp = agac->sag;
    while(temp->sol != NULL){
        temp = temp->sol;
    }

   
    agac->data = temp->data;

    agac->sag = delNode(agac->sag, temp->data);

    return agac;
}

int treeHeight(node* agac) {
    if (agac == NULL) 
        return 0;

    int solYuk = treeHeight(agac->sol); 
    int sagYuk = treeHeight(agac->sag); 
    
    int enBuyuk;
    if (solYuk > sagYuk) {
        enBuyuk = solYuk;
    } else {
        enBuyuk = sagYuk;
    }

    return enBuyuk + 1; 
}
int nodeSay(node* agac){
    if(agac == NULL){
        return 0; 
    }

    int solSay = nodeSay(agac->sol);   
    int sagSay = nodeSay(agac->sag);   
    int toplam = solSay + sagSay + 1; 

    return toplam;
}



int main(){
    node* agac = NULL;
    agac = ekle(agac, 40);
    agac = ekle(agac, 20);
    agac = ekle(agac, 60);
    agac = ekle(agac,18);
    agac = ekle(agac,30);
    agac = ekle(agac,80);
    agac = ekle(agac,10);
    dolas(agac);
    enkucuk(agac);
    enbuyuk(agac); 
    delNode(agac,10);
    int yukseklik = treeHeight(agac);
    printf("Agacin yuksekligi: %d\n", yukseklik);
    int toplamDugum = nodeSay(agac);
    printf("%d\n", toplamDugum);

    
    return 0;
}
