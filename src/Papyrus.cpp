#include "Papyrus.h"

#include "Papyrus/ActiveMagicEffectExt.h"
#include "Papyrus/AliasExt.h"
#include "Papyrus/DEST.h"
#include "Papyrus/FormExt.h"
#include "Papyrus/UIExt.h"

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
