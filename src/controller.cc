int direction(char c1, char c2) {
    if (c1 == 'n') {
        if (c2 == 'w') { return 1; }
        else if (c2 == 'o') { return 2; }
        else if (c2 == 'e') { return 3; }
    } 
    else if (c1 == 'w' && c2 == 'e') { return 4; }
    else if (c1 == 'e' && c2 == 'a') { return 5; }
    else if (c1 == 's') {
        if (c2 == 'w') { return 6; }
        else if (c2 == 'o') { return 7; }
        else if (c2 == 'e') { return 8; }
    }
    return 0;
}


while (cin >> command) {
    if (command == 'q') {
        break;
    } else if (command == 'r') {
        game->init();
        game->update();
    } else if (command == 's') {
        //            Player* player = new Shade();
        //            game->setPlayer(player); //TODO
        game->init();
        game->update();
    } else if (command == 'd') {
        //drow
        //            Player* player = new Drow();
        //            game->setPlayer(player); //TODO
        game->init();
        game->update();
    } else if (command == 'v') {
        //vampire
        //            Player* player = new Vampire();
        //            game->setPlayer(player); //TODO
        game->init();
        game->update();
    } else if (command == 'g') {
        //goblin
        //            Player* player = new Goblin();
        //            game->setPlayer(player); // TODO
        game->init();
        game->update();
    } else if (command == 't') {
        //troll
        //            Player* player = new Troll();
        //            game->setPlayer(player); //TODO
        game->init();
        game->update();
    } else if (command == 'n' || command == 's' || command == 'e' || command == 'w') {
        char dir;
        cin >> dir;
        if (cin.fail()) {
            break;
        } else {
            //game->movePlayer(direction(command, dir)); //TODO
        }
    } else if (command == 'u') {
        char c1, c2;
        cin >> c1 >> c2;
        if (cin.fail()) {
            break;
        } else {
            //               player.use(direction(c1, c2));
        }
    } else if (command == 'a') {
        char c1, c2;
        cin >> c1 >> c2;
        if (cin.fail()) {
            break;
        } else {
            //               player.attack(direction(c1, c2));
        }
    }
}

