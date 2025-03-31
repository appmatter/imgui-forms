#pragma once

#include <imgui.h>
#include <string>
#include <imgui-forms/field_traits.hpp>
#include <imgui-forms/field_traits_macros.hpp>
#include <iostream>
struct ExampleTraitsModel
{
    std::string name;
    std::string email;
};

template <>
struct imgui_forms::FormFieldTraits<ExampleTraitsModel>
{
    static std::string get(const ExampleTraitsModel &u, const std::string &field)
    {
        if (field == "name")
        {
            std::cout << "get name: " << u.name << std::endl;
            return u.name;
        }
        // FORM_FIELD_GET(u, name, field);
        FORM_FIELD_GET(u, email, field);
        throw std::runtime_error("Unknown field");
    }

    static void set(ExampleTraitsModel &u, const std::string &field, const std::string &val)
    {
        if (field == "name")
        {
            std::cout << "set name: " << val << std::endl;
            u.name = val;
        }
        FORM_FIELD_SET(u, email, field, val);
        throw std::runtime_error("Unknown field");
    }
};
