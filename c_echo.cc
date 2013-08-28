/*$Id: c_echo.cc,v 26.133 2013/07/16 8:30:00 al Exp $ -*- C++ -*-
 * Copyright (C) 2013 Rishabh Yadav
 * Author: Rishabh Yadav <rishabh.ece.iitbhu@gmail.com>
 *
 * This file is part of "Gnucap", the Gnu Circuit Analysis Package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *------------------------------------------------------------------
 * echo:prints the text
 */

#include <gnucap/c_comand.h>
#include <gnucap/globals.h>
/*--------------------------------------------------------------------*/
namespace {
/*--------------------------------------------------------------------*/
class CMD_ECHO : public CMD {
        
public:
  void do_it(CS& cmd, CARD_LIST*){
    if(cmd.more()){itested();
      IO::mstdout << cmd.tail() << "\n";
    }
    else{itested();
      IO::mstdout << "Usage: echo [text]\n"; 
    }
  }
}p;
DISPATCHER<CMD>::INSTALL d1002(&command_dispatcher, "echo", &p);
/*----------------------------------------------------------------------*/
}

