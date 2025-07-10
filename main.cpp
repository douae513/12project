#include <iostream>
#include <string>
#include <map>
#include "les_h/NoteManager.h"
#include "les_h/Collection.h"
#include "les_h/Note.h"
#include "les_h/Observer.h"

int main() {
    NoteManager manager;
    std::map<std::string, Collection*> collections;

    int choice = 0;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Add a note\n";
        std::cout << "2. Delete a note\n";
        std::cout << "3. Show all notes\n";
        std::cout << "4. Show important notes\n";
        std::cout << "5. Lock / Unlock a note\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, content, collectionName;
            char importantChar;

            std::cout << "Title: ";
            std::getline(std::cin, title);

            std::cout << "Content: ";
            std::getline(std::cin, content);

            std::cout << "Collection name: ";
            std::getline(std::cin, collectionName);

            std::cout << "Is this note important? (y/n): ";
            std::cin >> importantChar;
            std::cin.ignore();

            bool isImportant = (importantChar == 'y' || importantChar == 'Y');

            // Create or get the collection
            if (collections.find(collectionName) == collections.end()) {
                collections[collectionName] = new Collection(collectionName);
                manager.addObserver(collections[collectionName]);
            }

            Note* note = new Note(title, content, collectionName, isImportant);
            manager.addNote(note);

        } else if (choice == 2) {
            std::string title;
            std::cout << "Title of the note to delete: ";
            std::getline(std::cin, title);
            manager.deleteNote(title);

        } else if (choice == 3) {
            manager.afficherToutesLesNotes();

        } else if (choice == 4) {
            manager.afficherNotesImportantes();

        } else if (choice == 5) {
            std::string title;
            std::cout << "Title of the note to modify: ";
            std::getline(std::cin, title);

            Note* note = manager.getNote(title);
            if (!note) {
                std::cout << "Note not found.\n";
            } else {
                if (note->getLocked()) {
                    note->unlock();
                    std::cout << "Note unlocked.\n";
                } else {
                    note->lock();
                    std::cout << "Note locked.\n";
                }
            }
        }

    } while (choice != 6);

    // Memory cleanup
    for (auto& pair : collections) {
        delete pair.second;
    }

    std::cout << "Goodbye!\n";
    return 0;
}
