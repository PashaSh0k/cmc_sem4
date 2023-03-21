#include<iostream>
using namespace std;
class A{
    int a;
    A(int i = 0): a(i){} 
    A(const A& b){
        a = b.a;
    }
    public:
        static A* x;
        static int count;
        static A* getobj(int i = 0){
            if(count == 0){
                x = new A(i);
                count++;
            }
            return x;
        }
        void print() const{
            cout << a << "\n";
        }
};
A* A::x;
int A::count = 0;
int main(){
    A * first = A::getobj(10);
    A * second = A::getobj(5);
    first->print();
    second->print();
    delete A::x;
    return 0;
}