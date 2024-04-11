#ifndef OUT_NATIONAL_IDEAS_H
#define OUT_NATIONAL_IDEAS_H

#include "../Ideas/NationalIdeas.h"

namespace EU4
{
void outNationalIdeas(std::ostream& output, const NationalIdeas& idea, const std::set<std::string>& eu4Cultures);
} // namespace EU4
#endif // OUT_NATIONAL_IDEAS_H