#ifndef TASKPERSONNEL_H
#define TASKPERSONNEL_H

#include "Task.h"

class TaskPersonnel : public Task {
private:
    string deadline;

public:
    TaskPersonnel();
    TaskPersonnel(int id, string n, string d, string deadline);
    TaskPersonnel(const TaskPersonnel& tp);

    string getDeadline() const;
    void setDeadline(string dl);

    void afficher() const override;

    ~TaskPersonnel();
};

#endif
