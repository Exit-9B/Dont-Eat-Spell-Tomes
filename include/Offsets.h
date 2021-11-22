#pragma once

namespace Offset
{
#ifndef SKYRIMVR
	namespace TESObjectBOOK
	{
		// SkyrimSE 1.6.318.0: 0x2392A0
		inline constexpr REL::ID ProcessBook(17842);
	}
#else
	namespace TESObjectBOOK
	{
		inline constexpr REL::Offset ProcessBook(0x23B240);
	}
#endif
}
