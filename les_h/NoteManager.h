#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <vector>
#include <iostream>
#include "Note.h"
#include "Subject.h"
#include "Collection.h"

class NoteManager : public Subject {
private:
    std::vector<Note*> notes;

public:
    void addNote(Note* note);
    void deleteNote(const std::string& title);
    Note* getNote(const std::string& title);
    void afficherToutesLesNotes() const ;
    void afficherNotesImportantes() const;
    const std::vector<Note*>& getNotes() const;

    ~NoteManager();
};

#endif // NOTEMANAGER_H

