#include<iostream> 
using namespace std;
char c;
 
void gc(){
    cin >> c;
}

bool check(){
    enum state {H, E, S, A, BC, SAB, AB, ER};
    state CS;
    CS = H;
    gc();
    do{
        switch (CS){
            case H: 
                if(c == '1'){
                    gc();
                    CS = BC;
                }
                else
                    CS = ER;
                break;
            case BC:
                if(c == '0'){
                    gc();
                    CS = AB;
                }
                else if(c == '1'){
                    gc();
                    CS = S;
                }
                else
                    CS = ER;
                break;
            case S:
                if(c == '2'){
                    CS = E;
                }
                else
                    CS = ER;
                break;
            case A:
                if(c == '0'){
                    gc();
                    CS = S;
                }
                else if(c == '1'){
                    gc();
                    CS = A;
                }
                else
                    CS = ER;
                break;
            case AB:
                if(c == '0'){
                    gc();
                    CS = SAB;
                }
                else if (c == '1'){
                    gc();
                    CS = A;
                }
                else
                    CS = ER;
                break;
            case SAB:
                if(c == '0'){
                    gc();
                    CS = SAB;
                }
                else if (c == '1'){
                    gc();
                    CS = A;
                }
                else if (c == '2'){
                    CS = E;
                }
                else
                    CS = ER;
                break;
        }
    }    
    while (CS != E && CS != ER);
    return CS == E;
}

int main(){
    if(check()) 
        cout << "true";
    else
        cout << "false";
    return 0;
}