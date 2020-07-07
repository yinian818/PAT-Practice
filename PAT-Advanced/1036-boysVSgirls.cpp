#include <string>
#include <iostream>

using namespace std;
typedef struct
{
    string name;
    char gender;
    string id;
    short grade;
} Student;

int main()
{
    int n;
    cin >> n;

    Student stu[n];
    Student m, f;
    Student *min_m = &m;
    Student *max_f = &f;

    m.grade = 101;
    f.grade = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].gender >> stu[i].id >> stu[i].grade;
        // cin;
        // cin;
        // cin;
        if (stu[i].gender == 'M' && stu[i].grade < min_m->grade)
        {
            min_m = &stu[i];
        }
        else if (stu[i].gender == 'F' && stu[i].grade > max_f->grade)
        {
            max_f = &stu[i];
        }
    }

    if (max_f->grade != -1)
        cout << max_f->name << ' ' << max_f->id << '\n';
    else
        cout << "Absent" << '\n';
    if (min_m->grade != 101)
        cout << min_m->name << ' ' << min_m->id << '\n';
    else
        cout << "Absent" << '\n';
    if (max_f->grade != -1 && min_m->grade != 101)
        cout << (max_f->grade - min_m->grade);
    else
        cout << "NA";

    return 0;
}
