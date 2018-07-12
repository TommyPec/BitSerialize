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

#include "BitDeserializer.h"
#include <iostream>

BitDeserializer::BitDeserializer() {
  m_deserializing = false;
}

BitDeserializer::~BitDeserializer() {
  // TODO Auto-generated destructor stub
}

void BitDeserializer::PushBytes (std::vector<uint8_t> bytes)
{
  if (m_deserializing)
    {
      std::cout << "ERROR, can't add bytes after deserialization started" << std::endl;
      return;
    }
  m_bytesBlob.insert (m_bytesBlob.end (), bytes.begin (), bytes.end ());
}

void BitDeserializer::PushBytes (uint8_t* bytes, uint32_t size)
{
  for (uint32_t index=0; index < size; index++)
    {
      m_bytesBlob.push_back (bytes[index]);
    }
}

void BitDeserializer::PushByte (uint8_t byte)
{
  if (m_deserializing)
    {
      std::cout << "ERROR, can't add bytes after deserialization started" << std::endl;
      return;
    }
  m_bytesBlob.push_back (byte);
}

uint8_t BitDeserializer::GetBits8 (uint8_t size)
{
  uint8_t result = 0;
  PrepareDeserialization ();

  if (size > 8)
    {
      std::cout << "ERROR, number of requested bits exceeds 8" << std::endl;
      return 0;
    }
  if (size > m_blob.size ())
    {
      std::cout << "ERROR, number of requested bits exceeds blob size" << std::endl;
      return 0;
    }

  for (uint8_t i=0; i<size; i++)
    {
      result <<= 1;
      result |= m_blob.front ();
      m_blob.pop_front ();
    }
  return result;
}

uint16_t BitDeserializer::GetBits16 (uint8_t size)
{
  uint8_t result = 0;
  PrepareDeserialization ();

  if (size > 16)
    {
      std::cout << "ERROR, number of requested bits exceeds 16" << std::endl;
      return 0;
    }
  if (size > m_blob.size ())
    {
      std::cout << "ERROR, number of requested bits exceeds blob size" << std::endl;
      return 0;
    }

  for (uint8_t i=0; i<size; i++)
    {
      result <<= 1;
      result |= m_blob.front ();
      m_blob.pop_front ();
    }
  return result;
}

uint32_t BitDeserializer::GetBits32 (uint8_t size)
{
  uint8_t result = 0;
  PrepareDeserialization ();

  if (size > 32)
    {
      std::cout << "ERROR, number of requested bits exceeds 32" << std::endl;
      return 0;
    }
  if (size > m_blob.size ())
    {
      std::cout << "ERROR, number of requested bits exceeds blob size" << std::endl;
      return 0;
    }

  for (uint8_t i=0; i<size; i++)
    {
      result <<= 1;
      result |= m_blob.front ();
      m_blob.pop_front ();
    }
  return result;
}

uint64_t BitDeserializer::GetBits64 (uint8_t size)
{
  uint8_t result = 0;
  PrepareDeserialization ();

  if (size > 64)
    {
      std::cout << "ERROR, number of requested bits exceeds 64" << std::endl;
      return 0;
    }
  if (size > m_blob.size ())
    {
      std::cout << "ERROR, number of requested bits exceeds blob size" << std::endl;
      return 0;
    }

  for (uint8_t i=0; i<size; i++)
    {
      result <<= 1;
      result |= m_blob.front ();
      m_blob.pop_front ();
    }
  return result;
}

void BitDeserializer::PrepareDeserialization ()
{
  if (m_deserializing == false)
    {
      m_deserializing = true;
      for (auto index = m_bytesBlob.begin (); index != m_bytesBlob.end (); index++)
        {
          m_blob.push_back (*index & 0x80);
          m_blob.push_back (*index & 0x40);
          m_blob.push_back (*index & 0x20);
          m_blob.push_back (*index & 0x10);
          m_blob.push_back (*index & 0x8);
          m_blob.push_back (*index & 0x4);
          m_blob.push_back (*index & 0x2);
          m_blob.push_back (*index & 0x1);
        }
    }
}
