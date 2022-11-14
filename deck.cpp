//
// Created by Martin on 02.11.2022.
//

#include "deck.h"
#include "cards.h"
#include "algorithm"
#include "chrono"
#include "random"

Deck::Deck() {
    for (int i = 0; i <= 3; i++) {

        for (int j = 1; j <= 13; j++) {

            stack.push_back(Card ((Card::color) i , (Card::number) j));

        }
    }
}

void Deck::printDeck() {

    int j = 0;

    for (int i = 0; i < stack.size(); ++i) {
        std::string ausgabe = stack.at(i).toString(stack.at(i).c, stack.at(i).n);
        std::cout << ausgabe << " | ";
        j++;

        if (j == 4) {
            std::cout <<  " " << std::endl;
            j = 0;
        }
    }

}

void Deck::shuffle() {
    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();

    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();

    auto rng = std::default_random_engine{seed};

    std::shuffle(std::begin(stack), std::end(stack), rng);
}

int Deck::checkValue(int i, int hand) {

    switch (stack.at(i).n) {

        case Card::ace:
            if (hand > 10) {
                return 1;
            } else {
                return 11;
            }
            break;
        case Card::two:
            return 2;
            break;
        case Card::three:
            return 3;
            break;
        case Card::four:
            return 4;
            break;
        case Card::five:
            return 5;
            break;
        case Card::six:
            return 6;
            break;
        case Card::seven:
            return 7;
            break;
        case Card::eight:
            return 8;
            break;
        case Card::nine:
            return 9;
            break;
        case Card::ten:
            return 10;
            break;
        case Card::jack:
            return 10;
            break;
        case Card::queen:
            return 10;
            break;
        case Card::king:
            return 10;
            break;
    }



}
