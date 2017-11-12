#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "GerenciadorDeArquivos.h"
using namespace std;

//Privado
char* GerenciaArquivo::seleciona(){
    if(tamanho==1000){
        return "basePalavras\\aurelio1000.txt";
    }else if(tamanho==5000){
        return "basePalavras\\aurelio5000.txt";
    }else if(tamanho==10000){
        return "basePalavras\\aurelio10000.txt";
    }else if(tamanho==15000){
        return "basePalavras\\aurelio15000.txt";
    }else if(tamanho==20000){
        return "basePalavras\\aurelio20000.txt";
    }else if(tamanho==30000){
        return "basePalavras\\aurelio30000.txt";
    }else{
        return "basePalavras\\aurelio40000.txt";
    }
}

//Publico

GerenciaArquivo::GerenciaArquivo(){
    palavras = 0;
}

GerenciaArquivo::~GerenciaArquivo(){
    delete []
     palavras;
}

void GerenciaArquivo::loadBase(){
    ifstream ifs;
    ifs.open(seleciona()); // Tenta abrir o arquivo que está entre aspas
    if(ifs.is_open()){ // Se conseguiu abrir o arquivo
        palavras = new (nothrow) char*[tamanho]; // Tenta alocar um vetor de 1000 posições de ponteiros para caracter
        for(int j=0; j<tamanho; j++)
            palavras[j] = 0;

        if(palavras){
            int i=0;
            char p[30];

            while(ifs.good()){
                ifs >> p; // lê cada palavra do arquivo e copia para a variável p

                palavras[i] = new (nothrow) char[strlen(p)+1];
                if(palavras[i]){
                    strcpy(palavras[i], p);
                    cout << endl << i+1 << " - " << palavras[i] << " ";
                    i++;
                }else{
                    cout << "\nNao conseguiu alocar memoria para a palavra " << p;
                    exit(1);
                }
            }
        }else
            cout << "\nNão conseguiu alocar memória para o vetor de ponteiros para caracter";

        ifs.close(); // Fecha o arquivo
    }else
        cout << "\nNão abriu!";
}

void GerenciaArquivo::salvar(char *nomeSaida){
    // Copia cada palavra de palavras no arquivo de saida
    ofstream ofs(nomeSaida);
    if(ofs.is_open()){
        for(int i=0; i<tamanho; i++){
            ofs << i+1 << " - " << palavras[i] << '\n'; // Insere cada palavra em uma nova linha
        }
        ofs.close();
    }else
        cout << "\nNão abriu arquivo para saída!";
}

void GerenciaArquivo::setTamanho(int _tamanho){
    tamanho = _tamanho;
}

char** GerenciaArquivo::getPalavras(){
    return palavras;
}



