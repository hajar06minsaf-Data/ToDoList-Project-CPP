#include "../include/TaskPersonnel.h"

TaskPersonnel::TaskPersonnel() : Task(), deadline("") {}

TaskPersonnel::TaskPersonnel(int id, string n, string d, string dl)
    : Task(id, n, d), deadline(dl) {}

TaskPersonnel::TaskPersonnel(const TaskPersonnel& tp)
    : Task(tp), deadline(tp.deadline) {}

string TaskPersonnel::getDeadline() const { return deadline; }
void TaskPersonnel::setDeadline(string dl) { deadline = dl; }

void TaskPersonnel::afficher() const {
    cout << "  [PERSONNEL] ";
    Task::afficher();
    cout << "  Deadline    : " << deadline << endl;
}

TaskPersonnel::~TaskPersonnel() {}
