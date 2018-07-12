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

#ifndef BITDESERIALIZER_H_
#define BITDESERIALIZER_H_

#include <vector>
#include <deque>

class BitDeserializer {
public:
  BitDeserializer();
  virtual ~BitDeserializer();

  void PushBytes (std::vector<uint8_t> bytes);
  void PushBytes (uint8_t* bytes, uint32_t size);
  void PushByte (uint8_t byte);

  uint8_t GetBits8 (uint8_t size);
  uint16_t GetBits16 (uint8_t size);
  uint32_t GetBits32 (uint8_t size);
  uint64_t GetBits64 (uint8_t size);

private:
  void PrepareDeserialization ();

  std::deque<bool> m_blob;
  std::vector<uint8_t> m_bytesBlob;
  bool m_deserializing;
};

#endif /* BITDESERIALIZER_H_ */
