/**CppCreateObjectOfStructure.cpp*/
#include<iostream>
#include<string>
#include<memory>
#include<new>
using namespace std;

struct Student
{
public:

    // Default constructor
    Student() {}

    // Parameterized constructor with initialization list
    Student(string name, long long phone) : name(name), phone(phone) {}

    // Factory Method
    static Student createStudent(string name, long long phone) {
        return Student(name, phone);  // Uses parameterized constructor
    }

    // Destructor
    ~Student() {}

    void showStudents() const {
        cout << "These are the Student's information:" << endl;
        cout << "Name: " << name << " | Phone: " << phone << endl;
    }

private:
    string name;
    long long phone;
};

int main() {

    /** Various ways to call Constructor in C++ to create Object */
    Student s1("Os", 9902627272);
    s1.showStudents();

    /**In C++, objects of a structure like Student can be created using various methods. Here's how you can create objects for the given Student structure:

    1. Default Constructor
    The default constructor initializes the object without any parameters. */

    Student student1;  // Default constructor
    student1.showStudents();  // Will display default-initialized values

    /**2. Parameterized Constructor
    The parameterized constructor allows you to initialize member variables directly with specific values. */
    Student student2("Alice", 9876543210);  // Direct initialization
    student2.showStudents();               // Displays initialized values

    /**3. Using Dynamic Memory Allocation
    You can create objects dynamically on the heap using the new operator. */
    Student* student3 = new Student("Bob", 1234567890);  // Dynamic creation
    student3->showStudents();                           // Access using pointer
    delete student3;                                    // Free memory

    /**4. Copy Constructor
    Objects can be created as a copy of another object. If no custom copy constructor is provided, the compiler generates a default one. */
    Student student4("Charlie", 9998887770);  // Parameterized constructor
    Student student5 = student4;             // Copy constructor
    student5.showStudents();                 // Displays same values as student4

    /**5. Using Initializer Lists
    Objects can be initialized using brace-enclosed initializer lists (C++11 and later). */
    Student student6{"David", 1231231234};  // Brace-enclosed initialization
    student6.showStudents();               // Displays initialized values

    /**6. Array of Objects
    You can create multiple objects as an array. */
    Student students[] = {
        Student("Eve", 1112223334),
        Student("Frank", 5556667778),
        Student("Grace", 9990001112)
    };

    for (const auto& student : students) {
        student.showStudents();
    }
    /**7. Using Smart Pointers (Modern C++)
    Modern C++ (C++11 and later) provides smart pointers for safe and automatic memory management. */

    
    std::shared_ptr<Student> student7 = std::make_shared<Student>("Hannah", 3332221110);
    student7->showStudents();

    std::unique_ptr<Student> student8 = std::make_unique<Student>("Ivan", 8887776665);
    student8->showStudents();

    /**8. Placement new
    You can create an object at a specific memory location using placement new. */

   
    char buffer[sizeof(Student)];
    Student* student9 = new (buffer) Student("Jack", 4443332221);
    student9->showStudents();
    /**9. Factory Method
    You can use a static factory method to create and return objects. */
    Student student10 = Student::createStudent("Kate", 7778889990);
    student10.showStudents();






    
    return 0;
}
/**Here are the various ways to create an object of Student:

Default Constructor
Parameterized Constructor
Dynamic Object Creation
Copy Constructor
Initializer Lists
Array of Objects
Using Smart Pointers
Placement new
Factory Method */