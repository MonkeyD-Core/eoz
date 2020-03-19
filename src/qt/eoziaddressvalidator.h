// Copyright (c) 2011-2014 The Eozi Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EOZI_QT_EOZIADDRESSVALIDATOR_H
#define EOZI_QT_EOZIADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class EoziAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EoziAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Eozi address widget validator, checks for a valid eozi address.
 */
class EoziAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit EoziAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // EOZI_QT_EOZIADDRESSVALIDATOR_H
