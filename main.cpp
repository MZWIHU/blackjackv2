#include <iostream>
#include "cards.h"
#include "deck.h"
int main() {

    //balance and bet
    double konto = 0;
    double bet = 0;

    //input
    int input = 0;

    //hands
    int hand = 0;
    int dealerHand = 0;

    //counts WIN LOSS DRAW
    int loss = 0;
    int win = 0;
    int draw = 0;

    //for first two rounds
    int begin = 0;

    //Draw another card Y or N
    char decide;
    //indicates whos turn it is TRUE=PLAYER FALSE = DEALER
    bool turn = true;
    //turns true if you got 21 on first two cards
    bool blackjack = false;

    std::cout << "How many Decks? Default = 2" << std::endl;
    std::cin >> input;
    if (input == 0) {
        input = 2;
    }

    std::cout << "How much you want to transfer to your account?" << std::endl;
    std::cin >> konto;
    std::cout << "How much you want to bet?" << std::endl;
    std::cin >> bet;



    Deck d;

    //Deck erstellen -------------------------------------------------------------------------------------------------*/
    for (int k = 0; k < input - 1; k++) {

        Deck temp;
        d.stack.insert(d.stack.end(), temp.stack.begin(), temp.stack.end());

    }
    d.printDeck();
    std::cout << std::endl << std::endl;
    d.shuffle();


    //spielen---------------------------------------------------------------------------------------------------------*/


    for (int i = 0; i < d.stack.size(); i++) {

        //check balance
        if(konto < bet) {
            std::cout << "Not enough balance to play another round" << std::endl;
            break;
        }

        //check if new round started
        if (begin == 0) {
            std::cout << "Your current balance: " << konto  << " USD"<< std::endl;
            std::cout << "Placed bet of: " << bet << " USD" << std::endl;
            konto = konto - bet;
        }

        //first two rounds
        if (begin < 2) {
            std::cout << "You have drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n) << std::endl;
            hand += d.checkValue(i, hand);
            begin++;
            blackjack = true;
            continue;
        }
        //dealer draws his first card
        if (begin == 2) {
            std::cout << "Dealer has drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n) << std::endl;
            dealerHand += d.checkValue(i, dealerHand);
            begin++;
            continue;
        }


        //check if you overbought INSTANT LOSS
        if (hand > 21) {
            loss++;
            std::cout << "You lost with: " << hand << std::endl;
            std::cout << "You lost: " << bet << " USD" << std::endl << std::endl << std::endl;
            hand = 0;
            begin = 0;
            if (i > d.stack.size() - 6) {
                break;
            }
            continue;
        }

        //check if u want to draw another card
        if (turn) {

            std::cout << "Your Hand is: " << hand << std::endl;
            std::cout << "You want to draw a card Y or N" << std::endl;
            std::cin >> decide;

            switch (decide) {
                case 'y':
                    std::cout << "You have drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n)
                              << std::endl;
                    hand += d.checkValue(i, hand);
                    blackjack = false;
                    break;
                case 'n':
                    turn = false;
                    break;
                default:
                    std::cout << "Please enter valid option" << std::endl;
                    turn = false;
            }
        //dealers turn
        }else {
            //dealer needs to stand on 17
            if (dealerHand < 17) {
                std::cout << "Dealer has drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n)
                          << std::endl;
                dealerHand += d.checkValue(i, dealerHand);
                continue;
            }

            //check for blackjack
            if(dealerHand < 21 && hand == 21 || dealerHand > 21 && hand == 21) {
                std::cout << "You won with Blackjack!" << std::endl;
                std::cout << "You won: " << bet * 2.5 << " USD" <<  std::endl << std::endl << std::endl;

                //PAYOUT
                konto = konto + bet*2.5;
                //RESET FOR NEW ROUND
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }

            if (dealerHand > 21 && hand <= 21) {
                std::cout << "You won with: " << hand << " against " << dealerHand << std::endl;
                std::cout << "You won: " << bet*2  << " USD"<< std::endl << std::endl << std::endl;
                win++;

                //PAYOUT
                konto = konto +  bet*2;
                //RESET FOR NEW ROUND
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }
            if (hand < dealerHand) {
                std::cout << "You lost with: " << hand << " against " << dealerHand << std::endl;
                std::cout << "You lost: " << bet  << " USD" <<  std::endl << std::endl << std::endl;
                //RESET FOR NEW ROUND
                loss++;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }

            if (hand > dealerHand) {
                std::cout << "You won with: " << hand << " against " << dealerHand << std::endl;
                std::cout << "You won: " << bet*2 << " USD" << std::endl << std::endl << std::endl;
                //PAYOUT
                konto = konto +  bet*2;
                //RESET FOR NEW ROUND
                win++;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }
            //check for draw
            if (hand == dealerHand) {
                std::cout << "Draw! Your hand: " << hand << " Dealer: " << dealerHand << std::endl;
                std::cout << "You got your bet back" << std::endl << std::endl << std::endl;
                //PAYOUT
                konto += bet;
                //RESET FOR NEW ROUND
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                draw++;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }

        }
    }
    std::cout << "You won " << win << " times :)" << std::endl;
    std::cout << "You lost " << loss << " times :(" << std::endl;
    std::cout << "Draw: " << draw << " times :|" << std::endl;
    std::cout << "Your balance at the end: " << konto << " USD"<< std::endl;


    return 0;

}