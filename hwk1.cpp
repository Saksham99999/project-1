/* 
 * Name:Saksham Shrestha
 * EUID: ss4539
 * Email: sakshamshrestha2@my.unt.edu
 * Department: Computer Science
 * Date: 09/09/2025
 * Description: Write a program to display the menue of student management system based on user input and store student id, name , 3 exam score and mean of those scores.
 */
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//Using Structure
struct Student{
	int id;
	string first;
	string last;
	int exam1;
	int exam2;
	int exam3;
	float mean;
};
//Using function menu
//for print option in menu for the user
void Menu(){
	cout << "******************Menu*****************************" <<endl;
	cout << "| 1. Display list of students' information        |" << endl;
        cout << "| 2. Add student information                      |" << endl;
        cout << "| 3. Update student's information                 |" << endl;
        cout << "| 4. Compute mean of list of students exams       |" << endl;
        cout << "| 5. Compute minimum of the mean of the exams     |" << endl;
        cout << "| 6. Compute maximum of the mean of the exams     |" << endl;
        cout << "| 7. Exit program                                 |" << endl;
        cout << "***************************************************" << endl;
}
//Using function displayStudents
void displayStudents(Student* list, int count) {
    if (count == 0) {
        cout << "Empty list of students." << endl;
        return;
    }

    cout << "*********************** Students Information ***********************" << endl;
    // for table header
    cout << left << setw(10) << "Id"
         << setw(15) << "First name"
         << setw(15) << "Last name"
         << setw(7) << "Exam1"
         << setw(7) << "Exam2"
         << setw(7) << "Exam3"
         << "Mean" << endl;
    //Print for under the header
    cout << "_____________________________________________________________________" << endl;
// for each students infor
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << list[i].id
             << setw(15) << list[i].first
             << setw(15) << list[i].last
             << setw(7) << list[i].exam1
             << setw(7) << list[i].exam2
             << setw(7) << list[i].exam3
             << fixed << setprecision(2) << list[i].mean << endl;
    }
}
//using function newstudent
void newstudent(Student* list, int &count, int maxSize) {
    if (count >= maxSize) {
        cout << "Student list is full. Cannot add more." << endl;
        return;
    }

    Student s;
    cout << "Enter student's information" << endl;
    cout << "Id: ";
    cin >> s.id;
    cout << "First name: ";
    cin >> s.first;
    cout << "Last name: ";
    cin >> s.last;
    cout << "Exam 1 score: ";
    cin >> s.exam1;
    cout << "Exam 2 score: ";
    cin >> s.exam2;
    cout << "Exam 3 score: ";
    cin >> s.exam3;

    s.mean = (s.exam1 + s.exam2 + s.exam3) / 3.0f;

    list[count++] = s;
    cout << "New student with id " << s.id << " added." << endl;
}
//using function updateStudent
void updateStudent(Student* list, int count) {
    if (count == 0) {
        cout << "Empty list of students." << endl;
        return;
    }

    int id;
    cout << "Please enter student id: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            cout << "Update student's information:" << endl;
            cout << "Id: " << list[i].id << endl;
            cout << "First name: ";
            cin >> list[i].first;
            cout << "Last name: ";
            cin >> list[i].last;
            cout << "Exam 1 score: ";
            cin >> list[i].exam1;
            cout << "Exam 2 score: ";
            cin >> list[i].exam2;
            cout << "Exam 3 score: ";
            cin >> list[i].exam3;
// Calculating mean score
            list[i].mean = (list[i].exam1 + list[i].exam2 + list[i].exam3) / 3.0f;
            cout << "Student's information with id " << id << " updated." << endl;
            return;
        }
    }
    cout << "Student with id " << id << " not found." << endl;
}
//using function means
void means(Student* list, int count) {
    if (count == 0) {
        cout << "Empty list of students." << endl;
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += list[i].mean;
    }

    cout << "Mean of the exams: " << fixed << setprecision(2) << (sum / count) << endl;
}
// using function minMean 
void minMean(Student* list, int count) {
    if (count == 0) {
        cout << "Empty list of students." << endl;
        return;
    }

    float minVal = list[0].mean;
    for (int i = 1; i < count; i++) {
        if (list[i].mean < minVal) {
            minVal = list[i].mean;
        }
    }

    cout << "Minimum of the mean of the exams: " << fixed << setprecision(2) << minVal << endl;
}
//using funtion maxMean
void maxMean(Student* list, int count) {
    if (count == 0) {
        cout << "Empty list of students." << endl;
        return;
    }

    float maxVal = list[0].mean;
    for (int i = 1; i < count; i++) {
        if (list[i].mean > maxVal) {
            maxVal = list[i].mean;
        }
    }

    cout << "Maximum of the mean of the exams: " << fixed << setprecision(2) << maxVal << endl;
}
// Main program
int main() {
    const int MAX = 25;
    Student* list = new Student[MAX];// using dynamic array of students  
    int count = 0;                    
    int choice;
    cout << "+----------------------------------------------+" << endl;
    cout << "|       Computer Science and Engineering       |" << endl;
    cout << "|      CSCE 1040 - Computer Science II         |" << endl;
    cout << "|   Your Name     YourEUID   your@my.unt.edu   |" << endl;
    cout << "+----------------------------------------------+" << endl;
    //for menu loop
    do {
        Menu();
        cout << ">> ";
        cin >> choice;

        switch (choice) {
            case 1: displayStudents(list, count); break;
            case 2: newstudent(list, count, MAX); break;
            case 3: updateStudent(list, count); break;
            case 4: means(list, count); break;
            case 5: minMean(list, count); break;
            case 6: maxMean(list, count); break;
            case 7:
                cout << "Thank you for using this program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please pick a number between 1 and 7." << endl;
        }
    }while (choice != 7);

    delete[] list;  // for free allocated memory
    return 0;
}
