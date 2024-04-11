#include "outNationalIdeas.h"
#include "OSCompatibilityLayer.h"

void EU4::outNationalIdeas(std::ostream& output, const NationalIdeas& idea, const std::set<std::string>& eu4Cultures)
{
	output << idea.getDynamicName() + "_ideas = {";

	// National Traditions
	output << "\n\tstart = {";
	for (auto& effect: idea.getEthosEffects())
		output << "\n\t\t " + effect.modifier + " = " + effect.value;
	output << "\n\t}";

	// Trigger
	output << "\n\ttrigger = {\n";
	output << "\tOR = {\n";
	for (const auto& culture: eu4Cultures)
	{
		output << "\t\tprimary_culture = " + culture + "\n";
	}
	output << "\t}\n";
	output << "\t}\n";
	output << "\tfree = yes\n\n";

	// First 7 traditions become ideas, last one becomes ambition
	const auto& traditionIdeas = idea.getTraditionIdeas();
	const auto& traditionEffects = idea.getTraditionEffects();

	for (int i = 0; i < traditionIdeas.size() - 1; i++)
	{
		output << "\t" + traditionIdeas[i] + " = {";

		for (auto& effect: traditionEffects[i])
			output << "\n\t\t" + effect.modifier + " = " + effect.value;

		output << "\n\t}\n";
	}

	// National Ambition
	const auto& ambitionEffect = traditionEffects[7].front(); // For multi effect ideas, the ambition is only the first effect, not all effects
	output << "\tbonus = {\n\t\t" + ambitionEffect.modifier + " = " + ambitionEffect.value + "\n\t}\n";
	output << "}\n\n";
}