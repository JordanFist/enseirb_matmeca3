#ifndef CARCASSONNE_INTERFACE_H
#define CARCASSONNE_INTERFACE_H
#include <stddef.h>

void finalize();

/* Positions */
struct position {
  int x;
  int y;
};

/* Sides of the cards */
enum direction {
  NORTH,
  WEST,
  SOUTH,
  EAST,
};

/* Places */
/* Lists all the possible places of the meeples on a card */
enum place {
  NO_MEEPLE,      //0. special place for not placing a meeple
  POS_NORTH_EAST, //1. {NE}
  POS_NORTH,      //2. N
  POS_NORTH_WEST, //3. {NW}
  POS_WEST_NORTH, //4. {WN}
  POS_WEST,       //5. W
  POS_WEST_SOUTH, //6. {WS}
  POS_SOUTH_WEST, //7. {SW}
  POS_SOUTH,      //8. S
  POS_SOUTH_EAST, //9. {SE}
  POS_EAST_SOUTH, //10. {ES}
  POS_EAST,       //11. E
  POS_EAST_NORTH, //12. {EN}  
  POS_CENTER,     //13. C
  LAST_POS,
};

/* Cards */
/* This list is the same as the one given on in the rules file :
   http://riograndegames.com/getFile.php?id=670
   There are 24 types of cards, listed here line by line, left to right.
   All cards are described here by their directions, one per side (NWSE).
   When a direction is not described, it is by default a plain. 
*/
enum card_id {
  CARD_MONASTERY_ROAD,      // 0. monastery center, connected to one road S (2)
  CARD_MONASTERY_ALONE,     // 1. monastery center (4)
  CARD_CITY_ALL_SIDES,      // 2. connected cities on all sides (1)
  CARD_ROAD_STRAIGHT_CITY,  // 3. road connected N to S, city E, initial card (4)
  CARD_CITY_ONE_SIDE,       // 4. city N (5)
  CARD_CITY_TUNNEL_SHLD,    // 5. city connected E to W, shield (2)
  CARD_CITY_TUNNEL,         // 6. city connected N to S (1)
  CARD_PLAIN_TUNNEL,        // 7. plain connected N to S, city elsewhere (3)
  CARD_PLAIN_TWO_CITIES,    // 8. plain connected W to N, 
                            //    disconnected but jointive cities E and S (2)
  CARD_ROAD_TURN_RIGHT_CITY,// 9. city N, road connected S to E (3)
  CARD_ROAD_TURN_LEFT_CITY, // 10. city E, road connected W to N (3)
  CARD_JUNCTION_CITY,       // 11. city E, 3 roads elsewhere connected at center (3)
  CARD_PLAIN_CITY_SHLD,     // 12. city connected W to N, shield (2)
  CARD_PLAIN_CITY,          // 13. city connected W to N (3)
  CARD_PLAIN_CITY_ROAD_SHLD,// 14. city connected W to N, road connected S to E, shield (2)
  CARD_PLAIN_CITY_ROAD,     // 15. city connected W to N, road connected S to E (3)
  CARD_CITY_THREE_SHLD,     // 16. plain S, connected city elsewhere, shield (1)
  CARD_CITY_THREE,          // 17. plain S, connected city elsewhere (3)
  CARD_CITY_THREE_ROAD_SHLD,// 18. road S, connected city elsewhere, shield (2)
  CARD_CITY_THREE_ROAD,     // 19. road S, connected city elsewhere (1)
  CARD_ROAD_STRAIGHT,       // 20. road connected N to S (8)
  CARD_ROAD_TURN,           // 21. road connected W to S (9) 
  CARD_JUNCTION_THREE,      // 22. plain N, 3 roads elsewhere connected at center (4)
  CARD_JUNCTION_FOUR,       // 23. 4 roads connected at the center (1)
  LAST_CARD,
};

/* Authorized positions */
/* The allowed_positions table lists for each card the allowed
   position of a meeple. Each list is terminated by NO_MEEPLE. 
 */
static const enum place allowed_positions[LAST_CARD][LAST_POS] = {
  { POS_NORTH, POS_SOUTH, POS_CENTER, NO_MEEPLE },
  { POS_NORTH, POS_CENTER, NO_MEEPLE },
  { POS_CENTER, NO_MEEPLE },
  { POS_WEST, POS_EAST, POS_CENTER, POS_NORTH_EAST, NO_MEEPLE },
  { POS_NORTH, POS_CENTER, NO_MEEPLE },
  { POS_NORTH, POS_SOUTH, POS_CENTER, NO_MEEPLE },
  { POS_WEST, POS_EAST, POS_CENTER, NO_MEEPLE },
  { POS_WEST, POS_EAST, POS_CENTER, NO_MEEPLE },
  { POS_SOUTH, POS_EAST, POS_CENTER, NO_MEEPLE },
  { POS_NORTH, POS_WEST, POS_SOUTH_EAST, POS_SOUTH, NO_MEEPLE },
  { POS_NORTH_WEST, POS_SOUTH, POS_EAST, POS_NORTH, NO_MEEPLE },
  { POS_NORTH, POS_NORTH_WEST, POS_WEST, POS_SOUTH_WEST, POS_SOUTH,
    POS_EAST, POS_NORTH_EAST, NO_MEEPLE },
  { POS_NORTH, POS_SOUTH, NO_MEEPLE },
  { POS_NORTH, POS_SOUTH, NO_MEEPLE },
  { POS_NORTH, POS_SOUTH, POS_SOUTH_EAST, POS_SOUTH_WEST, NO_MEEPLE },
  { POS_NORTH, POS_SOUTH, POS_SOUTH_EAST, POS_SOUTH_WEST, NO_MEEPLE },
  { POS_SOUTH, POS_CENTER, NO_MEEPLE },
  { POS_SOUTH, POS_CENTER, NO_MEEPLE },
  { POS_SOUTH, POS_SOUTH_EAST, POS_SOUTH_WEST, POS_CENTER, NO_MEEPLE },
  { POS_SOUTH, POS_SOUTH_EAST, POS_SOUTH_WEST, POS_CENTER, NO_MEEPLE },
  { POS_WEST, POS_EAST, POS_CENTER, NO_MEEPLE },
  { POS_NORTH_EAST, POS_SOUTH_WEST, POS_WEST, NO_MEEPLE },
  { POS_NORTH, POS_WEST, POS_SOUTH_WEST, POS_SOUTH, POS_SOUTH_EAST,
    POS_EAST, NO_MEEPLE },
  { POS_NORTH, POS_NORTH_WEST, POS_WEST, POS_SOUTH_WEST, POS_SOUTH,
    POS_SOUTH_EAST, POS_EAST, POS_NORTH_EAST, NO_MEEPLE }
};

/* Action and moves */
enum action {
  VALID,             // valid action
  FAILED,            // invalid action
};

/* Announces the end of the game to the player, and cleans up the
   memory he may have been using.
 * POSTCOND:
 * - every allocation done during the calls to initialize and play
 *   functions must have been freed
 */
struct move {
  enum action check;     // validation of the move by the server
  unsigned int player;   // player issueing the move
  enum card_id card;     // card played
  struct position onto;  // position on the board
  enum direction dir;    // direction of the north of the card
  enum place place;      // place of the meeple on the card
};

struct player_base {
  void* pointeur;
  void (*initialize)(unsigned int, unsigned int);
  struct move (*play)(enum card_id card, struct move const previous_moves[], size_t n_moves);
  const char * (*get_player_name)(void);
  void (*finalize)(void);
};

//void* sym(void* p,char* str);
//void *open(const char *str);
//void load_functions(void *p, struct player_base *base);
//size_t min(size_t x,size_t y);
/* Public functions */

/* Access to player informations
 * RETURNS:
 * - the player name as an [a-zA-Z0-9 -_]* string
 */
char const* get_player_name();

/* Player initialization
 * PARAM:
 * - id: player ID
 * - n_players: number of players in the game
 * PRECOND:
 * - 0 <= id < n_players
 */
void initialize(unsigned int id,
		unsigned int n_players);

/* Computes next move
 * PARAM:
 * - card: the id of the card that has been drawn
 * - previous_moves: ordered list of previous moves starting from the last
 *   move issued by the player.
 * - n_moves: number of moves in previous_moves
 * PRECOND:
 * - previous_moves is an array of at least n_moves elements.
 * - previous_moves is an ordered list of previous moves starting from the last
 *   move of the player. Every move invalidated by the server has action
 *   FAILED. Every move validated by the server is faithfully transcribed.
 * RETURNS:
 * - the next move for the player.
 */
struct move play(enum card_id card,
		 const struct move previous_moves[], size_t n_moves);
#endif // CARCASSONNE_INTERFACE_H