#ifndef GERENCIADORDEARQUIVOS_H_INCLUDED
#define GERENCIADORDEARQUIVOS_H_INCLUDED

class GerenciaArquivo{
private:
    char **palavras;
    int tamanho;
//Metodos Privados
    char* seleciona();
public:
    GerenciaArquivo();
    ~GerenciaArquivo();

    void loadBase();
    void salvar(char *nomeSaida);

    char** getPalavras();
    void setTamanho(int _tamanho);
};

#endif // GERENCIADORDEARQUIVOS_H_INCLUDED
