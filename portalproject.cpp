#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string f_name;
    string batch;
    int roll;
    string sem;
    char section;
    string courses[6]; // Array to store 6 courses
    double fee_s = 0; // Initialize fee to 0
    string feeStatus = "Not Paid"; // Initialize status
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

        cout<<"Enter Student "<<i+1<<" Semister: ";
        getline(cin,inf[i].sem);
        
        cout << "Enter Student Section: ";
        cin >> inf[i].section;
        
        cout << endl;
    }
}

void fee(Student inf[], int studentCount) {
    for(int i = 0; i < studentCount; i++) {
        cout << "Enter fees of the Student " << inf[i].name << " : ";
        cin >> inf[i].fee_s;
        
        // Update fee status based on payment
        if(inf[i].fee_s > 0) {
            inf[i].feeStatus = "Paid";
        } else {
            inf[i].feeStatus = "Not Paid";
        }
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
        
        if (studentName.find(searchLower) != string::npos) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << inf[i].name << endl;
            cout << "Father's Name: " << inf[i].f_name << endl;
            cout << "Roll Number: " << inf[i].roll << endl;
            cout << "Batch: " << inf[i].batch << endl;
            cout << "Semister: "<<inf[i].sem<<endl;
            cout << "Section: " << inf[i].section << endl;
            cout << "Courses: ";
            for (int j = 0; j < 6; j++) {
                if (!inf[i].courses[j].empty()) {
                    cout << inf[i].courses[j];
                    if (j < 5) cout << ", ";
                }
            }
            cout << "\nFee Details: " << inf[i].fee_s << endl;
            cout << "Fee Status: " << inf[i].feeStatus << endl;
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
        cout << "Semister: "<<inf[i].sem<<endl;
        cout << "Section: " << inf[i].section << endl;
        cout << "Courses: ";
        for (int j = 0; j < 6; j++) {
            if (!inf[i].courses[j].empty()) {
                cout << inf[i].courses[j];
                if (j < 5) cout << ", ";
            }
        }
        cout << "\nFee Details: " << inf[i].fee_s << endl;
        cout << "Fee Status: " << inf[i].feeStatus << endl;
        cout << "\n--------------------------\n";
    }
}

void deleteStudent(Student inf[], int &studentCount) {
    int roll;
    cout << "Enter the roll number of the student to delete: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (inf[i].roll == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                inf[j] = inf[j + 1];
            }
            studentCount--;
            cout << "Student with roll number " << roll << " has been deleted." << endl;
            return;
        }
    }
    cout << "No student found with roll number: " << roll << endl;
}

void editStudent(Student inf[], int studentCount) {
    int roll;
    cout << "Enter the roll number of the student to edit: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (inf[i].roll == roll) {
            cout << "Editing details for " << inf[i].name << ":\n";
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, inf[i].name);
            cout << "Enter new father's name: ";
            getline(cin, inf[i].f_name);
            cout << "Enter new batch: ";
            getline(cin, inf[i].batch);
            cout << "Enter new semester: ";
            getline(cin, inf[i].sem);
            cout << "Enter new section: ";
            cin >> inf[i].section;
            cout << "Student details updated successfully." << endl;
            return;
        }
    }
    cout << "No student found with roll number: " << roll << endl;
}

int main() {
    int choice;
    int studentCount = 0;
    int maxStudents = 0;
    Student* studentInfo = NULL;  // Using NULL

    do {
        cout << "**********************************" << endl;
        cout << "***          DASHBOARD         ***" << endl;
        cout << "**********************************" << endl;
        cout << "*   1. Add Student Information   *" << endl;
        cout << "*   2. Course Registration       *" << endl;
        cout << "*   3. Display All Students      *" << endl;
        cout << "*   4. Search Student by Name    *" << endl;
        cout << "*   5. Edit Student              *" << endl;
        cout << "*   6. Delete Student            *" << endl;
        cout << "*   7. Exit                      *" << endl;
        cout << "**********************************" << endl;
        cout << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number of students: ";
                cin >> studentCount;
                
                if (studentCount <= 0) {
                    cout << "Invalid number of students." << endl;
                    break;
                }

                // Allocate new array or resize existing one
                if (studentInfo != NULL) {
                    delete[] studentInfo;
                }
                studentInfo = new Student[studentCount];
                enterStudentInfo(studentInfo, studentCount);
                fee(studentInfo, studentCount);
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
            case 5: {
                if (studentCount > 0 && studentInfo != NULL) {
                    editStudent(studentInfo, studentCount);
                } else {
                    cout << "No students available to edit." << endl;
                }
                break;
            }
            case 6: {
                if (studentCount > 0 && studentInfo != NULL) {
                    deleteStudent(studentInfo, studentCount);
                } else {
                    cout << "No students available to delete." << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    if (studentInfo != NULL) {
        delete[] studentInfo;
    }

    return 0;
}