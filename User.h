#ifndef USER_H
#define USER_H

#include "Task.h"
#include "TaskPersonnel.h"
#include "TaskProfessionnel.h"
#include <vector>

class User {
private:
    int id_user;
    string nom_utilisateur;
    vector<Task*> tasks; // Association: User possède plusieurs Tasks

public:
    // Constructeurs
    User();
    User(int id, string nom);

    // Getters
    int getId() const;
    string getNom() const;

    // Setters
    void setId(int id);
    void setNom(string n);

    // Gestion des tâches
    void ajouterTask(string nom, string description);
    void ajouterTaskPersonnel(string nom, string description, string deadline);
    void ajouterTaskProfessionnel(string nom, string description, string categorie);
    void supprimerTask(int id);
    void afficherTasks() const;
    void marquerTerminee(int id);
    Task* rechercherTask(int id) const;

    // Connexion (simulée)
    void connecter();

    // Destructeur
    ~User();
};

#endif
