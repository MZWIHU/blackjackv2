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
