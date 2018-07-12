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

#include <iostream>
#include "BitSerializer.h"
#include "BitDeserializer.h"

using namespace std;

int main() {

	BitSerializer testBitSerializer1;

	testBitSerializer1.PushBits (0x55, 7);
	testBitSerializer1.PushBits (0x7, 3);
	testBitSerializer1.PushBits (0x0, 2);

	std::vector<uint8_t> result = testBitSerializer1.GetBytes ();

	std::cout << "Result:    ";
	for (uint8_t i=0; i<result.size (); i++)
		std::cout << std::hex << int(result[i]) << " ";
	std::cout << std::endl;

  std::cout << "Expecting: ab c0" << std::endl;

  BitSerializer testBitSerializer2;

  testBitSerializer2.PushBits (0x55, 7);
  testBitSerializer2.PushBits (0x7, 3);
  testBitSerializer2.PushBits (0x0, 2);

  testBitSerializer2.InsertPaddingAtEnd (false);

  result = testBitSerializer2.GetBytes ();

  std::cout << "Result:    ";
  for (uint8_t i=0; i<result.size (); i++)
    std::cout << std::hex << int(result[i]) << " ";
  std::cout << std::endl;

  std::cout << "Expecting: a bc" << std::endl;

  BitDeserializer testBitDeserializer;
  uint8_t test[2];
  test[0] = 0xab;
  test[1] = 0xc0;

  testBitDeserializer.PushBytes (test,2);
  uint16_t nibble1 = testBitDeserializer.GetBits16 (7);
  uint8_t nibble2 = testBitDeserializer.GetBits8 (3);
  uint8_t nibble3 = testBitDeserializer.GetBits8 (2);
  std::cout << "Here we expect an error..." << std::endl;
  uint8_t errorNibble = testBitDeserializer.GetBits8 (6);

  std::cout << "Result:    " << std::hex << +nibble1 << " " << +nibble2 << " " << +nibble3 << " " << +errorNibble << std::endl;
  std::cout << "Expecting: 55 7 0 0" << std::endl;

	return 0;
}
