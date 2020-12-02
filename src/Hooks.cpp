#include "Hooks.h"

namespace Hooks
{
	constexpr REL::ID TESObjectBook_ProcessBook{ 17439 };

	void ReadSpellBook([[maybe_unused]] RE::PlayerCharacter* a_player, [[maybe_unused]] RE::SpellItem* a_spell)
	{
		logger::info("Read spell book: {}", a_spell->fullName);
	}

	void Install()
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
		Patch patch{ SKSE::unrestricted_cast<std::uintptr_t>(ReadSpellBook) };
		patch.ready();

		static REL::Relocation<std::uintptr_t> hook{ TESObjectBook_ProcessBook, 0xEF };
		REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
	}
}