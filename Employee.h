#ifndef __Employee_H__
#define __Employee_H__
#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    string position;
    int age;
    Employee()
    {
        name = "";
        position = "";
        age = 0;
    }
        
    Employee(string var1, string var2, int var3)
    {
        name = var1;
        position = var2;
        age = var3;
    }
    
    friend ostream & operator << (ostream & s, Employee a)
    {
        s << a.name << " " << a.position << " " << a.age;
        return s;
    }
    
};


#endif /* __Employee_H__ */
