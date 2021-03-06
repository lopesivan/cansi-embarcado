#!/bin/bash
#                      __ __       ___
#                     /\ \\ \    /'___`\
#                     \ \ \\ \  /\_\ /\ \
#                      \ \ \\ \_\/_/// /__
#                       \ \__ ,__\ // /_\ \
#                        \/_/\_\_//\______/
#                           \/_/  \/_____/
#                                         Algoritimos
#
#
#       Author: Ivan carlos da Silva Lopes
#         Mail: ivanlopes (at) 42algoritimos (dot) com (dot) br
#      License: gpl
#        Site: http://www.42algoritimos.com.br
#       Phone: +1 561 801 7985
#    Language: Shell Script
#        File: mklinks.sh
#        Date: Tue 09 Apr 2013 06:42:20 PM BRT
# Description:
#	`<  =code here=  >`

# ----------------------------------------------------------------------------
__debug__=0; __help__=0
__usage__=0
__clean__=0
# ----------------------------------------------------------------------------
[ "$1" = '--gui'   ] && { __gui__=1; shift;   }
[ "$1" = '-h'      ] && { __help__=1; shift;  }
[ "$1" = '--help'  ] && { __help__=1; shift;  }
[ "$1" = '-d'      ] && { __debug__=1; ECHO=echo;shift; }
[ "$1" = '--debug' ] && { __debug__=1; ECHO=echo;shift; }
[ "$1" = '--usage' ] && { __usage__=1; shift; }
[ "$1" = '--clean' ] && { __clean__=1; shift; }
# ----------------------------------------------------------------------------

##############################################################################
##############################################################################
##############################################################################

# ----------------------------------------------------------------------------

for tmpl in *.tmpl; do
	rm $tmpl
done

ls                 | 
grep -v *.tmpl     | 
grep -v mklinks.sh | 
sed -r -e 's/.*/& &/' -e 's/\./_/' -e 's/(.*) (.*)/ln -s \2 \1.tmpl/'| sh


# ----------------------------------------------------------------------------
exit 0
