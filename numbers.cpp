
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


void printPrimes(int size){
    vector<bool> primes(size+1);
    primes[2] = true;
    primes[3] = true;
    for(int i=5; i<=size; i++){
        primes[i] = false;
    }
    long int limit = ceil(sqrt(size));
    
    for(int x=1; x<= limit; x++){
        for(int y=1; y<= limit; y++){
            long int n = 4*x*x+y*y;
            if((n<= size) && ((n%12 == 1 )||(n%12 == 5))){
                primes[n] = true;
            }
            n = 3*x*x+y*y;
            if((n<=size) && (n%12==7)){
                primes[n] = true;
            }
            if(x>y){
                n = 3*x*x-y*y;    
                if((n<=size) && (n%12==11)){
                    primes[n] = true;
                }
            }
            
        }
    }
    for(int i=5; i<limit; i++){
        if(primes[i]){
            for(int j = i*i; j<size; j += i){
                primes[j] = false;
            }
        }
    }
    for(int i=2; i<size; i++){
        if(primes[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

void printFibonacci(int n){
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    while(fib.back() < n){
        fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
    }
    for(int i=0; i<(fib.size()-1); i++){
        cout << fib[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Insert a maximum : ";
    long int size;
    cin >> size;
    cout<< "Testing primes : " << endl; 
    printPrimes(size);
    cout << endl;
    cout << "Testing fibonacci sequence : " << endl;
    printFibonacci(size);
    cout << endl;
    return 0;
}