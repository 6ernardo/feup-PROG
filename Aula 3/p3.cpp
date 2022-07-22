#include <iostream>

using namespace std;

//exercicio 1
unsigned long hstr_to_integer(const char hstr[]){
    unsigned long ret=0;
    
    for(int i=0; hstr[i]!='\0'; i++){
        ret*=16;
        if(hstr[i]>='a' && hstr[i]<='f') ret+=10+hstr[i]-'a';
        else if(hstr[i]>='A' && hstr[i]<='F') ret+=10+hstr[i]-'A';
        else ret+=hstr[i]-'0';
    }

    return ret;
}

//exercicio 2
struct fraction {
   int num; // Numerator
   int den; // Denominator
}; 

int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);
}

fraction sum(const fraction fa[], int n){
    fraction ret;
    ret.den=fa[0].den;
    ret.num=fa[0].num;

    for(int i=1; i<n; i++){
        ret.num=ret.num*fa[i].den+fa[i].num*ret.den;
        ret.den*=fa[i].den;

        int aux = gcd(ret.num, ret.den);

        ret.num/=aux;
        ret.den/=aux;

        if(ret.den<0){
            ret.den*=-1;
            ret.num*=-1;
        }
    }  

    return ret; 
}

//exercicio 3
//! Auxiliary function to print n elements of an array.
void print_array(const int a[], int n){
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
    int i=0, j=0;

    while(i<na && j<nb){
        if(a[i]>b[j]){
            c[i+j]=b[j];
            j++;
        }
        else{
            c[i+j]=a[i];
            i++;
        }
    }

    while(i<na){
        c[i+j]=a[i];
        i++;
    }

    while(j<nb){
        c[i+j]=b[j];
        j++;
    }
}

//exercicio 4
void int_to_string(int n, char str[], int& pos){
    char aux[999];
    int i=0;
    while(n>0){
        aux[i]= '0' + (n%10);
        n/=10;
        i++;
    }

    while(i>0){
        str[pos++]=aux[i-1];
        i--;
    }
}

void rleEncode(const char str[], char rle[]){
    int i=0, aux=0, pos=0;
    char prev = str[0];

    while(str[i]!='\0'){
        if(str[i]==prev){
            aux++;
        }   
        else{
            int_to_string(aux,rle,pos);
            rle[pos++]=prev;
            prev=str[i];
            aux=1;
        }
        i++;
    }
    int_to_string(aux,rle,pos);
    rle[pos++]=prev;
    rle[pos]='\0';
}

//exercicio 5
struct time_of_day {
  unsigned char h; // hours
  unsigned char m; // minutes
};
struct interval {
  time_of_day start; // start time
  time_of_day end;   // end time
};

//! Prints the results.
void print(int d, const interval il) {
  cout << d << " ["
       << (int) il.start.h << ':' << (int) il.start.m << ','
       << (int) il.end.h   << ':' << (int) il.end.m 
       << "[\n";
}

//função auxilar
int hours_to_mins(time_of_day t){
    return t.h*60+t.m;
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    int count=0;

    u.start.h=23; u.start.m=59;
    u.end.h=0; u.end.m=0;
    
    for(int i=0; i<n; i++){
        if(hours_to_mins(t)>=hours_to_mins(a[i].start) && hours_to_mins(t)<hours_to_mins(a[i].end)){
            count++;
            if(hours_to_mins(u.start)>hours_to_mins(a[i].start)){
                u.start.h=a[i].start.h;
                u.start.m=a[i].start.m;
            }
            if(hours_to_mins(u.end)<hours_to_mins(a[i].end)){
                u.end.h=a[i].end.h;
                u.end.m=a[i].end.m;
            }
        }
    }

    if(count==0){
        u.end=t;
        u.start=t;
    }

    return hours_to_mins(u.end)-hours_to_mins(u.start);
}

int main(){
    //cout << hstr_to_integer("FFFFFFFFFFFFFFFF") << "\n"; // => 18446744073709551615

    /*
    fraction fa[] { {0, 1}, {0, 2}, {0, 3}, {-1, 4}, {4, 5}};
    fraction s = sum(fa, 5);  
    cout << s.num << '/' << s.den << "\n"; // => 11/20
    
    
    const int NA = 15, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
    */

    /*
    {
        char rle[19 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
        rleEncode("wwwwwwwwwwwwxxxyyuxaaabbboooooocccccccc", rle);
        cout << rle << endl;
    } // => 12w3x2y1u1x3a3b6o8c
    */

    /*
    {
        const int n = 5;
        const time_of_day t = { 8, 27 };
        interval a[n] { { { 3, 29 }, { 9, 53 } },
                        { { 10, 00 }, { 13, 30 } },
                        { { 1, 24 }, { 6, 13 } },
                        { { 5, 25 }, { 7, 05 } },
                        { { 7, 30 }, { 11, 55 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        print(d, u);
    }  // --> 506 [3:29,11:55[
    */
}