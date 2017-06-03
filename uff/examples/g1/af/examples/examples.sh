#!/usr/bin/env bash

out=examples.md

echo '# Códigos' > $out
echo '# Exemplo de *Abstract Factory* Config.' >> $out

i=0
for yaml in *.yaml; do
	let i++
	cat << EOF >> $out
Arquivo *$yaml*:

~~~~ {#mycode$(printf "%03d" $i) .yaml include="$yaml"}
this will be replaced by contents of file
~~~~

\clearpage
EOF

done 
