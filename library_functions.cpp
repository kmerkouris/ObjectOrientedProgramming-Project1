#include <iostream>
#include <string.h>
#include <cstring>
#include "library_constr.h"

using namespace std;


//////////////////////////////place_book////////////////////////////////
bool Shelf::place_book(Book *book)
{
    
    if (counter<nmax)           // if counter >= nmax there is no space for other books  
    {
        books[counter]=+book; // put a book into the books array
        counter++;
        cout<<"place a book :"<<endl;
        
        return true;
    }   
    else 
    {
        cout<<"!no more space to place!"<<endl;
        return false;
    }    
    
}

bool Cabinet::place_book(Book *book,int n ) 
{
   if (n==1)            //check the position and print the message
   {
       up.place_book(book);
       cout<<"placing book in top bookcase shelf of cabinet"<<endl;
       
       return true;
   }   
   else if (n==2)      //same check 
   {
        down.place_book(book);
        cout<<"placing book in bottom bookcase shelf"<<endl;
        
        return true;
   }
   else
   {
       return false;

   }
}

bool Library::place_book(Book *book,int n)   //in this place_book check which shelf is the pos and go there 
{
    
    if (n==1)
    {
        top.place_book(book);
        cout<<"placing book in top bookcase shelf"<<endl;
        
        return true;     
    }
    else if (n==2)
    {
        mid.place_book(book);
        cout<<"placing book in middle bookcase shelf"<<endl;
        

        return true;
    }
    else if (n==3)
    {
        bot.place_book(book);
         cout<<"placing book in bottom bookcase shelf"<<endl;
                
         return true;
    }       
    if (n==4)
    {   
        cab.place_book(book,1);
        return true;

        
    }
    if (n==5)
    {
        cab.place_book(book,2);
        return true;
        
        
    }
    else {
        return false;
    }
}
//////////////////////////////////////////////////////////////////////////

///////////////////take_book//////////////////////////////////////////////
bool Shelf::take_book(void)
{
    
    if(books[counter] != nullptr && counter!=0)
    {
        books[counter]=nullptr;
        cout<<"take a book:"<<endl;
        counter--;
        return true;
    }
    else 
    {
        cout<<"!no more books to take!"<<endl;
        return false;
    }
}

bool Cabinet::take_book(int n)
{
    if (n==1)
    {
        up.take_book();
        cout<<"taking book in top bookcase shelf of cabinet "<<endl;
        
        return true;
        
    }
    else if(n==2)
    {
        down.take_book();
        cout<<"taking book in bottom bookcase shelf of cabinet"<<endl;
        
        return true;
    }
    else{
        return false;
    }
}

bool Library::take_book(int n )
{
    if (n==1)
    {
        top.take_book();
        cout<<"taking book in top bookcase shelf"<<endl;
       
        return true;
    }
    else if (n==2)
    {
        mid.take_book();
         cout<<"taking book in middle bookcase shelf"<<endl;
         
         return true;
    }
    else if (n==3)
    {
        bot.take_book();
        cout<<"taking book in bottom bookcase shelf"<<endl;
        
        return true;

    }
    else if (n==4)
    {
        cab.take_book(1);
        return true;
    }
    else if (n==5)
    {
        cab.take_book(2);
        return true;
    }
    else
    {
        return false;
    }
    
    
}





//////////////////////////////////////////////////////////////////////////

///////////////////////print//////////////////////////////////////////////
void Book::print()
{
    
    cout<<"title:"<<title<<",writer:"<<writerName<<",ISBN:"<<ISBN<<endl;

}
 
void Shelf::print()
{
    
    for (int i = 0; i < counter; i++)
    {

        books[i]->print();
    }
    
}

void Cabinet::print()
{
    cout<<"4. up shelf of cabinet:"<<endl;
    up.print();
    cout<<"5. down shelf of cabinet:"<<endl;
    down.print();



}


void Library::print()
{
    cout<<"1. top shelf :"<<endl;
    top.print();
    cout<<"2. middle shelf :"<<endl;
    mid.print();
    cout<<"3. bot shelf :"<<endl;
    bot.print();
    
    cab.print();
    
}
// ////////////////////////////////////////////////////////////////////////////