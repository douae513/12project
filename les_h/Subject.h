#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
#include <algorithm>
class Note;


class Subject {
protected:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify() {
        for (Observer* obs : observers) {
            obs->update();
        }
    }

void notify(Note* note) {
    for (Observer* obs : observers) {
        obs->updateWithNote(note);  // Appel de la nouvelle méthode
    }
}
    virtual ~Subject() = default;
};
#endif // SUBJECT_H
