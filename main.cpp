#include "Student.h"
#include <iostream>

int main() {
    char choice;
    do {
        // Gather student1
        std::string name;
        std::cout << "Enter the student's name: ";
        std::getline(std::cin, name);

        // Using the string constructor to create student obj
        Student student1(name);
        std::cout << "String constructor called: Student created " << student1.getName() << std::endl;

        // course and addAnother variables
        std::string course;
        char addAnother;
        do {
            // Prompt user to add a course
            std::cout << "Add a course: ";
            std::getline(std::cin, course);
            student1.addCourse(course);

            // Ask user if they want to add another course
            std::cout << "Do you want to add another course? (press y/n): ";
            std::cin >> addAnother;
            std::cin.ignore(); // To ignore the newline character left in the buffer
        } while (addAnother == 'y' || addAnother == 'Y'); // Continue looping if user enters 'y' or 'Y'

        // Print the student's details using the print function and the overloaded << operator
        std::cout << "\nStudent 1 Details (using print function):\n";
        student1.print();
        std::cout << "\nStudent 1 Details (using << operator):\n" << student1 << std::endl;

        // Using the copy constructor
        std::string newName;
        std::cout << "Enter the second student's name: ";
        std::getline(std::cin, newName);
        Student student2 = student1;
        std::cout << "Copy constructor called: Copied student " << student1.getName() << " to new student " << newName << std::endl;
        student2.setName(newName);

        // Print second student's details to show deep copy worked
        std::cout << "\nStudent 2 Details (after setting new name):\n" << student2 << std::endl;

        // Reset the first student's courses
        student1.resetCourses();
        std::cout << "Reset function called: Reset courses for student " << student1.getName() << std::endl;
        std::cout << "\nFirst student after reset:\n" << student1 << std::endl;

        // Print second student again to verify deep copy
        std::cout << "\nStudent 2 Details (after first student's reset):\n" << student2 << std::endl;

        // Using the assignment operator
        std::string thirdName;
        std::cout << "Enter the third student's name: ";
        std::getline(std::cin, thirdName);
        Student student3;
        student3 = student2;
        std::cout << "Assignment operator called: Assigned student " << student2.getName() << " to new student " << thirdName << std::endl;
        student3.setName(thirdName);

        // Print third student's details to show assignment operator worked
        std::cout << "\nThird student details:\n" << student3 << std::endl;

        // Ask user if they want to restart the process or exit
        std::cout << "\nDo you want to start over or exit? (press r to restart, any other key to exit): ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character left in the buffer
    } while (choice == 'r' || choice == 'R'); // Continue looping if user enters 'r' or 'R'

    std::cout << "Program exited." << std::endl;
    return 0;
}
