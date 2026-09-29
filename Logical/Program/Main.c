
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	REAL Tj = 1;
	REAL D_T = 0.01;

	fb_motor.Tm = 0.1;    
	fb_motor.ke = 0.24; 
	fb_motor.dt = D_T;
	fb_motor.integrator.dt = D_T;

	fb_regulator.k_p = fb_motor.ke * fb_motor.Tm / Tj;
	fb_regulator.k_i = fb_motor.ke / Tj;
	fb_regulator.dt  = D_T;
	fb_regulator.max_abs_value = 24.0;
	fb_regulator.integrator.dt = D_T;

	fb_motor_2.Tm = 0.1;    
	fb_motor_2.ke = 0.24; 
	fb_motor_2.dt = D_T;
	fb_motor_2.integrator.dt = D_T;

}

void _CYCLIC ProgramCyclic(void)
{

	if (Enable)
	{
		fb_regulator.e = Speed - fb_motor.w;
		FB_regulator(&fb_regulator);

		fb_motor.u = fb_regulator.u;
		FB_motor(&fb_motor);
		
		fb_motor_2.u = Speed * fb_motor_2.ke;
		FB_motor(&fb_motor_2);	
	}
	else
	{
		fb_regulator.u = 0.0;
		fb_regulator.iyOld = 0.0;
		fb_regulator.integrator.out = 0.0;

		fb_motor.u = 0.0;
		FB_motor(&fb_motor);
		
		fb_motor_2.u = 0;
		FB_motor(&fb_motor_2);
	}
}
void _EXIT ProgramExit(void)
{

}

