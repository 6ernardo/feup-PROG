#include <iostream>

using namespace std;

//exercicio 1
void check_char(){
    char in;
    cin >> in;

    if((in>='a' && in<='z') || (in>='A' && in<='Z')) cout << "LETTER";
    else if(in>='0' && in<='9') cout << "DIGIT";
    else cout << "OTHER";
}

//exercicio 2
//! Print array.
void print(int a[], int size) {
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << "]";
  cout << endl;
}

void remove_duplicates(int a[], int& size){
    for(int i=1; i<size; i++){
        if(a[i]==a[i-1]){
            int aux=a[i];
            for(int j=i; j<size-1; j++){
                a[j]=a[j+1];
            }
            a[size-1]=aux;
            size--;
            i--;
        }
    }
}

//exercicio 3
bool anagrams(const char a[], const char b[], int& n){
    int counta[26]={0}, countb[26]={0};
    int i=0;
    
    while(a[i]!='\0'){
        if(a[i]>='a' && a[i]<='z') counta[a[i]-'a']++;
        else if(a[i]>='A' && a[i]<='Z') counta[a[i]-'A']++;

        i++;
    }

    i=0;

    while(b[i]!='\0'){
        if(b[i]>='a' && b[i]<='z') countb[b[i]-'a']++;
        else if(b[i]>='A' && b[i]<='Z') countb[b[i]-'A']++;

        i++;
    }

    n=0;

    for(int j=0; j<26; j++){
        if(counta[j]>countb[j]) n+=counta[j]-countb[j];
        else n+=countb[j]-counta[j];
    }

    return n==0;
}

//exercicio 4
//! Complex number
struct complex {
  int real;  // Real part
  int img;   // Imaginary part
};
 
//! Print array of complex numbers.
void print(const complex z[], int n) {
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (z[i].real == 0 && z[i].img == 0) 
      cout << 0;
    else {
      if (z[i].real != 0)
        cout << z[i].real;
      if (z[i].img > 0) 
        cout  << '+' << z[i].img << 'i';
      else if (z[i].img < 0) 
        cout  << z[i].img << 'i';
    }
    cout << ' ';
  }
  cout << "]\n";
}

//funcões auxiliares
complex complex_add(complex a, complex b){
    complex ret;
    ret.real=a.real+b.real;
    ret.img=a.img+b.img;

    return ret;
}

complex complex_mul(complex a, complex b){
    complex ret;

    ret.real=a.real*b.real-a.img*b.img;
    ret.img=a.real*b.img+b.real*a.img;

    return ret;
}

void mandel(complex c, int n, complex z[]){
    complex aux;
    aux.img=0;
    aux.real=0;

    z[0]=aux;

    for(int i=1; i<n; i++){
        z[i]=complex_add(complex_mul(z[i-1], z[i-1]), c);
    }
}

int main(){
    //check_char();
    /*{
        int a[] = { 10 };
        int size = sizeof(a) / sizeof(int);
        remove_duplicates(a, size);
        print(a, size);
    } // => [ 10 ] */

    /*{
        char a[] = "Eric Clapton and Britney Spears and Meg Ryan";
        char b[] = "are narcoleptic presbyterians Germany";
        int n = -1;
        bool r = anagrams(a, b, n);
        cout << '\"' << a << '\"' << ' '
            << '\"' << b << '\"' << ' '
            << boolalpha << r << ' ' << n << '\n';
    } // -> "Eric Clapton and Britney Spears and Meg Ryan" "are narcoleptic presbyterians Germany" false 7 */

    /*{
        complex c = { -3, 3 };
        const int n = 5;
        complex z[n];
        mandel(c, n, z);
        print(z, n);
    } // -> [ 0 -3+3i -3-15i -219+93i 39309-40731i ]*/


}