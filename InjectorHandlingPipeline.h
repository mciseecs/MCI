#ifndef SOFA_COMPONENT_COLLISION_INJECTORHANDLINGPIPELINE_H
#define SOFA_COMPONENT_COLLISION_INJECTORHANDLINGPIPELINE_H
#include <sofa\config.h>

#include "ExercisePipeline.h"
#include <sofa/helper/gl/Texture.h>
#include <sofa/helper/gl/RAII.h>
#include <sofa/helper/io/ImagePNG.h>
#include <sofa/helper/system/FileRepository.h>




namespace sofa
{

namespace component
{

namespace collision
{
class InjectorHandlingPipeline : public sofa::component::collision::ExercisePipeline
{
public:
	SOFA_CLASS(InjectorHandlingPipeline,sofa::component::collision::ExercisePipeline);
	//bool visEffect;
	//bool collisionContinue;

 

public:
	InjectorHandlingPipeline():cubeCount(0),firstTouchObj(true),lastx(0.0),lastz(0.0),damageCountAllow(true), numTimeSteps(0)
	{
		
		exerciseId=1;
	//	texLogo = new helper::gl::Texture(new helper::io::ImagePNG( sofa::helper::system::DataRepository.getFile("mesh/body/leftlobeliver.png")));
	//	texLogo->init();
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
		int startFlag;
		double pathLengthLI;
		double tempxL, tempyL, tempzL;
protected:
	// -- Pipeline interface

	void doCollisionResponse();
};

} // namespace collision

} // namespace component

} // namespace sofa


#endif
