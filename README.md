
ParMiBench
==========

Code taken from the original at:

  http://code.google.com/p/multiprocessor-benchmark/

I have only changed the makefiles to support relatively painless
cross-compilation.

Known Issues (patches wanted!)
--------------------------------------
+ Lots of style issues (e.g. trailing white space)
+ bitcount is broken: it segfaults.
+ Inconsistent file formats: they should all be in unix format (LF line breaks)
+ Code raises warnings in modern gcc's

Bitcount -> broken 

sha -> OK
susan -> OK
patricia -> Termina OK, mas não mostra nada no console como saída


string search, Basicmath e dijkstra ficam em loop infinito. Modificar o codigo para ver o progresso pode auxiliar no processo de verificar what's going on.


=======
# parmibench-riscv
This repo contains the parmibench suite with the makefile adapted to run on Risc-v architecture

