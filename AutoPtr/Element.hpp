#pragma once

#include <string>
class Element {
        std::string m_label;
        std::string m_description;

    public:
        Element(const std::string &_m_label);
        void set_label(const std::string &_m_label);
        const std::string &get_label() const;
        void add_description(const std::string &description);
        void delete_description();
        const std::string get_description() const;
        bool is_empty() const;

};
