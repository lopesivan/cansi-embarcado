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
  continue
end

break eq2.c:eq2g
commands
  info locals
  continue
end

break eq2.c:54
commands
  info locals
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
run 10  8 19     # run
run 10  8 19  10 # run

#start # alternative to run: runs to main, and stops
#continue
