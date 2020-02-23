#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_CLASS
#error "You must define PARM_COMP_CLASS macro before include this file"
#endif

#ifndef PARM_FILEPATH_H
#define PARM_FILEPATH_H visiongraph/comp/##PARM_COMP_CLASS##.h
#endif

#include XSTR(PARM_FILEPATH_H)

#undef PARM_COMP_NAME
#undef PARM_COMP_CLASS
#undef PARM_FILEPATH_PARM
