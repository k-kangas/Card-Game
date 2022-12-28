/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 7 Project
* Deck of Cards Game (Create, Print, Deal 2 Random Cards using Enums)
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum suits { HEARTS, DIAMONDS, SPADES, CLUBS };

enum ranks { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct cards
{
	suits suit;
	ranks rank;
};

void createDeck(cards[]);
void printDeck(cards[]);
string cardName(cards);
cards deal(cards[]);
string winner(cards, cards);

int main()
{
	srand((unsigned)time(0));

	cards deck[52];
	cards card1, card2;

	cout << "Game instructions: \n";
	cout << "This is a game that picks two random cards and whichever card is the highest and of highest suit wins." << endl;

	bool again = true;
	while (again)
	{
		cout << "\n\nThe deck of cards:\n\n";
		// Function call - Create deck
		createDeck(deck);
		// Function call - Print deck
		printDeck(deck);
		// Deal card 1 and card 
		cout << endl;
		cout << "Card 1 is the ";
		card1 = deal(deck);
		cout << "Card 2 is the ";
		card2 = deal(deck);
		// Winner
		cout << endl;
		winner(card1, card2);

		cout << "\nEnter 1 to run the program again else enter 0>";
		cin >> again;
	}
	cout << endl;
	system("pause");
	return 0;
}

void createDeck(cards deck[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[13 * i + j].suit = (suits)i;

			deck[13 * i + j].rank = (ranks)j;
		}
	}
}

void printDeck(cards deck[])
{
	for (int i = 0; i < 52; i++)
	{
		cardName(deck[i]);
	}
}

string cardName(cards deck)
{
	string card_name_full;
	string card_name_rank;
	string card_name_suit;

	switch (deck.rank)
	{
	case 0:
		card_name_rank = "Two";
		break;
	case 1:
		card_name_rank = "Three";
		break;
	case 2:
		card_name_rank = "Four";
		break;
	case 3:
		card_name_rank = "Five";
		break;
	case 4:
		card_name_rank = "Six";
		break;
	case 5:
		card_name_rank = "Seven";
		break;
	case 6:
		card_name_rank = "Eight";
		break;
	case 7:
		card_name_rank = "Nine";
		break;
	case 8:
		card_name_rank = "Ten";
		break;
	case 9:
		card_name_rank = "Jack";
		break;
	case 10:
		card_name_rank = "Queen";
		break;
	case 11:
		card_name_rank = "King";
		break;
	case 12:
		card_name_rank = "Ace";
		break;
	}

	switch (deck.suit)
	{
	case 0:
		card_name_suit = "Hearts";
		break;
	case 1:
		card_name_suit = "Diamonds";
		break;
	case 2:
		card_name_suit = "Spades";
		break;
	case 3:
		card_name_suit = "Clubs";
		break;
	}

	if (deck.suit >= 0 && deck.suit < 4 && deck.rank >= 0 && deck.rank < 13)
	{
		cout << card_name_rank << " of " << card_name_suit << endl;
	}
	else
	{
		cout << card_name_rank << " of " << card_name_suit << endl;
	}

	return card_name_full;
}

cards deal(cards deck[])
{
	int temp;
	cards randomCard;

	while (true)
	{
		temp = rand() % 52 + 1;
		if (deck[temp].rank != 0)
		{
			randomCard.suit = deck[temp].suit;
			randomCard.rank = deck[temp].rank;
			break;
		}
	}
	cardName(randomCard);

	return randomCard;
}

string winner(cards card_1, cards card_2)
{
	string winner1;

	if (card_1.rank > card_2.rank)
	{
		cout << "The winner is ";
		cardName(card_1);
	}
	else
	{
		cout << "The winner is ";
		cardName(card_2);
	}
	return winner1;
}