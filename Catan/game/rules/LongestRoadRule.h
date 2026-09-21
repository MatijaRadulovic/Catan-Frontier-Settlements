//
// Created by andja on 6.1.26..
//

#ifndef CATAN_LONGESTROADRULE_H
#define CATAN_LONGESTROADRULE_H

#include <unordered_map>

#include "Rule.h"
#include "player/Player.h"

/**
 * @ingroup rules
 * @brief Pravilo zaduzeno za pracenje, dodelu poena i racunanje ko ima najduzi put
 */
class LongestRoadRule : public Rule {
private:

    int dfsLongest(const Edge *edge, PlayerId playerId, std::unordered_set<EdgeId> &visited, std::unordered_set<NodeId> &visitedNodes);

    int computeLongestRoad(Player &p);
public:
    /**
     * @brief Racuna duzine puteva svih igraca i po potrebi menja vlasnika karte.
     * @param session Sesija sa igracima i tekucim vlasnikom karte.
     */
    void evaluate(GameSession& session) override;

};


#endif //CATAN_LONGESTROADRULE_H
