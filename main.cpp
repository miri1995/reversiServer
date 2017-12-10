#include <stdlib.h>
#include "Server.h"
#include <iostream>
#include <fstream>

using namespace std;


int readFromTextFile(){
    int port;
    ifstream infile;
    infile.open("../server.txt");
    infile >> port;
    infile.close();
    cout<<"port:"<<port<<endl;
    return port;
}

int main() {
    int port;
    Server server(readFromTextFile());
    try {
        server.start();
    }
    catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}