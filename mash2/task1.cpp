#include<iostream>
using namespace std;

class A{
    int a;
    ~A(){cout << "destr\n";}
    public:
        A(int i = 5): a(i){};
        void print() const{
            cout << a << "\n";
        }
        void dell(A* x){x->~A();}
};
int main(){
    void *x = operator new (5*sizeof(A));
    A *ptr = (A*)x;
    for(int i = 0; i < 5; i++){
        A *y = new (ptr) A(i);
        y->print();
        ptr = ptr + 1;
    }
    ptr = (A*)x;
    //delete
    for(int i = 0; i < 5; i++){
        ptr->dell(ptr);
        ptr = ptr + 1;
    }
    delete (char*)x;
    return 0;
}