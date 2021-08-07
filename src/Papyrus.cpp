#include "Papyrus.h"

#include "ActiveMagicEffectExt.h"
#include "AliasExt.h"
#include "DEST.h"
#include "FormExt.h"
#include "UIExt.h"

bool Papyrus::RegisterFuncs(VM* a_vm)
{
	DEST::RegisterFuncs(a_vm);
	logger::info("Registered DEST"sv);

	ActiveMagicEffectExt::RegisterFuncs(a_vm);
	logger::info("Registered DEST_ActiveMagicEffectExt"sv);

	AliasExt::RegisterFuncs(a_vm);
	logger::info("Registered DEST_AliasExt"sv);

	FormExt::RegisterFuncs(a_vm);
	logger::info("Registered DEST_FormExt"sv);

	UIExt::RegisterFuncs(a_vm);
	logger::info("Registered DEST_UIExt"sv);

	return true;
}
