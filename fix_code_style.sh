#!/bin/bash

# if [[ $# -eq 0 ]] ; then
#   exit 0
# fi

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# astyle --options=$DIR/.astylerc --recursive *.h *.cpp *.cc *.hpp
# find . -name '*.orig' -delete

find . -type f  \
    \( -name \*.h -o -name \*.hpp -o -name \*.h.in -o -name \*.cpp -o -name \*.cc \) \
    ! -path "./thirdparty/*" ! -path "./build/*" -print \
    | xargs astyle --options=$DIR/.astylerc

