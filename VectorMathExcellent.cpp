
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Student {
    std::string Name;
    std::string LastName;
    std::string GroupId;
    std::vector<unsigned> Ratings; 
    std::vector<std::string> Subjects;
};

vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    vector<Student> excellentMathStudents;

    for (const auto& student : students) {
        auto it = std::find(student.Subjects.begin(), student.Subjects.end(), "Math");
        if (it != student.Subjects.end()) {
            size_t index = std::distance(student.Subjects.begin(), it); 
            if (student.Ratings.size() > index && student.Ratings[index] == 5) {
                excellentMathStudents.push_back(student); 
            }
        }
    }

    return excellentMathStudents; 
}

int main() {
    vector<Student> students = {
        {"Anna", "Ivanova", "Group1", {5, 4}, {"Math", "Physics"}},     
        {"Ivan", "Vitaly", "Group2", {2, 4}, {"Biology", "Chemistry"}}, 
        {"Ars", "Potapov", "Group3", {5, 5}, {"Math", "Literature"}}    
    };

    vector<Student> excellentMathStudents = VectorMathExcellent(students);
    cout << "Студенты с отлом по матану:" << endl;
    for (const auto& student : excellentMathStudents) {
        cout << student.LastName << endl; 
    }

    return 0;
}
