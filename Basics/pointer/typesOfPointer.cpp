#include<bits/stdc++.h>
using namespace std;
int main(){
  

//  Types of pointers in C++ => 
 

// There are different types of pointers in C++, and they are as follows:

// Null Pointers
// Double Pointers
// Void Pointers
// Wild Pointers
// Dangling Pointer
 
/*

1. Null Pointers: 
A NULL pointer is a pointer that is pointing to nothing. If we don’t have the address to be assigned to a pointer, we can use NULL.

 

Advantages of Null pointer are:

We can initialize a pointer variable when that pointer variable is not assigned any actual memory address.
We can pass a null pointer to a function argument when we are unwilling to pass any actual memory address.
 

Example:

int *p; //Contains garbage value
int *p = NULL; //NULL is constant with vaue 0
int *q = 0; // Same as above
 

Here, we have created a pointer variable that contains garbage values. To dereference the pointer, we have initialized it to NULL to avoid unexpected behavior.

 

Note: An uninitialized pointer variable contains garbage; this will lead to unexpected results or segmentation faults. Hence, we should never leave a pointer uninitialized and instead.

 

Example:

#include <iostream>
using namespace std;
int main() {
    // Null Pointer 
    int * ptr = NULL;
    cout << "The value of ptr is " << ptr;
    return 0;
}
Output:
The value of ptr is 0

 */

 
/*
2. Double Pointers:  
We can create a pointer to a pointer that in turn may point to data or another pointer. The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double pointers.

 

Example:

int a = 10;
int *p = &a; 
int **q = &p;
 

Here q is a pointer to a pointer, i.e., a double-pointer, as indicated by **.
*/
 


// Example:

// #include<iostream>
// using namespace std;
// int main() {
//     int a = 10;
//     int * p = & a; //pointer
//     int ** q = & p; //pointer-to-pointer
//     /* Next three statements will print same value i.e. address of a */
//     cout << & a << endl;
//     cout << p << endl;
//     cout << * q << endl;
//     /* Next two statements will print same value i.e. address of p */
//     cout << & p << endl;
//     cout << q << endl;
//     /* Next three statements will print same value i.e. value of a */
//     cout << a << endl;
//     cout << * p << endl;
//     cout << ** q << endl;
//     return 0;
// }
// Output:
// 0x7ffcab7af9ac
// 0x7ffcab7af9ac
// 0x7ffcab7af9ac
// 0x7ffcab7af9b0
// 0x7ffcab7af9b0
// 10
// 10
// 10

 

 

// 3. Void Pointers:
// A void pointer is a generic pointer; it has no associated type with it. A void pointer can hold an address of any type and can be typecasted to any type. Thus we can use the void pointer to store the address of any variable.

// Void pointer is declared by: 

// void *ptr;
 

// Note:

// 1. void pointers cannot be dereferenced. It can, however, be done using typecasting the void pointer.

// 2. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and size.

 

// Example:

// #include <iostream>
// using namespace std;
// int main() {
//     void * ptr;
//     int i = 10;
//     // assign int address to void
//     ptr = & i;
//     cout << "Address of variable i " << & i << endl;
//     cout << "Address where the void pointer is pointing " << ptr <<  endl;
//     return 0;
// }
// Output:
// Address of variable i 0x7ffc848c25f4
// Address where the void pointer is pointing 0x7ffc848c25f4
 

 

// 4. Wild Pointers:
//  A pointer behaves like a wild pointer when declared but not initialized. So, they point to any random memory location.

 

// Example:

// int *ptr; //wild pointer
// *ptr = 5;
 

// Note: If a pointer p points to a known variable, it’s not a wild pointer.

 

// Example:

// int * p; /* wild pointer */
// int a = 10;
// p = & a; /* p is not a wild pointer now*/
// * p = 12; /* This is fine. Value of a is changed */
 

// In the above program, p is a wild pointer till this points to a.

 

 

// 5. Dangling Pointers:
// A dangling pointer is a pointer pointing to a memory location that has been freed (or deleted). There are three different ways where Pointer acts as a dangling pointer.

 

// a)Function Call

// The pointer pointing to the local variable becomes dangling when the local variable is not static.

// Example:

// #include<iostream>
// using namespace std;
// int * fun() {
//     int x = 10;
//     return &x;
// }
// int main() {
//     int * p = fun();
//     // p points to something which is not 
//     // valid anymore 
//     cout << * p;
//     return 0;
// }
 

// b) Deallocation of memory

// Deallocating a memory pointed by a pointer causes a dangling pointer.

// Example:

// #include<iostream>
// using namespace std;
// int main() {
//     //dynamic memory allocation.
//     int * p = (int * ) malloc(sizeof(int));
//     //after calling free() p becomes a dangling pointer
//     free(p);
//     //now p no more a dangling pointer.
//     p = NULL;
//     return 0;
// }
 

// c) Variable goes out of scope

// When a pointer goes out of scope where it is valid, then it becomes a dangling pointer.

// Example:

// #include<iostream>
// using namespace std;
// void main() {
//     int * ptr;
//     ..... //any code statements
//     {   int ch;
//         ptr = & ch;
//     }
//     ....
//     // Here ptr is dangling pointer
// }
}