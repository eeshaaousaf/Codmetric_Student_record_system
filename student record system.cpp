#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// Constants
const int MAX_STUDENTS = 100;

// Arrays to Store Student Data
int studentIDs[MAX_STUDENTS];
char studentNames[MAX_STUDENTS][50];
char studentEmails[MAX_STUDENTS][50];
char studentPhones[MAX_STUDENTS][15];
int studentAttendance[MAX_STUDENTS];
int cpMarks[MAX_STUDENTS], ictMarks[MAX_STUDENTS], dmMarks[MAX_STUDENTS];
int phyMarks[MAX_STUDENTS], ethicsMarks[MAX_STUDENTS], islMarks[MAX_STUDENTS];
char studentGrades[MAX_STUDENTS];
int totalStudents = 0;

// Function Prototypes
bool adminLogin();
void registerStudent();
void addStudentDetails();
void updateStudent();
void Attendance();
void addMarks();
void displayStudents();
void calculateGrade(int);
void writeFile();
void readFile();
void sortStudents();
void menu();

int main() {
    cout<< "--------------------------------------------------"<<endl;
    cout <<"|                                                |"<<endl;
    cout <<"|     WELCOME TO THE STUDENT RECORD SYSTEM!      |\n";
    cout <<"|                                                |"<<endl;
    cout<< "--------------------------------------------------"<<endl;

    // Load Data from File
    readFile();

    // Admin Login
    if (!adminLogin())
	 {
        return 0;
    }
    
    cout << "\nLogin successful!\n";
    cout<< "----------------------------------------"<<endl;
    // Display Menu
    menu();

    // Save Data to File
    writeFile();

    return 0;
}

// Admin Login Function
bool adminLogin() {
    char username[20], password[20];

    for (int attempts = 0; attempts < 3; attempts++) {
        cout << "Enter Admin Username: ";
        cin >> username;

        if (string(username) != "admin") {
            cout<< "----------------------------------------"<<endl;
            cout << "Invalid username! Attempts left: " << (2 - attempts) << "\n";
            continue; // Skip to next attempt
        }

        cout << "Enter Admin Password: ";
        cin >> password;

        if (string(password) != "123") {
            cout << "Invalid password! Attempts left: " << (2 - attempts) << "\n";
            cout<< "----------------------------------------"<<endl;
            continue; // Skip to next attempt
        }
        // Both username and password are correct
        return true;
    }
    cout << "Too many failed attempts! Exiting...\n";
    return false;
}

// Menu Function
void menu()
{
    int choice;

    do {
    	cout<< "----------------------------------------"<<endl;
        cout << "\n--- Student Record System ---\n";
        cout << "1. Register Student\n";
        cout << "2. Add Student Details\n";
        cout << "3. Update Student\n";
        cout << "4. Add Marks\n";
        cout << "5. Display All Students\n";
        cout << "6. Sort Students by Total Marks\n";
        cout << "7. Attendance\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<< "----------------------------------------"<<endl;

        // Perform action based on choice
        switch (choice) {
        case 1: 
            registerStudent(); 
            break;
        case 2: 
            addStudentDetails();
            break;
        case 3: 
            updateStudent(); 
            break;
        case 4:
            addMarks();
            break;
        case 5: 
            displayStudents(); 
            break;
        case 6: 
            sortStudents(); 
            break;
        case 7: 
            Attendance(); 
            break;
        case 8: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
}

// Register Student Function
void registerStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        cout << "Student limit reached!\n";
        return;
    }

    // Input ID
    cout << "Input ID: ";
    cin >> studentIDs[totalStudents];
    for (int i = 0; i < totalStudents; i++) {
        if (studentIDs[i] == studentIDs[totalStudents]) {
            cout << "Student ID already exists! Please use a unique ID.\n";
            return;
        }
    }

    // Input Name
    cout << "Input Name: ";
    cin.ignore(); // Clear input buffer
    cin.getline(studentNames[totalStudents], 50);

    // Input and Validate Email
    bool validEmail = false;
    while (!validEmail) {
        cout << "Input Email (example@gmail.com): ";
        cin.getline(studentEmails[totalStudents], 50);

        string email = studentEmails[totalStudents];
        // Check if email contains '@' and '.' after '@'
        if (email.find('@') != string::npos && email.find('.', email.find('@')) != string::npos) {
            validEmail = true;
        } else {
            cout << "Invalid email format! Please try again.\n";
        }
    }

    // Input and Validate Phone Number
    bool validPhone = false;
    while (!validPhone) {
        cout << "Input Phone (0123-4567891): ";
        cin.getline(studentPhones[totalStudents], 15);

        string phone = studentPhones[totalStudents];
        if (phone.length() == 12 && phone[4] == '-' &&
            isdigit(phone[0]) && isdigit(phone[1]) &&
            isdigit(phone[2]) && isdigit(phone[3]) &&
            isdigit(phone[5]) && isdigit(phone[6]) &&
            isdigit(phone[7]) && isdigit(phone[8]) &&
            isdigit(phone[9]) && isdigit(phone[10]) &&
            isdigit(phone[11])) {
            validPhone = true;
        } else {
            cout << "Invalid phone number format! Please try again.\n";
        }
    }

    // Initialize Marks
    cpMarks[totalStudents] = -1;
    ictMarks[totalStudents] = -1;
    dmMarks[totalStudents] = -1;
    phyMarks[totalStudents] = -1;
    ethicsMarks[totalStudents] = -1;
    islMarks[totalStudents] = -1;
    studentGrades[totalStudents] = 'F'; // Default grade

    totalStudents++;
    cout << "Student registered successfully!\n";
}

// Add student attendance function
void Attendance() {
    int id;
    cout << "Input ID for attendance: ";
    cin >> id;

    for (int i = 0; i < totalStudents; i++) {
        if (studentIDs[i] == id) {
            int attendance;
            cout << "Enter attendance percentage (0-100): ";
            cin >> attendance;

            if (attendance < 0 || attendance > 100) {
                cout << "Invalid percentage! Please enter a value between 0 and 100.\n";
                return;
            }
            studentAttendance[i] = attendance;
            cout << "Attendance updated successfully!\n";
            return;
        }
    }
    cout << "Student ID not found!\n";
}

// Add Student Details Function
void addStudentDetails() {
    int id;
    cout << "Input ID to add details: ";
    cin >> id;

    for (int i = 0; i < totalStudents; i++) {
        if (studentIDs[i] == id) {
            cout << "Enter Marks for CP: ";
            cin >> cpMarks[i];
            cout << "Enter Marks for ICT: ";
            cin >> ictMarks[i];
            cout << "Enter Marks for DM: ";
            cin >> dmMarks[i];
            cout << "Enter Marks for Physics: ";
            cin >> phyMarks[i];
            cout << "Enter Marks for Ethics: ";
            cin >> ethicsMarks[i];
            cout << "Enter Marks for Islamic Studies: ";
            cin >> islMarks[i];

            calculateGrade(i);
            cout << "Details updated successfully!\n";
            return;
        }
    }
    cout << "Student ID not found!\n";
}

// Update Student Function
void updateStudent() {
    int id;
    cout << "Input ID to update: ";
    cin >> id;

    for (int i = 0; i < totalStudents; i++) {
        if (studentIDs[i] == id) {
            cout << "Enter New Student Name: ";
            cin.ignore();
            cin.getline(studentNames[i], 50);
            
            // Input and Validate Email
    bool validEmail = false;
    while (!validEmail) {
        cout << "Input Email (example@gmail.com): ";
        cin.getline(studentEmails[totalStudents], 50);

        string email = studentEmails[totalStudents];
        // Check if email contains '@' and '.' after '@'
        if (email.find('@') != string::npos && email.find('.', email.find('@')) != string::npos) {
            validEmail = true;
        } else {
            cout << "Invalid email format! Please try again.\n";
        }
    }
            // Input and Validate Phone Number
    bool validPhone = false;
    while (!validPhone) {
        cout << "Input Phone (0123-4567891): ";
        cin.getline(studentPhones[totalStudents], 15);

        string phone = studentPhones[totalStudents];
        if (phone.length() == 12 && phone[4] == '-' &&
            isdigit(phone[0]) && isdigit(phone[1]) &&
            isdigit(phone[2]) && isdigit(phone[3]) &&
            isdigit(phone[5]) && isdigit(phone[6]) &&
            isdigit(phone[7]) && isdigit(phone[8]) &&
            isdigit(phone[9]) && isdigit(phone[10]) &&
            isdigit(phone[11])) {
            validPhone = true;
        } else {
            cout << "Invalid phone number format! Please try again.\n";
        }
    }
            cout << "Update Marks for CP: ";
            cin >> cpMarks[i];
            cout << "Update Marks for ICT: ";
            cin >> ictMarks[i];
            cout << "Update Marks for DM: ";
            cin >> dmMarks[i];
            cout << "Update Marks for Physics: ";
            cin >> phyMarks[i];
            cout << "Update Marks for Ethics: ";
            cin >> ethicsMarks[i];
            cout << "Update Marks for Islamic Studies: ";
            cin >> islMarks[i];

            calculateGrade(i);
            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student ID not found!\n";
}

// Add Marks Function
void addMarks() {
    int id;
    cout << "Input ID to calculate total marks and grade: ";
    cin >> id;

    for (int i = 0; i < totalStudents; i++) {
        if (studentIDs[i] == id) {
            // Check if marks are already provided
            if (cpMarks[i] == -1 || ictMarks[i] == -1 || dmMarks[i] == -1 ||
                phyMarks[i] == -1 || ethicsMarks[i] == -1 || islMarks[i] == -1) {
                cout << "Marks not provided for all subjects. Please update the student details first.\n";
                return;
            }

            // Calculate Total Marks and Grade
            float totalMarks = cpMarks[i] + ictMarks[i] + dmMarks[i] +
                phyMarks[i] + ethicsMarks[i] + islMarks[i];
            float average = totalMarks / 6.0;

            calculateGrade(i);

            cout << "Total Marks: " << totalMarks << "\n";
            cout << "Grade: " << studentGrades[i] << "\n";

            return;
        }
    }
    cout << "Student ID not found!\n";
}

// Display All Students Function
void displayStudents() {
    if (totalStudents == 0) {
        cout << "No students registered yet!\n";
        return;
    }
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < totalStudents; i++) {
        float totalMarks = cpMarks[i] + ictMarks[i] + dmMarks[i] + phyMarks[i] + ethicsMarks[i] + islMarks[i];
        float average = totalMarks / 6.0;

        cout << "ID: " << studentIDs[i]
            << ", Name: " << studentNames[i]
            << ", Email: " << studentEmails[i]
            << ", Phone: " << studentPhones[i]
            << ", Total Marks: " << totalMarks
            << ", Average: " << average
            << ", Grade: " << studentGrades[i]
            << ", Attendance: " << studentAttendance[i] << "%\n";
    }
}

// Calculate Grade Function
void calculateGrade(int index) {
    float totalMarks = cpMarks[index] + ictMarks[index] + dmMarks[index] + phyMarks[index] + ethicsMarks[index] + islMarks[index];
    float average = totalMarks / 6.0;

    if (average >= 90) studentGrades[index] = 'A';
    else if (average >= 80) studentGrades[index] = 'B';
    else if (average >= 70) studentGrades[index] = 'C';
    else if (average >= 60) studentGrades[index] = 'D';
    else studentGrades[index] = 'F';
}

// Sort Students by Total Marks Function
void sortStudents() {
    for (int i = 0; i < totalStudents - 1; i++) {
        for (int j = 0; j < totalStudents - i - 1; j++) {
            float totalMarks1 = cpMarks[j] + ictMarks[j] + dmMarks[j] + phyMarks[j] + ethicsMarks[j] + islMarks[j];
            float totalMarks2 = cpMarks[j + 1] + ictMarks[j + 1] + dmMarks[j + 1] + phyMarks[j + 1] + ethicsMarks[j + 1] + islMarks[j + 1];

            if (totalMarks1 < totalMarks2) {
                swap(studentIDs[j], studentIDs[j + 1]);
                swap(studentNames[j], studentNames[j + 1]);
                swap(studentEmails[j], studentEmails[j + 1]);
                swap(studentPhones[j], studentPhones[j + 1]);
                swap(cpMarks[j], cpMarks[j + 1]);
                swap(ictMarks[j], ictMarks[j + 1]);
                swap(dmMarks[j], dmMarks[j + 1]);
                swap(phyMarks[j], phyMarks[j + 1]);
                swap(ethicsMarks[j], ethicsMarks[j + 1]);
                swap(islMarks[j], islMarks[j + 1]);
                swap(studentGrades[j], studentGrades[j + 1]);
            }
        }
    }

    cout << "Students sorted by total marks successfully!\n";
}

// Save to File Function
void writeFile() {
    ofstream outFile("students.txt");

    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    outFile << totalStudents << "\n"; // Save the total number of students

    for (int i = 0; i < totalStudents; i++) {
        outFile << studentIDs[i] << "\n"
                << studentNames[i] << "\n"
                << studentEmails[i] << "\n"
                << studentPhones[i] << "\n"
                << studentAttendance[i] << "\n"
                << cpMarks[i] << " " << ictMarks[i] << " " << dmMarks[i] << " "
                << phyMarks[i] << " " << ethicsMarks[i] << " " << islMarks[i] << "\n"
                << studentGrades[i] << "\n";
    }

    outFile.close();
    //Data saved to students.txt successfully!
}

// Load from File Function
void readFile() {
    ifstream inFile("students.txt");

    if (!inFile) {
        cout << "No saved data found! Starting fresh.\n"<<endl;;
        return;
    }

    inFile >> totalStudents;
    inFile.ignore(); // To handle the newline after totalStudents

    for (int i = 0; i < totalStudents; i++) {
        inFile >> studentIDs[i];
        inFile.ignore(); 

        inFile.getline(studentNames[i], 50);
        inFile.getline(studentEmails[i], 50);
        inFile.getline(studentPhones[i], 15);

        inFile >> studentAttendance[i];
        inFile >> cpMarks[i] >> ictMarks[i] >> dmMarks[i]
               >> phyMarks[i] >> ethicsMarks[i] >> islMarks[i];

        inFile.ignore(); 
        inFile >> studentGrades[i];
        inFile.ignore(); // To handle the newline after the grade
    }

    inFile.close();
    //"Data loaded from students.txt successfully!
}