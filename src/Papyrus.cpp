#include "Papyrus.h"
#include "ActiveMagicEffectExt.h"
#include "FormExt.h"
#include "ReferenceAliasExt.h"
#include "UIExt.h"

void Papyrus::Register()
{
	auto papyrus = SKSE::GetPapyrusInterface();

	papyrus->Register(FormExt::RegisterFuncs);
	logger::info("Registered DEST_FormExt"sv);

	papyrus->Register(ReferenceAliasExt::RegisterFuncs);
	logger::info("Registered DEST_ReferenceAliasExt"sv);

	papyrus->Register(ActiveMagicEffectExt::RegisterFuncs);
	logger::info("Registered DEST_ActiveMagicEffectExt"sv);

	papyrus->Register(UIExt::RegisterFuncs);
	logger::info("Registered DEST_UIExt"sv);
}