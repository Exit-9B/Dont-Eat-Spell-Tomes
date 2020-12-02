class SpellTomeManager
{
public:
	static void InstallHooks();

private:
	static void ReadSpellTome(RE::PlayerCharacter* a_player, RE::SpellItem* a_spell);
};