//
//  Message.hpp
//  CBitcoin
//
//  Created by Wolf McNally on 11/5/18.
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

#ifndef Message_hpp
#define Message_hpp

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

    void _messageSign(const uint8_t* _Nonnull message, size_t messageLength, const char* _Nonnull wifKey, char* _Nullable * _Nonnull signature, size_t* _Nonnull signatureLength);
    bool _messageValidate(const char* _Nonnull paymentAddress, const char* _Nonnull signature, const uint8_t* _Nonnull message, size_t messageLength);

#ifdef __cplusplus
}
#endif

#endif /* Message_hpp */
