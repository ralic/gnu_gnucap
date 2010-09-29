/*$Id: d_ccvs.cc,v 23.1 2002/11/06 07:47:50 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
 * Author: Albert Davis <aldavis@ieee.org>
 *
 * This file is part of "Gnucap", the Gnu Circuit Analysis Package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *------------------------------------------------------------------
 * functions for ccvs
 * It is really voltage controlled, taking into account the sense element.
 * Then adjust the gain to account for the sense element.
 */
#include "d_ccvs.h"
/*--------------------------------------------------------------------------*/
void DEV_CCVS::precalc()
{
  _loss1 = _loss0 = 1./OPT::shortckt;
  _y0.f0 = LINEAR;
  _y0.f1 = value();
  _m0.c1 = -_loss0 * value();
  _m0.c0 = 0.;
  _m1 = _m0;
  set_converged();
  assert(!constant()); /* because of incomplete analysis */
}
/*--------------------------------------------------------------------------*/
void DEV_CCVS::dc_begin()
{
  _loss1 = _loss0 = 1./OPT::shortckt;
  if (!using_tr_eval()){
    assert(_y0.f0 == LINEAR);
    assert(_y0.f1 == value());
  }
}
/*--------------------------------------------------------------------------*/
bool DEV_CCVS::do_tr()
{
  assert(_input);
  {if (using_tr_eval()){
    _m0.x = tr_involts_limited();
    _y0.x = _input->tr_amps();
    tr_eval();
    _m0.c0 = _y0.f0 - _y0.x * _y0.f1;
  }else{
    assert(_y0.f0 == LINEAR);
    assert(_y0.f1 == value());
    _m0.c0 = 0.;
    assert(converged());
  }}
  _m0.c0 += _y0.f1 * _input->_m0.c0;
  _m0.c1  = _y0.f1 * (_input->_loss0 + _input->_m0.c1);
  _m0 *= -_loss0;
  store_values();
  q_load();
  return converged();
}
/*--------------------------------------------------------------------------*/
void DEV_CCVS::do_ac()
{
  assert(_input);
  if (!_input->evaluated()){
    untested();
    _input->do_ac();	    /* BUG: premature load of sense element */
  }
  ac_load_loss();
  {if (has_ac_eval()){
    ac_eval();
  }else{
    assert(_ev == _y0.f1);
    assert(has_tr_eval() || _ev == value());
  }}
  {if (_input->is_source()){
    _acg = -_loss0 * _ev * _input->_acg;
    ac_load_source();
    _acg = -_loss0 * _ev * _input->_loss0;
  }else{
    _acg = -_loss0 * _ev * _input->_acg;
  }}
  ac_load_active();
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
