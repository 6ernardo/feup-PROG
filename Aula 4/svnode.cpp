#include <iostream>

using namespace std;

// Sparse vector node.
struct svnode {
  int position;  // Position.
  int value;     // Value (different from 0)
  svnode* next;  // Successor node (if non-null, position < next->position)
};

//! Build a new sparse vector node.
svnode* build(int position, int value, svnode* svn) {
  if (svn == nullptr || position < svn->position) {
    svn = new svnode { position, value, svn };
  } else {
    svn->next = build(position, value, svn->next);
  }
  return svn;
}

//! Destroy a sparse vector node and its successors.
void destroy(svnode* svn) {
  while (svn != nullptr) {
    svnode* aux = svn->next;
    delete svn;
    svn = aux;
  }
}

//! Print the contents (position-value pairs).
void print(const svnode* svn) {
  cout << "[";
  while (svn != nullptr) {
    cout << ' ' << svn->position 
         << ">" << svn->value;
    svn = svn->next;
  }
  cout << " ]";
}

//Exercicio 5
svnode* sum(const svnode* a, const svnode* b){
    if (a == nullptr && b == nullptr){
        return nullptr;
    }
    else if(a == nullptr ){
        return new svnode {b->position,b->value,sum (a,b->next)};
    }
    else if(b == nullptr){
        return new svnode {a->position,a->value,sum (a->next,b)};
    }
    else if(a->position > b->position){
        return new svnode {b->position,b->value,sum (a,b->next)};
    }
    else if ( a->position < b-> position){
        return new svnode {a->position,a->value,sum (a->next,b)};
    }
    else if ( a->value + b->value == 0){
        return sum (a->next,b->next);
    }
    return new svnode {a->position,a->value + b->value, sum (a->next,b->next)};
}