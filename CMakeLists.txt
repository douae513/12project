cmake_minimum_required(VERSION 3.30)
project(12project)

set(CMAKE_CXX_STANDARD 20)

# === INCLUDES ===
include_directories(les_h)
file(GLOB SOURCES "les_cpp/*.cpp")

# === GOOGLE TEST ===
enable_testing()
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# === EXÉCUTABLE PRINCIPAL (main interactif) ===
add_executable(main_exec
        main.cpp
        les_cpp/Note.cpp
        les_cpp/Collection.cpp
        les_cpp/Observer.cpp
        les_cpp/NoteManager.cpp
)
target_include_directories(main_exec PRIVATE les_h)

# === TESTS ===
add_executable(tests
        tests/test_note.cpp
        tests/test_collection.cpp
        tests/test_observer.cpp
        les_cpp/Note.cpp
        les_cpp/Collection.cpp
        les_cpp/Observer.cpp
        les_cpp/NoteManager.cpp
)
target_link_libraries(tests gtest gtest_main)
target_include_directories(tests PRIVATE les_h)