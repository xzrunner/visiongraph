#ifndef EXE_FILEPATH
#error "You must define EXE_FILEPATH macro before include this file"
#endif

#define PARM_COMP_CLASS Canny
#define PARM_COMP_NAME canny
#include EXE_FILEPATH

#define PARM_COMP_CLASS FileInput
#define PARM_COMP_NAME file_input
#include EXE_FILEPATH
