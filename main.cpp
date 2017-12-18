#include <stdlib.h>
#include "Server.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string port;
    ifstream infile;
    infile.open("server.txt");
    getline(infile,port);
    infile.close();
    Server server(atoi(port.c_str()));
    cout<<"port:"<<port<<endl;
    try {
        server.start();
    }
    catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
