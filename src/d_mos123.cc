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
#include "ap.h"
#include "d_mos123.h"
/*--------------------------------------------------------------------------*/
const double NA(NOT_INPUT);
const double INF(BIGBIG);
/*--------------------------------------------------------------------------*/
int MODEL_MOS123::_count = 0;
/*--------------------------------------------------------------------------*/
SDP_MOS123::SDP_MOS123(const COMMON_COMPONENT* cc)
  :SDP_MOS_BASE(cc)
{
  assert(cc);
  const COMMON_MOS* c = prechecked_cast<const COMMON_MOS*>(cc);
  assert(c);
  const MODEL_MOS123* m = prechecked_cast<const MODEL_MOS123*>(c->model());
  assert(m);
  l_eff = l_eff - 2. * m->ld;
  cgate = m->cox * w_eff * l_eff;
  phi = m->phi;
}
/*--------------------------------------------------------------------------*/
TDP_MOS123::TDP_MOS123(const DEV_MOS* d)
  :TDP_MOS_BASE(d)
{
}
/*--------------------------------------------------------------------------*/
MODEL_MOS123::MODEL_MOS123()
  :MODEL_MOS_BASE(),
   vto(NA),
   gamma(NA),
   phi(NA),
   lambda(NA),
   tox(NA),
   nsub(NA),
   nss(0.0),
   xj(NA),
   ld(0.0),
   uo((600.*CM2M2)),
   tpg(gtOPP),
   cox(NA),
   calc_vto(false),
   calc_gamma(false),
   calc_phi(false)
{
  ++_count;
  cjo = 0.;
  pb = 0.8;
  pbsw = NA;
}
/*--------------------------------------------------------------------------*/
bool MODEL_MOS123::parse_front(CS& cmd)
{
  return MODEL_MOS_BASE::parse_front(cmd);
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::parse_params(CS& cmd)
{
  get(cmd, "VTO", &vto, mSCALE, (static_cast<double>(polarity)));
  get(cmd, "GAmma", &gamma);
  get(cmd, "PHI", &phi, mPOSITIVE);
  get(cmd, "LAmbda", &lambda);
  get(cmd, "TOX", &tox, mPOSITIVE);
  get(cmd, "NSUb", &nsub, mSCALE, ICM2M3);
  get(cmd, "NSS", &nss, mSCALE, ICM2M2);
  get(cmd, "XJ", &xj, mPOSITIVE);
  get(cmd, "LD", &ld);
  get(cmd, "UO", &uo, mSCALE, CM2M2);
  get(cmd, "TPG", &tpg);
  MODEL_MOS_BASE::parse_params(cmd);
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::parse_finish()
{
  MODEL_MOS_BASE::parse_finish();

      {if (tpg < 0) {		// coerce tpg to a proper value
	tpg = gtSAME;		
      }else if (tpg > 0) {
	tpg = gtOPP;
      }else{
	assert(tpg == gtMETAL);
      }}
      if (tox != NA && tox <= 0) {
	untested();
	tox = NA;
	error(bWARNING, long_label()+": tox <= 0, treating as if not input\n");
      }
      if (nsub != NA && nsub < NI) {
	untested();
	nsub = NA;
	error(bWARNING,long_label()+": nsub < ni, treating as if not input\n");
      }
  if (pbsw == NA) {
    pbsw = pb;
  }
  cmodel = ((!cmodel)?3:cmodel);
}
/*--------------------------------------------------------------------------*/
SDP_CARD* MODEL_MOS123::new_sdp(const COMMON_COMPONENT* c)const
{
  assert(c);
  {if (dynamic_cast<const COMMON_MOS*>(c)) {
    return new SDP_MOS123(c);
  }else{
    return MODEL_MOS_BASE::new_sdp(c);
  }}
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::print_front(OMSTREAM& o)const
{
  MODEL_MOS_BASE::print_front(o);
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::print_params(OMSTREAM& o)const
{
  MODEL_MOS_BASE::print_params(o);
  if (!calc_vto)
    o << "  vto=" << vto/((static_cast<double>(polarity)));
  if (!calc_gamma)
    o << "  gamma=" << gamma;
  if (!calc_phi)
    o << "  phi=" << phi;
  if (lambda != NA)
    o << "  lambda=" << lambda;
  if (tox != NA)
    o << "  tox=" << tox;
  if (nsub != NA)
    o << "  nsub=" << nsub/(ICM2M3);
  if (nss != 0.0 || nsub != NA)
    o << "  nss=" << nss/(ICM2M2);
  if (xj != NA)
    o << "  xj=" << xj;
  o << "  ld=" << ld;
  o << "  uo=" << uo/(CM2M2);
  o << "  tpg=" << tpg;
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::print_calculated(OMSTREAM& o)const
{
  MODEL_MOS_BASE::print_calculated(o);
  if (calc_vto)
    o << "* vto=" << vto/((static_cast<double>(polarity)));
  if (calc_gamma)
    o << "* gamma=" << gamma;
  if (calc_phi)
    o << "* phi=" << phi;
  if (true)
    o << "* cox=" << cox;
}
/*--------------------------------------------------------------------------*/
bool MODEL_MOS123::is_valid(const COMMON_COMPONENT* cc)const
{
  const COMMON_MOS* c = dynamic_cast<const COMMON_MOS*>(cc);
  {if (!c) {
    return MODEL_MOS_BASE::is_valid(cc);
  }else{
    return MODEL_MOS_BASE::is_valid(cc);
  }}
}
/*--------------------------------------------------------------------------*/
void MODEL_MOS123::tr_eval(COMPONENT*)const
{
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
