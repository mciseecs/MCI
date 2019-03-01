#include "ObjectHandlingPipeline.h"

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
#include <C:\sofa\build\applications\plugins\ExercisePipeline\sqlite3.h>
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

SOFA_DECL_CLASS(ObjectHandlingPipeline)

int ObjectHandlingPipelineClass = core::RegisterObject("The collision detection and modeling pipeline for Object Handling exercise")
.add< ObjectHandlingPipeline >()
.addAlias("ObjectHandlingResponse")
;


	



void ObjectHandlingPipeline::doCollisionResponse()
{
	

	DefaultPipeline::doCollisionResponse();
	core::objectmodel::BaseContext* scene = getContext();
	simulation::Node* rootNode = dynamic_cast<simulation::Node*>(scene);

	sofa::component::engine::BoxROI<sofa::defaulttype::Vec3dTypes>* boxROI = NULL;
	simulation::Node* objectNode = NULL;

	
	switch (cubeCount) {
	case 0:
	{
		objectNode = rootNode->getChild("Object1");
		break;
	}
	case 1:
	{
		objectNode = rootNode->getChild("Object2");
		break;
	}
	case 2:
	{
		objectNode = rootNode->getChild("Object4");
		break;
	}
	case 3:
	{
		objectNode = rootNode->getChild("Object3");
		break;
	}
	case 4:
	{
		collisionContinue = false;
	}
	default:
		break;
	}
	visEffect = false;
	if (objectNode) {
		boxROI = objectNode->getTreeObject<sofa::component::engine::BoxROI<sofa::defaulttype::Vec3dTypes>>();
	}
	if (boxROI) {
		if (boxROI->d_pointsInROI.getValue().size() > 0) {

			numTimeSteps++;
			
			if (numTimeSteps == 10) {
				firstTouchObj = true;
				if (firstTouchObj) {
					numTimeSteps = 0;
					visEffect = true;
					cubeCount++;
				}

			}
		}
	}
}
	

void ObjectHandlingPipeline::draw(const core::visual::VisualParams* )
{
	core::objectmodel::BaseContext* scene = getContext();
	simulation::Node* node = dynamic_cast<simulation::Node*>(scene);

	simulation::Node* visualSphere = NULL;
	visualSphere = node->getTreeNode("Bag1");

	sofa::component::visualmodel::OglModel* sphereOgl = NULL;
	
	
	if (visualSphere != NULL) {
		sphereOgl = visualSphere->get<sofa::component::visualmodel::OglModel>();
		if (sphereOgl != NULL) {
			switch (cubeCount) {
			case 1:
			{
				if (firstTouchObj) {
					firstTouchObj = false;
					sphereOgl->applyRotation(0, 0, -180);
					sphereOgl->applyTranslation(0, 80, 0);					
					simulation::Node* objectNode = NULL;
					simulation::Node* objectNode2 = NULL;
					objectNode = node->getTreeNode("Object1");
					if (objectNode != NULL)
						objectNode->setActive(false);
					objectNode2 = node->getTreeNode("Object2");
					if (objectNode2 != NULL) {
						sofa::component::visualmodel::OglModel* objectOgl = NULL;
						objectOgl = objectNode2->getTreeObject<sofa::component::visualmodel::OglModel>();
						if (objectOgl != NULL) {
								sofa::core::loader::Material mtrl = objectOgl->material.getValue();
								mtrl.diffuse = defaulttype::Vec4f(0.75, 0.27, 0.11, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.91, 0.35, 0.16, 1.0);
								objectOgl->material.setValue(mtrl);
						}
					}
					
				}
				break;
			}
			case 2:
			{
				if (firstTouchObj) {
					firstTouchObj = false;
					sphereOgl->applyTranslation(-20, 0, 40);
					simulation::Node* objectNode = NULL;
					simulation::Node* objectNode2 = NULL;
					objectNode = node->getTreeNode("Object2");
					if (objectNode != NULL)
						objectNode->setActive(false);
					objectNode2 = node->getTreeNode("Object4");
					if (objectNode2 != NULL) {
						sofa::component::visualmodel::OglModel* objectOgl = NULL;
							objectOgl = objectNode2->getTreeObject<sofa::component::visualmodel::OglModel>();
							if (objectOgl != NULL) {
								sofa::core::loader::Material mtrl = objectOgl->material.getValue();
								mtrl.diffuse = defaulttype::Vec4f(0.75, 0.27, 0.11, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.91, 0.35, 0.16, 1.0);
								objectOgl->material.setValue(mtrl);
							}
						}
					
				}
				break;
			}
			case 3:
			{
				if (firstTouchObj) {
					firstTouchObj = false;
					sphereOgl->applyRotation(0, 0, -180);
					sphereOgl->applyTranslation(30, 0, 0);
					simulation::Node* objectNode = NULL;
					simulation::Node* objectNode2 = NULL;
					objectNode = node->getTreeNode("Object4");
					if (objectNode != NULL)
						objectNode->setActive(false);
					objectNode2 = node->getTreeNode("Object3");
					if (objectNode2 != NULL) {
						sofa::component::visualmodel::OglModel* objectOgl = NULL;
							objectOgl = objectNode2->getTreeObject<sofa::component::visualmodel::OglModel>();
							if (objectOgl != NULL) {
								sofa::core::loader::Material mtrl = objectOgl->material.getValue();
								mtrl.diffuse = defaulttype::Vec4f(0.75, 0.27, 0.11, 1.0);
								mtrl.ambient = defaulttype::Vec4f(0.91, 0.35, 0.16, 1.0);
								objectOgl->material.setValue(mtrl);
							}
						}
					
				}
				break;
			}
			default:
				break;
			}

		}
	}
		
}

} // namespace collision

} // namespace component

} // namespace sofa



