//
// Created by andja on 6.1.26..
//

#ifndef CATAN_VICTORYRULE_H
#define CATAN_VICTORYRULE_H

#include "Rule.h"

/**
 * @ingroup rules
 * @brief Pravilo zaduzeno za racunanje poena i proveru da li je igra gotova i ko je pobedio
 */
class GameOverRule : public Rule {
public:
    /**
     * @brief Trazi igraca sa dovoljno poena, upisuje ga kao pobednika i zavrsava partiju
     * @param session Sesija ciji se igraci proveravaju
     */
    void evaluate(GameSession& session) override;
};

#endif //CATAN_VICTORYRULE_H
