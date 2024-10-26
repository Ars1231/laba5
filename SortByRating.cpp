#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;




struct Student {
    string Name;
    string LastName;
    string GroupId;
    vector<unsigned> Ratings;
    vector<std::string> Subjects;

    void cout_inf() const {
        cout << "Имя: " << Name << ",Фамилия: " << LastName
                  << ", Группа: " << GroupId << ", Средний балл: "
                  << middlegrad() << std::endl;
    }

    double middlegrad() const {
        if (Ratings.empty()) return 0.0;
        return static_cast<double>(accumulate(Ratings.begin(), Ratings.end(), 0)) / Ratings.size();
    }
};


void SortByAverageRating(std::vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.middlegrad() > b.middlegrad();
    });
}

int main() {
    vector<Student> students = {
       {"Anna", "Ivanova", "Group1", {4, 5, 5, 3}, {"Math", "Physics"}},
        {"Ivan", "Vitaly", "Group2", {2, 5, 4, 3}, {"Biology", "Chemistry"}},
        {"Ars", "Potapov", "Group3", {5, 5, 5, 5}, {"History", "Literature"}}
    };
    

    cout << "До сортировки:" << endl;
    for (const auto& student : students) {
        student.cout_inf();
    }

    SortByAverageRating(students);
    
    cout << "\n После сортировки:" << std::endl;
    for (const auto& student : students) {
        student.cout_inf();
    }

    return 0;
}
