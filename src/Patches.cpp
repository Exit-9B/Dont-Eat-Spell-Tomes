#include "Patches.h"
#include "Offsets.h"

#ifndef SKYRIMVR
bool Patch::WriteSpellTomePatch(ReadSpellTomeCallback* a_callback)
{
	struct Patch : public Xbyak::CodeGenerator
	{
		Patch(std::uintptr_t a_funcAddr)
		{
			Xbyak::Label hookAddr;
			L(hookAddr);

			mov(rcx, r15);
			mov(rax, a_funcAddr);
			call(rax);
			mov(rsi, 0);

			jmp(hookAddr.getAddress() + 0x72); // SkyrimSE 1.6.318: 0x23942F
		}
	};

	// SkyrimSE 1.6.318.0: 0x2392A0 + 0x11D
	std::uintptr_t hookAddr = Offset::TESObjectBOOK::ProcessBook.address() + 0x11D;
	std::uintptr_t funcAddr = reinterpret_cast<std::uintptr_t>(a_callback);
	Patch patch{ funcAddr };
	patch.ready();

	if (patch.getSize() > 0x56) {
		logger::critical("Patch was too large, failed to install"sv);
		return false;
	}

	REL::safe_fill(hookAddr, REL::NOP, 0x56);
	REL::safe_write(hookAddr, patch.getCode(), patch.getSize());

	logger::info("Installed hook for reading spell tome"sv);
	return true;
}

#else

bool Patch::WriteSpellTomePatch(ReadSpellTomeCallback* a_callback)
{
	struct Patch : public Xbyak::CodeGenerator
	{
		Patch(std::uintptr_t a_funcAddr)
		{
			Xbyak::Label hookAddr;
			L(hookAddr);

			mov(rcx, rdi);
			mov(rax, a_funcAddr);
			call(rax);
			mov(rsi, 0);

			jmp(hookAddr.getAddress() + 0x70); // SkyrimVR 1.4.15.1: 0x23B398
		}
	};

	// SkyrimSE 1.5.97.0: 0x229EF0 + 0xE8
	// SkyrimVR 1.4.15.1: 0x23B240 + 0xE8
	std::uintptr_t hookAddr = Offset::TESObjectBOOK::ProcessBook.address() + 0xE8;
	std::uintptr_t funcAddr = reinterpret_cast<std::uintptr_t>(a_callback);
	Patch patch{ funcAddr };
	patch.ready();

	if (patch.getSize() > 0x56) {
		logger::critical("Patch was too large, failed to install"sv);
		return false;
	}
	assert(patch.getSize() <= 0x56);

	REL::safe_fill(hookAddr, REL::NOP, 0x56);
	REL::safe_write(hookAddr, patch.getCode(), patch.getSize());
	logger::info("Installed hook for reading spell tome"sv);
	return true;
}
#endif
