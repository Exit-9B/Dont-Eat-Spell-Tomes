#include "SpellTomeManager.h"
#include "Offsets.h"
#include "Registration.h"

void SpellTomeManager::InstallHooks()
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

			jmp(hookaddr.getAddress() + 0x70);
		}
	};
	Patch patch{ SKSE::unrestricted_cast<std::uintptr_t>(ReadSpellTome) };
	patch.ready();
	assert(patch.getSize() <= 0x56);

	static REL::Relocation<std::uintptr_t> hook{ Offset::TESObjectBook_ProcessBook, 0xE8 };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::ReadSpellTome(RE::TESObjectBOOK* a_book, RE::SpellItem* a_spell)
{
	logger::info("Read spell tome: {}", a_spell->fullName);

	RE::TESObjectREFR* container = nullptr;

	auto ui = RE::UI::GetSingleton();
	auto menu = ui ? ui->GetMenu<RE::ContainerMenu>() : nullptr;

	if (menu)
	{
		auto refHandle = menu->GetTargetRefHandle();
		if (refHandle)
		{
			RE::TESObjectREFRPtr refr;
			RE::LookupReferenceByHandle(refHandle, refr);
			container = refr.get();
		}
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->QueueEvent(a_book, a_spell, container);
}
