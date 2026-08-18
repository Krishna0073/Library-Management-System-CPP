# 📚 Library Management System (C++)

> A modern, object-oriented **Library Management System** built in **C++** using file handling and STL. This project demonstrates clean software architecture, encapsulation, persistent data storage, and menu-driven application design.

---

## 🌟 Overview

The Library Management System is a console-based application that allows librarians to efficiently manage books and members. It follows **Object-Oriented Programming (OOP)** principles and stores records using file handling, making data persistent between program executions.

This project is designed as a beginner-to-intermediate C++ portfolio project and is ideal for students learning **OOP, STL, and File Handling**.

---

## ✨ Features

### 📖 Book Management

* Add new books
* View all books
* Search books by ID or title
* Update book details
* Delete books
* Track available quantity

### 👤 Member Management

* Register new members
* View member records
* Search members
* Delete members

### 🔄 Issue & Return System

* Issue books
* Return books
* Update available stock automatically
* Prevent issuing unavailable books

### 💾 Persistent Storage

* Save books to files
* Save members to files
* Automatically load records on startup

### 🧩 Additional Features

* Menu-driven interface
* Input validation
* Unique Book IDs
* Unique Member IDs
* Clean modular code structure

---

## 🛠️ Tech Stack

* **Language:** C++
* **Concepts:** OOP, STL, File Handling
* **Compiler:** g++
* **IDE:** VS Code

---

## 📂 Repository Structure

```text
Library-Management-System-CPP/
│
├── src/
│   ├── main.cpp
│   ├── Library.cpp
│   ├── Book.cpp
│   ├── Member.cpp
│   └── FileManager.cpp
│
├── include/
│   ├── Library.h
│   ├── Book.h
│   ├── Member.h
│   └── FileManager.h
│
├── data/
│   ├── books.txt
│   └── members.txt
│
├── docs/
│   └── screenshots/
│
├── LICENSE
└── README.md
```

---

## 🧠 OOP Design

### Book Class

Stores information related to books.

```cpp
Book
│
├── bookID
├── title
├── author
├── quantity
└── category
```

### Member Class

Stores library member information.

```cpp
Member
│
├── memberID
├── name
└── issuedBooks
```

### Library Class

Acts as the controller of the entire application.

```cpp
Library
│
├── Add Book
├── Remove Book
├── Search Book
├── Issue Book
├── Return Book
└── Manage Members
```

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/Krishna0073/Library-Management-System-CPP.git
```

### 2. Open the project

```bash
cd Library-Management-System-CPP
```

### 3. Compile

```bash
g++ src/*.cpp -Iinclude -o library
```

### 4. Run

```bash
./library
```

Windows:

```bash
library.exe
```

---

## 🖥️ Sample Menu

```text
=====================================
     LIBRARY MANAGEMENT SYSTEM
=====================================

1. Add Book
2. View Books
3. Search Book
4. Delete Book
5. Register Member
6. Issue Book
7. Return Book
8. Exit

Enter Choice:
```

---

## 📸 Screenshots

| Home Menu           | Book List           |
| ------------------- | ------------------- |
| Add your screenshot | Add your screenshot |

| Issue Book          | Search Book         |
| ------------------- | ------------------- |
| Add your screenshot | Add your screenshot |

---

## 📚 Concepts Practiced

* Classes & Objects
* Encapsulation
* Constructors
* Header Files
* Separate Compilation
* File Handling (`fstream`)
* STL (`vector`)
* Searching Algorithms
* Menu-driven Programming
* Modular Code Organization

---

## 🎯 Learning Outcome

This project helped strengthen understanding of:

* Object-Oriented Programming
* C++ project structure
* Persistent data storage
* Real-world CRUD operations
* Software design using multiple classes

---

## 🔮 Future Improvements

* [ ] Admin Login
* [ ] Student Login
* [ ] Fine Calculation
* [ ] Due Date Tracking
* [ ] Borrowing History
* [ ] CSV Export
* [ ] SQLite Database
* [ ] GUI Version (Qt)

---

## 📈 GitHub Topics

```text
c-plus-plus
cpp
library-management-system
object-oriented-programming
stl
file-handling
console-application
beginner-project
```

---

## 👨‍💻 Author

**Krishna Sharma**

* 🎓 B.Tech CSE (AI/ML)
* 💻 C++ | Python | AI/ML
* 🌱 Currently mastering DSA & Software Development

If you found this project useful, consider giving it a ⭐ on GitHub!
