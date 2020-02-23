#define XSTR(s) STR(s)
#define STR(s) #s

#ifndef PARM_COMP_CLASS
#error "You must define PARM_COMP_CLASS macro before include this file"
#endif

#ifndef PARM_COMP_NAME
#error "You must define PARM_COMP_NAME macro before include this file"
#endif

#ifndef PARM_FILEPATH_PARM
#define PARM_FILEPATH_PARM visiongraph/comp/##PARM_COMP_CLASS##.parm.h
#endif

#define RTTR_NAME vg::##PARM_COMP_NAME

rttr::registration::class_<vg::comp::PARM_COMP_CLASS>(XSTR(RTTR_NAME))
.constructor<>()
#define PARM_FILEPATH XSTR(PARM_FILEPATH_PARM)
#define PARM_NODE_CLASS vg::comp::##PARM_COMP_CLASS
#include <dag/rttr_prop_gen.h>
#undef PARM_FILEPATH
#undef PARM_NODE_CLASS
;

#undef PARM_COMP_NAME
#undef PARM_COMP_CLASS
#undef PARM_FILEPATH_PARM
