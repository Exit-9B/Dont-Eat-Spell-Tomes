#include "Papyrus.h"
#include "ReferenceAliasExt.h"
#include "UIExt.h"

void Papyrus::Register()
{
	auto papyrus = SKSE::GetPapyrusInterface();

	papyrus->Register(ReferenceAliasExt::RegisterFuncs);
	logger::info("Registered DEST_ReferenceAliasExt"sv);

	papyrus->Register(UIExt::RegisterFuncs);
	logger::info("Registered DEST_UIExt"sv);
}