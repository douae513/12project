#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <string>
#include "Note.h"
#include "Observer.h"

class Collection : public Observer {
private:
    std::string name;
    std::vector<Note*> notes;
    bool isImportant = false;
public:
    Collection(const std::string& name);

    std::string getName() const;
    int getNoteCount() const;

    void setEstImportante(bool value);
    bool getEstImportante() const;

    void addNote(Note* note);
    void removeNote(const std::string& title);

    void displayNotes() const;
    void update() override; // implémentée dans .cpp
    void updateWithNote(Note* note) override;
    const std::vector<Note*>& getNotes() const;



};

#endif // COLLECTION_H
