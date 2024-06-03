#include "Sed.hpp"

void	replace(std::string& data, const std::string& find, const std::string& replace)
{
	size_t	start = data.find(find, 0);

	while (start != data.npos)
	{
		data.erase(start, find.length());
		data.insert(start, replace);
		start += replace.length();
		start = data.find(find, start);
	}
}