#ifndef STRINGSORT_H_INCLUDED
#define STRINGSORT_H_INCLUDED

class StringSort{
private:
    char **palavras;
    int tamanho;
public:
    StringSort(char **_palavras,int _tamanho);
    void Bubblesort();
    void BubblesortCVerif();
    void Selectionsort();
    void Insertionsort();
    void Mergesort();
    void Heapsort();
    void Quicksort();
};

#endif // STRINGSORT_H_INCLUDED
