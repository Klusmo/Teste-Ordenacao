#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "StringSort.h"
#include "GerenciadorDeArquivos.h"
using namespace std;

char* arquivoSaida(int tamanho, int tipoOrd){
    char s[40];
    strcpy(s,"saida\\saida");
    if(tipoOrd == 1){
        strcat(s,"_bubbleSort");
    }else if(tipoOrd == 2){
        strcat(s,"_bubbleSortCVerif");
    }else if(tipoOrd == 3){
        strcat(s,"_selectionSort");
    }else if(tipoOrd == 4){
        strcat(s,"_insertionSort");
    }else if(tipoOrd == 5){
        strcat(s,"_mergeSort");
    }else if(tipoOrd == 6){
        strcat(s,"_heapSort");
    }else {
        strcat(s,"_quickSort");
    }

    if(tamanho == 1000){
        strcat(s,"_1000");
    }else if(tamanho == 5000){
        strcat(s,"_5000");
    }else if(tamanho == 10000){
        strcat(s,"_10000");
    }else if(tamanho == 15000){
        strcat(s,"_15000");
    }else if(tamanho == 20000){
        strcat(s,"_20000");
    }else if(tamanho == 30000){
        strcat(s,"_30000");
    }else {
        strcat(s,"_40000");
    }
    strcat(s,".txt");
    return s;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    GerenciaArquivo *base = new GerenciaArquivo();
    StringSort *sorter;
    clock_t t;
    int op, tamanho;
    double tempo;
    bool valida;
    char *s;

    do{
        cout<<"Teste de Ordenação"<<endl;
        cout<<"Escolha o tamanho da base de dados"<<endl;
        cout<<" 1000 palavras"<<endl;
        cout<<" 5000 palavras"<<endl;
        cout<<"10000 palavras"<<endl;
        cout<<"15000 palavras"<<endl;
        cout<<"20000 palavras"<<endl;
        cout<<"30000 palavras"<<endl;
        cout<<"40000 palavras"<<endl;
        cout<<"0 - sair"<<endl;
        cin>>tamanho;
        if(tamanho!=1000 &&tamanho!=5000 &&tamanho!=10000 &&tamanho!=15000 &&tamanho!=20000 &&tamanho!=30000 &&tamanho!=40000 &&tamanho!=0)
            cout<<"Entrada invalida"<<endl;

    }while(tamanho!=1000 &&tamanho!=5000 &&tamanho!=10000 &&tamanho!=15000 &&tamanho!=20000 &&tamanho!=30000 &&tamanho!=40000 &&tamanho!=0);
    if(tamanho!=0){
        base->setTamanho(tamanho);
        base->loadBase();
        sorter = new StringSort(base->getPalavras(), tamanho);
        cout<<endl<<"Base de dados Carregada"<<endl;
        system("pause");
        system("cls");

        do{
            cout<<"Teste de Ordenação"<<endl;
            cout<<"Escolha o Metodo de ordenação"<<endl;
            cout<<"1 - Bubblesort"<<endl;
            cout<<"2 - Bubblesort com verificação"<<endl;
            cout<<"3 - Selection sort"<<endl;
            cout<<"4 - Insertion sort"<<endl;
            cout<<"5 - Merge sort"<<endl;
            cout<<"6 - Heap sort"<<endl;
            cout<<"7 - Quick sort"<<endl;
            cout<<"0 - sair"<<endl;
            cin>>op;
            valida=true;
            switch(op){
                case 1:
                    t = clock();
                    //bubbleSort
                    sorter->Bubblesort();
                    t = clock()- t;
                    break;
                case 2:
                    t = clock();
                    //bubbleSort com verificação
                    sorter->BubblesortCVerif();
                    t = clock()- t;
                    break;
                case 3:
                    t = clock();
                    //SelectionSort
                    sorter->Selectionsort();
                    t = clock()- t;
                    break;
                case 4:
                    t = clock();
                    //InsertionSort
                    sorter->Insertionsort();
                    t = clock()- t;
                    break;
                case 5:
                    t = clock();
                    //MergeSort
                    sorter->Mergesort();
                    t = clock()- t;
                    break;
                case 6:
                    t = clock();
                    //HeapSort
                    sorter->Heapsort();
                    t = clock()- t;
                    break;
                case 7:
                    t = clock();
                    //QuickSort
                    sorter->Quicksort();
                    t = clock()- t;
                    break;
                case 0:
                    valida = false;
                    cout<<"saindo..."<<endl;
                    break;
                default:
                    cout<<"Operador invalido"<<endl;
                    valida = false;
                    break;
            }
            if(valida){
                tempo = (float) t/CLOCKS_PER_SEC;
                cout<<"Tempo de execução da ordenação: "<<tempo<<" segundos"<<endl;
                s= new char(strlen(arquivoSaida(tamanho, op)));
                strcpy(s,arquivoSaida(tamanho,op));
                base->salvar(s);
                cout<<"Arquivo "<<s<<" salvo"<<endl;
                system("Pause");
                system("cls");
            }
        }while(op!=0);
    }
    return 0;
}
