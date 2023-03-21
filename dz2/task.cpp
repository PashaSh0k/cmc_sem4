#include<iostream>
using namespace std;
class bank{
    private:
        int account_number;
        char* name;
        char* create_time;
        int balance;
    public:
        bank(int number = 100000, const char n[] = "\0", const char date[] = "\0", int cash = 0){
            account_number = number;
            name = new char [30];
            create_time = new char [30];
            balance = cash;
            for(int i = 0; i < 31; i++){
                if((n[i] == 0) || (i == 30)){
                    name[i] = '\0';
                    break;
                }
                name[i] = n[i];
            }
            for(int i = 0; i < 31; i++){
                if((date[i] == 0) || (i == 30)){
                    create_time[i] = '\0';
                    break;
                }
                create_time[i] = date[i];
            }
            cout << "constr" << '\n';
        }

        bank(const bank &b){
            account_number = b.account_number;
            balance = b.balance;
            name = new char[30];
            create_time = new char [30];
            for(int i = 0; i < 31; i++){
                if((b.name[i] == 0) || (i == 30)){
                    name[i] = '\0';
                    break;
                }
                name[i] = b.name[i];
            }
            for(int i = 0; i < 31; i++){
                if((b.create_time[i] == 0) || (i == 30)){
                    create_time[i] = '\0';
                    break;
                }
                create_time[i] = b.create_time[i];
            }
            cout << "constr copy" << '\n';
        }

        ~bank(){
            delete[] name;
            delete[] create_time;
            cout << "destr" << '\n';
        }

        bank& operator= (const bank &b){
            if(this != &b){
                for(int i = 0; i < 31; i++){
                    if((b.name[i] == 0) || (i == 30)){
                        name[i] = '\0';
                        break;
                    }
                    name[i] = b.name[i];
                }
                for(int i = 0; i < 31; i++){
                    if((b.create_time[i] == 0) || (i == 30)){
                        create_time[i] = '\0';
                        break;
                    }
                    create_time[i] = b.create_time[i];
                }
                account_number = b.account_number;
                balance = b.balance;
            }
            return *this;
        }
        void outinfo(){
            cout << account_number << ' ' << name << ' ' << create_time << ' ' << balance << '\n';
        }
};

struct node{
    bank elem;
    node *next;
    node *prev;
};

class List{
    private:
        node *first, *last;
    public:
        List():first(nullptr), last(nullptr){};
        ~List(){
            node *curr;
            while(first != nullptr){
                curr = first;
                first = first->next;
                delete curr;
            }
        }
        void push_front(const bank& temp){
            node *curr = new node;
            curr->elem = temp;
            curr->prev = nullptr;
            curr->next = first;
            if(first != nullptr){
                first->prev = curr;
            }
            first = curr;
            if(last == nullptr){
                last = curr;
            }
        }
        void push_back(const bank& temp){
            node *curr = new node;
            curr->elem = temp;
            curr->prev = last;
            curr->next = nullptr;
            if(last != nullptr){
                last->next = curr;
            }
            last = curr;
            if(first == nullptr){
                first = curr;
            }
        }
        bank& front(){
            first->elem.outinfo();
            return first->elem;
        }
        bank& back(){
            last->elem.outinfo();
            return last->elem;
        }
        void pop_front(){
            if(first != nullptr){
                node *curr = first;
                first = first->next;
                if(first != nullptr){
                    first->prev = nullptr;
                }
                else{
                    last = nullptr;
                }
                delete curr;
            }
        }
        void pop_back(){
            if(last != nullptr){
                node *curr = first;
                while(curr->next != last){
                    curr = curr->next;
                }
                delete last;
                last = curr;
                last->next = nullptr;
            }
        }
        void insert(int p, const bank& b){
            if(p > (int)size() || p < 1){
                cout << "err" << '\n';
                return;
            }
            node *pointer = first;
            while(p > 1 && pointer != nullptr){
                pointer = pointer->next;
                p--;
            }
            if(pointer == first){
                push_front(b);
                return;
            }
            if(pointer == nullptr){
                push_back(b);
                return;
            }
            node *curr = new node;
            curr->elem = b;
            curr->next = pointer;
            curr->prev = pointer->prev;
            curr->prev->next = curr;
            pointer->prev = curr;
        }
        void erase(int p){
            if(p > (int)size() || p < 1){
                cout << "err" << '\n';
                return;
            }
            node *pointer = first;
            while(p > 1 && pointer != nullptr){
                pointer = pointer->next;
                p--;
            }
            if(pointer != nullptr){
                if(pointer == first){
                    pop_front();
                }
                else if(pointer == last){
                    pop_back();
                }
                else{
                    delete pointer;
                    pointer->prev->next = pointer->next;
                    pointer->next->prev = pointer->prev;
                }
            }

        }
        bool empty(){
            return first == nullptr;
        }
        int size(){
            node *curr = first;
            int size = 0;
            while(curr != nullptr){
                size++;
                curr = curr->next;
            }
            return size;
        }
        void print(){
            node *curr = first;
            if(curr == nullptr){
                cout << "empty" << '\n';
            }
            else{
                while(curr != nullptr){
                    curr->elem.outinfo();
                    curr = curr->next;
                }
            }
            cout << '\n';
        }
};
class queue : private List{
    private:
        int length = 0;
        int maxsize;
    public:
        queue(): maxsize(5){};
        queue(int insize) : maxsize(insize){};
        ~queue(){};

        void back(const bank& b){
            if (!full()){
                List::push_back(b);
                length++;
            }
        }
        bank& front(){
            if(!empty()){
                return List::front();
            }
            else{
                throw "Queue is empty";
            }
        }
        void pop(){
            if(!empty()){
                List::pop_front();
                length--;
            }
        }
        bool empty(){
            return size() == 0;
        }
        int size(){
            return length;
        }
        bool full(){
            return size() == maxsize;
        }
        void print(){
            List::print();
        }

};
int main(){
    bank ex1(422142, "Ivanov\0", "12:55 01.03.2022\0", 99999);
    bank ex2 = bank(422143, "Petrov\0", "12:59 01.03.2022\0", 13131);
    bank ex3(422144, "Sidorov\0", "13:05 01.03.2022\0", 923455);
    bank ex4 = bank(422145, "Vetrov\0", "13:12 01.03.2022\0", 543324);
    bank ex5 = bank(422146, "Stepanov\0", "13:19 01.03.2022\0", 34122);

    queue q(5);
    cout << "queue is empty = " << q.empty() << "\n";
    q.back(ex1);
    q.back(ex2);
    q.back(ex3);
    q.print();
    cout << "queue size is = " << q.size() << "\n";
    q.back(ex4);
    cout << "first is = ";
    ex1 = q.front();
    q.back(ex5);
    q.print();
    cout << "queue size is = " << q.size() << "\n";
    cout << "queue is full = " << q.full() << "\n";
    q.pop();
    q.pop();
    q.print();
    q.pop();
    q.pop();
    cout << "queue is empty = " << q.empty() << "\n";
    q.pop();
    cout << "queue is empty = " << q.empty() << "\n";
   return 0;
}