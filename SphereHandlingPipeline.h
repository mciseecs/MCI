#ifndef SOFA_COMPONENT_COLLISION_INJECTORPOSITIONINGPIPELINE_H
#define SOFA_COMPONENT_COLLISION_INJECTORPOSITIONINGPIPELINE_H
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
			class SphereHandlingPipeline : public sofa::component::collision::ExercisePipeline
			{
			public:
				SOFA_CLASS(SphereHandlingPipeline, sofa::component::collision::ExercisePipeline);
				sofa::component::collision::RayModel::SPtr graspRay;
				sofa::component::container::MechanicalObject< defaulttype::Vec3Types >::SPtr graspMech;
				//bool visEffect;
				//bool collisionContinue;
		      
			public:
				SphereHandlingPipeline() :cubeCount(0), firstTouchObj(true), lastx(0.0), lastz(0.0), damageCountAllow(true), numTimeSteps(0)
				{
					exerciseId = 1;
					objectChanged = false;
					bool getBodyPicked = NULL;
					graspHoldingPipette01 = NULL;
				/*
					graspHoldingPipette = NULL;
					graspHoldingPipette2 = NULL;
					graspHoldingPipette3 = NULL;
					graspHoldingPipette4 = NULL;
					graspHoldingPipette5 = NULL;
					graspHoldingPipette6 = NULL;
					graspHoldingPipette7 = NULL;

					Interaction1 = NULL;
					Interaction2 = NULL;
					Interaction3 = NULL;
					Interaction4 = NULL;
					Interaction5 = NULL;
			*/
					
				};
				sofa::helper::gl::Texture	*texLogo;
				//	int damageCount;
				bool damageCountAllow;
				void draw(const core::visual::VisualParams* vparams);
				
				sofa::gui::GraspFunction * newgrasp1;

				simulation::Node::SPtr interNode;
				simulation::Node::SPtr nodeRayPick;
				sofa::component::collision::BodyPicked result;
				bool bodyPicked;
				bool rightBodyPicked;
				sofa::component::collision::BaseMouseInteractor* graspInteractor;
				sofa::core::behavior::BaseMechanicalState::SPtr interMech;
				sofa::component::collision::AttachBodyPerformer<defaulttype::Vec3Types> * graspPerformer;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech2;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech3;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech4;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech5;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingSphereMech6;



				
         
				sofa::component::collision::RayModel * ray1;
				

				sofa::gui::GraspFunction* graspHoldingPipette1;
				sofa::gui::GraspFunction* graspHoldingPipette2;
				sofa::gui::GraspFunction* graspHoldingPipette3;
				



				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingPipetteMech;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* holdingPipetteRigidMech;


				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingPipetteMech2;
			
				sofa::component::collision::MouseInteractor<sofa::defaulttype::Vec3dTypes>* MouseInteract1;
			
				sofa::component::collision::MouseInteractor<sofa::defaulttype::Vec3dTypes>* MouseInteract2;
				;
				sofa::component::collision::MouseInteractor<sofa::defaulttype::Vec3dTypes>* MouseInteract3;


				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>* Spheree;

				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>* MechGrasp1;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>* MechGrasp2;
				bool holderPressureActivated;
				

				sofa::simulation::Node * graspHoldingPipette0;
				sofa::simulation::Node * graspHoldingPipette01;
				sofa::simulation::Node * graspHoldingPipette02;
				sofa::simulation::Node * graspHoldingPipette03;
			

				
				sofa::simulation::Node * graspHoldingPipettenew;

				sofa::simulation::Node * Interaction1;
				sofa::simulation::Node * Interaction2;
				sofa::simulation::Node * Interaction3;
				sofa::simulation::Node * Interaction4;
				sofa::simulation::Node * Interaction5;
				sofa::simulation::Node * Interaction6;


				sofa::simulation::Node * mech1;
				sofa::simulation::Node * mech2;

				sofa::simulation::Node * mechin1;
				sofa::simulation::Node * mechin2;
				sofa::simulation::Node * mechin3;
				sofa::simulation::Node * mechin4;









				//simulation::Node::SPtr nodeRayPick;



				
				bool holderPressureActivated1;
			private:
				int cubeCount;
				bool firstTouchObj;
				double lastx;
				double lastz;
				int numTimeSteps;
				bool objectChanged;


			protected:
				// -- Pipeline interface

				void doCollisionResponse();
				void deactivateRay();

				sofa::gui::GraspFunction * g1;
			};

		} // namespace collision

	} // namespace component

} // namespace sofa


#endif
