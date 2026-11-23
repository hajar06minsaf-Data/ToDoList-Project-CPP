#include "../include/Task.h"

// Constructeur par défaut
Task::Task() : id_task(0), nom(""), description(""), etat(false) {}

// Constructeur paramétré
Task::Task(int id, string n, string d)
    : id_task(id), nom(n), description(d), etat(false) {}

// Constructeur de copie
Task::Task(const Task& t)
    : id_task(t.id_task), nom(t.nom), description(t.description), etat(t.etat) {}

// Getters
int Task::getId() const { return id_task; }
string Task::getNom() const { return nom; }
string Task::getDescription() const { return description; }
bool Task::getEtat() const { return etat; }

// Setters
void Task::setId(int id) { id_task = id; }
void Task::setNom(string n) { nom = n; }
void Task::setDescription(string d) { description = d; }
void Task::setEtat(bool e) { etat = e; }

// Opérateur d'affectation
Task& Task::operator=(const Task& t) {
    if (this != &t) {
        id_task = t.id_task;
        nom = t.nom;
        description = t.description;
        etat = t.etat;
    }
    return *this;
}

// Affichage de base
void Task::afficher() const {
    cout << "  [ID: " << id_task << "] " << nom << endl;
    cout << "  Description : " << description << endl;
    cout << "  Etat        : " << (etat ? "✔ Terminée" : "⏳ En cours") << endl;
}

// Surcharge opérateur <<
ostream& operator<<(ostream& os, const Task& t) {
    os << "[" << t.id_task << "] " << t.nom << " - " << (t.etat ? "Terminée" : "En cours");
    return os;
}

// Destructeur
Task::~Task() {}
