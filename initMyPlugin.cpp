#include "initMyPlugin.h"


extern "C" {
	SOFA_EvaluationMetrix_API void initExternalModule();
	SOFA_EvaluationMetrix_API const char* getModuleName();
	SOFA_EvaluationMetrix_API const char* getModuleVersion();
	SOFA_EvaluationMetrix_API const char* getModuleLicense();
	SOFA_EvaluationMetrix_API const char* getModuleDescription();
	SOFA_EvaluationMetrix_API const char* getModuleComponentList();

}
    void initExternalModule()
    {
		
    }

    const char* getModuleName()
    {
        return "EvaluationMetrix";
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
        return "EvaluationMetrix provides nothing for now.";
    }

    const char* getModuleComponentList()
    {
        // Comma-separated list of the components in this plugin, empty for now
		return "";
    }