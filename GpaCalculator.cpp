#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> grades;
    vector<int> creditHours;

    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Get grades and credit hours for each course
    for (int i = 0; i < numCourses; i++)
    {
        double grade;
        int creditHour;

        cout << "Enter the grade for course " << i+1 << ": ";
        cin >> grade;
        grades.push_back(grade);

        cout << "Enter the credit hours for course " << i+1 << ": ";
        cin >> creditHour;
        creditHours.push_back(creditHour);
    }

    // Calculate total quality points and credit hours
    double totalQualityPoints = 0;
    int totalCreditHours = 0;

    for (int i = 0; i < numCourses; i++)
    {
        totalQualityPoints += grades[i] * creditHours[i];
        totalCreditHours += creditHours[i];
    }

    // Calculate GPA
    double gpa = totalQualityPoints / totalCreditHours;

    // Output results
    cout << "GPA: " << gpa << endl;

    return 0;
}