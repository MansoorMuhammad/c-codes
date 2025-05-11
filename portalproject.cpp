#include <iostream>
#include <string>
using namespace std;

const int students = 10; 
struct may {
    string name;
    string f_name;
    string batch;
    int roll;
};

void namess(may inf[]) {
    for (int i = 0; i < students; i++) {
        cout << "Enter Student " << i + 1 << " Name: ";
        cin.ignore();
        getline(cin, inf[i].name);
//        
        cout << "Enter Student " << i + 1 << " Regd Number: ";
        cin >> inf[i].roll;
//        cout << endl;
        cout<<"Enter Father Name: ";
        cin.ignore();
        getline(cin,inf[i].f_name);
        cout<<"Enter Student Batch(e.g BSE243227): ";
        getline(cin,inf[i].batch);
        cout << endl;
    }
}

int main() {
    may studentInfo[students]; 
    namess(studentInfo); 

    return 0;
}