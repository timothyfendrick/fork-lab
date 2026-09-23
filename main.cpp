#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;



void print1to10();
void print11to20();

int main(int argc, char* argv[]) 
{    
    cout << "Hello World!!!" << endl;
    
    if(fork() == 0){
        print1to10();
    }else{
        print11to20();
    }

    return 0;
}

void print1to10(){
    int squares[10];
    
    for(int i = 1; i <= 10; i++){
        squares[i-1] = i * i;
        cout << i << " " << squares[i-1] << endl;
    }
}

void print11to20(){
    int status;

    wait(&status);

    int squares[10];
    
    for(int i = 11; i <= 20; i++){
        squares[i-11] = i * i;
        cout << i << " " << squares[i-11] << endl;
    }
}
