#include <iostream>
using namespace std;

//! Doubly-linked node containing an int value.
struct dlnode {
  int value;     // Value.
  dlnode* prev;  // Previous node.
  dlnode* next;  // Next node.
};

//! Builds a new node containing value v followed by next.
dlnode* build(int v, dlnode* next=nullptr) {
  dlnode* n = new dlnode { v , nullptr, next };
  if (next != nullptr) { next->prev = n; }
  return n;
}

//! Releases the memory allocated to n and successors.
void destroy(dlnode* n) {
  while (n != nullptr) {
    dlnode* aux = n -> next;
    delete n;
    n = aux;
  }
}

//! Prints 
void print(const dlnode* n) {
  while (n != nullptr) {
    cout << "(";
    if (n->prev == nullptr) cout << "\\<";
    else cout << n->prev->value << '<';
    cout << n->value << '<';
    if (n->next == nullptr) cout << "\\)";
    else cout << n->next->value << ')';
    n = n->next;
  }
  cout << '\n';
}


//Exercicio 3
dlnode* insert(dlnode* dln, int k, int v){
    dlnode* ret;

    if(dln==nullptr){
        ret= new dlnode {v, nullptr, dln};
        return ret;
    }

    if(k==0){
        ret= new dlnode {v, nullptr, dln};
        dln->prev=ret;
        return ret;
    }

    dlnode* prev;
    dlnode* aux= dln;

    for(int i=0; i<k; i++){
        if(dln->next==nullptr){
            dlnode* tmp = new dlnode {v, dln, nullptr};
            dln->next=tmp;

            return aux;
        }

        prev=dln;
        dln=dln->next;
    }

    dlnode* tmp= new dlnode {v, prev, dln};
    prev->next=tmp;
    dln->prev=tmp;

    return aux;

    return nullptr;
}