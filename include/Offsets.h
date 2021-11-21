#pragma once

namespace Offset
{
#ifndef SKYRIMVR
	namespace TESObjectBOOK
	{
		// SkyrimSE 1.5.97.0: 0x229EF0
		inline constexpr REL::ID ProcessBook(17439);
	}
#else
	namespace TESObjectBOOK
	{
		inline constexpr REL::Offset ProcessBook(0x23B240);
	}
#endif
}
