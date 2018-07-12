/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2018 Universita' di Firenze, Italy
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Tommaso Pecorella <tommaso.pecorella@unifi.it>
 */

#ifndef BITSERIALIZER_H_
#define BITSERIALIZER_H_

#include <vector>

class BitSerializer {
public:
  BitSerializer();
  virtual ~BitSerializer();

  void InsertPaddingAtEnd (bool padAtEnd);

  void PushBits (uint64_t value, uint8_t significantBits);

  std::vector<uint8_t> GetBytes ();
  uint8_t GetBytes (uint8_t *buffer, uint32_t size);

private:
  void PadAtStart ();

  void PadAtEnd ();

  std::vector<bool> m_blob;
  bool m_padAtEnd;
};

#endif /* BITSERIALIZER_H_ */
