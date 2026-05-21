#pragma once

#include <string>

class Box {
public:
	Box() = default;
	explicit Box(std::string content);

	bool isEmpty() const;

	const std::string& getContent() const;
	void setContent(std::string content);

private:
	std::string content;
};