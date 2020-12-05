#include "FormExt.h"
#include "Registration.h"

#define REGISTER(vm, script_name, fn_name) \
vm->RegisterFunction(#fn_name ## sv, script_name, fn_name, true)

void FormExt::RegisterForSpellTomeReadEvent(
	VM * a_vm, StackID a_stackID, RE::StaticFunctionTag*,
	const RE::TESForm* a_form)
{
	if (!a_form)
	{
		a_vm->TraceStack("akForm is a NONE form!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Register(a_form);
}

void FormExt::UnregisterForSpellTomeReadEvent(
	VM * a_vm, StackID a_stackID, RE::StaticFunctionTag*,
	const RE::TESForm* a_form)
{
	if (!a_form)
	{
		a_vm->TraceStack("akForm is a NONE form!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Unregister(a_form);
}

bool FormExt::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST_FormExt"sv;
	REGISTER(a_vm, scriptname, RegisterForSpellTomeReadEvent);
	REGISTER(a_vm, scriptname, UnregisterForSpellTomeReadEvent);

	return true;
}
