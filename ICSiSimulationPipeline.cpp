#include "ICSiSimulationPipeline.h"
#include "ExercisePipeline.h"
#include <sofa\config.h>
#include <sofa/core/visual/VisualParams.h>
#include <sofa/core/CollisionModel.h>
#include <sofa/simulation/Node.h>
#include <sofa/core/ObjectFactory.h>

#ifdef SOFA_DUMP_VISITOR_INFO
#include <sofa/simulation/common/Visitor.h>
#endif
#include <sofa/defaulttype/Vec.h>
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
#include <SofaBaseMechanics/MechanicalObject.h>
#include "C:\sofa\src\applications\plugins\EvaluationMetrics\ICSISimulationMetrics.h"
#include "dialog.h"
#include "ui_dialog.h"
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

			SOFA_DECL_CLASS(ICSiSimulationPipeline)
			
				int ICSiSimulationPipelineClass = core::RegisterObject("The collision detection and modeling pipeline for Injector Positioning exercise")
				.add< ICSiSimulationPipeline >()
				.addAlias("ICSiSimulationResponse")
				
				;
			
		
				//clock_t start = clock();
				// Execuatable code
				//clock_t stop = clock();
				//double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
				//double seconds = elapsed / 1000;
				//std::cout << "Time elapsed in seconds:" << seconds;
				// DWORD dw1 = GetTickCount();

				////Do something
		
			
			void ICSiSimulationPipeline::doCollisionResponse()
			{


				count = 60;
				startFlag = 0;
				count++;
				
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
								collisionContinue = false;
								
								std::cout << "time is :" << count<< "seconds\n";
								this->getContext()->getRootContext()->setAnimate(false);
								if (!dialogDisplayed)
								{
									Dialog* w = new Dialog();
									w->exec();
									dialogDisplayed = true;
								}
								break;
							}
							default:
								break;
							}

						}
					}
				}

			}
			

				/*
				double dropPos;
				sofa::simulation::Node::SPtr groot;
				

				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>*Vec1dObjectVariablePointer1;

				sofa::simulation::Node * dropNode = NULL;

				dropNode = groot->getTreeNode("Pipette");
				if (dropNode != NULL)
				{
					sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec1dTypes>* RigidObj;
					Vec1dObjectVariablePointer1 = dropNode->getTreeObject<sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>>();
					RigidObj = dropNode->getTreeObject<sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec1dTypes>>();
					helper::WriteAccessor<Data<sofa::defaulttype::Vec1dTypes::VecCoord>>instrumentX = *RigidObj->write(core::VecCoordId::position());
					sofa::component::visualmodel::OglModel *ogl;
					dropNode = groot->getTreeNode("node9");
					ogl = dropNode->getTreeObject<sofa::component::visualmodel::OglModel>();
					sofa::helper::vector<double>tempVec;
					dropPos -= 0.05;
					tempVec.push_back(dropPos);

					tempVec.push_back(0.0);
					tempVec.push_back(0.0);
					Vec1dObjectVariablePointer1->forcePointPosition(0, tempVec);
					std::cout << "im working";
					sofa::simulation::MechanicalPropagatePositionAndVelocityVisitor(core::MechanicalParams::defaultInstance()).execute(RigidObj->getContext());
					sofa::simulation::UpdateMappingVisitor(core::ExecParams::defaultInstance()).execute(RigidObj->getContext());
				    
				}
				else
				{
					collisionContinue = false;
				}
			
			
			}
			*/
			

		} // namespace collision

	} // namespace component

} // namespace sofa


