#include <iostream>
#include <string>
using namespace std;

float getGradePoint(string grade) {
    if (grade == "A+" || grade == "A") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D+") return 1.3;
    else if (grade == "D") return 1.0;
    else if (grade == "F") return 0.0;
    else return -1;   
}

int main() {
    int numCourses;

    cout << "How many courses did you take? ";
    cin >> numCourses;

    string grade[numCourses];
    float creditHrs[numCourses];
    float gradePoints[numCourses];

    float sumGradePoints = 0;
    float sumCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        cout << "\n--- Course " << i + 1 << " ---" << endl;

        float gp = -1;
        while (gp == -1) {
            cout << "Grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
            cin >> grade[i];
            gp = getGradePoint(grade[i]);
            if (gp == -1) {
                cout << "That doesn't look like a valid grade, try again.\n";
            }
        }
        gradePoints[i] = gp;

        cout << "Credit hours: ";
        cin >> creditHrs[i];

        // grade points earned for this course = gradePoint * credit hours
        sumGradePoints = sumGradePoints + (gradePoints[i] * creditHrs[i]);
        sumCredits = sumCredits + creditHrs[i];
    }

    float cgpa = sumGradePoints / sumCredits;

    cout << "\n\nHere's what you entered:" << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 << " -> Grade: " << grade[i]
             << " (" << gradePoints[i] << "), Credits: " << creditHrs[i] << endl;
    }
    cout << "-------------------------------" << endl;

    cout << "\nTotal Credit Hours = " << sumCredits << endl;
    cout << "Total Grade Points = " << sumGradePoints << endl;
    cout << "Your Semester GPA = " << cgpa << endl;
    cout << "Your Overall CGPA = " << cgpa << endl;

    return 0;
}