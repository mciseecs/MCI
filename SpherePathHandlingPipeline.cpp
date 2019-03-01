#include "SpherePathHandlingPipeline.h"
#include "ExercisePipeline.h"
#include <sofa/core/visual/VisualParams.h>
#include <sofa/core/CollisionModel.h>
#include <sofa/simulation/Node.h>
#include <sofa/core/ObjectFactory.h>
#include<sofa\config.h>
#ifdef SOFA_DUMP_VISITOR_INFO
#include <sofa/simulation/common/Visitor.h>
#endif
#include <sofa/core/behavior/MechanicalState.h>
#include <sofa/defaulttype/VecTypes.h>
#include <sofa/helper/vector.h>
#include <sofa/helper/accessor.h>
#include <SofaBaseMechanics/UniformMass.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include <sofa/defaulttype/defaulttype.h>
#include <sofa/core/collision/Detection.h>
#include <SofaBaseCollision/DefaultPipeline.h>
#include <sofa/helper/system/config.h>
#include <sofa/helper/system/gl.h>
#include <sofa/helper/system/glu.h>
#include <sofa/helper/gl/Transformation.h>
#include <sofa/helper/gl/Trackball.h>
#include <sofa/helper/gl/Texture.h>
#include <sofa/helper/system/thread/CTime.h>
#include <sofa/simulation/Node.h>
#include <sofa/helper/system/gl.h>
#include <sofa/helper/AdvancedTimer.h>

#include <sofa/simulation/PropagateEventVisitor.h>

#include <sofa/simulation/MechanicalVisitor.h>
#include <sofa/simulation/UpdateMappingVisitor.h>
#include <sofa/simulation/UpdateContextVisitor.h>
#include <sofa/simulation/StateChangeVisitor.h>

#include <SofaSimulationTree/TreeSimulation.h>
#include <sofa/helper/gl/glText.inl>

#include <SofaEngine/BoxROI.inl>
#include <SofaOpenglVisual/Light.h>

#include <SofaOpenglVisual/OglModel.h>
#define VERBOSE(a) if (bVerbose.getValue()) a; else {}

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
		
			
							
			SOFA_DECL_CLASS(SpherePathHandlingPipeline)

				SpherePathHandlingPipeline::SpherePathHandlingPipeline()
			{
				count = 1;

			}

			SpherePathHandlingPipeline::~SpherePathHandlingPipeline()
			{

			}


			void SpherePathHandlingPipeline::doCollisionResponse()
			{
			}



			void SpherePathHandlingPipeline::updatePosition(SReal dt)
			{
				//clock_t start = clock();
				// Execuatable code
				//clock_t stop = clock();
				//double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
				//double seconds = elapsed / 1000;
				//std::cout << "Time elapsed in seconds:" << seconds;
				// DWORD dw1 = GetTickCount();

				////Do something

				if (count == 1)
				{
					dw1 = GetTickCount();
					count++;

				}



				DWORD dw2 = GetTickCount();

				double time_diff = dw2 - dw1;
				double time = (time_diff) / CLOCKS_PER_SEC;
				//std::cout << "Total run time is:" << time << "Seconds\n";

				int y = ceil(time);
				std::cout << "time is :" << y << "seconds\n";





			}

			int SpherePathHandlingPipelineClass = sofa::core::RegisterObject("This component does nothing.").add<SpherePathHandlingPipeline>();


		} // namespace collision

	} // namespace component

} // namespace sofa



