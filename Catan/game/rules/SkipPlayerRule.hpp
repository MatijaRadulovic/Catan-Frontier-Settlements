//
// Created by matija on 1/27/26.
//

#ifndef CATAN_SKIPPLAYERRULE_HPP
#define CATAN_SKIPPLAYERRULE_HPP
#include <rules/Rule.h>

/**
 * @ingroup rules
 * @brief Pravilo koje preskace potez igraca koji nije aktivan
 */
class SkipPlayerRule: public Rule  {
public:
    /**
     * @brief Ako igrac na potezu nije aktivan, prebacuje potez na sledeceg
     * @param session Sesija ciji se tekuci igrac proverava
     */
    void evaluate(GameSession& session) override;

};

#endif //CATAN_SKIPPLAYERRULE_HPP
