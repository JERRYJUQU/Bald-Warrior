#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H

#include "treasure.h"

class MerchantHoard :
    public Treasure
{
    int amount = 4;
public:
    MerchantHoard(int x, int y,
        std::shared_ptr <Observer> display);
    virtual void effect(Hero& hero) override;
};

#endif