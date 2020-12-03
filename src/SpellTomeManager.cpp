#include "SpellTomeManager.h"
#include "Offsets.h"
#include "Registration.h"

void SpellTomeManager::InstallHooks()
{
	InstallEvent();
	InstallShowBookFromInventory();
	InstallShowBookFromContainer();
}

void SpellTomeManager::InstallEvent()
{
	struct Patch : public Xbyak::CodeGenerator {
		Patch(std::uintptr_t addr)
		{
			Xbyak::Label hookaddr;
			L(hookaddr);

			mov(rcx, rdi);
			mov(rax, addr);
			call(rax);
			mov(rsi, 0);

			jmp(hookaddr.getAddress() + 0x158 - 0xE8);
		}
	};
	Patch patch{ SKSE::unrestricted_cast<std::uintptr_t>(ReadSpellTome) };
	patch.ready();
	assert(patch.getSize() <= 0x56);

	static REL::Relocation<std::uintptr_t> hook{ Offset::TESObjectBook_ProcessBook, 0xE8 };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::InstallShowBookFromContainer()
{
	struct Patch : public Xbyak::CodeGenerator {
		Patch()
		{
			Xbyak::Label hookaddr;
			L(hookaddr);
			jmp(hookaddr.getAddress() + 0xAA - 0x193);
		}
	};
	Patch patch;
	patch.ready();

	static REL::Relocation<std::uintptr_t> hook{ Offset::ContainerMenu_EquipObject, 0x193 };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::InstallShowBookFromInventory()
{
	struct Patch : public Xbyak::CodeGenerator {
		Patch()
		{
			Xbyak::Label hookaddr;
			L(hookaddr);
			jmp(hookaddr.getAddress() + 0xC2 - 0x1B2);
		}
	};
	Patch patch;
	patch.ready();
	assert(patch.getSize() <= 0x3E);

	static REL::Relocation<std::uintptr_t> hook{ Offset::InventoryMenu_EquipObject, 0x1B2 };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::ReadSpellTome(RE::TESObjectBOOK* a_book, RE::SpellItem* a_spell)
{
	logger::info("Read spell tome: {}", a_spell->fullName);

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->QueueEvent(a_book, a_spell);
}
