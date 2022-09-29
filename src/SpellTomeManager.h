class SpellTomeManager
{
public:
	static void InstallHooks();

private:
	static void ReadSpellTome(RE::TESObjectBOOK* a_book, RE::SpellItem* a_spell);
};