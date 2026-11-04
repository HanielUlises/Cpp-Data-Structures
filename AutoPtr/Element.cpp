#include "Element.hpp"

Element::Element(const std::string &_m_label) : m_label(_m_label) {}

void Element::set_label(const std::string &_m_label) {
    m_label = _m_label;
}

const std::string &Element::get_label() const {
    return m_label;
}

void Element::add_description(const std::string &description) {
    m_description = description;
}

void Element::delete_description() {
    m_description.clear();
}

const std::string &Element::get_description() const {
    return m_description;
}

bool Element::is_empty() const {
    return m_description.empty() && m_label.empty();
}
