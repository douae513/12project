#include "NoteManager.h"
#include <iostream>

void NoteManager::addNote(Note* note) {
    notes.push_back(note);
    notify(note);
}

void NoteManager::deleteNote(const std::string& title) {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if ((*it)->getTitle() == title && !(*it)->getLocked()) {
            delete *it;
            notes.erase(it);
            std::cout << "🗑️ Note supprimée.\n";
            return;
        }
    }
    std::cout << "⚠️ Impossible de supprimer la note (bloquée ou introuvable).\n";
}

Note* NoteManager::getNote(const std::string& title) {
    for (Note* note : notes) {
        if (note->getTitle() == title)
            return note;
    }
    return nullptr;
}

void NoteManager::afficherToutesLesNotes() const {
    for (const Note* note : notes) {
        std::cout << "- " << note->getTitle();
        std::cout << " (" << note->getCollectionName() << ")";
        std::cout << (note->getLocked() ? " [🔒]" : "");
        std::cout << (note->getIsImportant() ? " [⭐]" : "") << "\n";
    }
}

void NoteManager::afficherNotesImportantes() const {
    for (const Note* note : notes) {
        if (note->getIsImportant()) {
            std::cout << "- " << note->getTitle() << ": " << note->getContent() << "\n";
        }
    }
}

const std::vector<Note*>& NoteManager::getNotes() const {
    return notes;
}

NoteManager::~NoteManager() {
    for (Note* note : notes) {
        delete note;
    }
}
