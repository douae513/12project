#include "gtest/gtest.h"
#include "NoteManager.h"
#include "Collection.h"

TEST(ObserverTest, NotifyCollectionOnAdd) {
    NoteManager manager;

    Collection col("Travail");
    col.setEstImportante(true);  // Important pour recevoir les notes importantes

    manager.addObserver(&col);

    Note* note = new Note("Urgent", "Texte", "Travail", true);
    manager.addNote(note);

    EXPECT_EQ(col.getNoteCount(), 1);

    //delete note;  // Nettoyage si NoteManager ne le fait pas
}
