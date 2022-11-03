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
            output = "Ace";
            break;
        case two:
            output = "Two";
            break;
        case three:
            output = "Three";
            break;
        case four:
            output = "Four";
            break;
        case five:
            output = "Five";
            break;
        case six:
            output = "Six";
            break;
        case seven:
            output = "Seven";
            break;
        case eight:
            output = "Eight";
            break;
        case nine:
            output = "Nine";
            break;
        case ten:
            output = "Ten";
            break;
        case jack:
            output = "Jack";
            break;
        case queen:
            output = "Queen";
            break;
        case king:
            output = "King";
            break;

    }

    output = output + " of ";


    switch (c) {
        case hearts:
             output = output + "Hearts";
            break;
        case diamonds:
            output += "Diamonds";
            break;
        case spades:
            output = output + "Spades";
            break;
        case clubs:
            output += "Clubs";
            break;

    }

    return output;

}


Card::Card(Card::color c, Card::number n) {

    this->c = c;
    this->n = n;

}




