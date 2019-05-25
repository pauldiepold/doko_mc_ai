#include "utility.hpp"

#include <iostream>

//////////////////////////////////////////////
// Suit
//

Suit::Suit( uint8_t init ): suit(init) {
}

const std::string Suit::names[6] = {
	"No Suit", "Club", "Spade", "Heart", "Diamond", "Trump"
};

const CardSet Suit::sets[6] = {
	CardSet( 0b111111111111111111111111111111111111111111111111ul ),
	CardSet( 0b000000000000000000001111000000000000000000001111ul ),
	CardSet( 0b000000000000000011110000000000000000000011110000ul ),
	CardSet( 0b000000000000011100000000000000000000011100000000ul ),
	CardSet( 0b000000000000000000000000000000000000000000000000ul ),
	CardSet( 0b111111111111100000000000111111111111100000000000ul )
};

bool Suit::operator == ( const Suit& op ) const {
	return suit == op.suit;
}

bool Suit::operator != ( const Suit& op ) const {
	return suit != op.suit;
}

const std::string& Suit::GetName() const {
	return names[suit];
}

const CardSet& Suit::GetSet() const {
	return sets[suit];
}

const Suit Suit::none = Suit(0);
const Suit Suit::club = Suit(1);
const Suit Suit::spade = Suit(2);
const Suit Suit::heart = Suit(3);
const Suit Suit::diamond = Suit(4);
const Suit Suit::trump = Suit(5);

/////////////////////////////////////////////
// Card
//

const Score Card::values[48] = {
	Score(0), Score(4), Score(10), Score(11),
	Score(0), Score(4), Score(10), Score(11),
	Score(0), Score(4), Score(11), Score(0),
	Score(4), Score(10), Score(11),
	Score(2), Score(2), Score(2), Score(2),
	Score(3), Score(3), Score(3), Score(3), Score(10),
	Score(0), Score(4), Score(10), Score(11),
	Score(0), Score(4), Score(10), Score(11),
	Score(0), Score(4), Score(11),
	Score(0), Score(4), Score(10), Score(11),
	Score(2), Score(2), Score(2), Score(2),
	Score(3), Score(3), Score(3), Score(3), Score(10) };
const Suit Card::suits[48] = {
	Suit::club, Suit::club, Suit::club, Suit::club,
	Suit::spade, Suit::spade, Suit::spade, Suit::spade,
	Suit::heart, Suit::heart, Suit::heart,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump, Suit::trump,
	Suit::club, Suit::club, Suit::club, Suit::club,
	Suit::spade, Suit::spade, Suit::spade, Suit::spade,
	Suit::heart, Suit::heart, Suit::heart,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump,
	Suit::trump, Suit::trump, Suit::trump, Suit::trump, Suit::trump
};
const std::string Card::names[48] = {
	"club nine", "club king", "club ten", "club ace",
	"spade nine", "spade king", "spade ten", "spade ace",
	"heart nine", "heart king", "heart ace",
	"diamond nine",	"diamond king",	"diamond ten", "diamond ace",
	"diamond jack",	"heart jack", "spade jack", "club jack",
	"diamond queen", "heart queen", "spade queen", "club queen", "heart ten",
	"club nine", "club king", "club ten", "club ace",
	"spade nine", "spade king", "spade ten", "spade ace",
	"heart nine", "heart king", "heart ace",
	"diamond nine",	"diamond king",	"diamond ten", "diamond ace",
	"diamond jack",	"heart jack", "spade jack", "club jack",
	"diamond queen", "heart queen", "spade queen", "club queen", "heart ten"
};

const std::string Card::short_names[48] = {
	"cn", "ck", "ct", "ca", "sn", "sk", "st", "sa", "hn", "hk", "ha", "dn", "dk", "dt", "da",
	"dj", "hj", "sj", "cj", "dq", "hq", "sq", "cq", "ht",
	"cn", "ck", "ct", "ca", "sn", "sk", "st", "sa", "hn", "hk", "ha", "dn", "dk", "dt", "da",
	"dj", "hj", "sj", "cj", "dq", "hq", "sq", "cq", "ht"
};

Card::Card(): card(255) {
}

Card::Card( uint8_t init ): card(init) {
}

Card::Card( std::string name ) {
	if ( name.length() < 2 ) {
		card = 255;
		return;
	}
	switch ( name[0] ) {
		case 'c': switch ( name[1] ) {
			case 'n': card = 0; return;
			case 'k': card = 1; return;
			case 't': card = 2; return;
			case 'a': card = 3; return;
			case 'j': card = 18; return;
			case 'q': card = 22; return;
		     }
		case 's': switch ( name[1] ) {
			case 'n': card = 4; return;
			case 'k': card = 5; return;
			case 't': card = 6; return;
			case 'a': card = 7; return;
			case 'j': card = 17; return;
			case 'q': card = 21; return;
		     }
		case 'h': switch ( name[1] ) {
			case 'n': card = 8; return;
			case 'k': card = 9; return;
			case 't': card = 23; return;
			case 'a': card = 10; return;
			case 'j': card = 16; return;
			case 'q': card = 20; return;
		     }
		case 'd': switch ( name[1] ) {
			case 'n': card = 11; return;
			case 'k': card = 12; return;
			case 't': card = 13; return;
			case 'a': card = 14; return;
			case 'j': card = 15; return;
			case 'q': card = 19; return;
		     }
	}
	card = 255;
	return;
}

bool Card::IsHighBlock() const {
	return card > 23;
}

bool Card::IsLowBlock() const {
	return card <= 23;
}

bool Card::IsNone() const {
	return card == 255;
}

const Suit& Card::GetSuit() const {
	return suits[card];
}

bool Card::operator == ( const Card& op ) const {
	return card == op.card;
}

bool Card::operator != ( const Card& op ) const {
	return card != op.card;
}

Card Card::LowBlock() const {
	return Card( IsHighBlock() ? card - 24 : card );
}

Card Card::HighBlock() const {
	return Card( IsLowBlock() ? card + 24 : card );
}

uint8_t Card::GetIndex() const {
	return card;
}

const std::string& Card::GetName() const {
	return names[card];
}

const std::string& Card::GetShortName() const {
	return short_names[card];
}

const Score& Card::GetValue() const {
	return values[card];
}

const Card Card::none			 = Card(255);
const Card Card::club_nine		 = Card( 0);
const Card Card::club_king		 = Card( 1);
const Card Card::club_ten		 = Card( 2);
const Card Card::club_ace		 = Card( 3);
const Card Card::spade_nine		 = Card( 4);
const Card Card::spade_king		 = Card( 5);
const Card Card::spade_ten		 = Card( 6);
const Card Card::spade_ace		 = Card( 7);
const Card Card::heart_nine		 = Card( 8);
const Card Card::heart_king		 = Card( 9);
const Card Card::heart_ace		 = Card(10);
const Card Card::diamond_nine	 = Card(11);
const Card Card::diamond_king	 = Card(12);
const Card Card::diamond_ten	 = Card(13);
const Card Card::diamond_ace	 = Card(14);
const Card Card::diamond_jack	 = Card(15);
const Card Card::heart_jack		 = Card(16);
const Card Card::spade_jack		 = Card(17);
const Card Card::club_jack		 = Card(18);
const Card Card::diamond_queen	 = Card(19);
const Card Card::heart_queen	 = Card(20);
const Card Card::spade_queen	 = Card(21);
const Card Card::club_queen		 = Card(22);
const Card Card::heart_ten		 = Card(23);
const Card Card::club_nine_h	 = Card(24);
const Card Card::club_king_h	 = Card(25);
const Card Card::club_ten_h		 = Card(26);
const Card Card::club_ace_h		 = Card(27);
const Card Card::spade_nine_h	 = Card(28);
const Card Card::spade_king_h	 = Card(29);
const Card Card::spade_ten_h	 = Card(30);
const Card Card::spade_ace_h	 = Card(31);
const Card Card::heart_nine_h	 = Card(32);
const Card Card::heart_king_h	 = Card(33);
const Card Card::heart_ace_h	 = Card(34);
const Card Card::diamond_nine_h	 = Card(35);
const Card Card::diamond_king_h	 = Card(36);
const Card Card::diamond_ten_h	 = Card(37);
const Card Card::diamond_ace_h	 = Card(38);
const Card Card::diamond_jack_h	 = Card(39);
const Card Card::heart_jack_h	 = Card(40);
const Card Card::spade_jack_h	 = Card(41);
const Card Card::club_jack_h	 = Card(42);
const Card Card::diamond_queen_h = Card(43);
const Card Card::heart_queen_h	 = Card(44);
const Card Card::spade_queen_h	 = Card(45);
const Card Card::club_queen_h	 = Card(46);
const Card Card::heart_ten_h	 = Card(47);

//////////////////////////////////////////////
// CardSet
//

CardSet::CardSet( uint64_t init ): cardset( init % (1ul << 48) ) {
}

CardSet::CardSet( const Card& init ): cardset( 1ul << init.GetIndex() ) {
}

CardSet::CardSet(): cardset(0ul) {
}

void CardSet::Add( const Card& op ) {
	cardset |= (1ul << op.GetIndex());
}

void CardSet::Add( const CardSet& op ) {
	cardset |= op.cardset;
}

void CardSet::Remove( const Card& op ) {
	cardset &= ~(1ul << op.GetIndex());
}

void CardSet::Remove( const CardSet& op ) {
	cardset &= ~op.cardset;
}

bool CardSet::Have( const Card& op ) const {
	return (cardset & (1ul << op.GetIndex())) != 0;
}

bool CardSet::Have( const Suit& op ) const {
	return (cardset & op.GetSet().cardset) != 0;
}

bool CardSet::IsEmpty() const {
	return cardset == 0ul;
}

CardSet CardSet::CompressLow() const {
	return CardSet( (cardset | cardset >> 24) & low_block.cardset );
}

CardSet CardSet::CompressHigh() const {
	return CardSet( (cardset | cardset << 24) & high_block.cardset );
}

CardSet CardSet::MaskSuit( const Suit& op ) const {
	return CardSet( cardset & op.GetSet().cardset );
}

CardSet CardSet::MaskSuitAndTrump( const Suit& op ) const {
	return CardSet( cardset & ( op.GetSet().cardset | Suit::trump.GetSet().cardset ) );
}

uint64_t CardSet::GetSet() const {
	return cardset;
}

uint8_t CardSet::GetList( CardList& list ) const {
	uint8_t len = 0;
	for ( uint8_t pos = 0; pos < 48; ++pos ) {
		if ( Have(Card(pos)) ) {
			list[len++] = Card(pos);
		}
	}
	return len;
}

const CardSet CardSet::empty =      CardSet( 0b000000000000000000000000000000000000000000000000ul );
const CardSet CardSet::all =        CardSet( 0b111111111111111111111111111111111111111111111111ul );
const CardSet CardSet::low_block  = CardSet( 0b000000000000000000000000111111111111111111111111ul );
const CardSet CardSet::high_block = CardSet( 0b111111111111111111111111000000000000000000000000ul );

//////////////////////////////////////////////////////
// CardSetIt
//

CardSetIt::CardSetIt( const CardSet& init ): cardset(init), pos(0xff) {
	Increase();
}

void CardSetIt::Increase() {
	++pos;
	while ( !cardset.Have(Card(pos)) && pos < 48 ) {
		++pos;
	}
}

bool CardSetIt::GoOn() {
	return pos < 48;
}

Card CardSetIt::GetCard() {
	return Card(pos);
}

//////////////////////////////////////////////////////
// Player
//

Player::Player( const std::string& name_init, const CardSet& cardset_init, const Score& score_init,
				const bool& is_human_init ):
		name(name_init),
		cardset(cardset_init),
		score(score_init),
		is_human(is_human_init),
		is_re(false) {
}

bool Player::Have( const Card& card ) const {
	return cardset.Have(card);
}

CardSet Player::GetLegalCards( const Suit& tricksuit ) const {
	if ( cardset.Have( tricksuit ) ) {
		return cardset.MaskSuit( tricksuit );
	}
	return cardset;
}

void Player::Play( const Card& card ) {
	cardset.Remove(card);
	if ( card.LowBlock() == Card::club_queen ) {
		is_re = true;
	}
}

void Player::AddToScore( const Score& op ) {
	score += op;
}

const Score& Player::GetScore() const {
	return score;
}

bool Player::IsRe() const {
	return is_re;
}

bool Player::IsHuman() const {
	return is_human;
}

const std::string& Player::GetName() const {
	return name;
}

