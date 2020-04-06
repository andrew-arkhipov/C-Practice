#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::string;


class Card{
        private:
                string name;
                int suit; // 0 = Spades, 1 = Clubs, 2 = Hearts, 3 = Diamonds
                int value; // 1 = Ace, 2 = Two, ... , 10 = Ten, 11 = Jack, 12 = Queen, 13 = King
        public:
                Card(){ // default constructor
                        name = "none";
                        suit = -1;
                        value = -1;
                }

                Card(int new_suit, int new_val){
                        suit = new_suit;
                        value = new_val;
                        string new_name = "";
                        string suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
                        string values[14] = {"", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                             "Jack", "Queen", "King"};
                        name = values[new_val] + " of " + suits[new_suit];
                }

                void set_name(string new_name){
                        name = new_name;
                }

                string get_name(){
                        return name;
                }

                void set_suit(int new_suit){
                        suit = new_suit;
                }

                int get_suit(){
                        return suit;
                }

                void set_value(int new_value){
                        value = new_value;
                }

                int get_value(){
                        return value;
                }

                int compare(Card c2){
                        if (c2.get_value() > value){
                                return -1;
                        } else if (c2.get_value() == value){
                                return 0;
                        } else {
                                return 1;
                        }
                }
};

class Deck{
        private:
                vector<Card> d;
        public:

                Deck(){ // default constructor, adds cards in ascending order for a standard 52-card deck
                        for(int i = 0; i < 4; i++){
                                for(int j = 1; j < 14; j++){
                                        d.push_back(Card(i, j));
                                }
                        }
                }

                Deck(vector<Card> deck){
                        for (int i = 0; i < deck.size(); i++){
                                d.push_back(deck[i]);
                        }
                }

                vector<Card> get_deck(){
                        return d;
                }

                void add_card(Card new_card){
                        d.push_back(new_card);
                }

                void clear_deck(){
                        d.clear();
                }

                void delete_card(int pos){
                        d.erase(d.begin() + pos);
                }

                int get_size(){
                        return d.size();
                }

                Deck deal(int number_of_cards){ // deals number_of_cards cards randomly from the deck
                        Deck new_deck = Deck();
                        new_deck.clear_deck();

                        srand(time(NULL));

                        for (int i = 0; i < number_of_cards; i++){
                                int temp = rand() % d.size();
                                new_deck.add_card(d[temp]);
                                d.erase(d.begin() + temp);
                        }

                        return new_deck;

                }

                void shuffle(Deck d2){
                        int num = d2.get_size();
                        for (int i = 0; i < 2*num; i++){
                                if ((i % 2) == 0){
                                        d.insert(d.begin() + i, d2.get_deck()[0]);
                                        d2.delete_card(0);
                                }
                        }
                }

                void sort(){
                        int swapped = 1;
                        while (swapped == 1){
                                swapped = 0;
                                for (int i = 0; i < d.size() - 1; i++){
                                        int comp_val = d[i].compare(d[i+1]);
                                        if (comp_val == 1){
                                                swap(d[i], d[i + 1]);
                                                swapped = 1;
                                        }
                                }
                        }

                        for (int i = 0; i < 13; i++){
                                int swapped = 1;
                                while (swapped == 1){
                                        swapped = 0;
                                        for (int j = 4*i; j < (4*i + 3); j++){
                                                if (d[j].get_suit() > d[j + 1].get_suit()){
                                                        swap(d[j], d[j + 1]);
                                                        swapped = 1;
                                                }
                                        }
                                }
                        }
                }
};

int main(){

        int cut_size;
        cout << "How many cards would you like? ";
        cin >> cut_size;

        Deck d1 = Deck();
        Deck deal = d1.deal(cut_size);

        cout << "Dealt hand: " << endl;

        vector<Card> dealt = deal.get_deck();
        for (int i = 0; i < cut_size; i++){
                cout << dealt[i].get_name() << endl;
        }

        d1.shuffle(deal);
        vector<Card> shuffled = d1.get_deck();

        cout << "\n";
        cout << "Shuffled deck: " << endl;

        for (int i = 0; i < 52; i++){
                cout << shuffled[i].get_name() << endl;
        }

        d1.sort();
        vector<Card> sorted = d1.get_deck();

        cout << "\n";
        cout << "Sorted deck: " << endl;

        for (int i = 0; i < 52; i++){
                cout << sorted[i].get_name() << endl;
        }

        return 0;

}
