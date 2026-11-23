#include "../include/TaskProfessionnel.h"

TaskProfessionnel::TaskProfessionnel() : Task(), categorie("") {}

TaskProfessionnel::TaskProfessionnel(int id, string n, string d, string cat)
    : Task(id, n, d), categorie(cat) {}

TaskProfessionnel::TaskProfessionnel(const TaskProfessionnel& tp)
    : Task(tp), categorie(tp.categorie) {}

string TaskProfessionnel::getCategorie() const { return categorie; }
void TaskProfessionnel::setCategorie(string cat) { categorie = cat; }

void TaskProfessionnel::afficher() const {
    cout << "  [PROFESSIONNEL] ";
    Task::afficher();
    cout << "  Catégorie   : " << categorie << endl;
}

TaskProfessionnel::~TaskProfessionnel() {}
