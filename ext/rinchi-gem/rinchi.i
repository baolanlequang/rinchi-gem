%module rinchi

%include stl.i
namespace std {
    %template(MolVect) vector<string>;
}

%{
#include "rinchi.h"
%}

%include "rinchi.h"
