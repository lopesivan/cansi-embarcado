# in batch mode:
set width 0
set height 0
set verbose off

define gprbuild
  if $argc == 0
    shell gprbuild
  end
  if $argc == 1
    shell gprbuild $arg0
  end
  if $argc > 1
    help gprbuild
  end
end

document gprbuild
Run the gprbuild program, optionally specifying the project name as
parameter.
Usage: gprbuild [project_name]
end

#define print_data
#  p *(int*)tree->root->data
#end

define pdata
  if $argc == 1
    if (($arg0)->root) != ((void *) 0)
      printf "<=>\n"
      p (char*)($arg0)->root->data
    end
  else
    help pdata
  end
end

document pdata
Run the gprbuild program, optionally specifying the project name as
parameter.
Usage: pdata <tree>
end

# at entry point - cmd1
break main
commands
  print argc
  continue
end

break bitree_destroy
commands
  printf "============================\n"
  p (char*)tree.root->data
  p (char*)tree.root->left->data
  p (char*)tree.root->left->left
  p (char*)tree.root->left->right
  p (char*)tree.root->right->data

  p (char*)tree.root->right->left->data
  p (char*)tree.root->right->left->left
  p (char*)tree.root->right->left->right

  p (char*)tree.root->right->right->data
  p (char*)tree.root->right->right->left
  p (char*)tree.root->right->right->right
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

run

#start # alternative to run: runs to main, and stops
#continue
