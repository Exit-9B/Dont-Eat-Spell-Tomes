#include "Hooks.h"
#include "SpellTomeManager.h"

namespace Hooks
{
	void Install()
	{
		SpellTomeManager::InstallHooks();
	}
}