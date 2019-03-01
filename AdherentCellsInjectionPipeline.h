#ifndef SOFA_COMPONENT_COLLISION_ADHERENTCELLSINJECTIONPIPELINE_H
#define SOFA_COMPONENT_COLLISION_ADHERENTCELLSINJECTIONPIPELINE_H
#include <sofa/config.h>

#include "ExercisePipeline.h"
#include <sofa/helper/gl/Texture.h>
#include <sofa/helper/gl/RAII.h>
#include <sofa/helper/io/ImagePNG.h>
#include <sofa/helper/system/FileRepository.h>
#include <SofaOpenglVisual/OglModel.h>
#include <sofa/helper/system/gl.h>
#include <string.h>
#include<sofa/gui/GraspFunction.h>
#include<SofaBaseMechanics\MechanicalObject.h>

namespace sofa
{

namespace component
{

namespace collision
{
class AdherentCellsInjectionPipeline : public sofa::component::collision::ExercisePipeline
{
public:
        SOFA_CLASS(AdherentCellsInjectionPipeline,sofa::component::collision::ExercisePipeline);
        //bool visEffect;
        //bool collisionContinue;
public:
        AdherentCellsInjectionPipeline():cubeCount(0),firstTouchObj(true),lastx(0.0),lastz(0.0),damageCountAllow(true), numTimeSteps(0)
        {
                exerciseId=1;
                objectChanged = false;
        };
        sofa::helper::gl::Texture	*texLogo;
//	int damageCount;
        bool damageCountAllow;
        void draw(const core::visual::VisualParams* vparams);
	


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
};

} // namespace collision

} // namespace component

} // namespace sofa


#endif
