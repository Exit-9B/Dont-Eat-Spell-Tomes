#include "Papyrus/DEST.h"
#include "Registration.h"

#define REGISTER(vm, script_name, fn_name) \
vm->RegisterFunction(#fn_name##sv, script_name, fn_name)

int DEST::GetAPIVersion(RE::StaticFunctionTag*)
{
	return DEST_API_VERSION;
}

void DEST::SendSpellTomeReadEvent(
	RE::StaticFunctionTag*,
	RE::TESObjectBOOK* a_book,
	RE::SpellItem* a_spell,
	RE::TESObjectREFR* a_container)
{
	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->QueueEvent(a_book, a_spell, a_container);
}

bool DEST::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST"sv;
	REGISTER(a_vm, scriptname, GetAPIVersion);
	REGISTER(a_vm, scriptname, SendSpellTomeReadEvent);

	return true;
}
