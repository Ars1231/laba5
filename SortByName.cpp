#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


template<class RandomIt>
void sort(RandomIt first, RandomIt last);


struct Student {
    string Name;
    string LastName;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> Subjects;
    void cout_inf() const{
        cout << "Имя: " << Name << ", Фамилия: " << LastName << ", Группа: " << GroupId << endl;
        cout << "Оценки: ";
        for (const auto& rating : Ratings) {
            cout << rating << " ";
        }
        cout << endl;
    }
};


void SortByName(vector<Student>& students) {
    sort(students.begin(), students.end(), []( Student& a,  Student& b) {
        return a.Name < b.Name; 
    });
}

int main() {
    vector<Student> students = {
        {"Anna", "Ivanova", "Group1", {4, 5, 5, 3}, {"Math", "Physics"}},
        {"Ivan", "Vitaly", "Group2", {2, 5, 4, 3}, {"Biology", "Chemistry"}},
        {"Ars", "Potapov", "Group3", {5, 5, 5, 5}, {"History", "Literature"}}
    };

    SortByName(students);

    cout << "\n После сортировки:" << endl;
    for (const auto& student : students) {
        student.cout_inf();
    }

    return 0;
}
