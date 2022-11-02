//
// Created by Martin on 02.11.2022.
//

#include "cards.h"
#include "deck.h"
#include "iostream"


std::string Card::toString(color c, number n) {


    std::string output;

    switch (n) {
        case ace:
            output = "ace";
            break;
        case two:
            output = "two";
            break;
        case three:
            output = "three";
            break;
        case four:
            output = "four";
            break;
        case five:
            output = "five";
            break;
        case six:
            output = "six";
            break;
        case seven:
            output = "seven";
            break;
        case eight:
            output = "eight";
            break;
        case nine:
            output = "nine";
            break;
        case ten:
            output = "ten";
            break;
        case jack:
            output = "jack";
            break;
        case queen:
            output = "queen";
            break;
        case king:
            output = "king";
            break;

    }

    output = output + " of ";


    switch (c) {
        case hearts:
             output = output + "hearts";
            break;
        case diamonds:
            output += "diamonds";
            break;
        case spades:
            output = output + "spades";
            break;
        case clubs:
            output += "clubs";
            break;

    }

    return output;

}


Card::Card(Card::color c, Card::number n) {

    this->c = c;
    this->n = n;

}




