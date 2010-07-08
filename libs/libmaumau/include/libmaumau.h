/***************************************************************************
 *   Copyright (C) 2009 by Max Reitz                                       *
 *   xanclic@googlemail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef __LIBMAUMAU_H
#define __LIBMAUMAU_H

#define NUM_ELEMENTS 32

#ifndef ISLIB

const char *colour_name[4] = {
  "Herz",
  "Karo",
  "Kreuz",
  "Pik"
};

const char *value_name[11] = {
  "<INV>",
  "Bube",
  "Dame",
  "König",
  "As",
  "<INV>",
  "<INV>",
  "7",
  "8",
  "9",
  "10"
};

const char value_char[11] = {
  '?',
  'B',
  'D',
  'K',
  'A',
  '?',
  '?',
  '7',
  '8',
  '9',
  'X'
};

#endif

#define MAUMAU_COLOUR_HEARTS   0 /* Herz  */
#define MAUMAU_COLOUR_DIAMONDS 1 /* Karo  */
#define MAUMAU_COLOUR_CLUBS    2 /* Kreuz */
#define MAUMAU_COLOUR_SPADES   3 /* Pik   */

#define MAUMAU_VALUE_7     7
#define MAUMAU_VALUE_8     8
#define MAUMAU_VALUE_9     9
#define MAUMAU_VALUE_10   10
#define MAUMAU_VALUE_JACK  1 /* Bube  */
#define MAUMAU_VALUE_QUEEN 2 /* Dame  */
#define MAUMAU_VALUE_KING  3 /* König */
#define MAUMAU_VALUE_ACE   4 /* As   */

#define MAUMAU_ACTION_PLAYER     0
#define MAUMAU_PLAYER_TAKE_CARDS 0

#define players ,1
#define with (player_count_t)
#define player MAUMAU_ACTION_PLAYER,
#define takes ,MAUMAU_PLAYER_TAKE_CARDS,
#define cards
#define card

typedef int player_count_t;

typedef union
{
  struct
  {
    char _colour;
    char _value;
  } _single;
  short _value;
} card_t;

typedef struct
{
  char _cards;
  card_t _hand[32];
} player_t;

typedef struct
{
  int _players;
  int _stackSize;
  player_t _player[5];
  card_t _stack[NUM_ELEMENTS];
  card_t _currentCard;
} maumau_t;

void      action(maumau_t *game, int number, ...);
maumau_t* newGame(player_count_t playerc, int correct_call);
void      putCurrentCardUnderStack(maumau_t *game);
void      shuffle(card_t *stack);
void      startGame(maumau_t *game);

#endif
