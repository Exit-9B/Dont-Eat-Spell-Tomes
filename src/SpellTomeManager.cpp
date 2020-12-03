#include "SpellTomeManager.h"
#include "Offsets.h"
#include "Registration.h"

void SpellTomeManager::InstallHooks()
{
	struct Patch : public Xbyak::CodeGenerator {
		Patch(std::uintptr_t addr) {
			Xbyak::Label hookaddr;
			L(hookaddr);

			mov(rax, addr);
			call(rax);
			xor_(rax, rax);
			jmp(hookaddr.getAddress() + 0x109);
		}
	};
	Patch patch{ SKSE::unrestricted_cast<std::uintptr_t>(ReadSpellTome) };
	patch.ready();

	static REL::Relocation<std::uintptr_t> hook{ Offset::TESObjectBook_ProcessBook, 0xEF };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::ReadSpellTome(
	[[maybe_unused]] RE::PlayerCharacter* a_player,
	RE::SpellItem* a_spell)
{
	logger::info("Read spell tome: {}", a_spell->fullName);

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->QueueEvent(a_spell);
}
