#include "Kernel.h"
#include "SysMod.h"
#include "user.h"

int userMain(int argC, char* argV[]);

int main(int argc, char* argv[]) {
	SysMode::InitSysMode();
	Kernel::StartKernel();
	Kernel::SaveOldTimer();

	int retVal = userMain(argc, argv);

	Kernel::RestoreOldTimer();
	Kernel::StopKernel();
	SysMode::ClearSysMode();
	
	return retVal;
}
