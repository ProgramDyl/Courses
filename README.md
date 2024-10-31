# Assignment 2 : Courses

## Functional Requirements:

### Create a class named Student that has three member variables:

**Name:** - A string that stores the name of the student.
**numCourses:** - An integer that tracks how many courses the student is currently enrolled in.
**courseList** - A dynamically declared (on heap) array of strings (not a vector or list) used to store
the names of classes that the student is enrolled in.

Write appropriate constructors(s), mutator, and accessor functions for the Student class along with the
following:

 A default constructor (i.e., creates a student object without a name and an empty course list).

 The “big three / rule of three” (i.e., copy constructor, assignment operator, destructor).

 An add function that will allow courses to be added to a student’s list of courses. This function
will demonstrate a deep copy using a ‘dynamically’ changing array to support the input for an
arbitrary number of courses. This is for educational purposes only, so you may not use a vector
or list as you would in production.

 A string constructor (i.e., constructor with arguments Student S1(“Bob”).

 A ‘print’ function that outputs the name and list of all courses.

 Overloaded << as a friend function that outputs the name and list of all courses.

 A function that resets the number of courses to 0 and the courseList array to an empty list.

### Write a driver program that tests/demonstrates the functionality of the Student class.
**The program should do the following:**

 Ask for the 1st students’ name and courses; looping until the student is finished. Note you may
not ask the user in advance how many classes they intend to enter, nor may any entry be left
blank.

 Display the 1st student’s name, number of courses in their list and their list of courses.

 Ask for the name of a second student and display this new student after copying the 1st student’s
course information and writing in the new name.

 Display the 1st student’s name, the number of courses in their list of courses after executing a
function that resets the number of courses to 0 and the courseList array to an empty list.

 Display the 2nd student’s name, number of courses in their list and their list of courses (to
demonstrate that a deep copy took place).

 Enter a third student and use the custom assignment operator i.e., 3rd student = 2nd student

 Allow for looping back to the beginning or exiting the program. Note that some destructor calls
will only show when the program is exited.

 Have your solution output when each of the ‘big three’ methods, plus the print, <<, add, and the
string constructor are called.

 You may need to add additional steps to this list to demonstrate all the functionality of the
Student class.
Other notes:

 Your solution should implement header files.

 Ensure that the destructor does a not-null test and assigns null after deleting.

 Ensure that the business logic and GUI are separate.

 Ensure that the driver you create demonstrates ALL the capabilities of the Student class
including methods that do the same thing (e.g., print and <<).