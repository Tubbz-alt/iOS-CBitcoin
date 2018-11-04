//
//  ECPrivateKey.hpp
//  CBitcoin
//
//  Created by Wolf McNally on 10/30/18.
//
//  Copyright © 2018 Blockchain Commons.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ECPrivateKey_hpp
#define ECPrivateKey_hpp

#include <stdlib.h>
#include "CBitcoinResult.hpp"

#ifdef __cplusplus
extern "C" {
#endif

    size_t _ecPrivateKeySize();

    CBitcoinResult _ecNewPrivateKey(const uint8_t* seed, size_t seedLength, uint8_t** privateKey, size_t* privateKeyLength);
    CBitcoinResult _ecPrivateKeyToWIF(const uint8_t* privateKey, size_t privateKeyLength, uint8_t wifVersion, bool isCompressed, char** wif, size_t* wifLength);
    CBitcoinResult _wifToECPrivateKey(const char* wif, uint8_t** privateKey, size_t* privateKeyLength);

#ifdef __cplusplus
}
#endif

#endif /* ECPrivateKey_hpp */
