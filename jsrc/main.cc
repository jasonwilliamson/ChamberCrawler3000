/*
 Implemented for local tests only
 ********************************
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "controller.h"
#include "constants.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Controller *controller;
    string cmd;
    char fileGrid[HEIGHT][WIDTH];
    //char **fileGrid;
    while (cin >> cmd) {
        
        if (cmd == "include") {
            string file;
            cin >> file;
            ifstream fs;
            cout << "opening " << file << endl;
            fs.open(file.c_str());
            if (fs.is_open()) {
                fs >> noskipws;
                char cell;
                for (int r = 0; r < HEIGHT; r++) {
                    for (int c = 0; c < WIDTH; c++) {
                        fs >> cell;
                        cout << cell << endl;
                        if (cell == '\n') { fs >> cell; }
                        if (fs.fail()) {
                            cerr << "Error: file was not read properly" << endl;
                            return 1;
                        }
                        fileGrid[r][c] = cell;
                    }
                }
            }
            fs.close();
            break;
        }
    }
    cout << "calling new controller" << endl;
    controller = new Controller(fileGrid[HEIGHT][WIDTH]);
    //controller->play();
}
