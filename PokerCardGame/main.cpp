#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;

void updateScores(int highestValuePlayerId,int numberOfPlayers,Player *players){

    if(highestValuePlayerId!=0){
        for(int i=0;i<numberOfPlayers;i++){
            if(players[i].getId()==highestValuePlayerId){
                int score = players[i].getScore();
                score += 10;
                players[i].setScore(score);
            }else{
                int score = players[i].getScore();
                score -= 1;
                players[i].setScore(score);
            }
        }
    }
}

void displayScore(int highestValuePlayerId,
                   int numberOfPlayer,Player *players){

    if(highestValuePlayerId==-1){
        cout<<"NO ONE WON THIS COMBINATION."<<endl;
        cout<<"THE SCORES ARE SAME"<<endl;
    }else{
        cout<< "Player Id with Highest Value : "<<highestValuePlayerId<<endl;
    }
    int total =0 ;
    double winningProbability;
    // Calculate the total marks
    for(int i=0;i<numberOfPlayer;i++){
        total += players[i].getScore();
    }
    cout<< "****************** Scores of Players ******************"<<endl;
    for(int i=0;i<numberOfPlayer;i++){
        int score = players[i].getScore();
        winningProbability = players[i].getScore() / 90 * 100;
        if(score < 0){
            winningProbability = 0;
        }

        cout<<"Player ID    : "<<players[i].getId()<<"      Score    : "<<players[i].getScore()<<
        "       Winning Probability     : "<<players[i].getScore()/total<<endl;
    }
    cout<<"========================================================"<<endl;
}
int main() {
    Dealer dealer(0);
    dealer.shuffleCards();
    int numberOfPlayers = 9;
    Player players[numberOfPlayers];

    for(int i=0;i<numberOfPlayers;i++){
        Player player(i+1);
        players[i] = player;
    }

    Player *playersPtr = players;
    dealer.distributeCards(playersPtr);

    cout<<"============= Dealer's Cards ============="<<endl;
    // Display dealer's cards
    Card *dealerCards;
    dealerCards = dealer.getCards();
    for(int i=0;i<5;i++){
        Card card = dealerCards[i];
        card.printCard();
    }

    Card *cards;
    int id;
    int score;

    // ============================================================
    // =================== Compare the cards ======================
    // ============================================================

    cout<<"========================================================"<<endl;
    cout<<"================== One Pair Combination ================"<<endl;
    cout<<"========================================================"<<endl;

    int highestValue =0 ;
    int highestValuePlayerId = -1 ;
    string highestValueCardShape = "";
    string highestValueCard = "";

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();

        // Check whether two cards have similar values
        for(int j=0;j<5;j++){
            Card currentCard = cards[j];
            for(int k=j+1;k<5;k++){
                if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                    if(highestValue<currentCard.getValueOfCard()){
                        cout<<currentCard.getShape()<<" "<<currentCard.getValueOfCard()<<endl;
                        cout<<cards[k].getShape()<<" "<<cards[k].getValueOfCard()<<endl;

                        highestValue = currentCard.getValueOfCard();
                        highestValueCardShape = currentCard.getShape();
                        highestValueCard = currentCard.getValue();
                        highestValuePlayerId = id;
                    }
                }
            }
        }
    }

    cards=dealer.getCards();
    id = dealer.getId();

    cout<<"Comparing with Dealer's Cards"<<endl;
    // Check whether two cards have similar values
    for(int j=0;j<5;j++){
        Card currentCard = cards[j];
        for(int k=j+1;k<5;k++){
            if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                if(highestValue<currentCard.getValueOfCard()){
                    cout<<currentCard.getShape()<<" "<<currentCard.getValueOfCard()<<endl;
                    cout<<cards[k].getShape()<<" "<<cards[k].getValueOfCard()<<endl;

                    highestValue = currentCard.getValueOfCard();
                    highestValueCardShape = currentCard.getShape();
                    highestValueCard = currentCard.getValue();
                    highestValuePlayerId = id;
                }
            }
        }
    }

    // Update ths scores of each person 10 marks for the winner -1 marks for other includiong

    if(highestValue!=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"================== Two Pair Combination ================"<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId =-1 ;

    // Loop over the players a hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();

        int highestValue1 = 0;
        int highestValue2 = 0;

        // Check whether two cards have similar values
        for(int j=0;j<5;j++){
            Card currentCard = cards[j];;
            for(int k=j+1;k<5;k++){
                if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                    if(highestValue1==0){
                        highestValue1 = currentCard.getValueOfCard();
                    }else if(highestValue2==0){
                        if(highestValue1>=currentCard.getValueOfCard()){
                            highestValue2 = currentCard.getValueOfCard();
                        }else{
                            int temp = highestValue1;
                            highestValue1 = currentCard.getValueOfCard();
                            highestValue2 = temp;
                        }
                    }else if(currentCard.getValueOfCard()>highestValue1){
                        int tempHighestValue1 = highestValue1;
                        highestValue1 = currentCard.getValueOfCard();
                        highestValue2 = tempHighestValue1;
                    }else if(currentCard.getValueOfCard()>highestValue2) {
                        highestValue2 = currentCard.getValueOfCard();
                    }
                }
            }
        }

        if(highestValue==0|| highestValue<(highestValue1+highestValue2)){
            if(!(highestValue1==0&&highestValue2==0))
            cout<<highestValue1<< " "<<highestValue2<<endl;
            highestValue = highestValue1 + highestValue2;
            highestValuePlayerId = id;
        }
    }

    // Compare with the dealers cards
    cards=dealer.getCards();
    id = dealer.getId();

    int highestValue1 = 0;
    int highestValue2 = 0;

    // Check whether two cards have similar values
    for(int j=0;j<5;j++){
        Card currentCard = cards[j];;
        for(int k=j+1;k<5;k++){
            if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                if(highestValue1==0){
                    highestValue1 = currentCard.getValueOfCard();
                }else if(highestValue2==0){
                    if(highestValue1>=currentCard.getValueOfCard()){
                        highestValue2 = currentCard.getValueOfCard();
                    }else{
                        int temp = highestValue1;
                        highestValue1 = currentCard.getValueOfCard();
                        highestValue2 = temp;
                    }
                }else if(currentCard.getValueOfCard()>highestValue1){
                    int tempHighestValue1 = highestValue1;
                    highestValue1 = currentCard.getValueOfCard();
                    highestValue2 = tempHighestValue1;
                }else if(currentCard.getValueOfCard()>highestValue2) {
                    highestValue2 = currentCard.getValueOfCard();
                }
            }
        }
    }

    if(highestValue==0|| highestValue<(highestValue1+highestValue2)){
        if(!(highestValue1==0&&highestValue2==0))
            cout<<highestValue1<< " "<<highestValue2<<endl;
        highestValue = highestValue1 + highestValue2;
        highestValuePlayerId = id;
    }

    // Update ths scores of each person 10 marks for the winner -1 marks for other includiing
    if(highestValue!=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"============== Three of a Kind Combination ============="<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId = -1;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();

        // Check whether three cards have similar values
        for(int j=0;j<3;j++){
            Card currentCard = cards[j];
            for(int k=j+1;k<5;k++){
                if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                    for(int l =k+1;l<5;l++){
                        if(currentCard.getValueOfCard()==cards[l].getValueOfCard()){
                            if(highestValue<currentCard.getValueOfCard()){
                                cout<<currentCard.getShape()<<" "<<currentCard.getValueOfCard()<<endl;
                                cout<<cards[k].getShape()<<" "<<cards[k].getValueOfCard()<<endl;

                                highestValue = currentCard.getValueOfCard();
                                highestValueCardShape = currentCard.getShape();
                                highestValueCard = currentCard.getValue();
                                highestValuePlayerId = id;
                            }
                        }
                    }
                }
            }
        }
    }

    // Compare Dealer's Cards
    cards=dealer.getCards();
    id = dealer.getId();

    // Check whether three cards have similar values
    for(int j=0;j<3;j++){
        Card currentCard = cards[j];
        for(int k=j+1;k<5;k++){
            if(currentCard.getValueOfCard()==cards[k].getValueOfCard()){
                for(int l =k+1;l<5;l++){
                    if(currentCard.getValueOfCard()==cards[l].getValueOfCard()){
                        if(highestValue<currentCard.getValueOfCard()){
                            cout<<currentCard.getShape()<<" "<<currentCard.getValueOfCard()<<endl;
                            cout<<cards[k].getShape()<<" "<<cards[k].getValueOfCard()<<endl;

                            highestValue = currentCard.getValueOfCard();
                            highestValueCardShape = currentCard.getShape();
                            highestValueCard = currentCard.getValue();
                            highestValuePlayerId = id;
                        }
                    }
                }
            }
        }
    }

    if(highestValue!=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"================= Straight Combination ================="<<endl;
    cout<<"========================================================"<<endl;

    int largetFirstCardValue = 0;
     highestValuePlayerId= -1;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();
        int smallestCardValue=19;

        // find the smallest value of the card
        for(int j=0;j<5;j++){
            if(smallestCardValue>cards[j].getValueOfCard()){
                smallestCardValue = cards[j].getValueOfCard();
            }
        }

        int nextCardValue = smallestCardValue;
        bool isNextValue = true;
        for(int k=0;k<4;k++){
            bool foundNextValue =false;
            nextCardValue++;
            for(int l=0;l<5;l++){
                if(nextCardValue == cards[l].getValueOfCard()){
                    cout<<"Found Next Card"<<endl;
                    foundNextValue = true;
                    break;
                }
            }
            if(!foundNextValue){
                cout<<"NO SEQUENCE"<<endl;
                isNextValue = false;
                break;
            }
        }

        if(smallestCardValue>largetFirstCardValue&&isNextValue){
            largetFirstCardValue = smallestCardValue;
            highestValuePlayerId = id;
        }
    }

    // Compare with the dealer's cards
    cards=dealer.getCards();
    id = dealer.getId();
    int smallestCardValue=19;

    // find the smallest value of the card
    for(int j=0;j<5;j++){
        if(smallestCardValue>cards[j].getValueOfCard()){
            smallestCardValue = cards[j].getValueOfCard();
        }
    }

    int nextCardValue = smallestCardValue;
    bool isNextValue = true;
    for(int k=0;k<4;k++){
        bool foundNextValue =false;
        nextCardValue++;
        if(nextCardValue==15){
            nextCardValue = 2;
        }
        for(int l=0;l<5;l++){
            if(nextCardValue == cards[l].getValueOfCard()){
                cout<<"Found Next Card"<<endl;
                foundNextValue = true;
                break;
            }
        }
        if(foundNextValue != true){
            cout<<"NO SEQUENCE"<<endl;
            isNextValue = false;
            break;
        }
    }

    if(smallestCardValue>largetFirstCardValue&&isNextValue){
        largetFirstCardValue = smallestCardValue;
        highestValuePlayerId = id;
    }

    if(largetFirstCardValue !=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"================== Flush Combination ==================="<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId = -1 ;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();
        int total =0 ;
        bool isFlush  = true;
        // Check whether two cards have similar values
        for(int j=0;j<4;j++){
            Card currentCard = cards[j];
            int cardValue = cards[j].getValueOfCard();
            string shape = cards[j].getShape();
            for(int k=j+1;k<5;k++){
                if(shape==cards[k].getShape()){
                    total += cardValue;
                }else if(shape=="Diamond"&&cards[k].getShape()=="Heart"){
                    total += cardValue;
                }else if(shape=="Heart"&&cards[k].getShape()=="Diamond"){
                    total += cardValue;
                }else if(shape=="Spade"&&cards[k].getShape()=="Club"){
                    total += cardValue;
                }else if(shape=="Club"&&cards[k].getShape()=="Spade"){
                    total += cardValue;
                }else{
                    isFlush = false;
                    break;
                }
            }
            if(!isFlush){
                break;
            }
        }
        if(isFlush && highestValue<total){
            highestValue = total;
            highestValuePlayerId = id;
        }
    }

    // Compare with the dealer's cards
    cards=dealer.getCards();
    id = dealer.getId();
    int total =0 ;
    bool isFlush  = true;
    // Check whether two cards have similar values
    for(int j=0;j<4;j++){
        Card currentCard = cards[j];
        int cardValue = cards[j].getValueOfCard();
        string shape = cards[j].getShape();
        for(int k=j+1;k<5;k++){
            if(shape==cards[k].getShape()){
                total += cardValue;
            }else if(shape=="Diamond"&&cards[k].getShape()=="Heart"){
                total += cardValue;
            }else if(shape=="Heart"&&cards[k].getShape()=="Diamond"){
                total += cardValue;
            }else if(shape=="Spade"&&cards[k].getShape()=="Club"){
                total += cardValue;
            }else if(shape=="Club"&&cards[k].getShape()=="Spade"){
                total += cardValue;
            }else{
                isFlush = false;
                break;
            }
        }
        if(!isFlush){
            break;
        }
    }
    if(isFlush && highestValue<total){
        highestValue = total;
        highestValuePlayerId = id;
    }

    if(highestValue !=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"============= Four Of A Kind Combination ==============="<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId = -1 ;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();
        int count =0;
        int cardValue;
        // Check whether two cards have similar values
        for(int j=0;j<4;j++){
            Card currentCard = cards[j];
            cardValue = cards[j].getValueOfCard();
            for(int k=j+1;k<5;k++){
                if(cardValue ==cards[k].getValueOfCard() ){
                    if(count==0){
                        count =count +2;
                    }else{
                        count++;
                    }
                }
            }
        }
        if(count==4 && highestValue<cardValue){
            highestValue = cardValue;
            highestValuePlayerId = id;
        }
    }

    // Compare with the dealer's cards
    cards=dealer.getCards();
    id = dealer.getId();
    int count =0;
    int cardValue;
    // Check whether two cards have similar values
    for(int j=0;j<4;j++){
        Card currentCard = cards[j];
        cardValue = cards[j].getValueOfCard();
        for(int k=j+1;k<5;k++){
            if(cardValue ==cards[k].getValueOfCard() ){
                if(count==0){
                    count =count +2;
                }else{
                    count++;
                }
            }
        }
    }
    if(count==4 && highestValue<cardValue){
        highestValue = cardValue;
        highestValuePlayerId = id;
    }

    if(highestValue !=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"================ Full House Combination ================"<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId = -1 ;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();
        int cardValue1=0,cardValue2=0;
        int count1=0,count2=0;

        // Check whether two cards have similar values
        for(int j=0;j<4;j++){
            int value = cards[j].getValueOfCard();
            for(int k=j+1;k<5;k++){
                if(cardValue1==0 && value==cards[k].getValueOfCard()){
                    cardValue1 = value;
                    count1 = count1 + 2;
                }else if(cardValue1==0&&cardValue2==0){
                    cardValue1=value;
                    cardValue2=cards[k].getValueOfCard();
                    count1++;
                    count2++;
                }else if(cardValue2==0){
                    cardValue2 = value;
                    count2++;
                }else if(cardValue1 == value){
                    cardValue1++;
                }else if(cardValue2==value){
                    cardValue2++;
                }
            }
        }

        if(count1==2&&count2==3||count1==3&&count2==2){
            if(cardValue1>cardValue2){
                if(cardValue1>highestValue){
                    highestValue=cardValue1;
                }
            }else if(cardValue2>cardValue1){
                if(cardValue2>highestValue){
                    highestValue=cardValue2;
                }
            }
        }
    }


    // Compare with the dealer's cards

    cards=dealer.getCards();
    id = dealer.getId();
    int cardValue1=0,cardValue2=0;
    int count1=0,count2=0;

    // Check whether two cards have similar values
    for(int j=0;j<4;j++){
        int value = cards[j].getValueOfCard();
        for(int k=j+1;k<5;k++){
            if(cardValue1==0 && value==cards[k].getValueOfCard()){
                cardValue1 = value;
                count1 = count1 + 2;
            }else if(cardValue1==0&&cardValue2==0){
                cardValue1=value;
                cardValue2=cards[k].getValueOfCard();
                count1++;
                count2++;
            }else if(cardValue2==0){
                cardValue2 = value;
                count2++;
            }else if(cardValue1 == value){
                cardValue1++;
            }else if(cardValue2==value){
                cardValue2++;
            }
        }
    }

    if(count1==2&&count2==3||count1==3&&count2==2){
        if(cardValue1>cardValue2){
            if(cardValue1>highestValue){
                highestValue=cardValue1;
            }
        }else if(cardValue2>cardValue1){
            if(cardValue2>highestValue){
                highestValue=cardValue2;
            }
        }
    }

    if(highestValue !=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    cout<<"========================================================"<<endl;
    cout<<"============= Straight Flush Combination ==============="<<endl;
    cout<<"========================================================"<<endl;

    highestValue =0 ;
    highestValuePlayerId = -1 ;

    // Loop over the players and dealers hands
    for(int i=0;i<numberOfPlayers;i++){
        cards=players[i].getCards();
        id = players[i].getId();
        int total =0 ;
        bool isFlush  = true;
        // Check whether two cards have similar values
        for(int j=0;j<4;j++){
            Card currentCard = cards[j];
            int cardValue = cards[j].getValueOfCard();
            string shape = cards[j].getShape();
            for(int k=j+1;k<5;k++){
                if(shape==cards[k].getShape()){
                    total += cardValue;
                }else{
                    isFlush = false;
                    break;
                }
            }
            if(!isFlush){
                break;
            }
        }
        if(isFlush && highestValue<total){
            highestValue = total;
            highestValuePlayerId = id;
        }
    }

    // Compare with the dealer's cards
    cards=dealer.getCards();
    id = dealer.getId();
    total =0 ;
    isFlush  = true;
    // Check whether two cards have similar values
    for(int j=0;j<4;j++){
        Card currentCard = cards[j];
        int cardValue = cards[j].getValueOfCard();
        string shape = cards[j].getShape();
        for(int k=j+1;k<5;k++){
            if(shape==cards[k].getShape()){
                total += cardValue;
            }else{
                isFlush = false;
                break;
            }
        }
        if(!isFlush){
            break;
        }
    }
    if(isFlush && highestValue<total){
        highestValue = total;
        highestValuePlayerId = id;
    }

    if(highestValue !=0){
        updateScores(highestValuePlayerId,numberOfPlayers,players);
    }
    displayScore(highestValuePlayerId,numberOfPlayers,players);

    // Select the winner
    int maximum =0 ;
    int winnerId =0;
    int maximumCardValue;
    for(int i=0;i<numberOfPlayers;i++){
        if(maximum<players[i].getScore()){
            maximum = players[i].getScore();
            winnerId = players[i].getId();
        }
    }

    // Check whether another have same value
    for(int i=0;i<numberOfPlayers;i++){
        if(players[i].getScore()==maximum){
            int highestCard=0;
            Card cards[5];
            for(int j=0;j<5;j++){
                if(highestCard<cards[i].getValueOfCard()){
                    highestCard = cards[i].getValueOfCard();
                }
            }

            if(highestCard>maximumCardValue){
                maximumCardValue = highestCard;
                winnerId = players[i].getId();
            }
        }
    }

    // Display Winner
    if(winnerId==0){

        cout<<"************************ CONGRATULATIONS *************************"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"********************** DEALER "<< winnerId<< " **********************************"<<endl;
        cout<<"******************************************************************"<<endl;
    }else{
        cout<<"************************* CONGRATULATIONS ************************"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"********************** PLAYER "<< winnerId<< " **********************************"<<endl;
        cout<<"******************************************************************"<<endl;
    }

    return 0;
}

