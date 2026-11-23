#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
using namespace std;

class Task {
protected:
    int id_task;
    string nom;
    string description;
    bool etat; // false = en cours, true = terminée

public:
    // Constructeurs
    Task();
    Task(int id, string n, string d);
    Task(const Task& t);

    // Getters
    int getId() const;
    string getNom() const;
    string getDescription() const;
    bool getEtat() const;

    // Setters
    void setId(int id);
    void setNom(string n);
    void setDescription(string d);
    void setEtat(bool e);

    // Opérateur d'affectation
    Task& operator=(const Task& t);

    // Affichage (polymorphisme)
    virtual void afficher() const; // Polymorphisme

    // Surcharge opérateur <<
    friend ostream& operator<<(ostream& os, const Task& t);

    // Destructeur virtuel
    virtual ~Task();
};

#endif
