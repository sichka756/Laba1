
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_motor(struct FB_motor* inst)
{
	
	REAL e = inst->u / inst->ke - inst->w;

	inst->integrator.dt = inst->dt;
	inst->integrator.in = e / inst->Tm;
	FB_integrator(&inst->integrator);
	inst->w = inst->integrator.out;

	inst->phi = inst->phi + inst->w * inst->dt;	
}
