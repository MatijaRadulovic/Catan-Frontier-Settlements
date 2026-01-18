//
// Created by jovan on 18/01/2026.
//

#ifndef CATAN_MOVEPARSER_H
#define CATAN_MOVEPARSER_H
#include "gamemodel/GameSession.h"


class MoveParser {
    public:
    static void parseMove(GameSession& session, std::string command);
};

#endif //CATAN_MOVEPARSER_H