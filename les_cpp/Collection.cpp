#include "Collection.h"
#include <iostream>

Collection::Collection(const std::string& name) : name(name) {}

std::string Collection::getName() const {
    return name;
}

int Collection::getNoteCount() const {
    return notes.size();
}

void Collection::addNote(Note* note) {
    notes.push_back(note);
}

void Collection::removeNote(const std::string& title) {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if ((*it)->getTitle() == title && !(*it)->getLocked()) {
            notes.erase(it);
            return;
        }
    }
}

void Collection::displayNotes() const {
    std::cout << "Collection: " << name << " (" << notes.size() << " notes)\n";
    for (const auto& note : notes) {
        note->display();
        std::cout << "--------------------------\n";
    }
}
void Collection::update() {
    std::cout << "La collection \"" << name << "\" a été notifiée. Elle contient maintenant "
              << notes.size() << " note(s).\n";
}
void Collection::updateWithNote(Note* note) {
    if (note->getCollectionName() == name || (isImportant && note->getIsImportant())) {
        notes.push_back(note);
        std::cout << "Note ajoutée à la collection \"" << name << "\" automatiquement.\n";
    }
}
const std::vector<Note*>& Collection::getNotes() const {
    return notes;
}

void Collection::setEstImportante(bool value) {
    isImportant = value;
}
bool Collection::getEstImportante() const {
    return isImportant;
}