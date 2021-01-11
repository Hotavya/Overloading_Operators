
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

int Array::Elements = 0;

/*======================================
 DEFAULT CONSTRUCTOR
 Receives Nothing. It initalizes the
 object's variables if no argument is
 passed during initalization. Doesn't
 return anything.
 =======================================*/
Array::Array()
{
    size = 0;
    ptr = nullptr;
    Elements += size;
    
}

/*==========================================
OVERLOADED CONSTRUCTOR
Receives an integer argument that represents
the size of the array. The size is used
to dynamically allocate an array of integers
 Return Nothing.
===========================================*/
Array::Array(int s)
{
    size = s;
    ptr = new int[size];
    Elements +=s;
    
}

/*======================================
DESTRUCTOR
Receives Nothing. The destructor frees
the dynamically allocated array and also
subtracts the size from the total element
count. Returns Nothing.
=======================================*/
Array::~Array()
{
    delete [] ptr;
    Elements -= size;
    
}

/*======================================
COPY CONSTRUCTOR
The copy constructor recevies a const
Array object by reference. It initalizes
the calling objects with the parameter's
values. Returns Nothing.
=======================================*/
Array::Array(const Array &obj)
{
    size = obj.size;
    ptr = new int [size];
    
    for (int i = 0; i < size; i++ )
    {
        ptr [i] = obj.ptr[i];
    
    }
    Elements += size;
}

/*=======================================
OVERLOADING == OPERATOR
Receives a const Array object by reference.
Function checks and returns true if one
array object is an in-order subset of
another Array object else returns false.
=========================================*/
bool Array::operator == (const Array &obj)
{
    int s;
    bool status;
    
    if ( size <= obj.size)
        s = size;
    else
        s = obj.size;
    
    for (int i = 0; i < size; i++ )
    {
        if ( ptr[i] == obj.ptr[i])
            status = true;
        else
            return false;
    }
    return status;
    
}

/*==========================================
OVERLOADING < OPERATOR
Receives a const Array object by refernce.
Compares two array objects element-by-element.
Returns a boolean value.
============================================*/
bool Array::operator < (const Array &obj)
{
    bool status;
    int num = 0;
    
    for (int i = 0; i < size; i++ )
    {
        if (ptr [i] < obj.ptr[i])
            return true;
        else if (ptr [i] > obj.ptr[i] )
            return false;
        else
        {
            if (ptr [i] == obj.ptr[i])
            {
                status = true;
                num++;
            }
        }
    if ( num == size)
        status = false;
    }
    return status;
}

/*======================================
OVERLOADING ! OPERATOR
Receives Nothing. This function randomly
shuffles all the elements in the array.
Returns an Array object.
=======================================*/
Array Array::operator!()
{
        srand(time(NULL));
        int x1, y1;
        int temp;
        
        for (int i = 0; i < size; i++)
        {
            x1 = rand() % size;
            y1 = rand() % size;
            
            temp = ptr[x1];
            ptr[x1] = ptr[y1];
            ptr[y1] = temp;
        
        }
        return *this;
}

/*======================================
OVERLOADING * OPERATOR
Receives Nothing. This function finds
and returns the smallest value in the
caling object's array. Returns an integer
equivalent to the value of the smallest
number in array.
=======================================*/
int Array::operator *()
{
    int smallest = ptr[0];
    
    for (int i = 1; i < size; i++)
    {
        if (ptr [i] < smallest )
            smallest = ptr [i];
    }
    return smallest;
    
}

/*==========================================
OVERLOADING += OPERATOR
Receives a const Array object by reference.
Extends left hand object to include elements
of right hand object. Returns an Array object
by reference.
============================================*/
Array& Array::operator += (const Array &obj)
{
    int s = size + obj.size;
    Array temp(s);
    
    for (int i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    
    int i = s - obj.size;
    for (int j = 0; j < obj.size; j++)
    {
        temp.ptr[i] = obj.ptr[j];
        i++;
        
    }
    *this = temp;
    return *this;
}

/*======================================
STATIC FUNCTION
Receives Nothing. This function returns
the value of Elements (total elements).
 It returns an integer
=======================================*/
int Array::getNumberOfElements()
   { return Elements;}

/*====================================
ACCESSOR FUNCTION FOR SIZE
Receives Nothing. Returns an integer
representing the value of an object's
 size variable.
=====================================*/
int Array::getSize()const
{ return size;}

/*======================================
OVERLOADING << OPERATOR
Recveives an ostream reference object &
a const Array object as reference. It
displays the values stored in the object's
array & returns a reference to an ostream
object.
=======================================*/
ostream &operator << (ostream &strm, const Array &obj)
{
    for (int i = 0; i < obj.size; i++)
        strm << obj.ptr[i] << " ";
    cout << endl;
    return strm;
}

/*======================================
OVERLOADING ++ OPERATOR
Receives an integer parameter. Increments
all the values in the object's array by 1.
Returns an Array object.
=======================================*/
Array Array::operator++(int)
{
    Array temp(*this);

    for (int i = 0; i < size; i++)
        ptr[i]++;
     
    return temp;
}

/*======================================
OVERLOADING -- OPERAOTR
Receives Nothing. Decrements the values
in the object's array by 1. Returns an
Array object.
=======================================*/
Array Array::operator--()
{
    for (int i = 0; i < size; i++)
        ptr[i] -= 1;
        
    return *this;
    
}

/*========================================
OVERLOADING = OPERATOR
Receives a const Array object by reference.
It initalizes the calling objects with the
parameter's values appropriately and also
adds and subtracts from total elements.
Returns an Array object by reference.
==========================================*/
Array & Array:: operator = (const Array &obj)
{
    if (this != &obj)
    {
        Elements -= size;
        delete [] ptr;
        size = obj.size;
        ptr = new int [size];
        
        for (int i = 0; i < size; i++)
        {
            ptr [i] = obj.ptr[i];
        }
    Elements += size;
    }
   return *this;
}


/*======================================
OVERLOADING [] OPERATOR
Receives a const integer by reference.
Returns an integers which equivalent to
the value stored in the object's array
at the given index.
=======================================*/
int& Array::operator[](const int &a)
{
    return ptr[a];
}








        






    
        

