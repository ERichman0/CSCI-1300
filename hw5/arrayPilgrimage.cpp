#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    double temps[10];
    for(int i=0; i<10; i++){
        temps[i]=-459.67;
        cout<<temps[i]<<endl;
    }
    cout<<endl;
    string colors[5]={"Red","Blue","Green","Cyan","Magenta"};
    for(int i=0; i<5; i++){
        cout<<colors[i]<<endl;
    }
    cout<<endl;
    int sequence[100];
    for(int i=1; i<101; i++){
        sequence[i]=i;
        cout<<sequence[i]<<endl;
    }
    cout<<endl;
    char letters[52];
    for(int i=0;i<26;i++){
        letters[i]=char(65+i);
    }
    for(int i=26; i<52; i++){
        letters[i]=char(71+i);
    }
    for(int i=0; i<26;i++){
        cout<<letters[i]<<" "<<letters[i+26]<<endl;
    }
}