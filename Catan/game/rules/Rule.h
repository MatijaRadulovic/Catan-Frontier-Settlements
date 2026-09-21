//
// Created by andja on 6.1.26..
//

#ifndef CATAN_RULE_H
#define CATAN_RULE_H

#include "types/TypeAliases.h"
class GameSession;

/**
 * @defgroup rules Pravila igre
 * @brief Pravila koja se primenjuju na stanje partije posle poteza.
 * @{
 */

/// Interfejs jednog pravila igre.
class Rule {
public:
    virtual ~Rule() = default;

    /**
     * @brief Primenjuje pravilo na tekuce stanje partije.
     * @param session Sesija cije se stanje cita i menja.
     */
    virtual void evaluate(GameSession& session) = 0;
};

/** @} */

#endif //CATAN_RULE_H
