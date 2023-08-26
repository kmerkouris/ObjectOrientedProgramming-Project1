#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

class Book
{
                string title;
                string writerName;
                int ISBN;
    public:
                Book(string t ,string w,int i):title(t),writerName(w),ISBN(i)
                {
                        cout<<"creating a book"<<endl;
                }
                ~Book(){cout<<"destroying a book"<<endl;};
                void print();

};
class Shelf
{   
                
                Book** books;
                int counter;
                int nmax;
    public:
                Shelf(int nMax):nmax(nMax)
                {
                        counter=0;
                        books=new Book*[nMax];
                        for(int i=0;i<nMax;i++)
                        {
                              books[i]=nullptr;
                        }
                        cout<<"creating a shelf"<<endl;
                }
                ~Shelf(){
                        
                        delete[] books;
                        cout<<"destroying shelf"<<endl;}
                bool place_book(Book *book);
                bool take_book(void);
                void print();
};

class Cabinet  
{
                Shelf up;
                Shelf down;       
    public:
                Cabinet(int nMax):up(nMax),down(nMax)
                {
                        cout<<"creating a cabinet"<<endl;
                }
                ~Cabinet(){cout<<"destroying cabinet"<<endl;}
                bool place_book(Book *book,int n);
                bool take_book(int n);
                void print();
};

class Base
{
    public:
            Base(){cout<<"creating a Base"<<endl;}
            ~Base(){cout<<"destroying a  base"<<endl;}
};

class Library 
{ 
        Base base;
        Cabinet cab;
        Shelf top,mid,bot;
                
               
    public:
                Library(int nMax):top(nMax),mid(nMax),bot(nMax),cab(nMax) 
                {cout<<"creating a Library"<<endl;}
                ~Library(){cout<<"destroying Library "<<endl;}
                
                bool place_book(Book *book,int n);
                bool take_book (int n);
                void print();


        

};






