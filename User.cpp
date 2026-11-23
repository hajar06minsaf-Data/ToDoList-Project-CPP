#include "../include/User.h"
#include <iostream>
#include <algorithm>

static int nextTaskId = 1; // Compteur global pour les IDs de tâches

User::User() : id_user(0), nom_utilisateur("") {}

User::User(int id, string nom) : id_user(id), nom_utilisateur(nom) {}

// Getters
int User::getId() const { return id_user; }
string User::getNom() const { return nom_utilisateur; }

// Setters
void User::setId(int id) { id_user = id; }
void User::setNom(string n) { nom_utilisateur = n; }

// Ajouter une tâche générique
void User::ajouterTask(string nom, string description) {
    Task* t = new Task(nextTaskId++, nom, description);
    tasks.push_back(t);
    cout << "  ✔ Tâche ajoutée : " << nom << endl;
}

// Ajouter une tâche personnelle
void User::ajouterTaskPersonnel(string nom, string description, string deadline) {
    TaskPersonnel* tp = new TaskPersonnel(nextTaskId++, nom, description, deadline);
    tasks.push_back(tp);
    cout << "  ✔ Tâche personnelle ajoutée : " << nom << endl;
}

// Ajouter une tâche professionnelle
void User::ajouterTaskProfessionnel(string nom, string description, string categorie) {
    TaskProfessionnel* tp = new TaskProfessionnel(nextTaskId++, nom, description, categorie);
    tasks.push_back(tp);
    cout << "  ✔ Tâche professionnelle ajoutée : " << nom << endl;
}

// Supprimer une tâche par ID
void User::supprimerTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            tasks.erase(it);
            cout << "  ✔ Tâche [" << id << "] supprimée." << endl;
            return;
        }
    }
    cout << "  ✗ Tâche [" << id << "] introuvable." << endl;
}

// Afficher toutes les tâches (polymorphisme)
void User::afficherTasks() const {
    if (tasks.empty()) {
        cout << "  Aucune tâche enregistrée." << endl;
        return;
    }
    cout << "\n  === Tâches de " << nom_utilisateur << " ===" << endl;
    for (const Task* t : tasks) {
        t->afficher(); // appel polymorphique
        cout << "  " << string(40, '-') << endl;
    }
}

// Marquer une tâche comme terminée
void User::marquerTerminee(int id) {
    Task* t = rechercherTask(id);
    if (t) {
        t->setEtat(true);
        cout << "  ✔ Tâche [" << id << "] marquée comme terminée." << endl;
    } else {
        cout << "  ✗ Tâche [" << id << "] introuvable." << endl;
    }
}

// Rechercher une tâche par ID
Task* User::rechercherTask(int id) const {
    for (Task* t : tasks) {
        if (t->getId() == id) return t;
    }
    return nullptr;
}

// Connexion simulée
void User::connecter() {
    cout << "\n  ✔ Utilisateur connecté : " << nom_utilisateur
         << " (ID: " << id_user << ")" << endl;
}

// Destructeur: libération mémoire
User::~User() {
    for (Task* t : tasks) {
        delete t;
    }
    tasks.clear();
}
