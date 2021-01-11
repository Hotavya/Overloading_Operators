#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array
{
    
private:
    int *ptr;
    int size;
    static int Elements;

public:
    
    Array();                    //Default Constructor
    
    Array (int);                //Overloaded Constructor
    
    ~Array();                   //Destructor
    
    Array (const Array &);      //Copy Constructor
    
    bool operator == (const Array &);   //Overloading == operator
    
    bool operator < (const Array &);    //Overloading < operator
    
    Array operator!();                  //Overloading ! operator
    
    int operator * ();                  //Overloading * operator
    
    Array& operator += (const Array &); //Overloading += operator
    
    static int getNumberOfElements();   //Static memeber function
    
    friend ostream &operator << (ostream &, const Array &);
                                        //Overloading << operator
    
    Array operator++(int);              //Overloading ++ operator
    
    Array operator--();                 //Overloading -- operator
    
    Array& operator = (const Array &);  //Overloading = operator
    
    int &operator[](const int &);       //Overloading [] operator
       
     int getSize()const;                //Return value of size
                                        //variable of object
    
};


#endif
