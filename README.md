# 🎓 Student Record Management System (C++)

A **console-based application** designed to manage and maintain student academic records efficiently. This system allows an admin to perform operations such as student registration, marks entry, grade calculation, attendance recording, and sorting, with all data saved persistently using file handling.

---

## 📌 Key Features

### 🔐 Admin Authentication
- Login system with hardcoded credentials (`admin` / `123`)
- Maximum of 3 attempts for secure access

### 👨‍🎓 Student Management
- Register students with:
  - Unique Student ID
  - Full name
  - Validated email (`example@gmail.com`)
  - Formatted phone number (`0123-4567891`)
  
### 📚 Academic Records
- Enter and update marks for:
  - Computer Programming
  - ICT
  - Discrete Mathematics
  - Physics
  - Ethics
  - Islamic Studies
- Calculate total and average marks
- Grade assignment:
  - `A` (90–100), `B` (80–89), `C` (70–79), `D` (60–69), `F` (<60)

### 📝 Attendance Tracking
- Add attendance percentage per student (0–100%)
  
### 📋 Display & Reporting
- View a list of all registered students with:
  - Contact information
  - Total marks, average, and grade
  - Attendance %
  
### 📊 Sorting & Analysis
- Sort students in descending order by total marks

### 💾 File Handling
- Automatically saves all records to `students.txt`
- Loads saved records on startup

---

## 📂 Files

- `Student_record_system.txt`: Complete source code of the Student record management system.

----

## 📚 Project Context

This project was developed to demonstrate the application of object-oriented programming principles in C++. It simulates a real-world academic system that allows for student registration, record tracking, grade computation, and attendance management. The project reinforces concepts such as class structures, file I/O, encapsulation, data validation, and sorting algorithms.

---

### 👩‍💻 Created by _Eesha Aousaf_
