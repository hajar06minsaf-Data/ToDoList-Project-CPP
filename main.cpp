#include <iostream>
#include <string>
#include <limits>
#include "../include/User.h"
using namespace std;

// ─────────────────────────────────────────────
//  Utilitaires d'affichage
// ─────────────────────────────────────────────
void separateur() {
    cout << "\n" << string(50, '=') << "\n";
}

void afficherBanner() {
    separateur();
    cout << "        ✅  APPLICATION ToDoList C++\n";
    cout << "        Gestion de tâches personnelles\n";
    cout << "          et professionnelles\n";
    separateur();
}

void afficherMenu() {
    cout << "\n  ┌─────────────────────────────────┐\n";
    cout << "  │         MENU PRINCIPAL          │\n";
    cout << "  ├─────────────────────────────────┤\n";
    cout << "  │  1. Ajouter une tâche simple    │\n";
    cout << "  │  2. Ajouter tâche personnelle   │\n";
    cout << "  │  3. Ajouter tâche pro           │\n";
    cout << "  │  4. Afficher toutes les tâches  │\n";
    cout << "  │  5. Marquer tâche terminée      │\n";
    cout << "  │  6. Supprimer une tâche         │\n";
    cout << "  │  0. Quitter                     │\n";
    cout << "  └─────────────────────────────────┘\n";
    cout << "  Votre choix : ";
}

int lireEntier() {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Entrée invalide. Réessayez : ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return val;
}

// ─────────────────────────────────────────────
//  Programme principal
// ─────────────────────────────────────────────
int main() {
    afficherBanner();

    // Création / connexion utilisateur
    cout << "\n  Entrez votre nom d'utilisateur : ";
    string nomUser;
    getline(cin, nomUser);

    User utilisateur(1, nomUser);
    utilisateur.connecter();

    int choix;
    do {
        afficherMenu();
        choix = lireEntier();

        switch (choix) {
            case 1: {
                cout << "  Nom de la tâche      : ";
                string nom; getline(cin, nom);
                cout << "  Description          : ";
                string desc; getline(cin, desc);
                utilisateur.ajouterTask(nom, desc);
                break;
            }
            case 2: {
                cout << "  Nom de la tâche      : ";
                string nom; getline(cin, nom);
                cout << "  Description          : ";
                string desc; getline(cin, desc);
                cout << "  Deadline (ex: 2026-06-01) : ";
                string dl; getline(cin, dl);
                utilisateur.ajouterTaskPersonnel(nom, desc, dl);
                break;
            }
            case 3: {
                cout << "  Nom de la tâche      : ";
                string nom; getline(cin, nom);
                cout << "  Description          : ";
                string desc; getline(cin, desc);
                cout << "  Catégorie (ex: Réunion, Rapport...) : ";
                string cat; getline(cin, cat);
                utilisateur.ajouterTaskProfessionnel(nom, desc, cat);
                break;
            }
            case 4:
                utilisateur.afficherTasks();
                break;
            case 5: {
                cout << "  ID de la tâche à marquer terminée : ";
                int id = lireEntier();
                utilisateur.marquerTerminee(id);
                break;
            }
            case 6: {
                cout << "  ID de la tâche à supprimer : ";
                int id = lireEntier();
                utilisateur.supprimerTask(id);
                break;
            }
            case 0:
                cout << "\n  À bientôt, " << nomUser << " ! 👋\n\n";
                break;
            default:
                cout << "  ✗ Choix invalide.\n";
        }
    } while (choix != 0);

    return 0;
}
