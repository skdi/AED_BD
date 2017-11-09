#include <iostream>
#include <queue>
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
    if(raiz->izq!=NULL || raiz->der!=NULL){
        h++;
        if(raiz->izq!=NULL)
            altura(raiz->izq,h);
        if(raiz->der!=NULL)
            altura(raiz->der,h);
    }
    return h;



}


bool Ebinario(arbol *raiz){
    bool flag=1;
    if(raiz->izq!=NULL){//si tiene cadena izquierda
        if(raiz->izq->der!=NULL){//si tiene cadena derecha a partir del siguiente nivel
            Ebinario(raiz->izq->der);//recursividad para recorrer el sub arbol
        }else if(raiz->izq->der==NULL && raiz->izq->izq!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<raiz->izq->num<<"||"<<endl;
        }

        if(raiz->izq->izq!=NULL){
            Ebinario(raiz->izq->izq);
        }else if(raiz->izq->izq==NULL && raiz->izq->der!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<raiz->izq->num<<"||"<<endl;
        }
    }
    if(raiz->der!=NULL){
        if(raiz->der->der!=NULL){
            Ebinario(raiz->der->der);
        }else if(raiz->der->der==NULL && raiz->der->izq!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<raiz->der->num<<"||"<<endl;
        }

        if(raiz->der->izq!=NULL){
            Ebinario(raiz->der->izq);
        }else if(raiz->der->izq==NULL && raiz->der->der!=NULL){//en caso solo tenga 1 hijo
            flag=0;
            cout<<"||"<<raiz->der->num<<"||"<<endl;
        }
}
    return flag;
}


bool completo(arbol *raiz,int a=0){
    bool flag=1;
    int h=altura(raiz,0);
    if(a<=(h-2)){
        if(raiz->izq!=NULL){
            a++;
            if(raiz->izq->der!=NULL){
                completo(raiz->izq->der,a);
            }else if(raiz->izq->der==NULL || raiz->izq->izq==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<raiz->izq->num<<"||"<<endl;
            }

            if(raiz->izq->izq!=NULL){
                completo(raiz->izq->izq,a);
            }else if(raiz->izq->izq==NULL || raiz->izq->der==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<raiz->izq->num<<"||"<<endl;
            }
        }
        if(raiz->der!=NULL){
            a++;
            if(raiz->der->der!=NULL){
                completo(raiz->der->der,a);
            }else if(raiz->der->der==NULL || raiz->der->izq==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<raiz->der->num<<"||"<<endl;
            }

            if(raiz->der->izq!=NULL){
                completo(raiz->der->izq,a);
            }else if(raiz->der->izq==NULL || raiz->der->der==NULL){//en caso solo tenga 1 hijo
                flag=0;
                cout<<"||"<<raiz->der->num<<"||"<<endl;
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
