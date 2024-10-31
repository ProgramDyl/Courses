#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    int numCourses_;
    std::string** courseList_;

public:
    //region Constructors!
    Student(); //default
    Student(std::string name); //string constructor
    Student(std::string name, int numCourses, std::string** courseList); //parameterized constructor
    Student(const Student& other); // copy constructor

    //assignment operator
    Student& operator=(const Student& other);

    // Destructor
    ~Student();

    //endregion Constructors!

    //region Setters
    void setName(const std::string& name);
    void setNumCourses(int numCourses);
    void setCourseList(std::string** courseList, int numCourses);

    //endregion Setters

    //region Getters
    std::string getName() const;
    int getNumCourses() const;
    std::string** getCourseList();
    //endregion Getters

    //Add a course
    void addCourse(const std::string& course);

    //print!
    void print();

    // friend function for << overloading
    friend std::ostream& operator<<(std::ostream& os,const Student& student);

    //reset courses
    void resetCourses();


};

#endif