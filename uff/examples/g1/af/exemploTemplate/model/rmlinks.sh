#!/usr/bin/env bash

for tmpl in *.tmpl; do
    # if exist link `tmpl' then remove.
    _l=$tmpl
    test -L $_l && rm $_l
done

# ----------------------------------------------------------------------------
exit 0
