/* $Id: d_mos5.h,v 20.15 2001/10/30 03:58:55 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
 * Author: Albert Davis <aldavis@ieee.org>
 *
 * This file is part of "GnuCap", the Gnu Circuit Analysis Package
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
 * Spice BSIM2 model
 * derived from Spice3f4,Copyright 1990 Regents of the University of California
 * 1988 Min-Chie Jeng, Hong J. Park, Thomas L. Quarles
 * Recoded for GnuCap model compiler, Al Davis, 2000
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS5_H_INCLUDED
#define D_MOS5_H_INCLUDED

#include "u_sdp.h"
#include "d_mos_base.h"
/*--------------------------------------------------------------------------*/
class SDP_MOS5
  :public SDP_MOS_BASE{
public:
  explicit SDP_MOS5(const COMMON_COMPONENT*);
public:
  double phi;	// Strong inversion surface potential
  double vfb;	// flat band voltage at given L and W
  double k1;	// bulk effect coefficient 1
  double k2;	// bulk effect coefficient 2
  double eta0;	// drain induced barrier lowering
  double etaB;	// Vbs dependence of Eta
  double mob0;	// 
  double mob0B;	// 
  double mobs0;	// 
  double mobsB;	// 
  double mob20;	// 
  double mob2B;	// 
  double mob2G;	// 
  double mob30;	// 
  double mob3B;	// 
  double mob3G;	// 
  double mob40;	// 
  double mob4B;	// 
  double mob4G;	// 
  double ua0;	// Linear Vgs dependence of Mobility
  double uaB;	// Vbs dependence of Ua
  double ub0;	// Quadratic Vgs dependence of Mobility
  double ubB;	// Vbs dependence of Ub
  double u10;	// Drift Velocity Saturation due to Vds
  double u1B;	// Vbs dependence of U1
  double u1D;	// Vds dependence of U1
  double n0;	// Subthreshold slope at Vds=0, Vbs=0
  double nB;	// Vbs dependence of n
  double nD;	// Vds dependence of n
  double vof0;	// Vth offset at Vds=0, Vbs=0
  double vofB;	// Vbs dependence of Vof
  double vofD;	// Vds dependence of Vof
  double ai0;	// Pre-factor in hot-electron effects
  double aiB;	// Vbs dependence of Ai
  double bi0;	// Exp-factor in hot-electron effects
  double biB;	// Vbs dependence of Bi
  double vghigh;	// Upper bound of cubic spline function
  double vglow;	// Lower bound of cubic spline function
  double beta0;	// Beta at Vds = 0 and Vgs = Vth
  double beta0B;	// Vbs dependence of Beta0
  double betas0;	// Beta at Vds=Vdd and Vgs=Vth
  double betasB;	// Vbs dependence of Betas
  double beta20;	// Vds dependence of Beta in tanh term
  double beta2B;	// Vbs dependence of Beta2
  double beta2G;	// Vgs dependence of Beta2
  double beta30;	// Vds dependence of Beta in linear term
  double beta3B;	// Vbs dependence of Beta3
  double beta3G;	// Vgs dependence of Beta3
  double beta40;	// Vds dependence of Beta in quadra term
  double beta4B;	// Vbs dependence of Beta4
  double beta4G;	// Vgs dependence of Beta4
  double Phis3;	// 
  double One_Third_CoxWL;	// 
  double Two_Third_CoxWL;	// 
  double Arg;	// 
};
/*--------------------------------------------------------------------------*/
class TDP_MOS5
  :public TDP_MOS_BASE{
public:
  explicit TDP_MOS5(const DEV_MOS*);
public:
};
/*--------------------------------------------------------------------------*/
class MODEL_MOS5
  :public MODEL_MOS_BASE{
public:
  // using generated copy constructor, should be unreachable
  explicit MODEL_MOS5();
  ~MODEL_MOS5() {--_count;}
public: // override virtual
  bool      parse_front(CS&);
  void      parse_params(CS&);
  void      parse_finish();
  SDP_CARD* new_sdp(const COMMON_COMPONENT* c)const;
  void      print_front(OMSTREAM&)const;
  void      print_params(OMSTREAM&)const;
  void      print_calculated(OMSTREAM&)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  enum {LEVEL=5};
  static int _count;
public: // input parameters
  SDP phi;	// Strong inversion surface potential
  SDP vfb;	// flat band voltage at given L and W
  SDP k1;	// bulk effect coefficient 1
  SDP k2;	// bulk effect coefficient 2
  SDP eta0;	// drain induced barrier lowering
  SDP etaB;	// Vbs dependence of Eta
  SDP mob0;	// 
  SDP mob0B;	// 
  SDP mobs0;	// 
  SDP mobsB;	// 
  SDP mob20;	// 
  SDP mob2B;	// 
  SDP mob2G;	// 
  SDP mob30;	// 
  SDP mob3B;	// 
  SDP mob3G;	// 
  SDP mob40;	// 
  SDP mob4B;	// 
  SDP mob4G;	// 
  SDP ua0;	// Linear Vgs dependence of Mobility
  SDP uaB;	// Vbs dependence of Ua
  SDP ub0;	// Quadratic Vgs dependence of Mobility
  SDP ubB;	// Vbs dependence of Ub
  SDP u10;	// Drift Velocity Saturation due to Vds
  SDP u1B;	// Vbs dependence of U1
  SDP u1D;	// Vds dependence of U1
  SDP n0;	// Subthreshold slope at Vds=0, Vbs=0
  SDP nB;	// Vbs dependence of n
  SDP nD;	// Vds dependence of n
  SDP vof0;	// Vth offset at Vds=0, Vbs=0
  SDP vofB;	// Vbs dependence of Vof
  SDP vofD;	// Vds dependence of Vof
  SDP ai0;	// Pre-factor in hot-electron effects
  SDP aiB;	// Vbs dependence of Ai
  SDP bi0;	// Exp-factor in hot-electron effects
  SDP biB;	// Vbs dependence of Bi
  SDP vghigh;	// Upper bound of cubic spline function
  SDP vglow;	// Lower bound of cubic spline function
  double dl;	// Channel length reduction
  double dw;	// Channel width reduction
  double tox;	// Gate oxide thickness
  double vdd;	// Max Vds
  double vgg;	// Max Vgs
  double vbb;	// Max Vbs
  double wdf;	// Default width of source drain diffusion (ignored)
  double dell;	// Length reduction of source drain diff (ignored)
  double temp;	// temperature
  double xpart;	// Flag for channel charge partitioning
public: // calculated parameters
  double cox;	// 
  double vdd2;	// 
  double vgg2;	// 
  double vbb2;	// 
  double Vtm;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
