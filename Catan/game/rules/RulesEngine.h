//
// Created by andja on 6.1.26..
//

#ifndef CATAN_RULESENGINE_H
#define CATAN_RULESENGINE_H

#include "Rule.h"
#include <memory>
#include <vector>

class GameSession;

/**
 * @ingroup rules
 * @brief Drzi sva pravila igre i evaluira ih kada treba
 *
 * Ovako mozemo da pravimo custom game logic i menjamo pravila radi kastomizacije
 */
class RulesEngine {
private:
    std::vector<std::unique_ptr<Rule>> m_rules; ///< engine je vlasnik liste pravila
public:
    RulesEngine();

    /**
     * @brief Dodaje pravilo u listu
     * @param rule Pravilo cije vlasnistvo preuzima engine
     *
     */
    void addRule(std::unique_ptr<Rule> rule);

    /**
     * @brief Evaluira sva pravila redom kojim su dodata
     * @param session Sesija nad kojom se pravila izvrsavaju
     */
    void evaluate(GameSession& session) const;
};

#endif //CATAN_RULESENGINE_H
