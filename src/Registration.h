#pragma once

class OnSpellTomeReadRegSet final :
	public SKSE::RegistrationSet<RE::TESObjectBOOK*, RE::SpellItem*, RE::TESObjectREFR*>
{
public:
	~OnSpellTomeReadRegSet() = default;
	OnSpellTomeReadRegSet(const OnSpellTomeReadRegSet&) = delete;
	OnSpellTomeReadRegSet(OnSpellTomeReadRegSet&&) = delete;

	OnSpellTomeReadRegSet& operator=(const OnSpellTomeReadRegSet&) = delete;
	OnSpellTomeReadRegSet& operator=(OnSpellTomeReadRegSet&&) = delete;

	using Base = SKSE::RegistrationSet<RE::TESObjectBOOK*, RE::SpellItem*, RE::TESObjectREFR*>;

	static OnSpellTomeReadRegSet* GetSingleton();

private:
	OnSpellTomeReadRegSet();
};
