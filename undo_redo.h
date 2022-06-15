#ifndef
#define
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct UndoRedo
{
    vector<string> text;
    vector<string> vecUndo;

    void write(string n);
    void undo();
    void redo();
    // void print()
    // {
    //     for (int i = 0; i < text.size(); i++)
    //     {
    //         cout << text[i] << endl;
    //     }
    // }
    // void print2()
    // {
    //     for (int i = 0; i < vecUndo.size(); i++)
    //     {
    //         cout << vecUndo[i] << endl;
    //     }
    // }
};

#endif