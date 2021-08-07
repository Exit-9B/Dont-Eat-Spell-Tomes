#pragma once

namespace AliasExt
{
	using VM = RE::BSScript::IVirtualMachine;
	using StackID = RE::VMStackID;
	using Severity = RE::BSScript::ErrorLogger::Severity;

	void RegisterForSpellTomeReadEvent(
		VM* a_vm,
		StackID a_stackID,
		RE::StaticFunctionTag*,
		const RE::BGSBaseAlias* a_alias);

	void UnregisterForSpellTomeReadEvent(
		VM* a_vm,
		StackID a_stackID,
		RE::StaticFunctionTag*,
		const RE::BGSBaseAlias* a_alias);

	bool RegisterFuncs(VM* a_vm);
};
