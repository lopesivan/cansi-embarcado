#!/usr/bin/env sh

d=m4
test -d $d || mkdir $d

autoheader               &&
  aclocal                &&
    autoconf             &&
      mkdir -p build-aux &&
        automake --add-missing && ./configure

exit 0

