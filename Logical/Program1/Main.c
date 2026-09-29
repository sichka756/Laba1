
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{

}

void _CYCLIC ProgramCyclic(void)
{
	counter++;
	if (counter >= 10 && counter < 20){
		Speed = 50;
	}
	else if (counter >= 20){
		Speed = 0;
		counter = 0;
	}
}

void _EXIT ProgramExit(void)
{

}

