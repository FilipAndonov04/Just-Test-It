#include "Box.h"

Box::Box(std::string content)
    : content(std::move(content)) {}

bool Box::isEmpty() const {
    return content.empty();
}

const std::string& Box::getContent() const {
    return content;
}

void Box::setContent(std::string content) {
    this->content = std::move(content);
}