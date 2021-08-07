#pragma once

namespace DEST
{
	using VM = RE::BSScript::IVirtualMachine;

	int GetAPIVersion(RE::StaticFunctionTag*);

	void SendSpellTomeReadEvent(
		RE::StaticFunctionTag*,
		RE::TESObjectBOOK* a_book,
		RE::SpellItem* a_spell,
		RE::TESObjectREFR* a_container);

	bool RegisterFuncs(VM* a_vm);
};