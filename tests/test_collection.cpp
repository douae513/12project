#include "gtest/gtest.h"
#include "Collection.h"
#include "Note.h"

TEST(CollectionTest, AddAndCountNotes) {
    Note* note1 = new Note("N1", "T1", "Travail", false);
    Note* note2 = new Note("N2", "T2", "Travail", false);
    Collection col("Travail");

    col.addNote(note1);
    col.addNote(note2);

    EXPECT_EQ(col.getNoteCount(), 2);

    delete note1;
    delete note2;
}

TEST(CollectionTest, RemoveUnlockedNote) {
    Note* note = new Note("N1", "T1", "Travail", false);
    Collection col("Travail");

    col.addNote(note);
    col.removeNote("N1");

    EXPECT_EQ(col.getNoteCount(), 0);

    delete note;
}

TEST(CollectionTest, BlockedNoteNotRemoved) {
    Note* note = new Note("N1", "T1", "Travail", false);
    note->lock();

    Collection col("Travail");
    col.addNote(note);
    col.removeNote("N1");  // Ne doit pas être supprimée

    EXPECT_EQ(col.getNoteCount(), 1);

    delete note;
}
