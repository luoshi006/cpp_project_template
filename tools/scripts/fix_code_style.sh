#!/bin/bash

# if [[ $# -eq 0 ]] ; then
#   exit 0
# fi

DirCur=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
DirLast=$( cd "$( dirname "${DirCur}" )" && pwd)
DirRoot=$( cd "$( dirname "${DirLast}" )" && pwd)

echo "Project Root Dir: ${DirRoot}"
# astyle --options=$DirCur/.astylerc --recursive *.h *.cpp *.cc *.hpp
# find . -name '*.orig' -delete

find . -type f  \
    \( -name \*.h -o -name \*.hpp -o -name \*.h.in -o -name \*.cpp -o -name \*.cc \) \
    ! -path "./thirdparty/*" ! -path "./build/*" -print \
    | xargs astyle --options=$DirRoot/.astylerc

echo "fix code style Done!"
