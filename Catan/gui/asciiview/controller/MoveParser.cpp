//
// Created by jovan on 18/01/2026.
//

#include "MoveParser.h"

#include <sstream>

#include "gamemodel/GameSession.h"
#include "move/BuildRoadMove.h"
#include "move/BuildSettlementMove.h"
#include "move/BuildCityMove.h"
#include "move/EndTurnMove.h"
#include "move/Move.h"
#include "move/RollDiceMove.h"

void MoveParser::parseMove(GameSession &session, std::string command) {

    if (command == "rolldice") {
        session.applyMove(RollDiceMove(session.currentPlayer()));
    }
    else if (command == "endturn") {
        session.applyMove(EndTurnMove(session.currentPlayer()));
    }
    else if (command.find("build(road)") != std::string::npos) {

        std::stringstream ss(command.substr( 11));

        int q, r, i;

        ss >> q >> r >> i;

        session.applyMove(BuildRoadMove(session.currentPlayer(), session.board().getEdgeAt(EdgeCoords(q, r, i))->getEdgeId()));
    }
    else if (command.find("build(settlement)") != std::string::npos) {
        std::stringstream ss(command.substr(17));

        int q, r, i;

        ss >> q >> r >> i;

        session.applyMove(BuildSettlementMove(session.currentPlayer(), session.board().getNodeAt(NodeCoords(q, r, i))->getNodeId()));
    }
    else if (command.find("build(city)") != std::string::npos) {
        std::stringstream ss(command.substr(11));

        int q, r, i;

        ss >> q >> r >> i;

        session.applyMove(BuildCityMove(session.currentPlayer(), session.board().getNodeAt(NodeCoords(q, r, i))->getNodeId()));
    }
}
