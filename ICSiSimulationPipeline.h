#ifndef SOFA_COMPONENT_COLLISION_ICSISIMULATIONPIPELINE_H
#define SOFA_COMPONENT_COLLISION_INJECTORPOSITIONINGPIPELINE_H
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
class ICSiSimulationPipeline : public sofa::component::collision::ExercisePipeline
{
public:
	SOFA_CLASS(ICSiSimulationPipeline,sofa::component::collision::ExercisePipeline);
	//bool visEffect;
	//bool collisionContinue;
public:
	ICSiSimulationPipeline():cubeCount(0),firstTouchObj(true),lastx(0.0),lastz(0.0),damageCountAllow(true), numTimeSteps(0)
	{
		exerciseId=1;
		objectChanged = false;
	};
	sofa::helper::gl::Texture	*texLogo;
//	int damageCount;
	bool damageCountAllow;
	
private:
	int cubeCount;
	bool firstTouchObj;
	double lastx;
	double lastz;
    int numTimeSteps;
	bool objectChanged;
	int time;
	bool dialogDisplayed;
	int startFlag;
	int timer;
	double PathLengthLI;
	double tempxL, tempyL, tempzL;



	//double time_diff;
	int count;
	DWORD dw1;
protected:
	// -- Pipeline interface
	void updatePosition(SReal dt);

	void doCollisionResponse();
};

} // namespace collision

} // namespace component

} // namespace sofa


#endif