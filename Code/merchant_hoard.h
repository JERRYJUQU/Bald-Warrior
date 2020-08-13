#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H

#include "treasure.h"

class MerchantHoard :
    public Treasure
{
    int amount = 4;
public:
    MerchantHoard(Position pos);
    virtual void effect(Hero& hero) override;
};

#endif