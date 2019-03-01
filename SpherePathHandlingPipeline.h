#ifndef SOFA_COMPONENT_COLLISION_SPHEREPATHHANDLINGPIPELINE_H
#define SOFA_COMPONENT_COLLISION_SPHEREPATHHANDLINGPIPELINE_H
#include <sofa\config.h>
#include <sofa\gui\GraspFunction.h>
#include "ExercisePipeline.h"
#include <sofa\gui\GraspFunction.h>
#include <sofa/helper/gl/Texture.h>
#include <sofa/helper/gl/RAII.h>
#include <sofa/helper/io/ImagePNG.h>
#include <sofa/helper/system/FileRepository.h>
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
#include <SofaUserInteraction/RayModel.h>
#include <SofaUserInteraction/MouseInteractor.h>
#include <sofa/core/Mapping.h>
#include <SofaUserInteraction/AttachBodyPerformer.h>
#include <SofaSimulationGraph/DAGNode.h>
#include <SofaSimulationGraph/DAGSimulation.h>
#include <sofa/gui/PickHandler.h>
#include <SofaUserInteraction/RayModel.h>

namespace sofa
{

	namespace component
	{

		namespace collision
		{
                        class SpherePathHandlingPipeline : public sofa::component::collision::ExercisePipeline
			{
			public:
                                SOFA_CLASS(SpherePathHandlingPipeline, sofa::component::collision::ExercisePipeline);
				sofa::component::collision::RayModel::SPtr graspRay;
				sofa::component::container::MechanicalObject< defaulttype::Vec3Types >::SPtr graspMech;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLi;

			



				//bool visEffect;
				//bool collisionContinue;
		      
			public:
				void updatePosition(SReal dt);
				virtual void doCollisionResponse();
				int count;
				DWORD dw1;
				int startFlag;
				double PathLenghtLi;
				double tempxL, tempyL, tempzL;
				SpherePathHandlingPipeline();
				~SpherePathHandlingPipeline();
			};

		} // namespace collision

	} // namespace component

} // namespace sofa


#endif
