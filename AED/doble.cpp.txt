#include <iostream>
using namespace std;

class nodo{
private:
    int valor;
public:
    nodo *sig;
    nodo *ant;
    nodo(int val){
        this->valor=val;
        this->sig=NULL;
        this->ant=NULL;
    }
    int getvalor(){
        return this->valor;
    }
};
class listadoble{
private:
    nodo *head;
    nodo *tail;
public:
    listadoble(){
        head=tail=NULL;
    }
    bool vacio(){
        return (head==NULL);
    }
    void iinicio(int val){
        nodo *temp=new nodo(val);
        if(vacio())
            head=tail=temp;
        else{
            temp->sig=head;//temp apunta al anterior head
            head->ant=temp;//temp llega a la primera posicion
            head=temp;//cambiamos la etiqueta de head
        }
    }
    void ifinal(int val){
        nodo *temp=new nodo(val);
        if(vacio())
            head=tail=temp;
        else{
            tail->sig=temp;//temp llega a la ultima posicion
            temp->ant=tail;//temp apunta al anterior tail
            tail=temp;//cambiamos la etiqueta de tail
        }
    }
    void einicio(){
        if(vacio())
            cout<<"lista vacia, no se puede eliminar"<<endl;
        else{
            if(head==tail)//si hay un solo elemento ,se eliminara
                head=tail=NULL;
            else{
                nodo *temp=head;//guardo copia del header
                head=head->sig;//translado la etiqueta de head a la sig posicion
                head->ant=NULL;//eliminamos el enlace al anterior
                delete temp;//borramos la direccion y el valor de temp
                cout<<"elemento eliminador"<<endl;
            }
        }

    }
    void efinal(){
        if(vacio())
            cout<<"lista vacia,no se puede eliminar"<<endl;
        else{
            if(head==tail)//si hay un solo elemento ,se eliminara
                head=tail=NULL;
            else{
                nodo *temp=tail;
                tail=tail->ant;
                tail->sig=NULL;
                delete temp;
                cout<<"elemento eliminado"<<endl;
            }
        }
    }
    void imprimir(){
        if(vacio())
            cout<<"lista vacia,no se puede mostrar algun elemento"<<endl;
        else{
            nodo *temp=head;//tomamos la primera posicion
            cout<<endl;
            while(temp->sig!=NULL){//condicional para el recorrido
                cout<<temp->getvalor()<<"  ";//imprimimos el valor actual
                temp=temp->sig;//actualizamos posicion
            }
            cout<<temp->getvalor()<<"  ";
            cout<<endl;

        }
    }
};



int main()
{
    listadoble *doble=new listadoble();
    doble->iinicio(5);
    doble->iinicio(7);
    doble->iinicio(3);
    doble->ifinal(8);
    doble->imprimir();
    return 0;
}







