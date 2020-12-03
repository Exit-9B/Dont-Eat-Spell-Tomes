#include "Papyrus.h"
#include "ReferenceAliasExt.h"

void Papyrus::Register()
{
	auto papyrus = SKSE::GetPapyrusInterface();

	papyrus->Register(ReferenceAliasExt::RegisterFuncs);
	logger::info("Registered DEST_ReferenceAliasExt"sv);
}