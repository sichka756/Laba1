
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
void FB_regulator(struct FB_regulator* inst)
{
	REAL p_channel = inst->e * inst->k_p;
	
	if (p_channel > inst->max_abs_value){
		p_channel = inst->max_abs_value;
	}
	if (p_channel < -inst->max_abs_value){
		p_channel = -inst->max_abs_value;
	}
	
	REAL i_channel = inst->k_i * inst->e - inst->iyOld;
	
	inst->integrator.dt = inst->dt;
	inst->integrator.in = i_channel;
	FB_integrator(&inst->integrator);
	i_channel = inst->integrator.out;
	
	REAL reg = p_channel + i_channel;
	
	inst->u = reg;
	if (reg > inst->max_abs_value){
		inst->u = inst->max_abs_value;
	}
	if (reg < -inst->max_abs_value){
		inst->u = -inst->max_abs_value;
	}
	
	inst->iyOld = reg - inst->u;

}
