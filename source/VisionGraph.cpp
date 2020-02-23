#include "visiongraph/VisionGraph.h"

namespace vg
{

CU_SINGLETON_DEFINITION(VisionGraph);

extern void regist_rttr();

VisionGraph::VisionGraph()
{
	regist_rttr();
}

}