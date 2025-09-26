# C++ Interview Questions and Answers

---

## 🔹 OOP & C++ Basics

### What is the difference between struct and class in C++?

* `struct` and `class` are functionally similar in C++, but differ in default access:

  * `struct`: members are `public` by default.
  * `class`: members are `private` by default.
* Both can have constructors, destructors, and member functions.

### What are virtual functions and virtual destructors?

* **Virtual functions**: Allow dynamic dispatch; the correct function is chosen at runtime.
* **Virtual destructor**: Ensures derived class destructor is called when deleting via base pointer.

### What is the Rule of 5?

If a class defines any of the following, it should generally define all:

* Destructor
* Copy constructor
* Copy assignment operator
* Move constructor
* Move assignment operator

### Explain smart pointers: `unique_ptr`, `shared_ptr`, and `weak_ptr`.

* `unique_ptr`: Owns the object exclusively. Non-copyable.
* `shared_ptr`: Multiple pointers share ownership via reference count.
* `weak_ptr`: Observes a `shared_ptr` without affecting its reference count. Used to avoid cycles.

### What are lvalue, rvalue, and move semantics?

* **lvalue**: Has a persistent address (e.g., variables).
* **rvalue**: Temporary values (e.g., `5`, `a + b`).
* **Move semantics**: Transfers ownership from one object to another to avoid copies.

### What are templates and template specialization?

* Templates: Enable generic programming.

  ```cpp
  template<typename T>
  T max(T a, T b) { return a > b ? a : b; }
  ```
* Specialization: Customize template behavior for specific types.

  ```cpp
  template<>
  const char* max<const char*>(const char* a, const char* b) { return strcmp(a, b) > 0 ? a : b; }
  ```

### What are the new features in C++11/14/17/20 you like or use most?

* C++11: auto, lambda, smart pointers, move semantics
* C++14: generic lambdas, `make_unique`
* C++17: `if constexpr`, structured bindings
* C++20: Concepts, ranges, coroutines

---

## 🔹 Memory & Pointers

### What happens when you delete a null pointer?

* Safe. `delete nullptr;` does nothing.

### What are memory leaks and how do you avoid them?

* Memory allocated and not freed.
* Avoid with RAII, smart pointers, tools like Valgrind.

### Difference between stack vs heap allocation?

* Stack: Fast, limited size, automatic lifetime.
* Heap: Manual allocation/deallocation, used for dynamic lifetime.

### What’s the output of this pointer arithmetic code?

```cpp
int arr[] = {10, 20, 30};
int* p = arr;
std::cout << *(p + 1); // 20
```

### How do `const int*`, `int* const`, and `const int* const` differ?

* `const int*`: pointer to constant int (can't modify value)
* `int* const`: constant pointer to int (can't change address)
* `const int* const`: constant pointer to constant int

---

## 🔹 Multithreading & Concurrency

### How do mutex, lock\_guard, and unique\_lock differ?

* `mutex`: Manual lock/unlock.
* `lock_guard`: RAII wrapper for mutex. Locks on creation, unlocks on destruction.
* `unique_lock`: More flexible, can lock/unlock manually, supports condition variables.

### How do you avoid deadlocks?

* Always acquire locks in same order.
* Use `std::lock()` for multiple mutexes.
* Use timeout-based locking.

### Explain std::thread, and how to join or detach threads.

* `std::thread` runs a function in a new thread.
* `join()`: Waits for thread to finish.
* `detach()`: Lets thread run independently.

### What is std::async, and when would you use it?

* Asynchronously runs a function and returns `std::future`.
* Use when you want easy threading + result fetching.

---

## 🔹 STL & Containers

### Which STL containers do you use most?

* `vector`, `map`, `unordered_map`, `set`, `queue`, `stack`

### What’s the difference between map and unordered\_map?

* `map`: Ordered (red-black tree), slower lookup.
* `unordered_map`: Unordered (hash table), faster average lookup.

### How do you sort a vector of custom objects?

```cpp
std::sort(vec.begin(), vec.end(), [](const MyObj& a, const MyObj& b) {
    return a.value < b.value;
});
```

### What’s the difference between emplace\_back and push\_back?

* `push_back`: Constructs then copies/moves.
* `emplace_back`: Constructs in-place (no copy/move).

---

## 🔹 Build, Compilation & Tools

### What are static and dynamic libraries (.a, .so, .dll)?

* `.a` (static): Linked at compile time.
* `.so`/`.dll` (dynamic): Linked at runtime.

### How do you create and use a Makefile or CMake?

* `Makefile`: Manual rules, GNU Make.
* `CMake`: Cross-platform, generates Makefiles or project files.

### Explain how the C compilation process works:

1. Preprocessing (`#include`, macros)
2. Compilation (to `.o`/`.obj`)
3. Linking (to executable)

### Difference between fork() and pthread\_create()?

* `fork()`: Creates a new process.
* `pthread_create()`: Creates a new thread in same process.

### How do you debug memory issues in C?

* Tools: `valgrind`, `AddressSanitizer`, `gdb`

---

## 🔹 Design, Modularity & Error Handling

### Explain a design pattern you’ve used (Singleton, Factory, etc.)

* Singleton: Ensure one instance. Lazy initialization + static method.
* Factory: Creates objects based on input or configuration.

### How do you manage dependencies and modularity in C++ projects?

* Use headers and implementation files.
* Encapsulate logic in classes/modules.
* Use `CMake` for dependency handling.

### What’s your approach to error handling? Exceptions vs error codes?

* Use exceptions for exceptional cases.
* Return error codes in performance-critical or low-level APIs.

---

Let me know if you’d like to export this or continue with examples!
