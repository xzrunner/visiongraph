#define EXE_FILEPATH "visiongraph/comp_include_gen.h"
#include "visiongraph/comp_regist_cfg.h"
#undef EXE_FILEPATH

#include <rttr/registration>

#define REGIST_COMP_TYPE(type, name)                                 \
	rttr::registration::class_<visiongraph::comp::type>("vg::"#name) \
		.constructor<>()                                             \
	;

#define REGIST_ENUM_ITEM(type, name, label) \
    rttr::value(name, type),                \
    rttr::metadata(type, label)             \

RTTR_REGISTRATION
{

rttr::registration::class_<dag::Node<vg::CompVarType>::Port>("vg::Node::Port")
	.property("var", &dag::Node<vg::CompVarType>::Port::var)
;

rttr::registration::class_<vg::Component>("vg::Comp")
	.method("GetImports", &vg::Component::GetImports)
	.method("GetExports", &vg::Component::GetExports)
;

#define EXE_FILEPATH "visiongraph/comp_rttr_gen.h"
#include "visiongraph/comp_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace vg
{

void regist_rttr()
{
}

}