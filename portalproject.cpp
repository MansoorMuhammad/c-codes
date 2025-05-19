#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string f_name;
    string batch;
    int roll;
    char section;
    string courses[6]; // Array to store 6 courses
    double fee_s = 0; // Initialize fee to 0
};

void enterStudentInfo(Student inf[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        cout << "Enter Student " << i + 1 << " Name: ";
        cin.ignore();
        getline(cin, inf[i].name);
        
        cout << "Enter Father Name: ";
        getline(cin, inf[i].f_name);

        cout << "Enter Student " << i + 1 << " Regd Number: ";
        cin >> inf[i].roll;

        cout << "Enter Student Batch (e.g BSE243227): ";
        cin.ignore();
        getline(cin, inf[i].batch);
        
        cout << "Enter Student Section: ";
        cin >> inf[i].section;
        
        cout << endl;
    }
}

void reg(Student inf[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        cout << "\nRegistering courses for " << inf[i].name << ":\n";
        for (int j = 0; j < 6; j++) {
            cout << "Enter Course " << j+1 << ": ";
            cin.ignore();
            getline(cin, inf[i].courses[j]);
        }
    }
}

void searchStudent(const Student inf[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students in records to search!" << endl;
        return;
    }

    string searchName;
    cout << "Enter student's first name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        string studentName = inf[i].name;
        string searchLower = searchName;
        
        // Check if search term exists in the name
        if (studentName.find(searchLower) != string::npos) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << inf[i].name << endl;
            cout << "Father's Name: " << inf[i].f_name << endl;
            cout << "Roll Number: " << inf[i].roll << endl;
            cout << "Batch: " << inf[i].batch << endl;
            cout << "Section: " << inf[i].section << endl;
            cout << "Courses: ";
            for (int j = 0; j < 6; j++) {
                if (!inf[i].courses[j].empty()) {
                    cout << inf[i].courses[j];
                    if (j < 5) cout << ", ";
                }
            }
            cout << "\nFee Status: " << inf[i].fee_s << endl;
            cout << "\n--------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with name containing: " << searchName << endl;
    }
}

void displayAllStudents(const Student inf[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students to display." << endl;
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent " << i+1 << ":\n";
        cout << "Name: " << inf[i].name << endl;
        cout << "Father's Name: " << inf[i].f_name << endl;
        cout << "Roll Number: " << inf[i].roll << endl;
        cout << "Batch: " << inf[i].batch << endl;
        cout << "Section: " << inf[i].section << endl;
        cout << "Courses: ";
        for (int j = 0; j < 6; j++) {
            if (!inf[i].courses[j].empty()) {
                cout << inf[i].courses[j];
                if (j < 5) cout << ", ";
            }
        }
        cout << "\n--------------------------\n";
    }
}


int main() {
    int choice;
    int studentCount = 0;
    Student* studentInfo = NULL;

    do {
        cout << "**********************************" << endl;
        cout << "***          DASHBOARD         ***" << endl;
        cout << "**********************************" << endl;
        cout << "*   1. Add Student Information   *" << endl;
        cout << "*   2. Course Registration       *" << endl;
        cout << "*   3. Display All Students      *" << endl;
        cout << "*   4. Search Student by Name    *" << endl;
        cout << "*   5. Exit                      *" << endl;
        cout << "**********************************" << endl;
        cout << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline left by cin >>

        switch (choice) {
            case 1: {
                cout << "Enter the number of students: ";
                cin >> studentCount;
                cin.ignore();  // Clear the newline

                if (studentCount <= 0) {
                    cout << "Invalid number of students." << endl;
                    break;
                }

                if (studentInfo != NULL) {
                    delete[] studentInfo;
                }
                studentInfo = new Student[studentCount];
                enterStudentInfo(studentInfo, studentCount);
                break;
            }
            case 2: {
                if (studentCount > 0 && studentInfo != NULL) {
                    reg(studentInfo, studentCount);
                } else {
                    cout << "No students available. Please add students first." << endl;
                }
                break;
            }

            case 3: {
                displayAllStudents(studentInfo, studentCount);
                break;
            }
            case 4: {
                if (studentCount > 0 && studentInfo != NULL) {
                    searchStudent(studentInfo, studentCount);
                } else {
                    cout << "No students available to search." << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    if (studentInfo != NULL) {
        delete[] studentInfo;
    }

    return 0;
}