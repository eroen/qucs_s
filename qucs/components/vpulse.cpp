/***************************************************************************
                         vpulse.cpp  -  description
                             -------------------
    begin                : Sat Sep 18 2004
    copyright            : (C) 2004 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "vpulse.h"


vPulse::vPulse()
{
  Description = QObject::tr("ideal voltage pulse source");

  Arcs.append(new Arc(-12,-12, 25, 25,     0, 16*360,QPen(QPen::darkBlue,2)));
  Lines.append(new Line(-30,  0,-12,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( 30,  0, 12,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( 18,  5, 18, 11,QPen(QPen::red,1)));
  Lines.append(new Line( 21,  8, 15,  8,QPen(QPen::red,1)));
  Lines.append(new Line(-18,  5,-18, 11,QPen(QPen::black,1)));

  Lines.append(new Line(  6, -3,  6,  3,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6, -7, -6, -3,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6,  3, -6,  7,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6, -3,  6, -3,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6,  3,  6,  3,QPen(QPen::darkBlue,2)));

  Ports.append(new Port( 30,  0));
  Ports.append(new Port(-30,  0));

  x1 = -30; y1 = -14;
  x2 =  30; y2 =  14;

  tx = x1+4;
  ty = y2+4;
  Model = "Vpulse";
  Name  = "V";

  Props.append(new Property("U1", "0 V", true,
		QObject::tr("voltage before and after the pulse")));
  Props.append(new Property("U2", "1 V", true,
		QObject::tr("voltage of the pulse")));
  Props.append(new Property("t1", "0", true,
		QObject::tr("start time of the pulse")));
  Props.append(new Property("t2", "1 ms", true,
		QObject::tr("ending time of the pulse")));
  Props.append(new Property("tr", "1 ns", false,
		QObject::tr("rise time of the leading edge")));
  Props.append(new Property("tf", "1 ns", false,
		QObject::tr("fall time of the trailing edge")));
}

vPulse::~vPulse()
{
}

Component* vPulse::newOne()
{
  return new vPulse();
}

Component* vPulse::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Voltage Pulse");
  BitmapFile = "vpulse";

  if(getNewOne)  return new vPulse();
  return 0;
}