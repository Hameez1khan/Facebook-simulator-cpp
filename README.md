# Facebook Simulator – C++ Console-Based Social Network Manager

A lightweight, console-based C++ application that simulates basic social networking functionalities. Built as a final project for the *Basics of Programming 2* course, this program allows users to manage a simplified Facebook-like database system including member registration, group affiliations, and data persistence.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Testing](#testing)
- [Improvements and Future Work](#improvements-and-future-work)
- [Difficulties Encountered](#difficulties-encountered)
- [Author](#author)
- [License](#license)

---

## 🧩 Overview

This C++ project simulates a simplified version of a social networking platform, enabling the creation and management of users and groups via a command-line interface. It showcases core programming concepts such as:

- Object-Oriented Programming (OOP)
- File Handling
- Dynamic Memory Management
- Modular Design
- Input Validation and Error Handling

---

## 🚀 Features

- **Add New Member** – Collect and store personal data including nickname, names, place, date of birth, and optional group affiliations.
- **Search Members** – Locate members by nickname.
- **Delete Members** – Remove a member from the database.
- **Group Management** – Add/remove members to/from groups.
- **Display Functions** – View all members, or those belonging to a specific group.
- **Data Persistence** – Save and load user data via a structured text file (`facebook.txt`).
- **Robust Input Handling** – Boundary and format checks for user input.

---

## 🗂 Project Structure

```bash
📁 FacebookSimulator/
│
├── 📄 main.cpp             # Entry point – CLI Menu + Execution Logic
├── 📄 container.cpp        # Manages dynamic member storage and operations
├── 📄 member.cpp           # Member class – encapsulates user data
├── 📄 date.cpp             # Date class – handles birthdate and validations
├── 📄 facebook.txt         # (Auto-generated) Member data storage
├── 📄 README.md            # Project documentation
```

---

## ⚙️ Getting Started

### Prerequisites

Ensure you have a standard C++ compiler like:
- GCC
- Clang
- MSVC

### Compile & Run

#### Using Terminal:

```bash
g++ -o facebook main.cpp
./facebook
```

#### Using Visual Studio:

1. Open `main.cpp`
2. Press `Ctrl + Alt + N` to run the program (via Code Runner)
3. Ensure `facebook.txt` is in the same directory.

---

## 🧑‍💻 Usage

When executed, the program displays a menu with the following options:

```
1. Enter a new member in the data.
2. Search a member in the data.
3. Delete a member in the data.
4. Add a member to a group.
5. Remove a member from a group.
6. List all group members.
7. List all members in the data.
8. Exit the program.
```

Each option will guide the user through relevant input prompts. Input validation is included for dates, group assignments, and duplicate entries.

---

## ✅ Testing

The system was rigorously tested using various input types to ensure:

- Valid date formats and logical correctness (e.g., leap years).
- Member addition/deletion under normal and boundary conditions.
- Robustness during invalid input.
- File I/O consistency for persistent storage.

Testing strategies included:
- **Functional Testing**
- **Integration Testing**
- **Boundary Testing**
- **User Interface Testing**

---

## 💡 Improvements and Future Work

The current implementation is console-based and built for educational purposes. Below are potential enhancements:

### UI/UX
- Implement a **GUI** using frameworks like Qt or GTK to improve usability.

### Data Management
- Introduce **hash tables** or **search indexing** for faster lookup and better scalability.

### Authentication
- Add **user login & password protection** for secure access and personalization.

### Object-Oriented Refinement
- Improve **encapsulation**, **inheritance**, and **exception handling** for greater modularity.

---

## 🧱 Difficulties Encountered

- Designing a flexible **file storage mechanism** to support variable-length group data per user.
- Applying **Object-Oriented Programming principles** effectively within a multi-class structure.
- Managing **dynamic memory allocation** and avoiding memory leaks.
- Ensuring cross-platform **input validation** and smooth CLI experience.

---

## 👨‍💻 Author

**Muhammad Hameez Khan**  
*Lab Group: CS16D*  
*Neptune Code: TFBB32*  
**Instructor:** Vaitkus Márton

---

## 📄 License

This project is educational and open for modification. You may use and adapt it for learning or demonstration purposes. Attribution is appreciated.

---

## 📎 References

- [C++ File Handling – YouTube](https://www.youtube.com/watch?v=Cz4fl-TUjVk&t=91s)
- [C++ Basics – GeeksforGeeks](https://www.geeksforgeeks.org/c-plus-plus/)
