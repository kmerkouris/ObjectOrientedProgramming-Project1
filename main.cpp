#include <iostream>
#include <string.h>
#include <cstring>
#include "library_constr.h"
#include <time.h>


using namespace std;



int pos()
{ 
    
    return rand()%5+1;
}

int main (int argc,char* argv[])
{
    srand(time(NULL));
    
    int pos();
    
    int nMax=std::atoi(argv[1]);
    int L=std::atoi(argv[2]);
    int K1=std::atoi(argv[3]);
    int K2=std::atoi(argv[4]);
    
    
    Book** book;
    book=new Book*[L];
    Library lib (nMax);
    
 
    
    lib.print();
    for (int i=0;i<L;i++)
    {
        
        book[i]=new Book("w","n",rand());
        
        
    }
    for (int k=0;k<K1;k++)
    { 
        int curPos=rand()%L;
        lib.place_book( book[curPos],pos());
                
    } 
    
    for(int t=0;t<K2;t++)
    {
        
        lib.take_book(pos());
    }

    lib.print();

    for (int i = 0; i < L; i++)
    {
        delete book[i];
    }
     delete[] book;
    
}
