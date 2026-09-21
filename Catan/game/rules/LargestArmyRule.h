//
// Created by andja on 6.1.26..
//

#ifndef CATAN_LARGESTARMYRULE_H
#define CATAN_LARGESTARMYRULE_H

#include "Rule.h"

/**
 * @ingroup rules
 * @brief Pravilo zaduzeno za pracenje, dodelu poena i racunanje ko ima najvecu vojsku
 */
class LargestArmyRule : public Rule {
public:
    /**
     * @brief Nalazi igraca sa najvise vitezova i po potrebi mu dodeljuje kartu
     * @param session Sesija sa igracima i tekucim vlasnikom karte
     */
    void evaluate(GameSession& session) override;
};

#endif //CATAN_LARGESTARMYRULE_H
