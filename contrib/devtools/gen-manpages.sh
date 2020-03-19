#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

EOZID=${EOZID:-$BINDIR/eozid}
EOZICLI=${EOZICLI:-$BINDIR/eozi-cli}
EOZITX=${EOZITX:-$BINDIR/eozi-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/eozi-wallet}
EOZIQT=${EOZIQT:-$BINDIR/qt/eozi-qt}

[ ! -x $EOZID ] && echo "$EOZID not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a EOZVER <<< "$($EOZICLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for eozid if --version-string is not set,
# but has different outcomes for eozi-qt and eozi-cli.
echo "[COPYRIGHT]" > footer.h2m
$EOZID --version | sed -n '1!p' >> footer.h2m

for cmd in $EOZID $EOZICLI $EOZITX $WALLET_TOOL $EOZIQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${EOZVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${EOZVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
