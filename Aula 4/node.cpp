
#include <iostream>
using namespace std;

//! Singly-linked node containing an int value.
struct node {
  int value;
  node* next;
};

//! Builds a new node with value x followed by n.
node* build(int x, node* n) {
  return new node { x , n };
}

//! Releases the memory allocated to n and successors.
void destroy(node* n) {
  while (n != nullptr) {
    node* aux = n->next;
    delete n;
    n = aux;
  }
}

//! prints Values in the node pointed by n and successors.
void print(const node* n) {
  if (n == nullptr){
    cout << "[]\n";
  } else {
    cout << '[' << n->value;
    while (n->next != nullptr) {
      n = n->next;
      cout << ',' << n->value;
    }
    cout << "]\n";
  }
}

//Exercicio 2
node* remove(int x, node* n){

    if(n==nullptr) return n;

    if(n->value==x){
        node* ret=n->next;
        n->next=nullptr;
        destroy(n);

        return ret;
    }

    node* ret=n;
    node* prev;

    while(n->value!=x){
        if(n->next==nullptr) return ret;

        prev=n;
        n=n->next;
    }

    prev->next=n->next;
    n->next=nullptr;
    destroy(n);

    return ret;

}