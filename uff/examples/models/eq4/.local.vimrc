"map <F4> cs<"
"echo tagbar#currenttag('%s', '', '')

map <F4> :put =substitute(tagbar#currenttag('%s', '', ''), '()', '', '')<CR>:<C-u>call MoveLineUp()<CR>:Comment -b -tc<CR>

map <F5> :A<CR>:BufOnly<CR>
let g:surround_{char2nr('c')} = "\\1command\1([\r])"
map <F9> ysiwc
