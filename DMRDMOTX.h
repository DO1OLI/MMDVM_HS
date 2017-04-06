/*
 *   Copyright (C) 2015,2016 by Jonathan Naylor G4KLX
 *   Copyright (C) 2016 by Colin Durbridge G4EML
 *   Copyright (C) 2016, 2017 by Andy Uribe CA6JAU
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(DMRDMOTX_H)
#define  DMRDMOTX_H

#include "DMRDefines.h"

#include "SerialRB.h"

class CDMRDMOTX {
public:
  CDMRDMOTX();

  uint8_t writeData(const uint8_t* data, uint8_t length);

  void process();

  void setTXDelay(uint8_t delay);

  uint16_t getSpace() const;
  
  void setColorCode(uint8_t colorCode);

private:
  CSerialRB            m_fifo;
  uint8_t              m_poBuffer[80U];
  uint16_t             m_poLen;
  uint16_t             m_poPtr;
  uint16_t             m_txDelay;
  uint32_t             m_count;
  bool                 m_delay;
  uint8_t              m_idle[DMR_FRAME_LENGTH_BYTES];
  uint8_t              m_cachPtr;

  void createCACH(uint8_t* buffer, uint8_t slotIndex);
  void writeByte(uint8_t c);
};

#endif
