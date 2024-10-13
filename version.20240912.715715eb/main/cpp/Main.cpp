/* Main src */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <deque>
#include <array>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <algorithm>
#include <tuple>
#include <string>
#include <chrono>
#include <type_traits>
#include <exception>
#include <cstdio> // For printf

#define MY_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << (message) << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)

// Class template
template <typename T>
class MyClass {
public:
    explicit MyClass(T value) : value_(value) {}
    T getValue() const { return value_; }

private:
    T value_;
};

// Enum class
enum class Color { Red, Green, Blue };

// Struct
struct Point {
    int x;
    int y;

    void print() const {
        printf("Point(%d, %d)\n", x, y);
    }
};

// Struct with constructor and method
struct Rectangle {
    int width;
    int height;

    Rectangle(int w, int h) : width(w), height(h) {}

    int area() const {
        return width * height;
    }
};

// Anonymous struct
struct {
    int a;
    double b;
} anonymousStruct;

// Union
union Number {
    int intValue;
    float floatValue;
    double doubleValue;
};

// // Anonymous union
// union {
//     int intAnon;
//     float floatAnon;
// };

// Ordinary class
class OrdinaryClass {
public:
    // Default constructor
    OrdinaryClass() noexcept : data_(0) {
        printf("OrdinaryClass Default Constructor\n");
    }

    // Parameterized constructor
    OrdinaryClass(int data) noexcept : data_(data) {
        printf("OrdinaryClass Parameterized Constructor\n");
    }

    // Copy constructor
    OrdinaryClass(const OrdinaryClass& other) noexcept : data_(other.data_) {
        printf("OrdinaryClass Copy Constructor\n");
    }

    // Move constructor
    OrdinaryClass(OrdinaryClass&& other) noexcept : data_(other.data_) {
        other.data_ = 0;
        printf("OrdinaryClass Move Constructor\n");
    }

    // Copy assignment operator
    OrdinaryClass& operator=(const OrdinaryClass& other) noexcept {
        if (this != &other) {
            data_ = other.data_;
            printf("OrdinaryClass Copy Assignment\n");
        }
        return *this;
    }

    // Move assignment operator
    OrdinaryClass& operator=(OrdinaryClass&& other) noexcept {
        if (this != &other) {
            data_ = other.data_;
            other.data_ = 0;
            printf("OrdinaryClass Move Assignment\n");
        }
        return *this;
    }

    // Destructor
    ~OrdinaryClass() noexcept {
        printf("OrdinaryClass Destructor\n");
    }

    // Member function, does not throw
    void display() const noexcept {
        printf("OrdinaryClass data: %d\n", data_);
    }

    // Member function, may throw an exception
    void riskyOperation(bool shouldThrow) {
        if (shouldThrow) {
            throw std::runtime_error("An error occurred in riskyOperation");
        }
        printf("riskyOperation completed successfully\n");
    }

private:
    int data_;
};

class Complex {
public:
    Complex(double r, double i) : real(r), imag(i) {}

    // 重载 + 运算符
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

private:
    double real;
    double imag;
};

void outer_function_with_lambda() {
    // callable lambda
    auto inner_function = []() {
        return "Hello from inner function!";
    };

    std::cout << inner_function() << std::endl; // call lambda
}

int getInteger1() {
    return 42;
}

int getInteger2() {
    return (int)((long)((int)42));
}

float getFloat() {
    return 3.14f * 2;
}

std::string getString() {
    return "Hello, " + std::string("World!");
}

typedef int (*FunctionPointer)();

struct OneStruct {
    int x;
    float y;
};

enum OneEnum {
    ENUM_VALUE_1,
    ENUM_VALUE_2
};

union OneUnion {
    int i;
    float f;
};

class OneClass {
public:
    std::string name;
    OneClass(std::string n) : name(n) {}
    void display() const {
        std::cout << "Class name: " << name << std::endl;
    }
};

int* getIntPointer() {
    static int value = 10;
    return &value;
}

int& getIntReference() {
    static int value = 20;
    return value;
}

int sampleFunction() {
    return 42;
}

FunctionPointer getFunctionPointer() {
    return &sampleFunction;
}

FunctionPointer& getFunctionPointerReference() {
    static FunctionPointer fp = &sampleFunction;
    return fp;
}

OneStruct getStruct() {
    return {5, 3.14f};
}

OneStruct& getStructReference() {
    static OneStruct s = {7, 2.71f};
    return s;
}

OneStruct* getStructPointer() {
    static OneStruct s = {7, 2.71f};
    return &s;
}

OneEnum getEnum() {
    return ENUM_VALUE_1;
}

OneEnum& getEnumReference() {
    static OneEnum e = ENUM_VALUE_2;
    return e;
}

OneEnum* getEnumPointer() {
    static OneEnum e = ENUM_VALUE_2;
    return &e;
}

OneUnion getUnion() {
    OneUnion u;
    u.i = 100;
    return u;
}

OneUnion& getUnionReference() {
    static OneUnion u;
    u.f = 1.23f;
    return u;
}

OneUnion* getUnionPointer() {
    static OneUnion u;
    u.f = 1.23f;
    return &u;
}

OneClass getClassObject() {
    return OneClass("OneClassInstance");
}

OneClass& getClassObjectReference() {
    static OneClass obj("OneClassReferenceInstance");
    return obj;
}

OneClass* getClassObjectPointer() {
    static OneClass obj("OneClassPointerInstance");
    return &obj;
}

class AnotherClass {
public:
    AnotherClass(int value) : data(value) {
        std::cout << "AnotherClass constructor called with value: " << data << std::endl;
    }

    ~AnotherClass() {
        std::cout << "AnotherClass destructor called for value: " << data << std::endl;
    }

    void display() const {
        std::cout << "AnotherClass object value: " << data << std::endl;
    }

private:
    int data;
};

std::unique_ptr<AnotherClass> createUniquePtr(int value) {
    return std::make_unique<AnotherClass>(value);
}

std::unique_ptr<AnotherClass> createUniquePtrWithNew(int value) {
    return std::unique_ptr<AnotherClass>(new AnotherClass(value));
}

int main() {
    std::unique_ptr<AnotherClass> ptr = createUniquePtr(100);

    ptr->display();

    std::unique_ptr<AnotherClass> ptr2 = createUniquePtrWithNew(200);

    ptr2->display();

    int* intPtr = getIntPointer();
    std::cout << "Integer pointer value: " << *intPtr << std::endl;

    int& intRef = getIntReference();
    std::cout << "Integer reference value: " << intRef << std::endl;

    FunctionPointer funcPtr = getFunctionPointer();
    std::cout << "Function pointer result: " << funcPtr() << std::endl;

    FunctionPointer& funcPtrRef = getFunctionPointerReference();
    std::cout << "Function pointer reference result: " << funcPtrRef() << std::endl;

    OneStruct s = getStruct();
    std::cout << "Struct values: x = " << s.x << ", y = " << s.y << std::endl;

    OneStruct& sRef = getStructReference();
    std::cout << "Struct reference values: x = " << sRef.x << ", y = " << sRef.y << std::endl;

    OneStruct* sPtr = getStructPointer();
    std::cout << "Struct pointer values: x = " << sPtr->x << ", y = " << sPtr->y << std::endl;

    OneEnum e = getEnum();
    std::cout << "Enum value: " << e << std::endl;

    OneEnum& eRef = getEnumReference();
    std::cout << "Enum reference value: " << eRef << std::endl;

    OneEnum* ePtr = getEnumPointer();
    std::cout << "Enum pointer value: " << *ePtr << std::endl;

    OneUnion u = getUnion();
    std::cout << "Union value (int): " << u.i << std::endl;

    OneUnion& uRef = getUnionReference();
    std::cout << "Union reference value (float): " << uRef.f << std::endl;

    OneUnion* uPtr = getUnionPointer();
    std::cout << "Union pointer value (float): " << uPtr->f << std::endl;

    OneClass obj = getClassObject();
    obj.display();

    OneClass& objRef = getClassObjectReference();
    objRef.display();

    OneClass* objPtr = getClassObjectPointer();
    objPtr->display();

    // Basic data types
    int noInit;
    int a = 10;
    double b = 5.5;
    char c = 'c';
    bool flag = true;
    std::string str = "Hello, C++11!";

    // Printing basic data types
    printf("int: %d\n", noInit); // The value of noInit is ramdom
    printf("int: %d\n", a);
    printf("double: %.2f\n", b);
    printf("char: %c\n", c);
    printf("bool: %s\n", flag ? "true" : "false");
    printf("string: %s\n", str.c_str());

    int choice = 2;
    int count = 0;

    // do-while
    do {
        // std::cout << "Enter a number between 1 and 3 (0 to exit): ";
        // std::cin >> choice;

        // switch
        switch (choice) {
            case 1:
                std::cout << "You chose option 1.\n";
                break;
            case 2:
                std::cout << "You chose option 2.\n";
                break;
            case 3:
                std::cout << "You chose option 3.\n";
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }

        count++;

    } while (choice != 2);

    std::cout << "\nYou made " << count << " choices.\n";

    while (count < 5) {
        std::cout << "Count is less than 5, current count: " << count << std::endl;
        count++;
    }

    std::cout << "Final count is " << count << ".\n";

    int x = 2;
    MY_ASSERT(x == 2, "x should be 2");
    std::unordered_map<int, int> switchMap = {
        {1, 10},
        {2, 20},
        {3, 30}
    };

    int result = switchMap.count(x) ? switchMap[x] : -1;
    std::cout << "Result: " << result << std::endl;

    bool go = false;
    while (go) {
        throw "An Exception won't be thrown:)";
    }

    while (go)
        while (go)
            while (go)
                throw "An Exception won't be thrown:)";

    do {
        std::cout << "in block of do while" << count << std::endl;
    } while (1 == 2);

    do
        do
            do
                std::cout << "in do while without block" << count << std::endl;
            while (1 == 2);
        while (1 == 2);
    while (1 == 2);

    if (go) {
        throw "An Exception won't be thrown:)";
    }

    if (go)
        if (go)
            if (go)
                throw "An Exception won't be thrown:)";
            else if (1 == 3)
                std::cout << "it is else if branch" << std::endl;
            else
                if (2 == 2)
                    std::cout << "it is anothre if in else branch" << std::endl;
                else
                    std::cout << "it is else branch" << std::endl;

    for (int i = 1; i < 5; i++) {
        if (i == 3) {
            break;
        } else if (i == 2){
            continue;
        }

        std::cout << "in for, i:" << i << std::endl;
    }

    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 2; j++)
            for (int k = 1; k < 2; k++)
                std::cout << "in for, i:" << i << ", j:" << j << ", k:" << k << std::endl;

    // ----- again

    while (go) {
        throw "An Exception won't be thrown:)";
    }

    while (go)
        while (go)
            while (go)
                throw "An Exception won't be thrown:)";

    do {
        std::cout << "in block of do while" << count << std::endl;
    } while (1 == 2);

    do
        do
            do
                std::cout << "in do while without block" << count << std::endl;
            while (1 == 2);
        while (1 == 2);
    while (1 == 2);

    if (go) {
        throw "An Exception won't be thrown:)";
    }

    if (go)
        if (go)
            if (go)
                throw "An Exception won't be thrown:)";
            else if (1 == 3)
                std::cout << "it is else if branch" << std::endl;
            else
                if (2 == 2)
                    std::cout << "it is anothre if in else branch" << std::endl;
                else
                    std::cout << "it is else branch" << std::endl;

    for (int i = 1; i < 5; i++) {
        if (i == 3) {
            break;
        } else if (i == 2){
            continue;
        }

        std::cout << "in for, i:" << i << std::endl;
    }

    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 2; j++)
            for (int k = 1; k < 2; k++)
                std::cout << "in for, i:" << i << ", j:" << j << ", k:" << k << std::endl;

    // STL containers
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::map<int, std::string> map = {{1, "one"}, {2, "two"}};
    std::set<int> set = {1, 2, 3};
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}};
    std::unordered_set<int> uset = {1, 2, 3};
    std::list<int> lst = {1, 2, 3};
    std::deque<int> deq = {1, 2, 3};
    std::array<int, 3> arr = {1, 2, 3};
    std::tuple<int, double, std::string> tup = std::make_tuple(1, 2.0, "tuple");

    // print("msg from print\n"); // print is not a valid function here
    printf("msg from printf\n");
    std::cout << "msg from std::cout" << std::endl;
    std::cerr << "msg from std::cerr" << std::endl;
    std::clog << "msg from std::clog" << std::endl;

    // Printing STL containers
    printf("vector: ");
    for (int i : vec) printf("%d ", i);
    printf("\n");

    printf("map: ");
    for (const auto& [key, value] : map) printf("{%d: %s} ", key, value.c_str());
    printf("\n");

    printf("set: ");
    for (int i : set) printf("%d ", i);
    printf("\n");

    printf("unordered_map: ");
    for (const auto& [key, value] : umap) printf("{%d: %s} ", key, value.c_str());
    printf("\n");

    printf("unordered_set: ");
    for (int i : uset) printf("%d ", i);
    printf("\n");

    printf("list: ");
    for (int i : lst) printf("%d ", i);
    printf("\n");

    printf("deque: ");
    for (int i : deq) printf("%d ", i);
    printf("\n");

    printf("array: ");
    for (int i : arr) printf("%d ", i);
    printf("\n");

    printf("tuple: { %d, %.2f, %s }\n", std::get<0>(tup), std::get<1>(tup), std::get<2>(tup).c_str());

    // Smart pointers
    std::unique_ptr<int> uptr = std::make_unique<int>(10);
    std::shared_ptr<int> sptr = std::make_shared<int>(20);

    // Printing smart pointers
    printf("unique_ptr: %d\n", *uptr);
    printf("shared_ptr: %d\n", *sptr);

    // Condition variable and mutex
    std::mutex mtx;
    std::condition_variable cv;
    int ready = 0;

    std::thread t1([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        ready = 1;
        cv.notify_one();
    });

    std::thread t2([&]() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return ready == 1; });
        printf("Thread 2 is running\n");
    });

    t1.join();
    t2.join();

    // Using enum class
    Color color = Color::Red;
    if (color == Color::Red) {
        printf("Color is red\n");
    }

    // Using lambda expression
    outer_function_with_lambda();

    auto add_lambda = [](int a, int b) { return a + b; };
    int res = add_lambda(3, 4);
    printf("Lambda result: %d\n", res);

    auto lambdaWithError = []() {
        throw std::runtime_error("An error occurred in lambda!");
    };

    try {
        lambdaWithError();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Using function template
    auto add = [](auto a, auto b) -> decltype(a + b) { return a + b; };
    printf("Template add result: %.2f\n", add(1.5, 2.5));

    // Static assertion
    static_assert(sizeof(int) >= 4, "int is too small!");

    // Using custom template class
    MyClass<int> myClass(100);
    printf("MyClass value: %d\n", myClass.getValue());

    // Using struct
    Point p = {3, 4};
    p.print();

    Rectangle rect(10, 5);
    printf("Rectangle area: %d\n", rect.area());

    // Using anonymous struct
    anonymousStruct.a = 5;
    anonymousStruct.b = 10.5;
    printf("AnonymousStruct a: %d, b: %.2f\n", anonymousStruct.a, anonymousStruct.b);

    // Using union
    Number num;
    num.intValue = 10;
    printf("Union intValue: %d\n", num.intValue);

    num.floatValue = 3.14f;
    printf("Union floatValue: %.2f\n", num.floatValue);

    // // Using anonymous union
    // intAnon = 42;
    // printf("AnonymousUnion intAnon: %d\n", intAnon);

    // floatAnon = 2.71f;
    // printf("AnonymousUnion floatAnon: %.2f\n", floatAnon);

    printf("----------------------------------------\n");

    // Using ordinary class
    printf("Creating OrdinaryClass instances...\n");

    // Default constructor
    OrdinaryClass obj1;
    obj1.display();

    // Parameterized constructor
    OrdinaryClass obj2(50);
    obj2.display();

    // Copy constructor
    OrdinaryClass obj3 = obj2;
    obj3.display();

    // Move constructor
    OrdinaryClass obj4 = std::move(obj3);
    obj4.display();
    obj3.display(); // obj3 data has been moved

    // Copy assignment
    obj1 = obj2;
    obj1.display();

    // Move assignment
    obj1 = std::move(obj4);
    obj1.display();
    obj4.display(); // obj4 data has been moved

    // user class Complex
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    c3.display();  // Output: 4 + 6i

    // Exception handling with the riskyOperation method
    try {
        obj2.riskyOperation(false); // This should not throw
        obj2.riskyOperation(true);  // This should throw
    } catch (const std::exception& e) {
        printf("Caught exception: %s\n", e.what());
    }

    printf("Exiting main...\n");
    return 0;
}
