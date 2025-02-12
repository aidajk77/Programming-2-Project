# Automated Exam Review System

## Project Overview
This project is an **Automated Exam Review System** developed in **C++** as part of a **Programming 2** course. The system is designed to assist in reviewing exams by providing automated feedback and evaluation. It processes exam questions, accepts student responses, and offers automated grading based on predefined answers.

## Features
- **Question Management**: Supports multiple types of questions (e.g., multiple-choice, true/false, and short answers).
- **Automated Grading**: Compares student responses against correct answers and assigns scores accordingly.
- **User Interface**: Command-line based interface for student interaction.
- **Result Analysis**: Provides performance feedback and summary reports.
- **Error Handling**: Robust exception handling for invalid inputs.
- **Automated Answer Generation**: Generates random student responses for testing purposes.
- **Exam Review Functionality**: Reads exam answers from files, sorts and compares them, and evaluates student performance.

## Technologies Used
- **Language**: C++
- **Standard Library**: `<iostream>`, `<fstream>`, `<vector>`, `<map>`, `<string>`, `<algorithm>`, `<stdexcept>`
- **Data Structures**: Arrays
- **File Handling**: Reads and writes exam questions and results from files
- **Randomization**: Utilizes `<cstdlib>` and `<ctime>` for generating random student responses
- **Sorting & String Handling**: Uses `<algorithm>` for sorting answers and `<cstring>` for string manipulation


## Usage
1. **Start the Exam**: Follow the on-screen prompts to begin the review process.
2. **Answer Questions**: Enter responses as instructed.
3. **View Results**: Once completed, the system provides feedback and scores.
4. **Automated Answer Generation**: The program can generate random student answers and store them in `student_answers.txt`.
5. **Exam Review**: The system reads the student and answer key files, sorts and compares responses, and assigns scores based on accuracy.


