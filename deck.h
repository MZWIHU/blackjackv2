//
// Created by Martin on 02.11.2022.
//

#ifndef BLACKJACKV2_DECK_H
#define BLACKJACKV2_DECK_H
#include "vector"
#include "cards.h"
#include "iostream"

class Deck {
public:
    std::vector <Card> stack;

    Deck();

    void printDeck();

   void shuffle();

};

#endif //BLACKJACKV2_DECK_H
