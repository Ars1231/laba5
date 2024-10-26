#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string Name;
    string LastName;
    string GroupId;
    vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
};


size_t CountTwoness(const std::vector<Student>& students) {
    size_t count = 0;
    for (const auto& student : students) {
        for (const auto& rating : student.Ratings) {
            if (rating == 2) {
                count++;
                break; 
            }
        }
    }
    
    return count;
}

int main() {
    vector<Student> students = {
         {"Anna", "Ivanova", "Group1", {4, 5, 5, 3}, {"Math", "Physics"}},
        {"Ivan", "Vitaly", "Group2", {2, 5, 4, 3}, {"Biology", "Chemistry"}},
        {"Ars", "Potapov", "Group3", {5, 5, 5, 5}, {"History", "Literature"}}
    };

    size_t count = CountTwoness(students);
    
    cout << "Cтудентов с неудами: " << count << endl;

    return 0;
}
