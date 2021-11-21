#pragma once

namespace Patch
{
	using ReadSpellTomeCallback = void(RE::TESObjectBOOK*, RE::SpellItem*);

	bool WriteSpellTomePatch(ReadSpellTomeCallback* a_callback);
}
