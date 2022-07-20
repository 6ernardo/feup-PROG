#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//exercicio 1 - FizzBuzz
void fizzbuzz(){
    int a;

    cin >> a;

    for(int i=1; i<=a; i++){
        if(i%3==0 && i%5==0){
            //nothing is done
        }
        else if(i%3==0) cout << "Fizz ";
        else if(i%5==0) cout << "Buzz ";
        else cout << i << " ";
    }
}

//exercicio 2 - Reverse
void reverse(){
    int a, b=0;
    
    cin >> a;

    while(a!=0){
        b*=10;
        b+=a%10;
        a/=10;
    }

    cout << b;
}

//exercicio 3 - primes
void primes(){
    int a;

    cin >> a;

    for(int i=2; i<=a; i++){
        bool prime=true;
        for(int j=2; j<i; j++){
            if(i%j==0) prime=false;
        }

        if(prime) cout << i << "\n";
    }
}

//exercicio 4 - pernicious
//funções auxiliares
bool isprime(int n){ //cerifica que numero é primo

    if(n==1) return false;

    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }

    return true;
}

int ones_in_bin(int n){ //converte número para binario e retorna o número de 1s
    int count=0;

    while(n!=0){
        if(n%2==1) count++;
        n/=2;
    }

    return count;
}

void pernicious(){
    int a,b;
    cin >> a >> b;

    for(int i=a; i<=b; i++){
        if(isprime(i) && isprime(ones_in_bin(i))) cout << i << "\n";
    }
}

//exercicio 5 - greg-leib
void greg_leib(){
    int k,d;
    cin >> k >> d;

    double ret=0;

    for(int i=0; i<=k; i++){
        ret+=(pow(-1, i))/(2*i+1);
    }

    ret*=4;

    cout << fixed << setprecision(d) << ret << "\n";
}

int main(){
    //fizzbuzz();
    //reverse();
    //primes();
    //pernicious();
    //greg_leib();
}