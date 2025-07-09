#include <iostream>
#include <string>
#include <map>
#include "les_h/NoteManager.h"
#include "les_h/Collection.h"
#include"les_h/Note.h"
#include"les_h/Observer.h"

int main() {
    NoteManager manager;
    std::map<std::string, Collection*> collections;

    int choix = 0;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Ajouter une note\n";
        std::cout << "2. Supprimer une note\n";
        std::cout << "3. Afficher toutes les notes\n";
        std::cout << "4. Afficher les notes importantes\n";
        std::cout << "5. Verrouiller / Deverrouiller une note\n";
        std::cout << "6. Quitter\n";
        std::cout << "Choix : ";
        std::cin >> choix;
        std::cin.ignore();

        if (choix == 1) {
            std::string titre, contenu, nomCollection;
            char importantChar;

            std::cout << "Titre : ";
            std::getline(std::cin, titre);

            std::cout << "Contenu : ";
            std::getline(std::cin, contenu);

            std::cout << "Nom de la collection : ";
            std::getline(std::cin, nomCollection);

            std::cout << "Cette note est-elle importante ? (o/n) : ";
            std::cin >> importantChar;
            std::cin.ignore();

            bool estImportante = (importantChar == 'o' || importantChar == 'O');

            // Création ou récupération de la collection
            if (collections.find(nomCollection) == collections.end()) {
                collections[nomCollection] = new Collection(nomCollection);
                manager.addObserver(collections[nomCollection]);
            }

            Note* note = new Note(titre, contenu, nomCollection, estImportante);
            manager.addNote(note);

        } else if (choix == 2) {
            std::string titre;
            std::cout << "Titre de la note à supprimer : ";
            std::getline(std::cin, titre);
            manager.deleteNote(titre);

        } else if (choix == 3) {
            manager.afficherToutesLesNotes();

        } else if (choix == 4) {
            manager.afficherNotesImportantes();

        } else if (choix == 5) {
            std::string titre;
            std::cout << "Titre de la note à modifier : ";
            std::getline(std::cin, titre);

            Note* note = manager.getNote(titre);
            if (!note) {
                std::cout << "Note non trouvée.\n";
            } else {
                if (note->getLocked()) {
                    note->unlock();
                    std::cout << "Note deverrouillée.\n";
                } else {
                    note->lock();
                    std::cout << "Note verrouillée.\n";
                }
            }
        }

    } while (choix != 6);

    // Nettoyage mémoire
    for (auto& pair : collections) {
        delete pair.second;
    }

    std::cout << "Au revoir !\n";
    return 0;
}
