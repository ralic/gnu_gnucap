/* $Id: d_mos123.model,v 21.14 2002/03/26 09:20:25 al Exp $ -*- C++ -*-
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
 * MOS model - base for levels 1,2,3,6
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS123_H_INCLUDED
#define D_MOS123_H_INCLUDED

#include "d_mos_base.h"
  enum gate_t {gtSAME = -1, gtMETAL = 0, gtOPP = 1};
  const double NI = 1.45e16;	/* intrinsic carrier concentration */
/*--------------------------------------------------------------------------*/
class SDP_MOS123
  :public SDP_MOS_BASE{
public:
  explicit SDP_MOS123(const COMMON_COMPONENT*);
public:
};
/*--------------------------------------------------------------------------*/
class TDP_MOS123
  :public TDP_MOS_BASE{
public:
  explicit TDP_MOS123(const DEV_MOS*);
public:
};
/*--------------------------------------------------------------------------*/
class MODEL_MOS123
  :public MODEL_MOS_BASE{
public:
  // using generated copy constructor, should be unreachable
  explicit MODEL_MOS123();
  ~MODEL_MOS123() {--_count;}
public: // override virtual
  bool      parse_front(CS&);
  void      parse_params(CS&);
  void      parse_finish();
  SDP_CARD* new_sdp(const COMMON_COMPONENT* c)const;
  void      print_front(OMSTREAM&)const;
  void      print_params(OMSTREAM&)const;
  void      print_calculated(OMSTREAM&)const;
  bool      is_valid(const COMMON_COMPONENT*)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  double vto;	// zero-bias threshold voltage
  double gamma;	// bulk threshold parameter
  double phi;	// surface potential
  double lambda;	// channel-length modulation
  double tox;	// oxide thickness
  double nsub;	// substrate doping
  double nss;	// surface state density
  double xj;	// metallurgical junction depth
  double ld;	// lateral diffusion
  double uo;	// surface mobility
  int tpg;	// type of gate material - really gate_t
public: // calculated parameters
  double cox;	// oxide capacitance (E_OX / tox)
  bool calc_vto;	// 
  bool calc_gamma;	// 
  bool calc_phi;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
