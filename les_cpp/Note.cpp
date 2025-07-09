#include "Note.h"
#include <iostream>

Note::Note(const std::string& title, const std::string& content, const std::string& collectionName, bool isImportant)
    : title(title), content(content), locked(false), collectionName(collectionName), isImportant(isImportant) {}

std::string Note::getTitle() const {
    return title;
}

std::string Note::getContent() const {
    return content;
}

std::string Note::getCollectionName() const {
    return collectionName;
}

bool Note::getLocked() const {
    return locked;
}

bool Note::getIsImportant() const {
    return isImportant;
}

void Note::setTitle(const std::string& newTitle) {
    if (!locked) title = newTitle;
}

void Note::setContent(const std::string& newContent) {
    if (!locked) content = newContent;
}

void Note::setCollectionName(const std::string& newCollectionName) {
    if (!locked) collectionName = newCollectionName;
}

void Note::setImportant(bool important) {
    isImportant = important;
}

void Note::lock() {
    locked = true;
}

void Note::unlock() {
    locked = false;
}

void Note::display() const {
    std::cout << "Titre: " << title << "\n"
              << "Contenu: " << content << "\n"
              << "Collection: " << collectionName << "\n"
              << "Important: " << (isImportant ? "Oui" : "Non") << "\n"
              << "Bloquée: " << (locked ? "Oui" : "Non") << std::endl;
}

