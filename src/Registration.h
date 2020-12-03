#pragma once

class OnSpellTomeReadRegSet : public SKSE::RegistrationSet<RE::TESObjectBOOK*, RE::SpellItem*>
{
public:
	~OnSpellTomeReadRegSet() = default;
	OnSpellTomeReadRegSet(const OnSpellTomeReadRegSet&) = delete;
	OnSpellTomeReadRegSet(OnSpellTomeReadRegSet&&) = delete;

	OnSpellTomeReadRegSet& operator=(const OnSpellTomeReadRegSet&) = delete;
	OnSpellTomeReadRegSet& operator=(OnSpellTomeReadRegSet&&) = delete;

	using Base = SKSE::RegistrationSet<RE::TESObjectBOOK*, RE::SpellItem*>;

	static OnSpellTomeReadRegSet* GetSingleton();

private:
	OnSpellTomeReadRegSet();
};
