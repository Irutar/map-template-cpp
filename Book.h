#ifndef __Book_H__
#define __Book_H__
#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    string author;
    string category;
    int pages;
	string status;
    Book()
    {
        author = "";
        category = "";
        pages = 0;
        status = "";
    }
        
    Book(string var1, string var2, int var3, string var4)
    {
        author = var1;
        category = var2;
        pages = var3;
        status = var4;
    }
    
    friend ostream & operator << (ostream & s, Book a)
    {
        s << a.author << " " << a.category << " " << a.pages << " " << a.status;
        return s;
    }
    
};


#endif /* __Book_H__ */
