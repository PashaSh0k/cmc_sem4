#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename cont>
void print(cont &vect){
    typename cont::const_iterator iter1 = vect.begin();
    typename cont::const_iterator iter2 = vect.end();
    while(iter1 != iter2){
        cout << *iter1 << ' ';
        ++iter1;
    }
    cout << "\n";
    typename cont:: const_reverse_iterator iter3 = vect.rbegin();
    typename cont:: const_reverse_iterator iter4 = vect.rend();
    while(iter3 != iter4){
        cout << *iter3 << ' ';
        ++iter3;
    }  
    cout << endl;
} 
template <typename T>
void func(vector <T>&V, list <T> &L){
    int i = 0;
    while(i <= V.size() && (L.size() > 2)){
        L.pop_front();
        V.insert(V.begin()+i+1, L.front());
        L.pop_front();
        i+= 3;
    }
}
template <typename T>
void func1(vector <T>&V){
    int i = 0;
    while(i < V.size()){
        V.insert(V.begin()+i, *(V.begin()+i));
        i+=3;
    }
}
template <typename T>
void func2(list <T>&L){
    int i = 0;
    typename list<T>::iterator iter = L.begin();
    while(i < L.size()){
        L.insert(iter, *iter);
        ++iter;
        ++iter;
        i+=3;
    }
}
int main(){
    vector<int> vec = {1,2}, *pvec = &vec;
    list<int> L = {5,6,7,8,9,10,11}, *pL = &L;
    //const vector<int> cvec = {0,1,2,3,4}, *pcvec = &cvec;
    
    print(*pvec);
    print(*pL);
    //print(*pcvec);


    //func(*pvec, *pL);
    //print(*pvec);

    func1(*pvec);
    print(*pvec);

    func2(*pL);
    print(*pL);
    return 0;
}