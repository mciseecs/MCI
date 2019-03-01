#include "InitExercisePipeline.h"

extern "C" {
	SOFA_ExercisePipeline_API void initExternalModule();
	SOFA_ExercisePipeline_API const char* getModuleName();
	SOFA_ExercisePipeline_API const char* getModuleVersion();
	SOFA_ExercisePipeline_API const char* getModuleLicense();
	SOFA_ExercisePipeline_API const char* getModuleDescription();
	SOFA_ExercisePipeline_API const char* getModuleComponentList();

}
void initExternalModule()
{

}

    const char* getModuleName()
    {
        return "ExercisePipeline";
    }

    const char* getModuleVersion()
    {
        return "0.1";
    }

    const char* getModuleLicense()
    {
        return "LGPL";
    }

    const char* getModuleDescription()
    {
        return "MyPlugin provides nothing for now.";
    }

    const char* getModuleComponentList()
    {
        // Comma-separated list of the components in this plugin, empty for now
        return "";
    }

