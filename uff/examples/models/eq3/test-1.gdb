# in batch mode:
set width 0
set height 0
set verbose off

# at entry point - cmd1
break main
commands
  print argc
  print argv[1]
  print argv[2]
  print argv[3]
  print argv[4]
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
run 1 -5  8 -6 # run
run 1 -4  3 -2 # run
run 1 -2 -3  4 # run

#start # alternative to run: runs to main, and stops
#continue
