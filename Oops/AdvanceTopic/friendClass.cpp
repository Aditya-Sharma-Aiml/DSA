#include <bits/stdc++.h>
using namespace std;


class Anyclass{
  
  private:
  int private_var = 111;
  
    // We can declare friend class or function anywhere in the base class body whether its private, protected or public block. It works all the same.
    friend class Dost;


  protected:
    int protected_var = 222;
  
  public:
    int public_var = 222;
    
};
class Dost{
  
  public:
  
  void display(Anyclass &obj){
    
    cout << "private_var: " << obj.private_var << endl;
    cout << "protected_var: " << obj.protected_var << endl;
    cout << "public_var: " << obj.public_var << endl;
    
    obj.private_var *= 100;
    obj.protected_var *= 100;
    obj.public_var *= 100;
    
    cout << "private_var: " << obj.private_var << endl;
    cout << "protected_var: " << obj.protected_var << endl;
    cout << "public_var: " << obj.public_var << endl;
   
  }
};
int main() 
{
    Dost d1;
    Anyclass A;
    d1.display(A);
    return 0;
}