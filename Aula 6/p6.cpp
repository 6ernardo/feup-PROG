#include <iostream>
#include <string>
#include <vector>

using namespace std;

//exercicio 1
bool pangram(const string& s, string& m){
    int array[26]={0};

    for(size_t i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z') array[s[i]-'a']++;
        else if(s[i]>='A' && s[i]<='Z') array[s[i]-'A']++;
    }

    for(int j=0; j<26; j++){
        if(array[j]==0) m+='a'+j;
    }

    return m.length()==0;
}

//exercicio 2
//! Print vector of strings.
void print(const vector<string>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << '\"' << v[i] << "\" ";
  }
  cout << "]\n";
}

void split(const string& s, vector<string>& v){
    size_t pos=0, posf;
    
    while(pos!=string::npos){
        if(s[pos]!=' '){
            posf=s.find(' ', pos+1);

            string aux=s.substr(pos, posf-pos);

            if(aux!=""){
                v.push_back(aux);
            }

            pos=posf;
        }
        else{
            posf=s.find(' ', pos+1);

            string aux=s.substr(pos+1, posf-pos-1);

            if(aux!=""){
                v.push_back(aux);
            }

            pos=posf;
        }
    }
    
}

//exercicio 3
//! Print vector with elements of type T.
template <typename T>
void print(const vector<T>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << "]\n";
}

//! Normalise elements of vector for values between min and max.
template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
  for (size_t i = 0; i < v.size(); i++) {
    T& e = v.at(i);  // or v[i]
    if (e > max) 
      e = max;
    else if (e < min) 
      e = min;
  }
}

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    for(size_t i=0; i<v.size(); i++){
        if(v[i]<min) v[i]=min;
        else if(v[i]>max) v[i]=max;
    }
}

//exercicio 4
string longest_prefix(const vector<string>& v){
    string ret = "";
        
        for(size_t i=0; i<v[0].length(); i++){
            for(size_t j=1; j<v.size(); j++){
                if(v[0][i]!=v[j][i]) return ret;
            }
            ret+=v[0][i];
        }
        
        return ret;
}

//exercicio 5
struct sm_entry {
  size_t row;
  size_t col;
  int value;
};

typedef vector<sm_entry> smatrix;

//! Print a sparse matrix.
void print(const smatrix& sm) {
  cout << "[ ";
  for (sm_entry e : sm) {
    cout << '(' << e.row << ", " << e.col << ", " << e.value << ") ";
  }
  cout << "]\n";
}

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t ai = 0, bi = 0;

    while (ai + bi < a.size() + b.size()) {
        if (ai < a.size() && bi < b.size()) {
            if (a[ai].row == b[bi].row && a[ai].col == b[bi].col) {
                if (a[ai].value + b[bi].value != 0)
                    r.push_back({a[ai].row, a[ai].col, a[ai].value + b[bi].value});
                ai++;
                bi++;
            }
            else if (a[ai].row < b[bi].row || (a[ai].row == b[bi].row && a[ai].col < b[bi].col)) {
                r.push_back(a[ai]);
                ai++;
            }
            else {
                r.push_back(b[bi]);
                bi++;
            }
        }
        else if (ai < a.size()) {
            if (a[ai].value != 0)
                r.push_back(a[ai]);
            ai++;
        }
        else {
            if (b[bi].value != 0)
                r.push_back(b[bi]);
            bi++;
        }
    }
}


int main(){
    /*{
        string s = "Hi";
        string m = "";
        bool r = pangram(s, m);
        cout << '\"' << s << "\" "
            << boolalpha << r << " \"" << m << "\"\n";
    } // -> "Hi" false "abcdefgjklmnopqrstuvwxyz" */

    /*{
        cout << "\"" << longest_prefix({ "Elisabethtomatofirepower", "Elisabethattackerschickweed", "ElisabethJohannMarat", "Elisabethmultiplicationopportunist", "Elisabethimpresariossentences", "Elisabethhaughtiestrhetoric", "Elisabethdiscussburnoose", "Elisabethfiremaninshore", "ElisabethsupportableBhutan", "Elisabethpredatepill", "Elisabethstitchesvertebra", "Elisabethpresumingtenacity", "Elisabethquadrupleenquiry", "Elisabethstreetwalkersnetworked", "Elisabethcompanyscrew", "Elisabethshowpiecehelmet", "Elisabethhindquartershallot", "ElisabethTweedledumverbs", "ElisabethbacillusHolstein", "ElisabethWaksmansculpture", "ElisabethabilityBrahmins", "ElisabethrevoltedBradstreet", "ElisabethinfectionsDirac", "ElisabethsettleMycenae", "ElisabethseminariesColleen", "ElisabethvireoJamaicans", "Elisabethpluckmisbehave", "Elisabethextroversionships", "ElisabethRossinipossess", "ElisabethSamuelsonpitch" }) << "\"\n";
    }*/

}