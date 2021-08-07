#include "AliasExt.h"
#include "Registration.h"

#define REGISTER(vm, script_name, fn_name) vm->RegisterFunction(#fn_name##sv, script_name, fn_name)

void AliasExt::RegisterForSpellTomeReadEvent(
	VM* a_vm,
	StackID a_stackID,
	RE::StaticFunctionTag*,
	const RE::BGSBaseAlias* a_alias)
{
	if (!a_alias) {
		a_vm->TraceStack("akAlias is a NONE alias!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Register(a_alias);
}

void AliasExt::UnregisterForSpellTomeReadEvent(
	VM* a_vm,
	StackID a_stackID,
	RE::StaticFunctionTag*,
	const RE::BGSBaseAlias* a_alias)
{
	if (!a_alias) {
		a_vm->TraceStack("akAlias is a NONE alias!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Unregister(a_alias);
}

bool AliasExt::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST_AliasExt"sv;
	REGISTER(a_vm, scriptname, RegisterForSpellTomeReadEvent);
	REGISTER(a_vm, scriptname, UnregisterForSpellTomeReadEvent);

	return true;
}
