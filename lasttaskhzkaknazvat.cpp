#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    std::string Name;
    std::string LastName;
    std::string GroupId;
    std::vector<unsigned> Ratings; 
    std::vector<std::string> Subjects;
};

struct Group {
    std::string Id;
    std::vector<Student> Students;
};


vector<Group> Groups(const std::vector<Student>& students) {
    vector<Group> groups; 

    for (const auto& student : students) {
        auto it = find_if(groups.begin(), groups.end(), 
            [&student](const Group& group) { return group.Id == student.GroupId; });

        if (it != groups.end()) it->Students.push_back(student);
        else {
            Group newGroup;
            newGroup.Id = student.GroupId;
            newGroup.Students.push_back(student);
            groups.push_back(newGroup);
        }
    }

    return groups;
}

int main() {
    vector<Student> students = {
        {"Anna", "Ivanova", "Group1", {5, 4}, {"Math", "Physics"}},
        {"Ivan", "Vitaly", "Group2", {2, 4}, {"Biology", "Chemistry"}},
        {"Ars", "Potapov", "Group1", {5, 5}, {"Math", "Literature"}},
        {"Maria", "Maurina", "Group3", {4, 4}, {"Math", "History"}},
        {"Blat", "Hodorovskiy", "Group2", {3, 4}, {"Math", "Biology"}}
    };

    vector<Group> groups = Groups(students);
    cout << "Список групп:" << endl;
    for (const auto& group : groups) {
        cout << "Номер гурппы: " << group.Id << endl;
        cout << "Козеры:" << endl;
        for (const auto& student : group.Students) {
            cout << "  " << student.Name << " " << student.LastName << endl; 
        }
    }

    return 0;
}
