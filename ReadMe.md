

gcc src/*.c Libft/libft.a includes/lemon.h -o lemon  
./lemon < maps/test.map  
https://github.com/bentenjamin/Libft.git  
https://github.com/microsoft/vscode-cpptools/issues/811  
valgrind --leak-check=full ./lemon < maps/viz.map

## To-Do:

* visualiser
* catch empty input file
* duplicate room coords (edit dupe room checker)
* check dupe links
* test all cases
* make file
* comment code
* readability update
* fix README
* rewrite addarterynode and popart to add to the start of the list for increased speed?
* check non zero positive ants

## Output Formats:

    pdf2_1 correct output
    L1-1 L2-2
    L1-4 L3-1 L2-3
    L3-4 L2-4
    
    viz correct output
    L1-3 L2-2
    L1-4 L2-5 L3-3 L4-2
    L1-end L2-6 L3-4 L4-5 L5-3
    L2-end L3-end L4-6 L5-4
    L4-end L5-end

Credit to https://github.com/gwasserfall && https://github.com/Ayano2000 for map files

## Using Libft after a fresh clone:

On the initial clone, the Libft directory will be empty.

To initialise the directory run `git submodule init` followed by `git submodule update` to get the data for the appropriate commit for the current branch in the parent project.

If during the course of work, the submodule is updated and you would like the updated data on your branch, run `git submodule update --remote Libft`.

## Adding source files:

When adding a `<filename>.c` file to the `src` directory, remember to include a rule for this file in the root `Makefile`.

Eg:

If `example.c` is added to `src`, ensure that `example.o` is added to the `Makefile` like this:

    OBJ_LEM += $(OBJ_DIR)example.o