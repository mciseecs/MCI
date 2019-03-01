#ifndef INITEXERCISEPIPELINE_H
#define INITEXERCISEPIPELINE_H
#include <sofa/helper/system/config.h>
#ifdef SOFA_BUILD_EXERCISEPIPELINE
#define SOFA_ExercisePipeline_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#define SOFA_ExercisePipeline_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif




#endif // INITEXERCISEPIPELINE_H
