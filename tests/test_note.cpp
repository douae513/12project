#include "gtest/gtest.h"
#include "Note.h"

TEST(NoteTest, Creation) {
    Note note("Titre", "Texte", "Travail", true);

    EXPECT_EQ(note.getTitle(), "Titre");
    EXPECT_EQ(note.getContent(), "Texte");
    EXPECT_EQ(note.getCollectionName(), "Travail");
    EXPECT_TRUE(note.getIsImportant());
    EXPECT_FALSE(note.getLocked());
}

TEST(NoteTest, LockAndModify) {
    Note note("Titre", "Texte", "Travail", false);
    note.lock();

    note.setTitle("NouveauTitre");
    note.setContent("NouveauTexte");
    note.setCollectionName("Perso");

    EXPECT_EQ(note.getTitle(), "Titre");
    EXPECT_EQ(note.getContent(), "Texte");
    EXPECT_EQ(note.getCollectionName(), "Travail");
}

TEST(NoteTest, UnlockAndModify) {
    Note note("Titre", "Texte", "Travail", false);
    note.lock();
    note.unlock();

    note.setTitle("NouveauTitre");
    note.setContent("NouveauTexte");
    note.setCollectionName("Perso");

    EXPECT_EQ(note.getTitle(), "NouveauTitre");
    EXPECT_EQ(note.getContent(), "NouveauTexte");
    EXPECT_EQ(note.getCollectionName(), "Perso");
}

TEST(NoteTest, ImportantFlag) {
    Note note("Titre", "Texte", "Travail", false);
    EXPECT_FALSE(note.getIsImportant());

    note.setImportant(true);
    EXPECT_TRUE(note.getIsImportant());
}
