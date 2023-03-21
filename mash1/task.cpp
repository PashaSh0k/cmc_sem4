#include<iostream>
using namespace std;
class Arr{
    int *arr;
    int size;
    public:
        Arr(int s, int date = 0): size(s){
            arr = new int[s]; 
            for(int i = 0; i < size; arr[i++] = date);
        }
        Arr(const Arr &a){
            size = a.size;
            arr = new int[size];
            for(int i = 0; i < size; i++)
                arr[i] = a.arr[i];
        }
        Arr(Arr &&a){
            size = a.size;
            arr = a.arr;
            a.arr = nullptr;
            cout << "constr move" << '\n';
        }
        Arr& operator= (Arr && a){
            if(&a != this)
                delete []arr;
            size = a.size;
            arr = a.arr;
            a.arr = nullptr;
            cout << "operator move" << '\n';
            return *this;
        }
        ~Arr(){
            delete[] arr;
        }
        int& operator[](int i){
            return arr[i];
        }
        Arr& operator= (const Arr& a);
        friend ostream& operator << (ostream &out, const Arr &a);
        friend Arr operator& (const Arr& a1, const Arr& a2);
        friend Arr operator& (const Arr& a1, const int n);
        friend Arr operator! (const Arr& a);
};

Arr & Arr::operator= (const Arr &a){
    size = a.size;
    delete[] arr;
    arr = new int [a.size];
    for(int i = 0; i < a.size; i++){
        arr[i] = a.arr[i];
    }
    return *this;
}
ostream& operator << (ostream& out, const Arr &a){
    for(int i = 0; i < a.size; i++)
        out << a.arr[i] << ' ';
    out << '\n';
    return out;
}

Arr operator&(const Arr& a1, const Arr& a2){
    Arr a = a1;
    int min;
    if(a1.size <= a2.size)
        min = a1.size;
    else
        min = a2.size;
    for(int i = 0; i < min; i++){
        a.arr[i] = a1.arr[i] + a2.arr[i];
    }
    return a;
}
Arr operator&(const Arr& a1, const int n){
    Arr a = a1;
    for(int i = 0; i < a1.size; i++){
        a.arr[i] = a1.arr[i] * n;
    }
    return a;
}
Arr operator!(const Arr& a){
    Arr a1 = a;
    for(int i = 0; i < a.size; i++)
        a1.arr[i] = a.arr[i] + 1;
    return a1;
}

int main(){
   Arr a1(5), a2(10,1), a3(4,2);
   const Arr a4(5);
   cout << a1 << a2 << a3 << a4 << '\n';
   a2 = a2 & 2;
   a3 = (!a2) & a3;
   a1 = a4 & a3;
   a1[1] = 100;
   cout << a1 << a2 << a3 << a4;
   return 0;
}