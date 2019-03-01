#include "AdherentCellsInjectionPipeline.h"
#include "ExercisePipeline.h"
#include <sofa\config.h>
#include <sofa/core/visual/VisualParams.h>
#include <sofa/core/CollisionModel.h>
#include <sofa/simulation/Node.h>
#include <sofa/core/ObjectFactory.h>

#ifdef SOFA_DUMP_VISITOR_INFO
#include <sofa/simulation/common/Visitor.h>
#endif

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

			SOFA_DECL_CLASS(AdherentCellsInjectionPipeline)

				int AdherentCellsInjectionPipelineClass = core::RegisterObject("The collision detection and modeling pipeline for Injector Positioning exercise")
				.add< AdherentCellsInjectionPipeline >()
				.addAlias("AdherentCellsInjectionPipelineResponse")
				;


			void AdherentCellsInjectionPipeline::doCollisionResponse()
			{
				DefaultPipeline::doCollisionResponse();
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

						numTimeSteps++;
						firstTouchObj = true;
						if (numTimeSteps == 10) {
							if (firstTouchObj) {
								firstTouchObj = false;
								visEffect = true;
								cubeCount++;
							}
							sofa::defaulttype::Vector6 boxDim;
							switch (cubeCount) {
							case 1:
							{
								
								    boxDim = defaulttype::Vector6(13, -2, 56, 18, 3, 64);
									helper::vector<defaulttype::Vector6> tempVec;
									tempVec.push_back(boxDim);
									boxROI->d_alignedBoxes.setValue(tempVec);
									//boxROI->boxes.setValue(tempVec);
									boxROI->update();
								
								break;
							}
							case 2:
							{
								boxDim = defaulttype::Vector6(30, -1, 46, 38, 2, 50);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								//boxROI->boxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 3:
							{
								boxDim = defaulttype::Vector6(4, -2, 9, 10, 3, 11);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								//boxROI->boxes.setValue(tempVec);
								boxROI->update();
								break;
							}
							case 4:
							{
								boxDim = defaulttype::Vector6(-13, -0.5, 26, -4, 2, 28);
								helper::vector<defaulttype::Vector6> tempVec;
								tempVec.push_back(boxDim);
								boxROI->d_alignedBoxes.setValue(tempVec);
								// boxROI->boxes.setValue(tempVec);
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
							std::cout << "Cube Count" << cubeCount << std::endl;

						}
					}
				}

			}

			void AdherentCellsInjectionPipeline::draw(const core::visual::VisualParams*)
			{
				core::objectmodel::BaseContext* scene = getContext();
				simulation::Node* node = dynamic_cast<simulation::Node*>(scene);

				simulation::Node* visualSphere = NULL;
				visualSphere = node->getTreeNode("Inj-Cell");

				std::vector <sofa::component::visualmodel::OglModel*> spheres;

				if (visualSphere != NULL) {
					sofa::component::visualmodel::OglModel* sphereOgl = NULL;
					sofa::component::visualmodel::OglModel* nextSphereOgl = NULL;
					visualSphere->getTreeObjects<sofa::component::visualmodel::OglModel, std::vector<sofa::component::visualmodel::OglModel*>>(&spheres);
					if (!spheres.empty()) {
						for (std::vector<sofa::component::visualmodel::OglModel*>::const_iterator it = spheres.begin(); it != spheres.end(); it++) {
							sofa::component::visualmodel::OglModel* temp = *it;
							switch (cubeCount) {
							case 0:
							{
								if (temp->getName() == "oglModel3")
									sphereOgl = temp;
								if (temp->getName() == "oglModel6")
									nextSphereOgl = temp;
								break;
							}
							case 1:
							{
								if (temp->getName() == "oglModel3")
									sphereOgl = temp;
								if (temp->getName() == "oglModel6")
									nextSphereOgl = temp;
								break;
							}
							case 2:
							{
								if (temp->getName() == "oglModel6")
									sphereOgl = temp;
								if (temp->getName() == "oglModel0")
									nextSphereOgl = temp;
								break;
							}
							case 3:
							{
								if (temp->getName() == "oglModel0")
									sphereOgl = temp;
								if (temp->getName() == "oglModel1")
									nextSphereOgl = temp;
								break;
							}
							case 4:
							{
								if (temp->getName() == "oglModel1")
									sphereOgl = temp;
								if (temp->getName() == "oglModel2")
									nextSphereOgl = temp;
								break;
							}
							case 5:
							{
								if (temp->getName() == "oglModel2")
									sphereOgl = temp;
								if (temp->getName() == "oglModel5")
									nextSphereOgl = temp;
								break;
							}
							case 6:
							{
								if (temp->getName() == "oglModel2")
									sphereOgl = temp;
								if (temp->getName() == "oglModel5")
									nextSphereOgl = temp;
								break;
							}
							default:
								break;
							}

						}
						//	std::cout << sphereOgl->getName() << nextSphereOgl->getName() << std::endl;
					}
					if (visEffect) {
						if (sphereOgl != NULL) {
							if (numTimeSteps == 10) {
								visEffect = false;
								objectChanged = true;
								numTimeSteps = 0;
								//   sphereOgl->applyTranslation(-10,-10,0);
							}
							else if (numTimeSteps < 10) {
								sofa::core::loader::Material mtrl = sphereOgl->material.getValue();
								mtrl.diffuse = defaulttype::Vec4f(0.0, 1.0, 0.0, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.23, 1.0, 0.54, 1.0);
								sphereOgl->material.setValue(mtrl);
							}
						}
					}
					else if (!visEffect) {
						if (sphereOgl != NULL) {
							sofa::core::loader::Material mtrl = sphereOgl->material.getValue();
							sofa::core::loader::Material mtrlNext = nextSphereOgl->material.getValue();
							if (objectChanged) {
								mtrl.diffuse = defaulttype::Vec4f(0.75, 0.75, 0.75, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.2, 0.2, 0.2, 1.0);
								mtrlNext.diffuse = defaulttype::Vec4f(1.0, 0.0, 0.0, 1.0);
								mtrlNext.ambient = defaulttype::Vec4f(1.0, 0.54, 0.23, 1.0);
							}
							else {
								mtrl.diffuse = defaulttype::Vec4f(1.0, 0.0, 0.0, 1.0);
								mtrl.ambient = defaulttype::Vec4f(1.0, 0.54, 0.23, 1.0);
							}
							sphereOgl->material.setValue(mtrl);
							nextSphereOgl->material.setValue(mtrlNext);
						}
					}
				}
			}

		} // namespace collision

	} // namespace component

} // namespace sofa


