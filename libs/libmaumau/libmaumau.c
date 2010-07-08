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

#define ISLIB

#include "libmaumau.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#ifdef MYXOMYCOTA
#include <myxomycota.h>
#else
#include <time.h>
#endif

maumau_t *newGame(player_count_t playerc, int correct_call)
{
  maumau_t *game;
  
  if ((playerc < 2) || (playerc > 5) || !correct_call)
    return 0;
  game = malloc(sizeof(maumau_t));
  game->_players = playerc;
  game->_stackSize = 0;
  return game;
}

void startGame(maumau_t *game)
{
  int i, j, k;
  
  for (i = 0; i < 5; i++)
    game->_player[i]._cards = 0;
  k = 0;
  for (i = MAUMAU_COLOUR_HEARTS; i <= MAUMAU_COLOUR_SPADES; i++)
  {
    for (j = MAUMAU_VALUE_7; j <= MAUMAU_VALUE_10; j++)
    {
      game->_stack[k]._single._colour = i;
      game->_stack[k++]._single._value = j;
      game->_stackSize++;
    }
    for (j = MAUMAU_VALUE_JACK; j <= MAUMAU_VALUE_ACE; j++)
    {
      game->_stack[k]._single._colour = i;
      game->_stack[k++]._single._value = j;
      game->_stackSize++;
    }
  }
}

void shuffle(card_t *stack)
{
  card_t tmpstack[NUM_ELEMENTS];
  int i, j;
  
  #ifdef MYXOMYCOTA
  srand(elapsedMilliseconds());
  #else
  srand(time(NULL));
  #endif
  memcpy(tmpstack, stack, sizeof(card_t)*NUM_ELEMENTS);
  for (i = 0; i < NUM_ELEMENTS; i++)
  {
    while (!tmpstack[(j = rand()%NUM_ELEMENTS)]._single._value);
    stack[i]._value = tmpstack[j]._value;
    tmpstack[j]._single._value = 0;
  }
}

void action(maumau_t *game, int number, ...)
{
  va_list pars;
  int which_player, cardstodo;
  
  va_start(pars, number);
  switch (number)
  {
    case (MAUMAU_ACTION_PLAYER):
      which_player = va_arg(pars, int)-1;
      switch (va_arg(pars, int))
      {
        case (MAUMAU_PLAYER_TAKE_CARDS):
          for (cardstodo = va_arg(pars, int); (cardstodo > 0) && (game->_player[which_player]._cards < 16) && (game->_stackSize > 0); cardstodo--)
          {
            game->_player[which_player]._hand[(int)game->_player[which_player]._cards++]._value = game->_stack[(int)--game->_stackSize]._value;
            game->_stack[(int)game->_stackSize]._value = 0;
          }
          break;
      }
      break;
  }
  va_end(pars);
}

void putCurrentCardUnderStack(maumau_t *game)
{
  memmove(&game->_stack[1], &game->_stack[0], sizeof(card_t)*(NUM_ELEMENTS-1));
  game->_stack[0]._value = game->_currentCard._value;
  game->_stackSize++;
}
