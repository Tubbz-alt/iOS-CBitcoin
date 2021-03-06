//
//  Base10.hpp
//  CBitcoin
//
//  Created by Wolf McNally on 10/24/18.
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

#ifndef Base10_hpp
#define Base10_hpp

#include <stdlib.h>
#include "CBitcoinResult.hpp"

#ifdef __cplusplus
extern "C" {
#endif

    uint8_t _btcDecimalPlaces(void);
    uint8_t _mbtcDecimalPlaces(void);
    uint8_t _ubtcDecimalPlaces(void);

    void _encodeBase10(uint64_t amount, char* _Nullable * _Nonnull string, size_t* _Nonnull stringLength, uint8_t decimalPlaces);
    CBitcoinResult _decodeBase10(const char* _Nonnull string, uint64_t* _Nonnull amount, size_t decimalPlaces, bool strict);

#ifdef __cplusplus
}
#endif

#endif /* Base10_hpp */
