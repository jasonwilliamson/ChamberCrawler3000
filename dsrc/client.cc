#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "constants.h"
#include "controller.h"

using namespace std;

int main(int argc, char* argv[]) {
    Controller *controller;
    char filedata[HEIGHT * 5][WIDTH];
    bool customfile = false;
    if (argc % 2 == 0) {
        cerr << "Usage: cc3k -f [filepath] -s [seed]" << endl;
        return 1;
    } else if (argc > 1) {
        for (int i = 1; i < argc; i += 2) {
            string arg = argv[i];
            string val = argv[i + 1];
            if (arg == "-s") {
                istringstream ss(val);
                int seed = time(NULL);
                if (ss >> seed) {
                    srand(seed);
                } else {
                    cerr << "Error: not a valid seed" << endl;
                    return 1;
                }
            } else if (arg == "-f") {
                ifstream fs;
                fs.open(val.c_str());
                if (fs.is_open()) {
                    fs >> noskipws;
                    char cell;
                    for (int r = 0; r < HEIGHT * 5; r++) {
                        for (int c = 0; c < WIDTH; c++) {
                            fs >> cell;
                            if (cell == '\n') { fs >> cell; }
                            if (fs.fail()) {
                                cerr << "Error: file was not read properly" << endl;
                                return 1;
                            }
                            filedata[r][c] = cell;
                        }
                    }
                    customfile = true;
                    fs.close();
                } else {
                    cerr << "Error: not a valid filepath" << endl;
                    return 1;
                }
            } else {
                cerr << "Usage: cc3k -f [filepath] -s [seed]" << endl;
                return 1;
            }
        }
    }
    
    if (customfile) {
        controller = new Controller(filedata);
    } else {
        controller = new Controller();
    }
    controller->play();
}
