#include "SpellTomeManager.h"
#include "Offsets.h"
#include "Registration.h"

void SpellTomeManager::InstallHooks()
{
	struct Patch : public Xbyak::CodeGenerator
	{
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
	Patch patch{ reinterpret_cast<std::uintptr_t>(ReadSpellTome) };
	patch.ready();
	assert(patch.getSize() <= 0x56);

	static REL::Relocation<std::uintptr_t> hook{ Offset::TESObjectBook_ProcessBook.address() +
												 0xE8 };
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
}

void SpellTomeManager::ReadSpellTome(RE::TESObjectBOOK* a_book, RE::SpellItem* a_spell)
{
	logger::info("Read spell tome: {}", a_spell->GetFullName());

	RE::TESObjectREFR* container = nullptr;

	const auto ui = RE::UI::GetSingleton();
	const auto menu = ui ? ui->GetMenu<RE::ContainerMenu>() : nullptr;
	const auto movie = menu ? menu->uiMovie : nullptr;

	if (movie) {
		// "Menu_mc" is stored in the class, but it's different in VR and we haven't RE'd it yet
		RE::GFxValue isViewingContainer;
		movie->Invoke("Menu_mc.isViewingContainer", &isViewingContainer, nullptr, 0);

		if (isViewingContainer.GetBool()) {
			auto refHandle = menu->GetTargetRefHandle();
			RE::TESObjectREFRPtr refr;
			RE::LookupReferenceByHandle(refHandle, refr);

			container = refr.get();
		}
	}

	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	regs->QueueEvent(a_book, a_spell, container);
}
