#pragma once

namespace ActiveMagicEffectExt
{
	using VM = RE::BSScript::IVirtualMachine;
	using StackID = RE::VMStackID;
	using Severity = RE::BSScript::ErrorLogger::Severity;

	void RegisterForSpellTomeReadEvent(
		VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*,
		const RE::ActiveEffect* a_effect);

	void UnregisterForSpellTomeReadEvent(
		VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*,
		const RE::ActiveEffect* a_effect);

	bool RegisterFuncs(VM* a_vm);
};
