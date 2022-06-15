#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct UndoRedo
{
    vector<string> text;
    vector<string> vecUndo;

    void write(string n)
    {
        text.push_back(n);
    }
    void undo()
    {
        vecUndo.push_back(text[text.size() - 1]);
        text.pop_back();
    }
    void redo()
    {
        text.push_back(vecUndo[vecUndo.size() - 1]);
        vecUndo.pop_back();
    }
    
};
int main()
{
    UndoRedo s;
    s.write("a");
    s.write("b");
    s.write("c");
    s.write("d");
    // s.print();
    // cout << "*********************" << endl;
    // s.undo();
    // s.undo();
    // s.print2();
    // cout << "*********************" << endl;
    // s.print();
    // cout << "*********************" << endl;
    // s.redo();
    // s.print();
    // cout << "*********************" << endl;
    // s.redo();
    // s.print();
    // cout << "*********************" << endl;
}