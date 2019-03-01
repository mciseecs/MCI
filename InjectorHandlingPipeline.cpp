#include "InjectorHandlingPipeline.h"
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

			SOFA_DECL_CLASS(InjectorHandlingPipeline)

				int InjectorHandlingPipelineClass = core::RegisterObject("The collision detection and modeling pipeline for Injector Handling exercise")
				.add< InjectorHandlingPipeline >()
				.addAlias("InjectorHandlingResponse")
				;


			void InjectorHandlingPipeline::doCollisionResponse()
			{

				core::objectmodel::BaseContext* scene = getContext();
				simulation::Node* rootNode = dynamic_cast<simulation::Node*>(scene);

				sofa::component::engine::BoxROI<sofa::defaulttype::Vec3dTypes>* boxROI = NULL;
				simulation::Node* injectorNode = NULL;
				injectorNode = rootNode->getChild("Pipette");
				visEffect = false;
				if (injectorNode) {
					boxROI = injectorNode->getTreeObject<sofa::component::engine::BoxROI<sofa::defaulttype::Vec3dTypes>>();
				}
				if (boxROI) {
					if (boxROI->d_pointsInROI.getValue().size() > 0) {
						visEffect = true;
						numTimeSteps++;
						firstTouchObj = true;
						if (numTimeSteps == 10) {
							if (firstTouchObj) {
								firstTouchObj = false;
								cubeCount++;
							}
							sofa::defaulttype::Vector6 boxDim;
							switch (cubeCount) {
							case 1:
							{
								boxDim = defaulttype::Vector6(-28, 42, 52, -12, 58, 68);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 2:
							{
								boxDim = defaulttype::Vector6(12, 42, 52, 28, 58, 68);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 3:
							{
								boxDim = defaulttype::Vector6(12, 42, 72, 28, 58, 88);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 4:
							{
								boxDim = defaulttype::Vector6(-18, 42, 72, -2, 58, 88);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 5:
							{
								collisionContinue = false;
								break;
							}
							default:
								break;
							}

						}
					}
				}

			}

			void InjectorHandlingPipeline::draw(const core::visual::VisualParams*)
			{
				core::objectmodel::BaseContext* scene = getContext();
				simulation::Node* node = dynamic_cast<simulation::Node*>(scene);

				simulation::Node* visualSphere = NULL;
				visualSphere = node->getTreeNode("node7");

				if (visualSphere != NULL) {
					sofa::component::visualmodel::OglModel* sphereOgl = NULL;
					sphereOgl = visualSphere->get<sofa::component::visualmodel::OglModel>();
					if (visEffect) {
						if (sphereOgl != NULL) {
							if (numTimeSteps == 10) {
								visEffect = false;
								numTimeSteps = 0;
								switch (cubeCount) {
								case 1:
								{
									sphereOgl->applyTranslation(-20, 0, 0);
									break;
								}
								case 2:
								{
									sphereOgl->applyTranslation(40, 0, 0);
									break;
								}
								case 3:
								{
									sphereOgl->applyTranslation(0, 0, 20);
									break;
								}
								case 4:
								{
									sphereOgl->applyTranslation(-30, 0, 0);
									break;
								}
								default:
									break;
								}

							}
							else {
								sofa::core::loader::Material mtrl = sphereOgl->material.getValue();
								mtrl.diffuse = defaulttype::Vec4f(0.0, 1.0, 0.0, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.23, 1.0, 0.54, 1.0);
								sphereOgl->material.setValue(mtrl);
							}
						}
					}
					if (!visEffect) {
						if (sphereOgl != NULL) {
							sofa::core::loader::Material mtrl = sphereOgl->material.getValue();
							mtrl.diffuse = defaulttype::Vec4f(1.0, 0.0, 0.0, 1.0);
							mtrl.ambient = defaulttype::Vec4f(1.0, 0.54, 0.23, 1.0);
							sphereOgl->material.setValue(mtrl);
						}
					}
				}
			}

		} // namespace collision

	} // namespace component

} // namespace sofa



