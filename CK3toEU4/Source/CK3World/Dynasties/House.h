#ifndef CK3_HOUSE_H
#define CK3_HOUSE_H
#include "Parser.h"

namespace CK3
{
class Dynasty;
class House: commonItems::parser
{
  public:
	House() = default;
	House(std::istream& theStream, int houseID);
	[[nodiscard]] const auto& getName() const { return name; }
	[[nodiscard]] const auto& getPrefix() const { return prefix; }
	[[nodiscard]] const auto& getDynasty() const { return dynasty; }
	[[nodiscard]] const auto& getID() const { return houseID; }

	void loadDynasty(const std::pair<int, std::shared_ptr<Dynasty>>& theDynasty) { dynasty = theDynasty; }

  private:
	void registerKeys();

	int houseID = 0;
	std::string name;
	std::pair<int, std::shared_ptr<Dynasty>> dynasty;
	std::string prefix;
	
};
} // namespace CK3

#endif // CK3_HOUSE_H