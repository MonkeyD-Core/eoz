// Copyright (c) 2019-2020 Monkey D. Core
// Copyright (c) 2019-2020 The Eozi Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/**
 * Money parsing/formatting utilities.
 */
#ifndef EOZI_UTIL_MONEYSTR_H
#define EOZI_UTIL_MONEYSTR_H

#include <amount.h>
#include <attributes.h>

#include <cstdint>
#include <string>

/* Do not use these functions to represent or parse monetary amounts to or from
 * JSON but use AmountFromValue and ValueFromAmount for that.
 */
std::string FormatMoney(const CAmount& n);
NODISCARD bool ParseMoney(const std::string& str, CAmount& nRet);
NODISCARD bool ParseMoney(const char* pszIn, CAmount& nRet);

#endif // EOZI_UTIL_MONEYSTR_H
