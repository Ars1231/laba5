#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct Student {
    std::string Name;
    std::string LastName;
    std::string GroupId;
    std::vector<unsigned> Ratings; 
    std::vector<std::string> Subjects;
};


vector<std::string> GroupsId(const std::vector<Student>& students) {
    set<string> uniqGroups; 

    for (const auto& student : students) {
        uniqGroups.insert(student.GroupId); 
    }
    
	vector<string> groupsVector(uniqGroups.begin(), uniqGroups.end());
    return groupsVector;
}

int main() {
    vector<Student> students = {
        {"Anna", "Ivanova", "Group1", {5, 4}, {"Math", "Physics"}},
        {"Ivan", "Vitaly", "Group2", {2, 4}, {"Biology", "Chemistry"}},
        {"Ars", "Potapov", "Group1", {5, 5}, {"Math", "Literature"}},
        {"Maria", "Maurina", "Group3", {4, 4}, {"Math", "History"}}
    };

    vector<string> uniqGroups = GroupsId(students);
    
    cout << "Разные группы:" << endl;
    for (const auto& group : uniqGroups) {
        cout << group << endl; 
    }

    return 0;
}
