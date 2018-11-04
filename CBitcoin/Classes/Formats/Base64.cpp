//
//  Base64.cpp
//  CBitcoin
//
//  Created by Wolf McNally on 10/25/18.
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

#include "Base64.hpp"
#include <bitcoin/bitcoin.hpp>
#include <string>
#include "Util.hpp"

using namespace libbitcoin;

void _base64Encode(const uint8_t* data, size_t length, char** string, size_t* stringLength) {
    auto s = encode_base64(_toDataSlice(data, length));
    _sendString(s, string, stringLength);
}

CBitcoinResult _base64Decode(const char* string, uint8_t** data, size_t* dataLength) {
    auto s = std::string(string);
    auto chunk = data_chunk();
    if(!decode_base64(chunk, s)) {
        return CBITCOIN_ERROR_INVALID_FORMAT;
    }
    _sendData(chunk, data, dataLength);
    return CBITCOIN_SUCCESS;
}
