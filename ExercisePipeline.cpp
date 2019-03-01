
#include <sofa\config.h>
#include "ExercisePipeline.h"
#include <sofa/core/visual/VisualParams.h>
#include <sofa/core/CollisionModel.h>
#include <sofa/simulation/Node.h>
#include <sofa/core/ObjectFactory.h>

#ifdef SOFA_DUMP_VISITOR_INFO
#include <sofa/simulation/common/Visitor.h>
#endif
#include <sofa/simulation/Simulation.h>
#include <sofa/core/objectmodel/KeypressedEvent.h>
#include <sofa/core/objectmodel/KeyreleasedEvent.h>
#include <sofa/core/ObjectFactory.h>
#include <sofa/core/objectmodel/Data.h>
//#include <sofa/helper/system/SetDirectory.h>

#define SOFA_SIMULATION_INSTRUMENTACTION_H
#include <sofa/helper/system/gl.h>
#include <sofa/helper/AdvancedTimer.h>
#include <SofaSimulationTree/TreeSimulation.h>
#include <SofaOpenglVisual/OglModel.h>
#include <sofa/helper/gl/glText.inl>
#include <sofa/core/objectmodel/BaseObject.h>
#define VERBOSE(a) if (bVerbose.getValue()) a; else {}
SOFA_DECL_CLASS(ExercisePipeline)
namespace sofa
{

	namespace component
	{

		namespace collision
		{

			using namespace core;
			using namespace core::objectmodel;
			using namespace core::collision;
			using namespace sofa::defaulttype;
			void  ExercisePipeline::doCollisionResponse()

			{
				sofa::core::objectmodel::BaseContext* scene = getContext();
				sofa::simulation::Node* node = dynamic_cast<simulation::Node*>(scene);
				const std::string category = "collision";



			}

			std::string ExercisePipeline::getText()
			{
				return dispText;
			}

		} // namespace collision

	} // namespace component

} // namespace sofa
