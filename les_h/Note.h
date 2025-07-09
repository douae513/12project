#ifndef NOTE_H
#define NOTE_H
#include <string>

class Note {
private:
    std::string title;
    std::string content;
    bool locked;
    std::string collectionName;
    bool isImportant;

public:
    // Constructeur
    Note(const std::string& title, const std::string& content, const std::string& collectionName, bool isImportant = false);

    // Getters
    std::string getTitle() const;
    std::string getContent() const;
    std::string getCollectionName() const;
    bool getLocked() const;
    bool getIsImportant() const;

    // Setters
    void setTitle(const std::string& newTitle);
    void setContent(const std::string& newContent);
    void setCollectionName(const std::string& newCollectionName);
    void setImportant(bool important);

    // Lock / Unlock
    void lock();
    void unlock();

    // Utilitaire
    void display() const;
};

#endif // NOTE_H

