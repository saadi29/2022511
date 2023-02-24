#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include<time.h>
#include<conio.h>


using namespace std;

// Define student 
struct Student {
    int marks;
    string name;
    int id;
    
    char getGrade(int marks) {
        if (marks >= 90) {
            return 'A';
        }
        else if (marks >= 80) {
            return 'B';
        }
        else if (marks >= 70) {
            return 'C';
        }
        else if (marks >= 60) {
            return 'D';
        }
        else if (marks >= 50) {
            return 'E';
        }
        else {
            return 'F';
        }
    }
    vector<string> courses;

    // Constructor
    Student(string name, int id) : name(name), id(id) {}
};
struct Teacher {
    string courses;
    string name;
    int id;

    // Constructor
    Teacher(string name, int id) : name(name), id(id) {}
};
struct Course {

    string name;
    int id;
    string teacher;
    string student;
   void enrollCourse();
    // Constructor
    Course(string name, int id, string teacher = "") : name(name), id(id), teacher(teacher) {}
};


// Define person 
struct person {

    vector<Teacher> teachers;
    vector<Student> students;
    vector<Course> courses;
    char getGrade(int marks) {
        if (marks >= 90) {
            return 'A';
        }
        else if (marks >= 80) {
            return 'B';
        }
        else if (marks >= 70) {
            return 'C';
        }
        else if (marks >= 60) {
            return 'D';
        }
        else if (marks >= 50) {
            return 'E';
        }
        else {
            return 'F';
        }
    }
    // Add a new student to the system
    void addStudent() {
        string name;
        int id;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;
        Student newStudent(name, id);
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

    // Remove a student from the system
    void removeStudent() {
        int id;
        cout << "Enter student ID to remove: ";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Student removed successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Update student details
    void updateStudent() {
        int id;
        string name;
        cout << "Enter student ID to update: ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> name;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students[i].name = name;
                cout << "Student updated successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Check record of all students
    void printAllStudents() {
       for (int i = 0; i < students.size(); i++) {
     
        cout << "List of all students:" << endl;
            cout << "Name: " << students[i].name << ", ID: " << students[i].id << endl;
        }
    }

    // Un-enroll a student from a course
    void unEnrollStudent() {
        int id;
        string course;
        cout << "Enter student ID to unenroll: ";
        cin >> id;
        cout << "Enter course name: ";
        cin >> course;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                for (int j = 0; j < students[i].courses.size(); j++) {
                    if (students[i].courses[j] == course) {
                        students[i].courses.erase(students[i].courses.begin() + j);
                        cout << "Student unenrolled successfully!" << endl;
                        return;
                    }
                }
                cout << "Course not found!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void addTeacher() {
        string name;
        int id;
        cout << "Enter teacher name: ";
        cin >> name;
        cout << "Enter teacher ID: ";
        cin >> id;
        Teacher newTeacher(name, id);
        teachers.push_back(newTeacher);
        cout << "Teacher added successfully!" << endl;
    }

    // Remove a teacher from the system
    void removeTeacher() {
        int id;
        cout << "Enter teacher ID to remove: ";
        cin >> id;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i].id == id) {
                teachers.erase(teachers.begin() + i);
                cout << "Teacher removed successfully!" << endl;
                return;
            }
        }
        cout << "Teacher not found!" << endl;
    }

    // Update teacher details
    void updateTeacher() {
        int id;
        string name;
        cout << "Enter teacher ID to update: ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> name;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i].id == id) {
                teachers[i].name = name;
                cout << "Teacher updated successfully!" << endl;
                return;
            }
        }
        cout << "Teacher not found!" << endl;
    }

    // Print record of all teachers
    void printTeachers() {
        for (int i = 0; i < teachers.size(); i++) {
            cout << "ID: " << teachers[i].id << ", Name: " << teachers[i].name << endl;
        }
    }
    // Add a new course to the system
    void addCourse() {
        string name;
        int id;
        cout << "Enter course name: ";
        cin >> name;
        cout << "Enter course ID: ";
        cin >> id;
        Course newCourse(name, id);
        courses.push_back(newCourse);
        cout << "Course added successfully!" << endl;
    }

    // Remove a course from the system
    void removeCourse() {
        int id;
        cout << "Enter course ID to remove: ";
        cin >> id;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].id == id) {
                courses.erase(courses.begin() + i);
                cout << "Course removed successfully!" << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;
    }

    // Update course details
    void updateCourse() {
        int id;
        string name;
        cout << "Enter course ID to update: ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> name;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].id == id) {
                courses[i].name = name;
                cout << "Course updated successfully!" << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;
    }

    // Print record of all courses
    void printCourses() {
        for (int i = 0; i < courses.size(); i++) {
            cout << "ID: " << courses[i].id << ", Name: " << courses[i].name << ", Teacher: " << courses[i].teacher << endl;
        }
    }

    // Allocate a course to a teacher
    void allocateCourse() {
        int course_id;
        int teacher_id;
        cout << "Enter course ID to allocate: ";
        cin >> course_id;
        cout << "Enter teachea\r ID to allocate course to: ";
        cin >> teacher_id;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].id == course_id) {
                courses[i].teacher = to_string(teacher_id);
                cout << "Course allocated successfully!" << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;
    }

    // De-allocate a course from a teacher
    void  deallocateCourse() {
        int course_id;
        cout << "Enter course ID to deallocate: ";
        cin >> course_id;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].id == course_id) {
                courses[i].teacher = "";
                cout << "Course deallocated successfully!" << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;

    }
    void printStudent() {
        int id;
        cout << "enetr your id: ";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                cout << "your data is" << endl;
                cout << "Name: " << students[i].name << ", ID: " << students[i].id << endl;
                return;
            }
        }
    }
    void EnrollStudent() {
        int id;
        string course;
        cout << "Enter student ID to enroll: ";
        cin >> id;
        cout << "Enter course name: ";
        cin >> course;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                for (int j = 0; j < students[i].courses.size(); j++) {
                    if (students[i].courses[j] == course) {
                        students[i].courses.erase(students[i].courses.begin() + j);
                        cout << "Student unenrolled successfully!" << endl;
                        return;
                    }
                }
                cout << "Course not found!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void enrollCourse() {
        int course_id;
        int student_id;
        cout << "Enter course ID to enroll: ";
        cin >> course_id;
        cout << "Enter student ID to enroll course to: ";
        cin >> student_id;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].id == course_id) {
                courses[i].student = to_string(student_id);
                cout << "Course enrolled successfully!" << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;
    }
    void printTeacher() {
        int id;
        cout << "enetr your id: ";
        cin >> id;
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i].id == id) {
                cout << "your data is" << endl;
                cout << "Name: " << teachers[i].name << ", ID: " << teachers[i].id << endl;
                return;
            }
        }
    }

    

    void assignMarksAndGrade() {
        string student;
        int marks;
        
        for (int i = 0; i < students.size(); i++) {
            
                cout << "enter student id:";
                cin >> students[i].id;
                cout << "enter total marks:";
                cin >> students[i].marks;
                
                   
                return;
            
        }
       
    }
    void showstudentmarks() {

        int id;
        cout << "enetr your id: ";
        cin >> id;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                cout << "your data is" << endl;
                cout << "Name: " << students[i].name << endl << "marks: " << students[i].marks << endl << "Grade: " << getGrade(students[i].marks) << endl;
                return;
            }
        }
    }
    void topstudent() {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[0].marks < students[i].marks)
                students[0].marks = students[i].marks;
           
        }
        cout << "top student is " << students[0].name<<endl;
    }
    //show  Allocate a course to a teacher
    void showallocatecourse() {
        int course_id;
        int teacher_id;
        
        cout << "Enter teachea\r ID to show course to: ";
        cin >> teacher_id;
        for (int i = 0; i<teachers.size(); i++) {
            if (teachers[i].id == teacher_id) {
               
                cout << "Course for this teacher are" << endl;
                
               
                return;
            }
        }
        cout << "Course not found!" << endl;
    }
    void listofstudentsenrolledincourses()
    {
        cout << "Enter your ID: ";
        int id;
        cin >> id;
        for (int i = 0; i < courses.size(); i++)
        {
            if (id == courses[i].id)
            {
                cout << "In Course " << courses[i].name << ": \n";
                for (int j = 0; j < courses.size(); j++)
                {
                    cout << "Student(s): " << courses[i].student;
                }
            }
        }
    }
    void enrolledcourse() {
        int id;
        string enrollcourse();
        
        cout << "enter student id to show courses:";
            cin >> id;
            for (int i = 0; i < courses.size(); i++)
            {
                if (id == students[i].id)
                {
                    cout << "the enrolled courses are ";
                    
                    

                   
                }
            }
    }
    void droppededcourse() {
        int id;

        string  enrollCourse();
        cout << "enter student id to show courses:";
        cin >> id;
        for (int i = 0; i < courses.size(); i++)
        {
            if (id != students[i].id)
            {
                cout << "the enrolled courses are ";
                
                


            }
        }
    }
    void grade_wise_division()
    {
        
       

        int id;
        cout << "Enter the courses division ";
        cin >> id;
        for (int i = 0; i < courses.size(); i++)
        {
            if (id == courses[i].id)
            {
                cout << "grade vise division of the students is:";
                cout << students[i].name;
            }
        }
       



        }

};
// Main function
int main() {
    char fname[20];
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    //printing the welcome note
re:
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           LEARNING MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
    
    c:
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  Learning MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     2022511\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) {//character 13 is enter
       
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");










        // Create an instance of the admin class
        person Person;

        // Menu-based user interface
    a:
        int choice = -1;
        cout << "Select an option:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Student" << endl;
        cout << "3. Teacher" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        system("cls");
        if (choice == 1) {
            while (choice != 0) {
                d:
                //admin
                cout << "Select an option:" << endl;
                cout << "1. Add a student" << endl;
                cout << "2. Remove a student" << endl;
                cout << "3. Update student" << endl;
                cout << "4. Print all students" << endl;
                cout << "5. unenroll a student" << endl;
                cout << "6. Add a teacher" << endl;
                cout << "7. Remove a teacher" << endl;
                cout << "8. Update teacher" << endl;
                cout << "9. Check record of all teachers" << endl;
                cout << "10. Add a course" << endl;
                cout << "11. Remove a course from system" << endl;
                cout << "12. update a course." << endl;
                cout << "13. Display all courses" << endl;
                cout << "14. Allocate a course to a teacher" << endl;
                cout << "15. De-Allocate a course from teacher" << endl;
                cout << "0. exit the program" << endl;
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    Person.addStudent();
                    break;
                    
                    goto d;
                case 2:
                    Person.removeStudent();
                    break;
                    goto d;
                case 3:
                    Person.updateStudent();
                    break;
                    goto d;
                case 4:
                    Person.printAllStudents();
                    break;
                    goto d;
                case 5:
                    Person.unEnrollStudent();
                    break;
                    goto d;
                case 6:
                    Person.addTeacher();
                    break;
                    goto d;
                case 7:
                    Person.removeTeacher();
                    break;
                    goto d;
                case 8:
                    Person.updateTeacher();

                    break;
                    goto d;
                case 9:
                    Person.printTeachers();
                    break;
                    goto d;
                case 10:
                    Person.addCourse();
                    break;
                    goto d;
                case 11:
                    Person.removeCourse();
                    break;
                    goto d;
                case 12:
                    Person.updateCourse();
                    break;
                    goto d;
                case 13:
                    Person.printCourses();
                    break;
                    goto d;
                case 14:
                    Person.allocateCourse();
                    break;
                        goto d;
                case 15:
                    Person.deallocateCourse();
                    goto d;
                case 16:
                    goto a;
                case 0:
                    goto b;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            while (choice != 0) {
                //student

                cout << "Select an option:" << endl;
                cout << "1. Check his/her details or data" << endl;
                cout << "2. Enroll any available course" << endl;
                cout << "3. See his/her final grade" << endl;
                cout << "4. See list of his/her teachers" << endl;
                cout << "5. See list of his/her enrolled courses" << endl;
                cout << "6. See list of his/her dropped courses" << endl;
                cout << "7. See list of his/her completed courses" << endl;
                cout << "8. Back" << endl;
                cout << "0. exit";
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    Person.printStudent();
                    break;
                case 2:
                    Person.enrollCourse();
                    break;
                case 3:
                    Person.showstudentmarks();
                    break;
                case 4:
                    Person.printTeacher();
                    break;
                case 5:
                    Person.enrolledcourse();
                    break;
                case 6:
                    Person.droppededcourse();
                    break;
                case 8:
                    goto a;
                    break;
                case 0:
                    goto b;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }



            }
        }
        else if (choice == 3)
        {
            //teacher
            while (choice != 0) {


                cout << "Select an option:" << endl;
                cout << "1. Check his/her details or data" << endl;
                cout << "2. See list of all courses allocated to him" << endl;
                cout << "3. See list of all students enrolled in each course separately" << endl;
                cout << "4. Assigning and grading students:" << endl;
                cout << "5. See the top student in his/her class after marking/grading" << endl;
                cout << "6. Grade-wise division of students in course allocated to him" << endl;
                cout << "7. Remove a teacher" << endl;
                cout << "8. Back";
                cout << "0. exit";
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    Person.printTeacher();
                    break;
                case 2:
                    Person.showallocatecourse();
                    break;
                case 3:
                    Person.listofstudentsenrolledincourses();
                    break;
                case 4:
                    Person.assignMarksAndGrade();
                    break;
                case 5:
                    Person.topstudent();
                    break;
                case 6:
                    Person.grade_wise_division();
                case 7:
                    goto a;
                case 0:
                    goto b;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }
        }
        else if (choice == 0)
        {

        b:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                            Learning MANAGEMENT SYSTEM                                 |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
            cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";


        }
        else
        {
            cout << "Invalid input." << endl;

            goto a;
        }
    }
     else {
         cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
         system("PAUSE");
         system("CLS");
         goto c;
    }
    return 0;
}
