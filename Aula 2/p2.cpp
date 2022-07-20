#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//exercicio 1
int adigits(int a, int b, int c){
    int ret=0;
    if(a>=b && a>=c && b>c) ret+=a*100+b*10+c;
    else if(a>=b && a>=c && c>b) ret+=a*100+c*10+b;
    else if(b>=a && b>=c && a>c) ret+=b*100+a*10+c;
    else if(b>=a && b>=c && c>a) ret+=b*100+c*10+a;
    else if(c>=a && c>=b && a>b) ret+=c*100+a*10+b;
    else ret+=c*100+b*10+a;

    return ret;
}

//exercicio 2
//funções auxiliares
bool bissexto(int y){
    if(y%4==0){
        if(y%100==0 && y%400!=0) return false;

        return true;
    }

    return false;
}

void advanceone(int& d, int& m, int& y){
    if(bissexto(y)){
        if( m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ){
            if(d<31) d++;
            else {
                if( m==12 ){
                    d=1;
                    m=1;
                    y++;
                }
                else{
                    d=1;
                    m++;
                }
            }
        }
        else if( m==2 ){
            if(d<29) d++;
            else{
                d=1;
                m++;
            }
        }
        else {
            if(d<30) d++;
            else {
                d=1;
                m++;
            }
        }
    }
    else {
        if( m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ){
            if(d<31) d++;
            else {
                if( m==12 ){
                    d=1;
                    m=1;
                    y++;
                }
                else{
                    d=1;
                    m++;
                }
            }
        }
        else if( m==2 ){
            if(d<28) d++;
            else{
                d=1;
                m++;
            }
        }
        else {
            if(d<30) d++;
            else {
                d=1;
                m++;
            }
        }
    }
}

void advance(int delta, int& d, int& m, int& y){
    
    while(delta>0){
        advanceone(d,m,y);
        delta--;
    }
}


//exercicio 3
bool is_mersenne_number(unsigned long n){
    while(n!=0){
        if(n%2==0) return false;

        n/=2;
    }

    return true;
}

//exercicio 4
int solve_eq(int a, int b, int c, double& x1, double& x2){
    if(b*b-4*a*c<0) {
        x1=NAN;
        x2=NAN;
        return 0;
    }
    else if(b*b-4*a*c==0){
        x1=-b/(2.0*a);
        x2=NAN;
        return 1;
    }
    else{
        x1=(-b-sqrt(b*b-4*a*c))/(2.0*a);
        x2=(-b+sqrt(b*b-4*a*c))/(2.0*a);
        return 2;
    }

    return -1;
}

//exercicio 5
//função auxiliar
unsigned long factorial(unsigned long n){
    unsigned long ret=n, aux=n-1;

    if(n<2) return 1;

    while(aux>1){
        ret*=aux;

        aux--;
    }

    return ret;
}


unsigned long bell(unsigned long n){
    unsigned long ret=0;
    
    if(n<2) return 1;

    for(unsigned long k=0; k<=n-1; k++){
        ret += (factorial(n-1)/(factorial(k)*factorial(n-1-k)))*bell(k);
    }

    return ret;
}

int main(){
    //cout << adigits(7,7,7);
    //int d = 28, m = 2, y = 2004; advance(746, d, m, y); cout << d << ' ' << m << ' ' << y;
    //cout << is_mersenne_number(18446744073709551615UL);
    //double x1, x2; int r = solve_eq(16, 0, -1, x1, x2); cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2;
    // cout << bell(15);
}