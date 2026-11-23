#ifndef TASKPROFESSIONNEL_H
#define TASKPROFESSIONNEL_H

#include "Task.h"

class TaskProfessionnel : public Task {
private:
    string categorie;

public:
    TaskProfessionnel();
    TaskProfessionnel(int id, string n, string d, string categorie);
    TaskProfessionnel(const TaskProfessionnel& tp);

    string getCategorie() const;
    void setCategorie(string cat);

    void afficher() const override;

    ~TaskProfessionnel();
};

#endif
