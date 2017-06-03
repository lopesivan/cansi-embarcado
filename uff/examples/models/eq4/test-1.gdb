# in batch mode:
set width 0
set height 0
set verbose off

# at entry point - cmd1
break main
commands
  print argc
  continue
end

# show arguments for program
show args
printf "Note, however: in batch mode, arguments will be ignored!\n"

# info breakpoints

# note: even if arguments are shown;
# must specify cmdline arg for "run"
# when running in batch mode! (then they are ignored)
# below, we specify command line argument "2":

# eq2g
run  1 -6  9
run 10  8 19

# eq3g
run 1 -5  8 -6
run 1 -4  3 -2
run 1 -2 -3  4

# eq4g
run 1 -10     35 -50     24
run 1   3.741  7   7.483  4

#start # alternative to run: runs to main, and stops
#continue
