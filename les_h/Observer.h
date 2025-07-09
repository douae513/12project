#ifndef OBSERVER_H
#define OBSERVER_H

class Note ;
class Observer {
public:
    virtual void update() = 0;
    virtual void updateWithNote(Note* note) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
