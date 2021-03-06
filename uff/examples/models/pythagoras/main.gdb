# in batch mode:
set width 0
set height 0
set verbose off

# at entry point - cmd1
break main
commands 1
  print argc
  print argv[1]
  print argv[2]
  continue
end

# # at entry point - cmd2
# break ex-1.c:new_2d
# commands
#   printf "******************** %s ********************\n", "função new_2d"
#   continue
# end

# show arguments for program
show args
printf "Note, however: in batch mode, arguments will be ignored!\n"

# info breakpoints

# note: even if arguments are shown;
# must specify cmdline arg for "run"
# when running in batch mode! (then they are ignored)
# below, we specify command line argument "2":
run 3 4  # run

#start # alternative to run: runs to main, and stops
#continue
