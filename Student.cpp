#include "Student.h"
#include <iostream>

//default constructor
Student::Student() : name_(""), numCourses_(0), courseList_(nullptr){

}

//string constructor
Student::Student(std::string name) : name_(std::move(name)), numCourses_(0), courseList_(nullptr){

}

//parameterized constructor
Student::Student(std::string name, int numCourses, std::string** courseList) :
name_(std::move(name)), numCourses_(numCourses), courseList_(courseList){

}

//copy constructor (performs deep copy)
//Explanation:
//- Copies name and number of courses using setters and getters
//- checks if courseList exists in other, then allocates mem for it (one for each course)
//then it loops through courses, allocs memory, and copies
//also handles if courseList is already nullptr
Student::Student(const Student& other) {
    std::cout << "copy constructor called!" <<std::endl; //for testing
    setName(other.getName());
    setNumCourses(other.numCourses_);
    if(other.courseList_) {
        courseList_ = new std::string*[getNumCourses()];
        for (int i = 0; i < getNumCourses(); i++) {
            courseList_[i] = new std::string(*(other.courseList_[i]));
        }
    } else {
        courseList_ = nullptr;
    }
}

// Assignment operator
Student& Student::operator=(const Student& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this == &other) {
        return *this; // Check for self-assignment
    }

    // Deallocate existing resources
    if (courseList_) {
        for (int i = 0; i < numCourses_; ++i) {
            delete courseList_[i];
        }
        delete[] courseList_;
    }

    // Copy name and numCourses
    setName(other.getName());
    setNumCourses(other.getNumCourses());

    // Deep copy of courseList_
    if (other.courseList_) {
        courseList_ = new std::string*[getNumCourses()];
        for (int i = 0; i < getNumCourses(); ++i) {
            courseList_[i] = new std::string(*(other.courseList_[i]));
        }
    } else {
        courseList_ = nullptr;
    }

    return *this; // Return the current object
}


//destructor
//not only destroys course list, but also deallocates its memory afterwards
Student::~Student() {
    if (courseList_) {
        for (int i = 0; i < numCourses_; i++) {
            delete courseList_[i];
        }
        delete[] courseList_;
    }
}


//region setters
void Student::setName(const std::string& name) {
    this->name_ = name;
}

void Student::setNumCourses(int numCourses) {
    this->numCourses_ = numCourses;
}

void Student::setCourseList(std::string** courseList, int numCourses) {
    this->courseList_ = courseList;
}
//endregion setters

//region getters
std::string Student::getName() const {
    return name_;
}

int Student::getNumCourses() const {
    return numCourses_;
}

std::string** Student::getCourseList() {
    return courseList_;
}
//endregion getters

//region methods
void Student::addCourse(const std::string& course) {
    //allocate new memory for new course list
    std::string **newCourseList = new std::string *[numCourses_ + 1];

    //copy the existing courses
    for (int i = 0; i < numCourses_; i++) {
        newCourseList[i] = new std::string(*(courseList_[i]));
    }

    //add the course into the new course
    newCourseList[numCourses_] = new std::string(course);

    //deallocate old course list
    if (courseList_) {
        for (int i = 0; i < numCourses_; i++) {
            delete courseList_[i];
        }
        delete[] courseList_;
    }

    //update to the new course list
    courseList_ = newCourseList;
    ++numCourses_;
}

void Student::resetCourses() {
    if (courseList_) {
        for (int i = 0; i < numCourses_; i++) {
            delete courseList_[i];
        }
        delete[] courseList_;
    }
    courseList_ = nullptr;
    numCourses_ = 0;
}
//endregion methods

// Print function
void Student::print() {
    std::cout << "Name: " << name_ << "\nCourses: ";
    for (int i = 0; i < numCourses_; i++) {
        std::cout << *(courseList_[i]) << " ";
    }
    std::cout << std::endl;
}

//Overloaded operator: <<

std::ostream& operator<<(std::ostream& stream, const Student& student) {
    stream << "Name: " << student.name_ << "\nCourses: ";
    for (int i = 0; i < student.numCourses_; i++) {
        stream << *(student.courseList_[i]) << " ";
    }
    return stream;
}

