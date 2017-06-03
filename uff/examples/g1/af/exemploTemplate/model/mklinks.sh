#!/usr/bin/env bash

ls                  |
grep -v *.tmpl      |
grep -v mklinks.sh  |
grep -v rmklinks.sh |
sed -r -e 's/.*/& &/' -e 's/\./_/' -e 's/(.*) (.*)/ln -s \2 \1.tmpl/'| sh

# ----------------------------------------------------------------------------
exit 0
