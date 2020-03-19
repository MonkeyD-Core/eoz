// Copyright (c) 2019-2020 Monkey D. Core
// Copyright (c) 2009-2018 The Eozi Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EOZI_SUPPORT_CLEANSE_H
#define EOZI_SUPPORT_CLEANSE_H

#include <stdlib.h>

/** Secure overwrite a buffer (possibly containing secret data) with zero-bytes. The write
 * operation will not be optimized out by the compiler. */
void memory_cleanse(void *ptr, size_t len);

#endif // EOZI_SUPPORT_CLEANSE_H
