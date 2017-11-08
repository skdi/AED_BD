#include <iostream>

using namespace std;


struct arbol{
    int num;
    arbol *izq,*der;
};
void preorden(arbol *aux){
    if(aux!=NULL){
        cout<<aux->num<<" ";
        preorden(aux->izq);
        preorden(aux->der);
    }
}
int altura(arbol *raiz,int h=0){

    if(raiz==NULL)
        return h;
    arbol *temp1=raiz->izq;
    arbol *temp2=raiz->der;
    if(temp1!=NULL || temp2!=NULL){
        h++;
        if(temp1!=NULL)
            altura(temp1,h);
        if(temp2!=NULL)
            altura(temp2,h);
    }
    return h;



}



bool Ebinario(arbol *raiz){
    bool flag=1;
    arbol *temp1=raiz->izq;
    arbol *temp2=raiz->der;
    if(temp1!=NULL){
        if(temp1->der!=NULL){
            Ebinario(temp1->der);
        }else if(temp1->der==NULL && temp1->izq!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<temp1->num<<"||"<<endl;
        }

        if(temp1->izq!=NULL){
            Ebinario(temp1->izq);
        }else if(temp1->izq==NULL && temp1->der!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<temp1->num<<"||"<<endl;
        }
    }
    if(temp2!=NULL){
        if(temp2->der!=NULL){
            Ebinario(temp1->der);
        }else if(temp2->der==NULL && temp2->izq!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<temp2->num<<"||"<<endl;
        }

        if(temp2->izq!=NULL){
            Ebinario(temp1->izq);
        }else if(temp2->izq==NULL && temp2->der!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<temp1->num<<"||"<<endl;
        }
}
    return flag;
}


bool completo(arbol *raiz,int a=0){
    bool flag=1;
    int h=altura(raiz,0);
    if(a<=(h-2)){
        arbol *temp1=raiz->izq;
        arbol *temp2=raiz->der;
        if(temp1!=NULL){
            a++;
            if(temp1->der!=NULL){
                completo(temp1->der,a);
            }else if(temp1->der==NULL || temp1->izq==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<temp1->num<<"||"<<endl;
            }

            if(temp1->izq!=NULL){
                completo(temp1->izq,a);
            }else if(temp1->izq==NULL || temp1->der==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<temp1->num<<"||"<<endl;
            }
        }
        if(temp2!=NULL){
            a++;
            if(temp2->der!=NULL){
                completo(temp1->der,a);
            }else if(temp2->der==NULL || temp2->izq==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<temp2->num<<"||"<<endl;
            }

            if(temp2->izq!=NULL){
                completo(temp1->izq,a);
            }else if(temp2->izq==NULL || temp2->der==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<temp1->num<<"||"<<endl;
            }
    }
    }
}
void mostrarinfo(arbol *aux){
    cout<<"valor de la raiz:"<<aux->num<<endl;
    if(Ebinario(aux)){
        cout<<"el arbol es estrictamente binario"<<endl;
    }else cout<<"el arbol NO es estrictamente binario"<<endl;
    if(completo(aux,0)){
        cout<<"el arbol es completo "<<endl;
    }else cout<<"el arbol NO es completo"<<endl;

}
int main()
{
    arbol *raiz=NULL;
    arbol *aux;
    arbol *nuevo;


    int op,bPosi;
    do{
        cout<<"------Menu-----"<<endl;
        cout<<"insertar 1:"<<endl;
        cout<<"mostrar arbol 2:"<<endl;
        cout<<"mostrar info arbol 3:"<<endl;
        cout<<"salir 4:"<<endl;
        cout<<"digite una opcion"<<endl;
        cin>>op;
            if(op<1 || op>4){
                cout<<"opcion invalida"<<endl;
            }else if(op==1){
                cout<<"digite el numero a ser insertado:"<<endl;
                nuevo=new arbol();
                cin>>nuevo->num;
                nuevo->der=NULL;
                nuevo->izq=NULL;
                if(raiz==NULL){
                    raiz=nuevo;
                }else{
                    aux=raiz;
                    bPosi=0;
                    while(bPosi==0){
                        if(nuevo->num<aux->num){
                            if(aux->izq==NULL){
                                aux->izq=nuevo;
                                bPosi=1;
                            }
                            else aux=aux->izq;
                        }
                        else if(nuevo->num>=aux->num){
                            if(aux->der==NULL){
                                aux->der=nuevo;
                                bPosi=1;
                            }else aux=aux->der;
                        }
                    }
                }
                cout<<"numero insertado :)"<<endl;
            }
            else if(op==2){
                if(raiz==NULL){
                    cout<<"Arbol vacio :c"<<endl;
                }else {
                    cout<<"Consultando en preorden:"<<endl;
                    preorden(raiz);
                    cout<<endl;
                }
        }
            else if(op==3){
                mostrarinfo(raiz);
            }

    }while(op!=4);
    return 0;
}

