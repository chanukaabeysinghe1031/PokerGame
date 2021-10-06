//
// Created by Chanuka Abeysinghe on 2021-10-05.
//

#ifndef POKERCARDGAME_PLAYER_H
#define POKERCARDGAME_PLAYER_H

#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "Dealer.h"

using namespace std;

class Player {
private:
    int id;
    Card cards[5];
    int score;

public:

    Player(){}

    Player(int i){
        id = i;
        score=0;
    }

    void setCards(Card c[5]){
        for(int i=0;i<5;i++){
            Card card = c[i];
            cards[i] = card;
        }
    }

    void setScore(int s){
        score = s;
    }

    Card * getCards(){
        return cards;
    }

    int getScore(){
        return score;
    }

    int getId(){
        return id;
    }
};


#endif //POKERCARDGAME_PLAYER_H
