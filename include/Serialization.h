#pragma once

namespace Serialization
{
	constexpr std::uint32_t Version = 1;
	constexpr std::uint32_t ID = 'DEST';
	constexpr std::uint32_t SpellTomeReadEvent = 'STRE';

	void SaveCallback(SKSE::SerializationInterface* a_intfc);

	void LoadCallback(SKSE::SerializationInterface* a_intfc);

	std::string DecodeTypeCode(std::uint32_t a_typeCode);
}
