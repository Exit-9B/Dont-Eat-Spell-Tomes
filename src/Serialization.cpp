#include "Serialization.h"
#include "Registration.h"

void Serialization::SaveCallback(SKSE::SerializationInterface* a_intfc)
{
	auto regs = OnSpellTomeReadRegSet::GetSingleton();
	if (!regs->Save(a_intfc, SpellTomeReadEvent, Version))
	{
		logger::critical("Failed to save SpellTomeReadEvent regs!"sv);
	}
}

void Serialization::LoadCallback(SKSE::SerializationInterface* a_intfc)
{
	std::uint32_t type;
	std::uint32_t version;
	std::uint32_t length;
	while (a_intfc->GetNextRecordInfo(type, version, length))
	{
		if (version != Version)
		{
			logger::critical("Loaded data is incompatible with plugin version!"sv);
		}

		if (type == SpellTomeReadEvent)
		{
			auto regs = OnSpellTomeReadRegSet::GetSingleton();
			regs->Clear();
			regs->Load(a_intfc);
			if (!regs->Load(a_intfc))
			{
				logger::critical("Failed to load SpellTomeReadEvent regs!"sv);
			}
		}
		else
		{
			logger::critical("Unrecognized record type ({})!", DecodeTypeCode(type));
		}
	}
}

std::string Serialization::DecodeTypeCode(std::uint32_t a_typeCode)
{
	constexpr std::size_t SIZE = sizeof(std::uint32_t);

	std::string sig;
	sig.resize(SIZE);
	char* iter = reinterpret_cast<char*>(&a_typeCode);
	for (std::size_t i = 0, j = SIZE - 2; i < SIZE - 1; ++i, --j)
	{
		sig[j] = iter[i];
	}
	return sig;
}
