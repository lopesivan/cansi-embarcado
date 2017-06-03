# in batch mode:
set width 0
set height 0
set verbose off

# at entry point - cmd1
break main
commands 1
  print argc
  continue
end

# at entry point - cmd2
break ex-1.c:new_2d
commands 2
  printf "******************** %s ********************\n", "função new_2d"
  continue
end

# at entry point - cmd3
break ex-1.c:31
commands 3
  printf "*** i    = %d ****\n", i
  printf "*** dim1 = %d ****\n", dim1
  printf "*** dim2 = %d ****\n", dim2
  printf "*** array2d = %d ****\n", array2d
  printf "*** array2d[%d] = %d ****\n", i, array2d[i]
  p *array2d@50
  printf "*->** array2d[%d] = %d ****\n", i, (array2d[1] - array2d[0])
  continue
end

#break ex-1.c:new_3d

# show arguments for program
show args
printf "Note, however: in batch mode, arguments will be ignored!\n"

# info breakpoints

# note: even if arguments are shown;
# must specify cmdline arg for "run"
# when running in batch mode! (then they are ignored)
# below, we specify command line argument "2":
run 2     # run

#start # alternative to run: runs to main, and stops
#continue
