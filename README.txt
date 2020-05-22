gcc src/*.c Libft/libft.a includes/lemon.h -o lemon
./lemon < maps/test.map
https://github.com/bentenjamin/Libft.git
https://github.com/microsoft/vscode-cpptools/issues/811
valgrind --leak-check=full ./lemon < maps/viz.map

todo:
visualiser
catch empty input file
duplicate room coords (edit dupe room checker)
check dupe links
test all cases
make file
comment code
readability update
fix README
rewrite addarterynode and popart to add to the start of the list for increased speed?
check non zero positive ants

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
