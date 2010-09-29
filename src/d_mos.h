/* $Id: d_mos.h,v 20.13 2001/10/15 00:57:11 al Exp $ -*- C++ -*-
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
 * data structures and defaults for mos model.
 * internal units all mks (meters)
 * but some user input parameters are in cm.
 *
 * netlist syntax:
 * device:  mxxxx d g s b mname <device args> <model card args>
 * model:   .model mname NMOS <args>
 *	or  .model mname PMOS <args>
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS_H_INCLUDED
#define D_MOS_H_INCLUDED

#include "e_subckt.h"
#include "d_diode.h"
  class DEV_MOS;		/* this file */
  class COMMON_MOS;
  class EVAL_MOS_Cgb;
  class EVAL_MOS_Cgd;
  class EVAL_MOS_Cgs;
  class DEV_DIODE;		/* external */
  class DEV_CAPACITANCE;
  class DEV_POLY_G;
  class DEV_RESISTANCE;
  class MODEL_MOS_BASE;
  class SDP_MOS_BASE;
  enum {mNUM_INIT_COND = 3};
/*--------------------------------------------------------------------------*/
class COMMON_MOS
  :public COMMON_COMPONENT{
public:
  explicit COMMON_MOS(const COMMON_MOS& p);
  explicit COMMON_MOS(int c=0);
           ~COMMON_MOS();
  bool        operator==(const COMMON_COMPONENT&)const;
  COMMON_COMPONENT* clone()const {return new COMMON_MOS(*this);}
  void        parse(CS&);
  void        print(OMSTREAM&)const;
  void        expand();
  const char* name()const {return "mosfet";}
  const SDP_CARD* sdp()const {assert(_sdp); return _sdp;}
  bool      has_sdp()const {return _sdp;}
  static int  count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  double l_in;	// drawn (optical) channel length
  double w_in;	// channel width (drawn)
  double ad_in;	// drain area, drawn
  double as_in;	// source area, drawn
  double pd;	// drain perimeter
  double ps;	// source perimeter
  double nrd;	// drain # squares
  double nrs;	// source # squares
public: // calculated parameters
  const SDP_CARD* _sdp;
public: // attached commons
  COMMON_COMPONENT* _db;
  COMMON_COMPONENT* _sb;
};
/*--------------------------------------------------------------------------*/
class EVAL_MOS_Cgb : public COMMON_COMPONENT {
private:
  explicit EVAL_MOS_Cgb(const EVAL_MOS_Cgb& p)
    :COMMON_COMPONENT(p) {unreachable();}
public:
  explicit EVAL_MOS_Cgb(int c=0) :COMMON_COMPONENT(c) {}
  bool operator==(const COMMON_COMPONENT&)const {incomplete(); return false;}
  COMMON_COMPONENT* clone()const {untested(); return new EVAL_MOS_Cgb(*this);}
  const char* name()const {untested(); return "EVAL_MOS_Cgb";}
  void tr_eval(ELEMENT*d)const;
  bool has_tr_eval()const {return true;}
  bool has_ac_eval()const {return false;}
};
/*--------------------------------------------------------------------------*/
class EVAL_MOS_Cgd : public COMMON_COMPONENT {
private:
  explicit EVAL_MOS_Cgd(const EVAL_MOS_Cgd& p)
    :COMMON_COMPONENT(p) {unreachable();}
public:
  explicit EVAL_MOS_Cgd(int c=0) :COMMON_COMPONENT(c) {}
  bool operator==(const COMMON_COMPONENT&)const {incomplete(); return false;}
  COMMON_COMPONENT* clone()const {untested(); return new EVAL_MOS_Cgd(*this);}
  const char* name()const {untested(); return "EVAL_MOS_Cgd";}
  void tr_eval(ELEMENT*d)const;
  bool has_tr_eval()const {return true;}
  bool has_ac_eval()const {return false;}
};
/*--------------------------------------------------------------------------*/
class EVAL_MOS_Cgs : public COMMON_COMPONENT {
private:
  explicit EVAL_MOS_Cgs(const EVAL_MOS_Cgs& p)
    :COMMON_COMPONENT(p) {unreachable();}
public:
  explicit EVAL_MOS_Cgs(int c=0) :COMMON_COMPONENT(c) {}
  bool operator==(const COMMON_COMPONENT&)const {incomplete(); return false;}
  COMMON_COMPONENT* clone()const {untested(); return new EVAL_MOS_Cgs(*this);}
  const char* name()const {untested(); return "EVAL_MOS_Cgs";}
  void tr_eval(ELEMENT*d)const;
  bool has_tr_eval()const {return true;}
  bool has_ac_eval()const {return false;}
};
/*--------------------------------------------------------------------------*/
class DEV_MOS : public BASE_SUBCKT {
private:
  explicit DEV_MOS(const DEV_MOS& p);
public:
  explicit DEV_MOS();
           ~DEV_MOS() {--_count;}
private: // override virtual
  char      id_letter()const {return 'M';}
  const char* dev_type()const{return "mosfet";}
  int       numnodes()const  {return 4;}
  CARD*     clone()const     {return new DEV_MOS(*this);}
  void      parse(CS&);
  void      print(OMSTREAM&,int)const;
  void      expand();
  //void    map_nodes();     //BASE_SUBCKT
  //void    precalc();       //BASE_SUBCKT
  //void    dc_begin();      //BASE_SUBCKT
  //void    tr_begin();      //BASE_SUBCKT
  //void    tr_restore();    //BASE_SUBCKT
  void      dc_advance() {set_not_converged(); BASE_SUBCKT::dc_advance();}
  void      tr_advance() {set_not_converged(); BASE_SUBCKT::tr_advance();}
  bool      tr_needs_eval();
  void      tr_queue_eval() {if(tr_needs_eval()){q_eval();}}
  bool      do_tr();
  //void    tr_load();       //BASE_SUBCKT
  //double  tr_review();     //BASE_SUBCKT
  //void    tr_accept();     //BASE_SUBCKT
  //void    tr_unload();     //BASE_SUBCKT
  double    tr_probe_num(CS&)const;
  //void    ac_begin();      //BASE_SUBCKT
  //void    do_ac();         //BASE_SUBCKT
  //void    ac_load();       //BASE_SUBCKT
  //XPROBE  ac_probe_ext(CS&)const;//CKT_BASE/nothing
public:
  static int  count() {return _count;}
public: // may be used by models
  void limit_mos(double Vds, double Vgs, double Vbs);
  void reverse_if_needed();
private: // not available even to models
  static int _count;
public: // input parameters
public: // calculated parameters
  double ids;	// 
  double gds;	// dids/dvds
  double gmf;	// dids/dvgs
  double gmr;	// dids/dvgd
  double gmbf;	// dids/dvbs
  double gmbr;	// dids/dvbd
  double isub;	// 
  double gbbs;	// disub/dvbs
  double gbgs;	// disub/dvgs
  double gbds;	// disub/dvds
  double qgate;	// 
  double cggb;	// 
  double cgsb;	// 
  double cgdb;	// 
  double qdrn;	// 
  double cdgb;	// 
  double cdsb;	// 
  double cddb;	// 
  double qbulk;	// 
  double cbgb;	// 
  double cbsb;	// 
  double cbdb;	// 
  double gtau;	// 
  double cqgb;	// 
  double cqsb;	// 
  double cqdb;	// 
  double cqbb;	// 
  double tconst;	// 
  double cgb;	// placeholder
  double qgb;	// placeholder
  double qgd;	// 
  double cgd;	// 
  double qgs;	// 
  double cgs;	// 
  double vgs;	// terminal voltages
  double vds;	// 
  double vbs;	// 
  double vdsat;	// saturation voltage
  double vgst;	// vgs - von.
  double von;	// actual threshold voltage
  bool reversed;	// flag: Vgs < 0, reverse s & d
  bool cutoff;	// flag: in cut off region
  bool subthreshold;	// flag: subthreshold region (L2 only)
  bool saturated;	// flag: in saturation region
  bool sbfwd;	// flag: sb diode fwd biased
  bool dbfwd;	// flag: db diode fwd biased
  bool punchthru;	// flag: punch thru region
public: // netlist
  DEV_RESISTANCE* _Rs;
  DEV_RESISTANCE* _Rd;
  DEV_DIODE* _Ddb;
  DEV_DIODE* _Dsb;
  DEV_CAPACITANCE* _Cgs;
  DEV_CAPACITANCE* _Cgd;
  DEV_CAPACITANCE* _Cgb;
  DEV_POLY_G* _Ids;
private: // node list
  enum {n_drain=0, n_gate=1, n_source=2, n_bulk=3, n_idrain=-1, n_isource=-2};
  node_t _nodes[6];
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
