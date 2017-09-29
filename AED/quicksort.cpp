#include <iostream>

using namespace std;
void quicksort(int *arr,int izq,int der){
    int i=izq,j=der,tmp;
    int p=arr[(izq+der)/2];//pivot
    while(i<j){
        while(arr[i]<p) i++;//recorrido de los indices
        while(arr[j]>p) j--;
        if(i<=j){
            tmp=arr[i];//intercambio para la ordenacion
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;j--;
        }
    }
    //llamado recursivo para el ordenamiento de los arreglos
    if(izq<j)
        quicksort(arr,izq,j);
    if(i<der)
        quicksort(arr,i,der);
}
void Imprimir(int *arr , int n){

    cout<<"Elementos Ordenados"<<endl;

    for(int i =0 ;i<n;i++){

        cout<<"["<<arr[i]<<"]";


    }
}
int main()
{
    int arr[10]={4,2,6,8,1,0,3,6,7,9};
    Imprimir(arr,10);
    cout<<endl;
    quicksort(arr,0,9);
    Imprimir(arr,10);
    return 0;
}
