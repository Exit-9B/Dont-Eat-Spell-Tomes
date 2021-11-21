#include "Papyrus/ActiveMagicEffectExt.h"
#include "Registration.h"

#define REGISTER(vm, script_name, fn_name) \
vm->RegisterFunction(#fn_name ## sv, script_name, fn_name)

void ActiveMagicEffectExt::RegisterForSpellTomeReadEvent(
	VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*,
	const RE::ActiveEffect* a_effect)
{
	if (!a_effect)
	{
		a_vm->TraceStack("akEffect is a NONE effect!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Register(a_effect);
}

void ActiveMagicEffectExt::UnregisterForSpellTomeReadEvent(
	VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*,
	const RE::ActiveEffect* a_effect)
{
	if (!a_effect)
	{
		a_vm->TraceStack("akEffect is a NONE effect!", a_stackID, Severity::kWarning);
		return;
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->Unregister(a_effect);
}

bool ActiveMagicEffectExt::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST_ActiveMagicEffectExt"sv;
	REGISTER(a_vm, scriptname, RegisterForSpellTomeReadEvent);
	REGISTER(a_vm, scriptname, UnregisterForSpellTomeReadEvent);

	return true;
}
