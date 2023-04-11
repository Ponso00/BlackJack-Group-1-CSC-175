//
// Created by ponso00 on 3/26/2023.
//
using namespace std;
#include <iostream>
#include <synchapi.h>

int card(int card); //card function(proto), returns the value of a card drawn from the deck
void intro();
void round();
void gamble();
void play();
void checkdealer();
void hors();
void dealer2();
void lose();

int total; //globals to fix and delete later
int bet;
int hand;
int dealerhand;



int main() {
    int card_face = 0; //placeholder crap to test card function
    //cout << card(card_face);
    //int card_face = 0;
    srand(time(0));
    intro();
    play();
}

void intro(){
    cout << "Welcome to black jack" << endl;
    cout<< "How many chips would you like to start with?";
    cin>> total;
}
void gamble(){
    cout << "How much would you like to bet this hand? Your have $" << total << " in total.";
    cin >> bet;
    while(bet>total){
        cout << "bet less, you broke"<< endl;
        cout << "How much would you like to bet this hand?";
        cin >> bet;
    }
    total = total - bet;

}
void checkdealer(){
    string again = "y"; //make again variable
    int card_face = 0;
    dealerhand = card(card_face) + card(card_face);

    if(dealerhand==21){
        cout << "Dealer has blackjack! " <<endl;
        lose();
    }
    else if(dealerhand==22){
        dealerhand=12;
    }
    else if(dealerhand<21){
        //there doesn't really need to be anything here
    }
}

void play(){
    gamble(); //call gamble function

    int card_face = 0;//variable just to get card from deck.cpp
    hand = card(card_face) + card(card_face);
    cout << "You have " << hand<< endl;
    Sleep(500);
    checkdealer();
    hors();

}

void hors(){
    string choice;
    string again;
    int card_face = 0;
    cout << "Hit or Stand? (h or s)";
    cin >> choice;
    while(choice=="h"){
        hand+=card(card_face);
        cout << "You have " << hand<< endl;
        if(hand>21){
            cout << "bust"<< endl;
            lose();
        }
        hors();
    }
    dealer2();
}

void dealer2(){
    string again;
    cout << "Dealer has " << dealerhand <<endl;
    while(dealerhand<hand){
        int card_face = 0;
        dealerhand = dealerhand + card(card_face);
    }
    if(dealerhand<=21 && dealerhand > hand){
        cout << "Dealer wins!";
        lose();
    }
    else if(dealerhand>21){ // this is the only way you can win so no need for a win function
        cout << "You win! " << bet*2 << " chips earned! You now have $" << total+(bet*2) <<endl;
        total+=bet*2;
        cout << "Play another round? y or n";
        cin >> again;

        if(again=="n"){
            cout << "You walked away with $" << total << ".";
            std::abort();
        }
        else if(again == "y"){
            play();
        }
    }
    else if(dealerhand==hand){
        cout << "The hand is a push! you get " << bet << " chips back. You now have $" << total+bet << endl;
        total = total +bet;
        cout << "Play another round? y or n";
        cin >> again;

        if(again=="n"){
            cout << "You walked away with $" << total << ".";
            std::abort();
        }
        else if(again == "y"){
            play();
        }
    }
}

void lose(){
    string again;
    cout << "You lose" <<endl;
    bet = 0;

    cout << "Play another round? y or n";
    cin >> again;
    if(again=="n"){
        cout << "You walked away with $" << total << ".";
        std::abort();
    }
    else if(again == "y"){
        play();
    }
}