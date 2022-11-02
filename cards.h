//
// Created by Martin on 02.11.2022.
//

#ifndef BLACKJACKV2_CARDS_H
#define BLACKJACKV2_CARDS_H

#include "iostream"


class Card {
public:

    enum color {
        hearts,
        diamonds,
        spades,
        clubs
    };

    enum number {
        ace = 1,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king
    };


    color c;
    number n;


    Card(color c, number n);

    std::string toString(color, number);
};


#endif //BLACKJACKV2_CARDS_H
