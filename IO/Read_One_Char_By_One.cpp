#include<iostream>
#include<fstream>
using namespace std; 

int main(){ 
    ifstream fin;
    ofstream fout;
    fin.open("src.txt");     
    fout.open("dst.txt");   

    if(!fin){ 
        return 1; 
    } 

    char ch; 

    while(fin.peek()!=EOF) {   
        fin.get(ch); 
        fout.put(ch); 
    } 

    fin.close(); 
    fout.close();
    return 0; 
}
